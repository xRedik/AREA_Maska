#include "BluetoothSerial.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
TFT_eSPI tft = TFT_eSPI(); 

const int oneWireBus = 12;

OneWire oneWire(oneWireBus);

DallasTemperature sensors(&oneWire);

String message = "";
char incomingChar;
String temperatureString = "";
float PreviousTemperature;
boolean Final = false;
unsigned long k = 1;
boolean DisplayBool = false;
String DisplayString = "";
unsigned long previousMillis = 0;
const long interval = 5000;
boolean dataflag2;
int xpos,xposAREA;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("AREA Mask");
  Serial.println("The device started, now you can pair it with bluetooth!");
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  randomSeed(analogRead(A0));
}

void loop() {
  if (SerialBT.available()) {
    DisplayString = SerialBT.readString();
    dataflag2=true;
  }
  
  if(dataflag2){
    Serial.print(DisplayString);
    //Serial.println(DisplayString.length());
    DisplayString.remove(DisplayString.length()-2);
    DisplayString.toLowerCase();
    if(DisplayString.equals("ekran aktiv olunsun")){
      Serial.println("Display Activated");
      DisplayBool=true;
    }
    else if(DisplayString.equals("ekran deaktiv olunsun")){
      Serial.println("Display Deactivated");
      DisplayBool=false;
      tft.fillScreen(TFT_BLACK);
    }
    
    DisplayString="";
    dataflag2=false;
  }
  delay(20);
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if(DisplayBool){
      tft.fillScreen(TFT_YELLOW);
      tft.setRotation(1);
      tft.setTextColor(TFT_BLACK); 
      tft.setTextDatum(TC_DATUM); 
      xpos = tft.width() / 2;  
      xposAREA=tft.width()*0.85;
      tft.drawString("AREA", xposAREA, 3, 4); 
      tft.drawString("Temperatur", xpos, 30, 4); 
    }
    sensors.requestTemperatures();
    float Temperatur = sensors.getTempCByIndex(0) + 2.3;
    if(Temperatur < 30.0){
      if(DisplayBool) tft.drawString("Maska daxil deyil", xpos, 54, 4);
      SerialBT.println("Xahiş olunur maskanı üzünüzə taxıb sensorun üz ilə təmasda olduğundan əmin olasınız!");
    }
    else {
      if (PreviousTemperature == Temperatur) k++;
      else k = 1;
      if(DisplayBool) tft.drawString(String(Temperatur,1), xpos, 54, 8);
      if (k == 3) Final = true;
      else Final = false;
      if (Final) {
        if (Temperatur < 37.0){
          if(DisplayBool){
            tft.fillScreen(TFT_BLUE);
            tft.drawString("AREA", xposAREA, 3, 4); 
            tft.drawString("Final Temperatur", xpos, 30, 4); 
            tft.drawString(String(Temperatur,1), xpos, 54, 8);
          }
          temperatureString = "Sizin temperaturunuz " + String(Temperatur) + "C-dir və təhlükəsizdir.  ";
          delay(10000);
        }
        else{
          if(DisplayBool){
            tft.fillScreen(TFT_RED);
            tft.drawString("AREA", xposAREA, 3, 4); 
            tft.drawString("Final Temperatur", xpos, 30, 4); 
            tft.drawString(String(Temperatur,1), xpos, 54, 8);
          }
          temperatureString = "TƏCİLİ: Sizin temperaturunuz " + String(Temperatur) + "C-dir və Normadan artıqdır.";
          delay(10000);
        }
      }
      else temperatureString = "Temperatur ölçülür: " + String(Temperatur) + "C ";
      PreviousTemperature = Temperatur;
      SerialBT.println(temperatureString);
    }
    if(DisplayBool) screenServer();
  }
  else{
      if(DisplayBool){
        tft.fillScreen(TFT_BLACK);
        tft.fillRect( 0, 0, 16, 16, TFT_RED);
        tft.fillRect(16, 0, 16, 16, TFT_GREEN);
        tft.fillRect(32, 0, 16, 16, TFT_BLUE);
        screenServer();
      }
    }
  }
