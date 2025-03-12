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
    if(x>0.05 && x<=200){
      resultado = (x*0.51684) - 0.8154;
    }
    if(x>200 && x<=2000){
      resultado = (x*0.51718) - 1.067;
    }
    if(x>2000){
      resultado = (x*0.51493) + 3.361;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.4359) - 0.2479;
    }
    if(x>5 && x<=200){
      resultado = (x*0.5152) - 0.7256;
    }
    if(x>200){
      resultado = (x*0.51777) - 1.267;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.43814) - 0.3091;
    }
    if(x>5){
      resultado = (x*0.5159) - 0.7317;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}

float CalibrarFI(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 0){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
   ///*
    if(x>0.05 && x<=200){
      resultado = (x*0.5219) + 0.5246;
    }
    if(x>200 && x<=2000){
      resultado = (x*0.5219) + 0.5246;
    }
    if(x>2000){
      resultado = (x*0.5219) + 0.5246;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=200){
      resultado = (x*0.52676) + 0.4958;
    }
    if(x>200){
      resultado = (x*0.52166) + 1.308;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.52696) + 0.3254;
    }
    if(x>5){
      resultado = (x*0.52696) + 0.3254;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}

