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
      if(x<=12){
        resultado = (x*0.4307)-0.271;
      }
      if(x>12 && x<=500){
        resultado = (x*0.403) + 0.028;
      }
      if(x>500){
        resultado = (x*0.404) - 0.343;
      }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
      if(x<=12){
        resultado = (x*0.3986)+0.0676;
      }
      if(x>12 && x<=500){
        resultado = (x*0.4033) - 0.0191;
      }
      if(x>500){
        resultado = (x*0.4065) - 6.111;
      }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
     ///*
      if(x<=12){
        resultado = (x*0.4079)-0.0608;
      }
      if(x>12){
        resultado = (x*0.4018) + 0.0185;
      }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}