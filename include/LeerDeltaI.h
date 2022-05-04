#include <Arduino.h>

float LeerDeltaI(int canal, int escala){
  
  float diferencia = 0.0;
  float corriente = 0.0;
  float tension = 0.0;

  float data = 0.0;
  int Iteraciones;
  int ret;


  ///*
  Iteraciones = 25;ret=10;

  for (int i = 0; i < Iteraciones; i++) {

    if(canal == 1){
      diferencia = ads.readADC_Differential_0_1();
    }else{
      diferencia = ads.readADC_Differential_2_3();
    }
    data = diferencia + data;
    delay(ret);

  }

  if(canal == 1){
    tension = float( (data / Iteraciones) * constanteADS );
    tension = Calibrar(tension,escala);
    corriente = float( (tension / constanteRshunt) - offset_1);
    ///*
    if(corriente > 1 || corriente < -1){
      digitalWrite(output_zumbador, HIGH);
    }else{
      digitalWrite(output_zumbador, LOW);
    }
    //*/
  }else{
    tension = float((data / Iteraciones) * constanteADS);
    tension = Calibrar(tension,escala);
    corriente = float( (tension / constanteRshunt) - offset_2);
    ///*
    if(corriente > 1 || corriente < -1){
      digitalWrite(output_zumbador, HIGH);
    }else{
      digitalWrite(output_zumbador, LOW);
    }
    //*/
  }
  
  /*///////////////////////////////////////////////////////////
      El tiempo que demoramos en tomar la lectura es:
      tiempo = (Iteraciones)*(4+ret)  [=] mili segundos
  */////////////////////////////////////////////////////////

  return corriente;
}
