#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    /*
    if(x>100 && x<=1000){
      x = (x*1.0004)+0.0165;
    }
    if(x>1000){
      x = (x*1.0006)-0.1591;
    }
    */
  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    /*
    if(x>0.5 && x<=50){
      x = (x*1.0001)+0.0030;
    }
    if(x>50){
      x = (x*1.0005)-0.0312;
    }
    */
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    /*
    if(x>0.2 && x<=5){
      x = (x*1.0022)+0.0018;
    }
    if(x>5){
      x = (x*1.0007)+0.0199;
    }
    */
  }

    if(negativo == true){
        x = x*-1;
    }

    return x;
}