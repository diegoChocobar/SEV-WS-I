#include <Arduino.h>

void PrintDeltaVLCD_Calibracion(Corrientes x, int y);
void PrintDeltaILCD(float x, int y);

void PrintDeltaI(){

  Corrientes deltaIf; //corriente de fuga, nos sirve para activar o desactivar el sonido
  Corrientes data_corriente = {0,0,0,0,0,0,0};//

  if(tiempo_actual > tiempo_LCD + 300){
      //pasaron 500ms
      tiempo_LCD = tiempo_actual;

      if(bandHold == false){
        tiempo_medida_total = millis();
        data_corriente = LeerDeltaI(1,escala);//obtenemos deltaI calibrado
        deltaI = data_corriente;
        tiempo_medida_total = millis() - tiempo_medida_total;
        deltaI.tiempo_total = tiempo_medida_total;
        //EnviarDatos(deltaI,sizeof(deltaI)/sizeof(deltaI[0]));
        //EnviarDatos1(data_corriente.valor,"VALOR");
        //EnviarDatos1(data_corriente.promedio,"PROMEDIO");
        //EnviarDatos1(data_corriente.desvio_standar,"DesvioStandar");
        //EnviarDatos1(data_corriente.tamaño,"tamaño medidas");
        //EnviarDatos2(data_corriente,"P,V,d,t,n");
        if(bandCalibrtacion==true){
            PrintDeltaILCD(deltaI.valor,escala);
        }else{
            PrintDeltaVLCD_Calibracion(deltaI,escala);//visualizacion de calibracion
        }
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

void PrintDeltaVLCD_Calibracion(Corrientes x, int y){

  boolean negativo = false;
  if(x.valor < 0){
    x.valor = x.valor * -1;
    negativo = true;
  }

  lcd.home();lcd.clear();
  lcd.setCursor(0, 0);
  if(negativo == true){lcd.print("CORRIENTE  A-B  (-)");}else{lcd.print("CORRIENTE  A-B  (+)");}
  if(y == 0) {lcd.setCursor(0, 3);lcd.print("*6000mV*");}
  if(y == 2) {lcd.setCursor(0, 3);lcd.print("*2000mV*");}
  if(y == 16){lcd.setCursor(0, 3);lcd.print("*250mV**");}

  lcd.setCursor(0, 1);lcd.print("V");lcd.print(x.valor,3);
  lcd.setCursor(9, 1);lcd.print("d");lcd.print(x.desvio_standar,3);
  lcd.setCursor(16, 1);lcd.print("n");lcd.print(x.n,0);

  lcd.setCursor(0, 2);lcd.print("P");lcd.print(x.promedio,3);
  lcd.setCursor(16, 2);lcd.print("t");lcd.print(x.tamaño,0);

  lcd.setCursor(8, 3);lcd.print("Time:");lcd.print(x.tiempo_total,0);
}


void PrintDeltaILCD(float x, int y){//x:corriente y:escala


  unsigned long unidad,decena,centena,mil,diezmil;
  boolean negativo = false;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }
    //* Habilitar una vez calibrado
    if(x < 0.1){//por debajo de este valor mostramos cero, para evitar oscilaciones pequeñas
      x = 0;
    }
    //*/

  if(y == 0){//tension maxima a medir son +/- 6.144V con resolucion de 0.1875mV
    if(x<=2000){
      //debemos mostrar 4 numero con un punto decimal
      x = x*10.0;
      diezmil = x/10000;
      mil = (x - diezmil*10000) / 1000;
      centena =(x - diezmil*10000 - mil*1000) / 100;
      decena = (x - diezmil*10000 - mil*1000 - centena*100) / 10;
      unidad = (x - diezmil*10000 - mil*1000 - centena*100 - decena*10);


      lcd.home();lcd.clear();
      lcd.setCursor(0, 0);
      if(negativo == true){lcd.print("CORRIENTE  A->B  (-)");}else{lcd.print("CORRIENTE  A->B  (+)");}
      lcd.setCursor(0, 3);
      lcd.print("***Escala: 2000mA***");
      mostranumero(pos1_unidad,unidad);
      mostranumero(pos1_decena,decena);
      mostranumero(pos1_unidad,unidad);
      mostranumero(pos1_decena,decena);
      if(diezmil==0 && mil==0 && centena==0){}else{mostranumero(pos1_centena,centena);}
      if(diezmil==0 && mil==0){}else{mostranumero(pos1_mil,mil);}
      if(diezmil!=0){mostranumero(pos1_diezmil,diezmil);} 
      lcd.setCursor(15,2);
      lcd.print("*");
    }
    else{
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

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    if(x<=1000){
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
      lcd.print("***Escala: 1000mA***");
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
      lcd.print("***Escala: 1000mA***");
      mostranumero(pos1_unidad,8);
      mostranumero(pos1_decena,8);
      mostranumero(pos1_centena,8);
      mostranumero(pos1_mil,8);
      mostranumero(pos1_diezmil,8);
      lcd.setCursor(15,2);
      lcd.print("*");

    }
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    if(x<=100){
      //debemos mostrar 3 numero con dos punto decimal
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
      lcd.print("***Escala: 100mA***");
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
      lcd.print("***Escala: 100mA***");
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
