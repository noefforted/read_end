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
    // Serial.print(data);
    if (data == marker[index])
    {
      index++;
      if (index == marker.length())
      {
        Serial.println(filtered_data);
        filtered_data = "";
        index = 0;
      }
    }
    else
    {
      filtered_data += data;
      index = 0;
    }
  }
  else
  {
    Serial.println("Data tidak diterima");
  }
  delay(1000);
}
