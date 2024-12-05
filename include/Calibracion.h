#include <Arduino.h>

float Calibrar(float x, int y){//x:tension y:escala

    boolean negativo = false;
    float resultado = 0;

  if(x < 0){
    x = x * -1;
    negativo = true;
  }

  if(y == 0){//tension maxima a medir son +/- 6.144V  con resolucion de 0.0625mV
   ///*
    if(x>0.05 && x<=400){
      resultado = (x*0.4945) + 0.0454;
    }
    if(x>400 && x<=2000){
      resultado = (x*0.4960) - 0.7781;
    }
    if(x>2000){
      resultado = (x*0.4939) + 3.4246;
    }
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.4579) - 0.0194;
    }
    if(x>5 && x<=400){
      resultado = (x*0.4938) - 0.1309;
    }
    if(x>400){
      resultado = (x*0.4950) + 1.8387;
    }
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    if(x>0.05 && x<=5){
      resultado = (x*0.4467) + 0.0026;
    }
    if(x>5){
      resultado = (x*0.4965) - 0.2477;
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
    //*/
  }

  if(y == 2){//tension maxima a medir son +/- 2.048V con resolucion de 0.0625mV
    ///*
    //*/
  }

  if(y == 16){//tension maxima a medir son +/- 0.256V con resolucion de 0.0078125mV
    ///*
    //*/
  }

    if(negativo == true){
        x = x*-1;
        resultado = resultado*-1;
    }

    return resultado;
}

