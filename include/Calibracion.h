#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
   ///*
    if(x<=0.05){
      resultado = 0.00;
    }
    if(x>0.05 && x<=0.25){
      resultado = (x*1.986);
    }
    if(x>0.25 && x<=2.5){
      resultado = (x*1.986)+0.0128;
    }
    if(x>2.5 && x<=12.5){
      resultado = (x*1.9924)-0.0335;
    }
    if(x>12.5 && x<=125.0){
      resultado = (x*1.9873)+0.0070;
    }
    if(x>125.0 && x<=500.0){
      resultado = (x*1.9798)+1.299;
    }
    if(x>500.0){
      resultado = (x*2.0433)-32.44;
    }
    //*/
  }

  if(y == 4){//tension maxima a medir son +/- 1.024V con resolucion de 0.03125mV
    ///*
    if(x<=0.05){
      resultado = 0.00;
    }
    if(x>0.05 && x<=0.25){
      resultado = (x*1.9902);
    }
    if(x>0.25 && x<=2.5){
      resultado = (x*1.9902)+0.0021;
    }
    if(x>2.5 && x<=12.5){
      resultado = (x*1.9888)-0.0122;
    }
    if(x>12.5 && x<=125.0){
      resultado = (x*1.9876)+0.0083;
    }
    if(x>125.0){
      resultado = (x*1.98)+1.2264;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x<=0.05){
      resultado = 0.00;
    }
    if(x>0.05 && x<=0.25){
      resultado = (x*1.999);
    }
    if(x>0.25 && x<=2.5){
      resultado = (x*1.9864)-0.0005;
    }
    if(x>2.5 && x<=12.5){
      resultado = (x*1.9892)-0.0053;
    }

    if(x>12.5){
      resultado = (x*1.9883)+0.0222;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}