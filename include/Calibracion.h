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
      resultado = (x*0.50292) - 0.0286;
    }
    if(x>200){
      resultado = (x*0.4994) + 0.3311;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=200){
      resultado = (x*0.50272) - 0.0479;
    }
    if(x>200){
      resultado = (x*0.50104) + 0.3173;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05){
      resultado = (x*0.50224) - 0.0324;
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
      resultado = (x*0.5022) - 0.0541;
    }
    if(x>200){
      resultado = (x*0.49935) + 1.4500;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=200){
      resultado = (x*0.5043) + 0.0158;
    }
    if(x>200){
      resultado = (x*0.50047) + 0.6614;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05){
      resultado = (x*0.50452) + 0.00145;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}

