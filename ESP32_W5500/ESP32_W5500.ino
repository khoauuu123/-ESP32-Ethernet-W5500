#include <SPI.h>
#include <Ethernet.h>

// Thay thế các địa chỉ MAC và IP bằng các địa chỉ thực tế của mạng của bạn
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

#define W5500_CS 5

void setup() {
  Serial.begin(115200);

  // Khởi tạo giao tiếp SPI
  SPI.begin();
  Ethernet.init(W5500_CS);
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // No point in carrying on, so do nothing forevermore:
    while (true);
  }
  // In các thông tin mạng
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.print("Subnet mask: ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("DNS server: ");
  Serial.println(Ethernet.dnsServerIP());
}

void loop() {

}