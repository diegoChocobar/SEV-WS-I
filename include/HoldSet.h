#include <Arduino.h>

#include <EnviarDatos.h>

void HoldSet(void){

  if(tiempo_actual > tiempo_pulsadorH + 25){
    //pasaron xxms
    tiempo_pulsadorH = tiempo_actual;

    if(digitalRead(pulsador_hold) == 1){
      if (bandHold == false) {//debemos congelar la señal actual
        bandHold = true;

        digitalWrite(output_led, HIGH);
        lcd.setCursor(0, 3);
        lcd.print("*HOLD ON --> MEDIDA*");

        /////////////////////////////////////////////////////////////////////////////////////////
        ///////////////Enviamos datos al software///////////////////////////////////////////////
        EnviarDatos(deltaI);
        ////////////////////////////////////////////////////////////////////////////////////////
        
        delay(150);//retardo de antirrebote (debido a que es una señal de otra placa que simula un pulsador)
        //Print en LCD que estamos poniento a cero off-set la medicion

        while(digitalRead(pulsador_hold) == 1){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        delay(50);
      }else{//debemos seguir midiendo
        bandHold = false;
        digitalWrite(output_led, LOW);
        lcd.setCursor(0, 3);
        lcd.print("*HOLD OFF -> MEDIDA*");
        delay(150);//retardo de antirrebote (debido a que es una señal de otra placa que simula un pulsador)
        //Print en LCD que estamos poniento a cero-cero la medicion
        while(digitalRead(pulsador_hold) == 1){delay(10);} //mientras tenememos presionado el pulsador de zero off set
        delay(50);
      }
    }

  }else{
    if(tiempo_actual<tiempo_pulsadorH){
      //se produjo un desbordamiento
      tiempo_pulsadorH = (4294967295-tiempo_pulsadorH) + tiempo_actual;
    }
  }

}
