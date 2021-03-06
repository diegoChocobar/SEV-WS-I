#include <Arduino.h>

void PrintDeltaILCD(float x, int y);

void PrintDeltaI(){

  float deltaIf = 0; //corriente de fuga, nos sirve para activar o desactivar el sonido

  if(tiempo_actual > tiempo_LCD + 500){
      //pasaron 500ms
      tiempo_LCD = tiempo_actual;

      if(bandHold == false){
        deltaI = LeerDeltaI(1,escala);//obtenemos deltaI calibrado
        //EnviarDatos(deltaI);
        PrintDeltaILCD(deltaI,escala);
      }else{
        //estamos en holld
        deltaIf = LeerDeltaI(1,escala);//obtenemos deltaI calibrado
      }
  }else{
    if(tiempo_actual<tiempo_LCD){
      //se produjo un desbordamiento
      tiempo_LCD = (4294967295-tiempo_LCD) + tiempo_actual;
    }
  }

}


void PrintDeltaILCD(float x, int y){//x:corriente y:escala


  unsigned long unidad,decena,centena,mil,diezmil;
  boolean negativo = false;
  //x = float(x * constanteRshunt);//llevamos "x" a tension para poder evaluar en que escala debe trabajar el conversor ad1115
  //x = abs(x);//abs redondea el numero a entero (no usar en este caso)

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    if(x<=2000){
      //debemos mostrar 4 numero con un punto decimal
      float xx = 0.0; //numero a redondear
      x = x*10.0;
      xx = round(x);

      diezmil = xx/10000;
      mil = (xx - diezmil*10000) / 1000;
      centena =(xx - diezmil*10000 - mil*1000) / 100;
      decena = (xx - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (xx - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("CORRIENTE  A->B  (-)");}else{lcd.print("CORRIENTE  A->B  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 2000mA***");
      mostranumero(pos1_unidad,unidad);
      mostranumero(pos1_decena,decena);
      if(diezmil==0 && mil==0 && centena==0){}else{mostranumero(pos1_centena,centena);}
      if(diezmil==0 && mil==0){}else{mostranumero(pos1_mil,mil);}
      if(diezmil!=0){mostranumero(pos1_diezmil,diezmil);} 
      lcd.setCursor(15,2);
      lcd.print("*");

    }else{
      //estamos fuera de escala
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***CORRIENTE  A-B***");
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 2000mA***");
      mostranumero(pos1_unidad,8);
      mostranumero(pos1_decena,8);
      mostranumero(pos1_centena,8);
      mostranumero(pos1_mil,8);
      mostranumero(pos1_diezmil,8);
      lcd.setCursor(15,2);
      lcd.print("*");

    }
  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    if(x<=1000){
      //debemos mostrar 4 numero con un punto decimal
      x = x*100.0;
      diezmil = x/10000;
      mil = (x - diezmil*10000) / 1000;
      centena =(x - diezmil*10000 - mil*1000) / 100;
      decena = (x - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (x - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("CORRIENTE  A->B  (-)");}else{lcd.print("CORRIENTE  A->B  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 1000mA***");
      mostranumero(pos2_unidad,unidad);
      mostranumero(pos2_decena,decena);
      mostranumero(pos2_centena,centena);
      if(diezmil==0 && mil==0){}else{mostranumero(pos2_mil,mil);}
      if(diezmil != 0){mostranumero(pos2_diezmil,diezmil);}
      lcd.setCursor(11,2);
      lcd.print("*");
    }
    else{
      //estamos fuera de escala
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***CORRIENTE  A-B***");
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 1000mA***");
      mostranumero(pos2_unidad,8);
      mostranumero(pos2_decena,8);
      mostranumero(pos2_centena,8);
      mostranumero(pos2_mil,8);
      mostranumero(pos2_diezmil,8);
      lcd.setCursor(11,2);
      lcd.print("*");
    }
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    if(x<=250){
      //debemos mostrar 4 numero con un punto decimal
      x = x*100.0;
      diezmil = x/10000;
      mil = (x - diezmil*10000) / 1000;
      centena =(x - diezmil*10000 - mil*1000) / 100;
      decena = (x - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (x - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("CORRIENTE  A->B  (-)");}else{lcd.print("CORRIENTE  A->B  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 250mA***");
      mostranumero(pos2_unidad,unidad);
      mostranumero(pos2_decena,decena);
      mostranumero(pos2_centena,centena);
      if(diezmil==0 && mil==0){}else{mostranumero(pos2_mil,mil);}
      if(diezmil != 0){mostranumero(pos2_diezmil,diezmil);}
      lcd.setCursor(11,2);
      lcd.print("*");
    }
    else{
      //estamos fuera de escala
      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("***CORRIENTE A-B***");
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 250mA***");
      mostranumero(pos2_unidad,8);
      mostranumero(pos2_decena,8);
      mostranumero(pos2_centena,8);
      lcd.setCursor(11,2);
      lcd.print("*");
      mostranumero(pos2_mil,8);
      mostranumero(pos2_diezmil,8);
      lcd.setCursor(11,2);
      lcd.print("*");
    }
  }


}
