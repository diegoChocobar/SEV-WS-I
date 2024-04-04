#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }
  if(x<=1.0){//Limite inferior para la lectura de corriente
    resultado = 0.00;
  }

  if(y == 0){//tension maxima a medir son +/- 6.144V  con resolucion de 0.1875mV
   ///*
      if(x>1.0 && x <= 400){
        resultado = (x*0.5132)-1.2022;
      }
      if(x > 400){
        resultado = (x*0.5137)-3.8036;
      }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
      if(x>1.0 && x <= 400){
        resultado = (x*0.5118)-1.1113;
      }
      if(x > 400){
        resultado = (x*0.5099)-1.3993;
      }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>1.0){
        resultado = (x*0.5138)-1.1027;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}