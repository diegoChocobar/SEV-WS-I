#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_ADS1X15.h>
//#include <Adafruit_ADS1015.h>

#include <LiquidCrystal_I2C.h>

#include <Variables.h>
#include <function.h>
#include <Setup.h>
#include <Calibracion.h>
#include <LeerDeltaI.h>
#include <SelectEscala.h>
#include <ZeroOffSet.h>
#include <HoldSet.h>
#include <PrintDeltaI.h>
#include <SelectPotencia.h>

///Este es proyecto subido a github 


void loop(void)
{

  tiempo_LCD = millis();
  tiempo_pulsadorZ = millis();
  tiempo_pulsadorE = millis();
  tiempo_pulsadorS = millis();
  tiempo_pulsadorH = millis();


  while (1){

    tiempo_actual = millis();

    PrintDeltaI();

    SelectEscala();

    ZeroOffSet();

    HoldSet();

    //SelectPotencia();

    delay(10);

    webSocket.loop();


  }


}
