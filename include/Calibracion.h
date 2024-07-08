#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }
  if(x<=0.5){//Limite inferior para la lectura de corriente
    resultado = 0.00;
  }

  if(y == 0){//tension maxima a medir son +/- 6.144V con resolucion de 0.0625mV -- Escala 2500mv
    if(x>0.5 && x<=400){
      resultado = (x*0,5333)-0.885;
    }
    if(x>400){
      resultado = (x*0.5329) - 6.03;
    }
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV -- Escala 1000mv
    if(x>0.5 && x<=400){
      resultado = (x*0,533)-0.5324;
    }
    if(x>400){
      resultado = (x*0.5323) - 4.524;
    }
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV -- Escala 100mv
    if(x>0.5 && x<400){
      resultado = (x*0,5329)-0.5811;
    }
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}