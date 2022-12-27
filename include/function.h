#include <Arduino.h>



void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {

	switch(type) {
		case WStype_DISCONNECTED:
            lcd.setCursor(0, 0);
            lcd.print("WSocket NO Conectado");
			break;
		case WStype_CONNECTED:
            lcd.setCursor(0, 0);
            lcd.print("WSocket I OK");
            delay(2000);
			break;
		case WStype_TEXT:

            if (strcmp((char*)payload, "SEV_C/SEV_I/Check/?") == 0) {
                //lcd.print("Check I");
                webSocket.sendTXT("SEV_I/SEV_C/Check/Ok");
                delay(50);
            }
            if (strcmp((char*)payload, "SEV_C/SEV_I/Disparo/ON") == 0) {
                bandDisparoWEB = true;
                webSocket.sendTXT("SEV_I/SEV_C/Disparo/ON");
                delay(50);
            }
            if (strcmp((char*)payload, "SEV_C/SEV_I/Disparo/OFF") == 0) {
                bandDisparoWEB = false;
                webSocket.sendTXT("SEV_I/SEV_C/Disparo/OFF");
                delay(50);
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
