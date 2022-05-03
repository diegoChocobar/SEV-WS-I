#include <Arduino.h>

//si usas esp8266
#include <ESP8266WiFi.h>
//#include <WebSocketsClient.h>
#include <Hash.h>

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

void Conectar_WiFi(){

    int cont_conexion = 0;

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    
    lcd.clear();lcd.setCursor(0, 0);
    lcd.print("Conectando...");

  while (WiFi.status() != WL_CONNECTED  and cont_conexion <50) { //Check for the connection
    cont_conexion = cont_conexion +1;
    delay(500);
    //Serial.print(".");
    lcd.print(".");
    if(WiFi.status() == WL_CONNECT_FAILED){
      //contraseña incorrecta, salimos del bucle
      cont_conexion = 100;
    }
    if (digitalRead(pulsador) == 0 || digitalRead(input_zero) == 0){
      /* no deseamos conectarnos con software */
      cont_conexion = 100;
      delay(100);//retardo de antirrebote
      while(digitalRead(pulsador) == 0){delay(10);}//mientras tenemos presionado el pulsador
      while(digitalRead(input_zero) == 0){delay(10);}//mientras tenemos presionado el pulsador

    }
    

  }


  if(WiFi.status()== WL_CONNECTED){
    ///Nos conectamos satisfactoriamente con el soft
    digitalWrite(output_led, HIGH);
    IPAddress IP = WiFi.localIP();

    lcd.clear();
    lcd.setCursor(0, 0) ;
    lcd.print("********************");
    lcd.setCursor(0, 1);
    lcd.print("**Conexion Exitosa**");
    lcd.setCursor(0, 2);
    lcd.print("IP: ");lcd.print(IP);
    lcd.setCursor(0, 3);
    lcd.print("********************");

    delay(5500);
    digitalWrite(output_led, LOW);

        ////Probado con la libreria Arduino WebSocket ////////////////
        // try to connect to Websockets server
        /*
        bool connected = client.connect(websockets_server_host, websockets_server_port, "/");
        //bool connected = client.connect("ws://192.168.1.1:80/");
        if(connected) {
            //Serial.println("Connected!");
            lcd.setCursor(0, 0);
            lcd.print("WSocket Conectado");
            client.send("Hello Server. Cliente SEV-I");
            delay(1000);
        } else {
            //Serial.println("Not Connected!");
            lcd.setCursor(0, 0);
            lcd.print("WSocket NO Conectado");
            delay(1000);
        }
        
        // run callback when messages are received
        client.onMessage([&](WebsocketsMessage message){
            //Serial.print("Got Message: ");
            //Serial.println(message.data());
        });
        */

    ////Probado con la libreria WebSocket ////////////////
          // server address, port and URL
          //IPAddress Server_IP(192,168,1,1);
          //webSocket.begin(Server_IP, 81);
          webSocket.begin("192.168.1.1", 80, "/ws");

          // event handler
          webSocket.onEvent(webSocketEvent);
          // try ever 5000 again if connection has failed
          webSocket.setReconnectInterval(5000);  // start heartbeat (optional)
          
          // ping server every 15000 ms
          // expect pong from server within 3000 ms
          // consider connection disconnected if pong is not received 2 times
          webSocket.enableHeartbeat(15000, 3000, 2);
    /////////////////////////////////////////////////////////////////////////////

  }else{
      //No nos pudimos conectar al software
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Equipo NO Conectado!");
        lcd.setCursor(0, 1);
        lcd.print("Error: ");

        ///*
        if(WiFi.status() == WL_NO_SSID_AVAIL){
          lcd.setCursor(0, 2);
          lcd.print("SSID no encontrado");
          lcd.setCursor(0, 3);
          lcd.print("********************");
        }
        if(WiFi.status() == WL_CONNECT_FAILED){
          lcd.setCursor(0, 2);
          lcd.print("Pass faild");
          lcd.setCursor(0, 3);
          lcd.print("********************");
        }
        if(WiFi.status() == WL_DISCONNECTED){
          lcd.setCursor(0, 2);
          lcd.print("Modulo STA faild");
          lcd.setCursor(0, 3);
          lcd.print("Pass faild");
        }
        //*/

        delay(2500);
  }

} 
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

	switch(type) {
		case WStype_DISCONNECTED:
			//USE_SERIAL.printf("[WSc] Disconnected!\n");
      lcd.setCursor(0, 0);
      lcd.print("WSocket NO Conectado");
			break;
		case WStype_CONNECTED:
			//USE_SERIAL.printf("[WSc] Connected to url: %s\n", payload);

			// send message to server when Connected
      lcd.setCursor(0, 0);
      lcd.print("WSocket I OK");
      delay(2000);
			break;
		case WStype_TEXT:
			//USE_SERIAL.printf("[WSc] get text: %s\n", payload);

			// send message to server
      lcd.setCursor(0, 0);
      lcd.print("msg: ");

      if (strcmp((char*)payload, "SEV_C/SEV_I/Check/?") == 0) {
        lcd.print("Check I");
        webSocket.sendTXT("SEV_I/SEV_C/Check/Ok");
        delay(1000);
      }
			break;
		case WStype_BIN:
			//USE_SERIAL.printf("[WSc] get binary length: %u\n", length);
			//hexdump(payload, length);

			// send data to server
			// webSocket.sendBIN(payload, length);
			break;
		case WStype_ERROR:
      lcd.setCursor(0, 0);
      lcd.print("WSocket NO Error!");		
      break;	
		case WStype_FRAGMENT_TEXT_START:
		case WStype_FRAGMENT_BIN_START:
		case WStype_FRAGMENT:
		case WStype_FRAGMENT_FIN:
			break;
	}

}
