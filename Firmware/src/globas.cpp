#include "globals.h"

// Definición de las instancias de hardware
BluetoothSerial SerialBT; 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
HuskylensV2 huskylens; 
HardwareSerial mySerial2(2); // Bus serial UART2 (GPIO 16 RX y 17 TX)
DFRobotDFPlayerMini myDFPlayer;

// Inicialización de variables globales de control
char modoActual = 'H'; 
int ultimoID = -1; 
unsigned long tiempoUltimoAudio = 0; 
unsigned long tiempoUltimoVisto = 0; 
unsigned long duracionBloqueo = 2000; 
bool accionEjecutada = false; 
bool huskyActivo = false; 
unsigned long tiempoUltimoReporte = 0;

// Inicialización de variables de marcha
int PERIODO = 1000;  
int LIFT    = 15;    
int STRIDE  = 12; 
int TURN    = 10; 

int estado = 0; 
float currentAngles[12] = {0};

// Límites físicos de rotación por canal de servo
const float maxAngulos[12] = {270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270, 270};