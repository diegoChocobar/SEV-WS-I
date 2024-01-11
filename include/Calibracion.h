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
    if(x>0.1 && x<=5){
      resultado = (x*1.9843)+0.1096;
    }
    if(x>5 && x<=100){
      resultado = (x*1.983)+0.1425;
    }
    if(x>100 && x<=1000){
      resultado = (x*1.9861)-3.3632;
    }
    if(x>1000.0){
      resultado = (x*1.9549)+30.372;
    }
    //*/
  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    ///*
    if(x>0.1 && x<=5){
      resultado = (x*1.9846)+0.0878;
    }
    if(x>5 && x<=100){
      resultado = (x*1.9808)+0.1814;
    }
    if(x>100){
      resultado = (x*1.9849)-2.5177;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.1 && x<=5){
      resultado = (x*1.9953) - 0.0414;
    }
    if(x>5 && x<=100){
      resultado = (x*1.9856) + 1.6884;
    }

    if(x>100){
      resultado = (x*1.9823) - 3.347;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}