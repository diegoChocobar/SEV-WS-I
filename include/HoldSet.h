#include <Arduino.h>

#include <EnviarDatos.h>

void HoldSet(void){


    if(señalhold == true){
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

        señalhold = false;
        delay(50);

      }else{//debemos seguir midiendo
        bandHold = false;
        digitalWrite(output_led, LOW);
        lcd.setCursor(0, 3);
        lcd.print("*HOLD OFF -> MEDIDA*");
        delay(150);//retardo de antirrebote (debido a que es una señal de otra placa que simula un pulsador)
        señalhold = false;
        delay(50);
      }
    

  }

}
