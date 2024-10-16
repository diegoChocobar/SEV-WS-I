#include <Arduino.h>


void FuenteInterna(void){

  if(tiempo_actual > tiempo_pulsadorF + 50){
    //pasaron 100ms
    tiempo_pulsadorF = tiempo_actual;

    if(digitalRead(pulsador_fuenteinterna) == bandFuenteInterna && bandHold == false){

      if (digitalRead(pulsador_fuenteinterna) == false) {//la llave se encuentra presionada
        bandFuenteInterna = true;      //debemos configurar la calibracion con fuente interna
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);
        delay(200);//retardo de antirrebote
        //Serial.println("Puesta a CERO OFF-SET la medion...");
        lcd.setCursor(0, 3);
        lcd.print("Fuente Interna -> ON");//Print en LCD que estamos poniento a cero off-set la medicion
        
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, LOW);
        
      }else{
        bandFuenteInterna = false;  //debemos configurar la calibracion con SIN fuente interna/////////
        digitalWrite(output_led, HIGH);
        digitalWrite(output_zumbador, HIGH);
        delay(200);//retardo de antirrebote
        //Serial.println("Puesta a CERO OFF-SET la medion...");
        lcd.setCursor(0, 3);
        lcd.print("Fuente Interna ->OFF");//Print en LCD que estamos poniento a cero off-set la medicion
        digitalWrite(output_led, LOW);
        digitalWrite(output_zumbador, LOW);
      }
    }

  }else{
    if(tiempo_actual<tiempo_pulsadorF){
      //se produjo un desbordamiento
      tiempo_pulsadorF = (4294967295-tiempo_pulsadorF) + tiempo_actual;
    }
  }

}
