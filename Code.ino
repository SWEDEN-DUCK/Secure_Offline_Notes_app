#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <SD.h>

WebServer server(80);

String notes = "";


void loadNotes() {
  if (SD.exists("/notes.txt")) {
    File file = SD.open("/notes.txt", FILE_READ);
    notes = file.readString();
    file.close();
  }
}

void saveNotes(String data) {
  File file = SD.open("/notes.txt", FILE_WRITE);
  if (file) {
    file.print(data);
    file.close();
  }
}

String htmlPage() {
  String page = "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>Notes</title></head><body>";
  page += "<h1>Offline-Notes</h1>";
  page += "<form action='/save' method='POST'>";
  page += "<textarea name='text' rows='20' cols='50'>" + notes + "</textarea><br>";
  page += "<input type='submit' value='Save'>";
  page += "</form>";
  page += "</body></html>";
  return page;
}

void handleRoot() {
  server.send(200, "text/html", htmlPage());
}

void handleSave() {
  if (server.hasArg("text")) {
    notes = server.arg("text");
    saveNotes(notes);
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);

  SPI.begin(6, 8, 10, 5);  // SCK, MISO, MOSI, CS
  if (!SD.begin(5)) {
    Serial.println("Problem whith SD!");
    return;
  }

  loadNotes();

  /*
  Change IP (The IP address needs to be a valid format)
  Local_ip > whatever IP you want the ESP32 to have.
  Gateway > should match local_ip for easy offline use.
  Subnet > leave as 255.255.255.0 for regular home and offline networks.
  */
  IPAddress local_ip(10, 10, 10, 10);
  IPAddress gateway(10, 10, 10, 10);
  IPAddress subnet(255, 255, 255, 0);

  WiFi.softAPConfig(local_ip, gateway, subnet);

  // Access Point
  WiFi.softAP("ESP32_Notes", "123456789");  // Change WiFI name and password
  Serial.println("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/save", HTTP_POST, handleSave);
  server.begin();
}

void loop() {
  server.handleClient();
}
