#include <Arduino.h>

#include <ESP8266HTTPClient.h>


void EnviarDatos(float x){

    float corriente;

  if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

    WiFiClient client;

    HTTPClient http;

    //corriente = random(0,20000)/100.0;

    corriente = x;

    String string_i = String(corriente,2);

    String datos_a_enviar = "esp_corriente=" + string_i + "&esp_status_i=1";
    
    
    //http.begin("http://10.42.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    //http.begin("http://192.0.0.1/cdcelectronics/recibe.php");        //Indicamos el destino

    http.begin(client,"http://10.42.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    //http.begin("http://192.0.0.1/cdcelectronics/recibe.php");        //Indicamos el destino
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Preparamos el header text/plain si solo vamos a enviar texto plano sin un paradigma llave:valor.

    int codigo_respuesta = http.POST(datos_a_enviar);   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)
    
    delay(100);

    if(codigo_respuesta>0){
      //Serial.println("Código HTTP ► " + String(codigo_respuesta));   //Print return code

      if(codigo_respuesta == 200){
        //String cuerpo_respuesta = http.getString();
        //Serial.println("El servidor respondió ▼ ");
        //Serial.println(cuerpo_respuesta);
        lcd.setCursor(0, 0);
        lcd.print("Dato Enviado->Exito!");

      }
    }else{

     //Serial.print("Error enviando POST, código: ");
     //Serial.println(codigo_respuesta);
     lcd.setCursor(0, 0);
     lcd.print("ERROR Envio de Dato*");

    }

    http.end();  //libero recursos

  }



}