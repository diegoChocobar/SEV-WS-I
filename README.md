
# SEV-WS-I
Este proyecto parte de la base que tenemos en SEV_Corriente, lo que moficamos es que toda la comunicacion se realiza mediante WebSocket.

Inicio de Proyecto: 20-12-2021

Version: 0.1 -->  20-12-2021
    Esta version contiene de base el soft anterior (comunicacion por HTTP->POST). 

Version 0.5  -->  03-05-2022
    En esta version trabajamos en:
     * Conexión a red Wifi.
     * Conexión a WebSocket.
     * Respuesta a Check Funcionamiento.

Version 0.6 -->  04-05-2022
    En esta version trabajamos en:
     * Mejora en visor de valores en lcd.
     * Calibración desactivada y Rshunt = 1.
     * Funcion de Enviar datos OK

Version 0.61 -->  04-05-2022
    En esta version trabajamos en:
     * Correcion string Envio de datos
     * Mejora en el tiempo de muestreo de carteles de inicio

Version 0.7  --> 13-09-2022
    En esta version trabajamos en:
     * en function incluimos la recepcion de dato por websocket para hacer hold
     * ya no recibimos señal digital para hacer hold

Version 0.9 --> 23-09-2022
    En esta version trabajamos en:
     * Reemplazamos HoldSet por Hold, ahora recibimos la orden de hold por el pulsador y la enviamos a la placa de tension
     * Cambiamos la velocidad de toma de datos de sensor ads1115, la dejamos en 490sps al igual que la placa de tension
     * La calibracion se encuentra desactivada

Version 1.0 --> 27-12-2022
    En esta version trabajamos en:
     * Limpiamos el codigo
     * Check la funcion de disparo
     * La calibracion se encuentra desactivada

Version 2.0 --> 23-01-2023
    En esta version trabajamos en:
     * Crear codigo para que la señal de corriente sea tratada con array y mejoramos asi el calculo
     * Todas las funciones fueron adaptadas para que funcionen.
     * La calibracion se encuentra desactivada