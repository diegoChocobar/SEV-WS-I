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
    if(x>0.05 && x<=400){
      resultado = (x*0.4251) - 0.056;
    }
    if(x>400 && x<=2000){
      resultado = (x*0.42542) - 0.4998;
    }
    if(x>2000){
      resultado = (x*0.4248) + 0.9727;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.4243) - 0.0281;
    }
    if(x>5 && x<=400){
      resultado = (x*0.42573) - 0.11575;
    }
    if(x>400){
      resultado = (x*0.42626) - 0.7195;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.41966) + 0.0251;
    }
    if(x>5){
      resultado = (x*0.43536) + 0.0188;
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

  if(y == 0){//tension maxima a medir son +/- 6.144V con resolucion de 0.0625mV
   ///*
    if(x>0.05 && x<=400){
      resultado = (x*0.4300) - 0.0564;
    }
    if(x>400 && x<=2000){
      resultado = (x*0.4290) - 0.0187;
    }
    if(x>2000){
      resultado = (x*0.4254) + 5.8299;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=400){
      resultado = (x*0.4318) - 0.1019;
    }
    if(x>400){
      resultado = (x*0.4298) + 1.0364;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05){
      resultado = (x*0.4418) + 0.0473;
    }
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}

