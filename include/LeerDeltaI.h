#include <Arduino.h>

Corrientes calculo_corrientes(float x[], int length);


Corrientes LeerDeltaI(int canal, int escala){
  
  float diferencia = 0.0;

  Corrientes result;
  float deltaI_señal[Iteraciones];
  
  int ret=1;

  ///*

  for (int i = 0; i < Iteraciones; i++) {

    if(canal == 1){
      diferencia = ads.readADC_Differential_0_1();
      deltaI_señal[i]= diferencia;
    }else{
      diferencia = ads.readADC_Differential_2_3();
      deltaI_señal[i]= diferencia;
    }
    delay(ret);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds

  }

  if(canal == 1){
    delay(1);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds
    result = calculo_corrientes(deltaI_señal,Iteraciones);
    result.valor = Calibrar(result.valor,escala);//aqui se incluye el valor del divisor resistivo
    delay(1);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds
    result.valor = result.valor - offset_1.valor;
  }

  if(result.valor > 1 || result.valor < -1){
    digitalWrite(output_zumbador, HIGH);
  }else{
    digitalWrite(output_zumbador, LOW);
  }


  return result;
}

Corrientes calculo_corrientes(float x[], int length){

  float corriente[length];
  float tension[length];
  float sumatoria=0;
  //float result=0;
  Corrientes result;
  result.valor=0;
  result.promedio=0;
  result.desvio_standar=0;

  int n=0;
  float valor=0;

//////////////Calculo de valor promerio //////////////////////////////
    for (int i = 0; i < length; i++) {
      tension[i] = float( (x[i] ) * constanteADS );
      //tension[i] = Calibrar(tension,escala);
      corriente[i] = float(tension[i] / constanteRshunt) ;
      //corriente[i] = corriente[i] *constanteProteccion; //esto debido a que tenemos una placa de proteccion que tiene un divisor resistivo X2
      result.promedio = result.promedio + corriente[i];
    }
    delay(1);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds
    result.promedio = result.promedio / length;
    result.tamaño = length;
/////////////////////////////////////////////////////////////////////////

///////////////calculo de desvio standard//////////////////    
    for (int i = 0; i < length; i++) {
        sumatoria = sumatoria + (corriente[i]-result.promedio)*(corriente[i]-result.promedio);
    }
    delay(1);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds
    result.desvio_standar = sqrt(sumatoria/length);
////////////////////////////////////////////////////////////

//////////////Calculo del valor final ////////////////////////////
    for (int i = 0; i < length; i++) {
      
      corriente[i] = sqrt(corriente[i]*corriente[i]);
      if(corriente[i]<=sqrt(result.promedio*result.promedio)+2*(result.desvio_standar))
      {
        n = n+1;
        valor = valor + corriente[i];
      }
      
    }
    delay(1);//este "delay" es fundamental para que la conexión WEBSOCKET no de caiga. no es lo mismo delayMicroseconds
    result.n = n;
    result.valor = float(valor/n);
    
    if(result.promedio < 0){
      result.valor = result.valor * -1;//conservamos el signo de la lectura
    }
///////////////////////////////////////////////////////////////////


    return result;
}
