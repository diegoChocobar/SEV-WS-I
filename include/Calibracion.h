#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }
  if(x<=0.1){//Limite inferior para la lectura de corriente
    resultado = 0.00;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
   ///*
    if(x>0.1 && x<=2.5){
      resultado = (x*2.00)-0.0001;
    }
    if(x>2.5 && x<=12.5){
      resultado = (x*2.00)-0.0001;
    }
    if(x>12.5 && x<=125.0){
      resultado = (x*2.00)-0.0001;
    }
    if(x>125.0 && x<=500.0){
      resultado = (x*2.00)-0.0001;
    }
    if(x>500.0){
      resultado = (x*2.00)-0.0001;
    }
    //*/
  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    ///*
    if(x>0.1 && x<=2.5){
      resultado = (x*2.00)-0.0001;
    }
    if(x>2.5 && x<=12.5){
      resultado = (x*2.00)-0.0001;
    }
    if(x>12.5 && x<=125.0){
      resultado = (x*2.00)-0.0001;
    }
    if(x>125.0){
      resultado = (x*2.00)-0.0001;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.1 && x<=2.5){
      resultado = (x*2.00)-0.0001;
    }
    if(x>2.5 && x<=12.5){
      resultado = (x*2.00)-0.0001;
    }

    if(x>12.5){
      resultado = (x*2.00)-0.0001;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}