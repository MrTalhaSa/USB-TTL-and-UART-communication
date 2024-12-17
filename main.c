#include <SoftwareSerial.h>

// SoftwareSerial portunu tanımlayın (dijital pinler kullanılacak)
SoftwareSerial ttlSerial(10, 11); // RX, TX pinleri (TTL ile bağladığınız pinler)
int ledPin = 13; // LED'in bağlı olduğu pin (Arduino'nun 13. pinine bağlı)

void setup() {
  Serial.begin(9600);  // Arduino'nun USB üzerinden bilgisayara haberleşmesi
  ttlSerial.begin(9600); // Arduino RX ve TX pinleri üzerinden TTL ile haberleşme
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarla
  Serial.println("LED kontrol sistemi başladı.");
}

void loop() {
  // TTL adaptöründen veri alıp bilgisayara gönder
  if (ttlSerial.available()) {
    char data = ttlSerial.read();
    Serial.print("TTL'den gelen veri: ");
    Serial.println(data);
    
    // Gelen veri 'A' ise LED'i yak
    if (data == 'A' || data == 'a') {
      digitalWrite(ledPin, HIGH); // LED'i yak
      Serial.println("LED Yandı");
    }
    
    // Gelen veri 'B' ise LED'i söndür
    if (data == 'B' || data == 'b') {
      digitalWrite(ledPin, LOW); // LED'i söndür
      Serial.println("LED Sönüldü");
    }
  }

  // Bilgisayardan TTL adaptörüne veri gönder
  if (Serial.available()) {
    char data = Serial.read();
    ttlSerial.write(data);
    Serial.print("Bilgisayardan gönderilen veri: ");
    Serial.println(data);
  }
}
