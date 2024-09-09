#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10);

char data;
String marker = "end";
String filtered_data = "";
int index = 0;
void setup()
{
  Serial.begin(115200);
  mySerial.begin(115200);
}

void loop()
{
  if (mySerial.available())
  {
    data = mySerial.read();
    // data = "12en13end14nd15end";
    // Serial.print(" ");
    Serial.print(data);
    if (data == marker[index]) // Mendeteksi data = e atau n atau d
    {
      index++;                      // Kalau iya maka pembacaan dilanjutkan
      if (index == marker.length()) // Jika sudah terpenuhi [2] = panjang end = 3
      {
        Serial.print(" Data yang terfilter: ");
        Serial.println(filtered_data); // Maka print data di wadah
        filtered_data = "";            // Reset untuk pembacaan selanjutnya
        index = 0;                     // Reset index juga
      }
    }
    else if (data != 'e' || data != 'n' || data != 'd') // Kalau tidak terdeteksi e atau n atau d
    {
      filtered_data += data; // Maka data dimasukkan ke wadah (filtered_data)
      index = 0;             // Menjaga index tetap kereset
    }
  }
  else
  {
    Serial.println("Data tidak diterima");
  }
  delay(1000);
}
