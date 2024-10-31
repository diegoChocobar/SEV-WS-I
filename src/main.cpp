#include <Arduino.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_ADS1X15.h>
//#include <Adafruit_ADS1015.h>

#include <LiquidCrystal_I2C.h>

#include <Variables.h>
#include <function.h>
#include <Setup.h>
#include <EnviarDatos.h>
#include <Calibracion.h>
#include <LeerDeltaI.h>
#include <SelectEscala.h>
#include <ZeroOffSet.h>
#include <Hold.h>
#include <PrintDeltaI.h>
#include <Disparo.h>
#include <FuenteInterna.h>


void loop(void)
{

  tiempo_LCD = millis();
  tiempo_pulsadorZ = millis();
  tiempo_pulsadorE = millis();
  tiempo_pulsadorH = millis();
  tiempo_pulsadorD = millis();
  tiempo_pulsadorF = millis();

  ////////Bloque para INICIALIZAR WebSockwt de forma CORRECTA////////////////////
  while(webSocket.isConnected()==false){
    webSocket.loop();
    delay(10);
  }
  ///////////////////////////////////////////////////////////////////////////////

  while (1){

    tiempo_actual = millis();

    PrintDeltaI();delay(10);webSocket.loop();

    SelectEscala();delay(10);webSocket.loop();

    ZeroOffSet();delay(10);webSocket.loop();

    Hold();delay(10);webSocket.loop();

    Disparo();delay(10);webSocket.loop();

    FuenteInterna();delay(10);webSocket.loop();

    delay(10);

    webSocket.loop();


  ////////Bloque para RE-INICIALIZAR WebSockwt en caso que se CAIGA////////////////////
  while(webSocket.isConnected()==false){
    webSocket.loop();
    delay(10);
  }
  ///////////////////////////////////////////////////////////////////////////////


  }


}
