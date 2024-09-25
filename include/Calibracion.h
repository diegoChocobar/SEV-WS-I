#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 0){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
   ///*
    if(x>0.05 && x<=400){
      resultado = (x*0.51924)+0.1767;
    }
    if(x>400 && x<=2000){
      resultado = (x*0.5183) + 0.70142;
    }
    if(x>2000){
      resultado = (x*0.51711) + 3.1772;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=400){
      resultado = (x*0.5174)-0.69248;
    }
    if(x>400){
      resultado = (x*0.51698) - 0.34122;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05){
      resultado = (x*0.52081)-0.3462;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}