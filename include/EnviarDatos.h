#include <Arduino.h>

#include <ESP8266HTTPClient.h>


void EnviarDatos(float x){

    float corriente;


    //tension = random(0,20000)/100.0;
    if(x<0){x=x*-1;}
    corriente = x;

    String string_i = String(corriente,2);
    String str_final = "SEV_I/SEV_C/Corriente/" + string_i;
    
    webSocket.sendTXT(str_final);

}

void EnviarHold(String hold){

    //String string_h = String(hold);

    String str_final = "SEV_I/SEV_V/Hold/" + hold;
    webSocket.sendTXT(str_final);

}