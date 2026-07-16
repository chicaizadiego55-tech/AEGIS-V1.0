#include <Arduino.h>
#include <Wire.h>
#include "src/globals.h"
#include "src/config.h"
#include "src/bluetooth.h"
#include "src/servos.h"
#include "src/locomotion.h"
#include "src/vision.h"
#include "src/audio.h"
#include "src/animations.h"
#include "src/battery.h"
#include "src/utils.h"

void setup() {
  Serial.begin(115200); 
  Wire.begin(); 
  
  // Inicialización modular jerárquica
  initAudio();
  initBluetooth();
  initServos();
  initVision();
  initBattery();
  
  standUp(); 
  Serial.println("✅ AEGIS EduBot: Inicialización modular exitosa.");
}

void loop() {
  // 1. LEER COMANDOS BLUETOOTH
  if (SerialBT.available()) {
    char dato = SerialBT.read();
    procesarBT(dato);
  }

  // 2. PROCESAR LA VISIÓN (CON TEMPORIZADOR ANTIBLOQUEO)
  static unsigned long tiempoUltimaMirada = 0;
  if (modoActual != '0' && huskyActivo == true && estado == 0) {
    // Frecuencia controlada a 150 ms para evitar latencia en Bluetooth
    if (millis() - tiempoUltimaMirada > 150) { 
      procesarVision();
      tiempoUltimaMirada = millis();
    }
  }

  // 3. MÁQUINA DE ESTADOS - EJECUTAR MARCHAS Y COMPORTAMIENTOS
  switch(estado) {
    case 1: trotStepRecto();     break;
    case 2: trotStepAtras();     break;
    case 3: trotStepIzquierda(); break;
    case 4: trotStepDerecha();   break;
    case 5: sentarseYDarMano();  break; 
  }

  // 4. TELEMETRÍA (Reporte cada 1 segundo)
  if (millis() - tiempoUltimoReporte > 1000) {
    imprimirSenales();
    tiempoUltimoReporte = millis();
  }
}