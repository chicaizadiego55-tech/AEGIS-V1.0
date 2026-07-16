#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "BluetoothSerial.h" 
#include "DFRobot_HuskylensV2.h" 
#include "DFRobotDFPlayerMini.h"
#include "config.h"

// --- Instancias de Hardware (Declaración externa) ---
extern BluetoothSerial SerialBT; 
extern Adafruit_PWMServoDriver pwm;
extern HuskylensV2 huskylens; 
extern HardwareSerial mySerial2; 
extern DFRobotDFPlayerMini myDFPlayer;

// --- Variables de Control y Estados ---
extern char modoActual; 
extern int ultimoID; 
extern unsigned long tiempoUltimoAudio; 
extern unsigned long tiempoUltimoVisto; 
extern unsigned long duracionBloqueo; 
extern bool accionEjecutada; 
extern bool huskyActivo; 
extern unsigned long tiempoUltimoReporte;

// --- Parámetros Cinematizados de Marcha ---
extern int PERIODO;  
extern int LIFT;    
extern int STRIDE; 
extern int TURN; 

extern int estado; 
extern float currentAngles[12];
extern const float maxAngulos[12];

#endif