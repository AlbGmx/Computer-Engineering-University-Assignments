#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int ONE_WIRE_BUS = 7;
OneWire oneWireLocal(ONE_WIRE_BUS);
DallasTemperature sensorsLocal(&oneWireLocal);

float tempLocal = 0.0;

const int FAN_OUTPUT = 8;

void setup()
{
   // set up the LCD's number of columns and rows
   lcd.begin(16, 2);

   pinMode(8, OUTPUT);

   Serial.begin(9600);
   sensorsLocal.begin();
}

void loop()
{
   CheckTemps();

   lcd.setCursor(0, 0);
   lcd.print("Temp: ");
   lcd.setCursor(6, 0);
   lcd.print(tempLocal);

   if (tempLocal > 26)
   {
      lcd.setCursor(0, 1);
      lcd.print("Fan: ON ");
      digitalWrite(FAN_OUTPUT, HIGH);
   }
   else
   {
      lcd.setCursor(0, 1);
      lcd.print("Fan: OFF");
      digitalWrite(FAN_OUTPUT, LOW);
   }
}

void CheckTemps()
{
   sensorsLocal.requestTemperatures(); // Send command to get temperature from the DS18B20
   // The sensor will return reading from previous request unless a delay is used to give it time to
   // complete the reading request.  If polling every second like we are doing here, the delay can be ignored.
   delay(100);
   tempLocal = sensorsLocal.getTempCByIndex(0); // There can be more than one device on this same bus
                                                // so we need to use the first index of (0)
}