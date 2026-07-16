# AEGIS EduBot - Firmware 

Este firmware está modularizado para la fácil compilación y control del robot móvil cuadrúpedo AEGIS.

## Requisitos de Librerías
Asegúrate de instalar las siguientes dependencias en tu Arduino IDE o PlatformIO:
1. **Adafruit PWM Servo Driver Library** (para el chip PCA9685)
2. **DFRobot_Huskylens** (para la cámara inteligente)
3. **DFRobotDFPlayerMini** (para el reproductor de sonido)

## Cómo compilar
1. Crea una carpeta llamada `AEGIS` en tu directorio de proyectos de Arduino.
2. Clona o copia el contenido de `AEGIS.ino` dentro de esa carpeta.
3. Crea un subdirectorio llamado `src` al mismo nivel de tu archivo `.ino`.
4. Añade todos los archivos `.h` y `.cpp` dentro de la carpeta `src/`.
5. Abre `AEGIS.ino` en el Arduino IDE y presiona **Upload** (Subir) seleccionando la placa **ESP32 Dev Module**.