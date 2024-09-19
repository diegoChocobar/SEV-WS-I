#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 0){//tension maxima a medir son +/- 6.144V con resolucion de 0.0625mV
   ///*
    if(x>0.05 && x<=200){
      resultado = (x*0.49691)-0.1736;
    }
    if(x>200){
      resultado = (x*0.49566) + 1.079;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=200){
      resultado = (x*0.49668)-0.1203;
    }
    if(x>200){
      resultado = (x*0.49732) + 0.3959;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05){
      resultado = (x*0.49763)-0.0511;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}