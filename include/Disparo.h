#include <Arduino.h>

//#include <EnviarDatos.h>

void Disparo(void){

  if(tiempo_actual > tiempo_pulsadorD + 300){
    //pasaron 100ms
    tiempo_pulsadorD = tiempo_actual;

    /////////////////////////////////////////////////////////////
    
    if(digitalRead(pulsador_disparo) != bandDisparo){
      
        delay(10);
        lcd.setCursor(0, 0);
        lcd.print("Disparo");
        bandDisparo = digitalRead(pulsador_disparo);
        digitalWrite(output_disparo, !bandDisparo);
        digitalWrite(output_zumbador, !bandDisparo);
        digitalWrite(output_led, !bandDisparo);
        delay(10);
      
    }
    if(bandDisparoWEB != bandDisparoWEBAnt){
      
        delay(10);
        lcd.setCursor(0, 0);
        lcd.print("Disparo:");
        lcd.print(bandDisparoWEB);
        bandDisparoWEBAnt = bandDisparoWEB;
        digitalWrite(output_disparo, bandDisparoWEB);
        digitalWrite(output_zumbador, bandDisparoWEB);
        digitalWrite(output_led, bandDisparoWEB);
        delay(10);
      
    }

    /////////////////////////////////////////////////////////////
  }else{
    if(tiempo_actual<tiempo_pulsadorD){
      //se produjo un desbordamiento
      tiempo_pulsadorD = (4294967295-tiempo_pulsadorD) + tiempo_actual;
    }
  }

}
