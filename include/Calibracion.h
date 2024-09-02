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
    if(x>0.5 && x<=500){
      resultado = (x*0.48779)-0.011;
    }
    if(x>500 && x<=2000){
      resultado = (x*0.48771) - 4.122;
    }
    if(x>2000){
      resultado = (x*0.48591) - 0.193;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.5 && x<=500){
      resultado = (x*0.48777)+0.045;
    }
    if(x>500){
      resultado = (x*0.48777) - 3.202;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.5){
      resultado = (x*0.49895)+0.064;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}