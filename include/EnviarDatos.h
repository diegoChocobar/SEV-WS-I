#include <Arduino.h>

#include <ESP8266HTTPClient.h>

void EnviarCorriente(float x){

    float corriente;

    if(x<0){x=x*-1;}
    
    String string_corriente = "SEV_I/SEV_C/Corriente/" + String(x,2);
    webSocket.sendTXT(string_corriente);

}


void EnviarDatos(float x[], int length){

    float corriente;


    //tension = random(0,20000)/100.0;
    //if(x<0){x=x*-1;}
    
    int tamaño = length;
    String string_tamaño = "SEV_I/SEV_C/tamaño/" + String(tamaño);
    webSocket.sendTXT(string_tamaño);

    String string_array = "";
    //*
    for(int i=0;i<tamaño;i++){
        corriente = x[i];
        string_array = string_array + "[i"+String(i)+"]" + String(corriente);
    }
    //*/

    String str_final = "SEV_I/SEV_C/MIli Amperes/" + string_array;
    webSocket.sendTXT(str_final);
}

void EnviarHold(String hold){

    //String string_h = String(hold);

    String str_final = "SEV_I/SEV_V/Hold/" + hold;
    webSocket.sendTXT(str_final);

}

void EnviarDatos1(float x, String str){
    delay(1);
    String string_envia = "SEV_I/SEV_C/"+ str +"/" + String(x);
    webSocket.sendTXT(string_envia);
    delay(1);
}

void EnviarDatos2(Corrientes x, String str){
    delay(1);
    String string_envia = "SEV_I/SEV_C/"+ str +"/" + String(x.promedio)+";"+String(x.valor)+";"+String(x.desvio_standar)+";"+String(x.tamaño)+";"+String(x.n)+";";
    webSocket.sendTXT(string_envia);
    delay(1);
}