#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }
  /* 
  if(x<=0.5){//Limite inferior para la lectura de corriente
    resultado = 0.00;
  }
  */

  if(y == 0){//tension maxima a medir son +/- 6.144V con resolucion de 0.1875mV
   ///*
      if(x<=400){
        resultado = (x*0.502)+0.0257;
      }
      if(x>400){
        resultado = (x*0.5027) - 1.2625;
      }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
      if(x<=400){
        resultado = (x*0.5026)-0.0122;
      }
      if(x>400){
        resultado = (x*0.5028) - 4.471;
      }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
      if(x<=250){
        resultado = (x*0.5018)-0.068;
      }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}