#include "vision.h"
#include "globals.h"

void initVision() {
  if (!huskylens.begin(Wire)) { 
    Serial.println("⚠️ ALERTA: HuskyLens NO detectada.");
    huskyActivo = false;
  } else {
    Serial.println("✅ HuskyLens conectada.");
    huskylens.switchAlgorithm(ALGORITHM_HAND_RECOGNITION);
    huskyActivo = true;
  }
}

void procesarVision() {
  eAlgorithm_t algoritmoActual;
  
  if (modoActual == 'A') algoritmoActual = ALGORITHM_FACE_RECOGNITION;
  else if (modoActual == 'B') algoritmoActual = ALGORITHM_COLOR_RECOGNITION;
  else if (modoActual == 'C') algoritmoActual = ALGORITHM_OBJECT_CLASSIFICATION;
  else if (modoActual == 'D') algoritmoActual = ALGORITHM_SELF_LEARNING_CLASSIFICATION;
  else if (modoActual == 'H') algoritmoActual = ALGORITHM_HAND_RECOGNITION;
  else return; 

  if (huskylens.getResult(algoritmoActual)) {
    int cantidad = huskylens.available(algoritmoActual); 
    if (cantidad > 0) {
      tiempoUltimoVisto = millis(); 
      Result *result = static_cast<Result *>(huskylens.popCachedResult(algoritmoActual));
      
      if (result->width > 30 && result->height > 30) {
        if (modoActual == 'H') {
          if (result->ID == 1 && !accionEjecutada) {
            estado = 5; 
            accionEjecutada = true;
          } else if (result->ID == 0) {
            accionEjecutada = false; 
          }
        }
        else if (result->ID != ultimoID && (millis() - tiempoUltimoAudio > duracionBloqueo)) {
          ultimoID = result->ID; 
          tiempoUltimoAudio = millis(); 
          duracionBloqueo = 3500; 

          if (modoActual == 'A') {
            if (result->ID == 1) { duracionBloqueo = 5000; myDFPlayer.play(1); }
            else if (result->ID == 2) { duracionBloqueo = 5000; myDFPlayer.play(2); }
            else if (result->ID == 3) { duracionBloqueo = 5000; myDFPlayer.play(3); }
            else if (result->ID == 0) { duracionBloqueo = 6000; myDFPlayer.play(4); } 
          }
          else if (modoActual == 'B') {
            if (result->ID == 1) { myDFPlayer.play(5); }
            else if (result->ID == 2) { myDFPlayer.play(6); }
            else if (result->ID == 3) { myDFPlayer.play(7); }
            else if (result->ID == 4) { myDFPlayer.play(8); }
            else if (result->ID == 5) { myDFPlayer.play(9); }
            else if (result->ID == 6) { myDFPlayer.play(10); }
          }
          else if (modoActual == 'D') {
            if (result->ID == 1) { duracionBloqueo = 20000; myDFPlayer.play(11); }
            else if (result->ID == 3) { myDFPlayer.play(12); }
            else if (result->ID == 6) { myDFPlayer.play(13); }
            else if (result->ID == 7) { myDFPlayer.play(14); }
            else if (result->ID == 11) { myDFPlayer.play(15); }
            else if (result->ID == 31) { myDFPlayer.play(25); }
            else if (result->ID == 13) { duracionBloqueo = 4000; myDFPlayer.play(17); }
            else if (result->ID == 25) { duracionBloqueo = 4000; myDFPlayer.play(18); }
            else if (result->ID == 15) { duracionBloqueo = 4000; myDFPlayer.play(19); }
          }
        }
      }
      while(huskylens.available(algoritmoActual)) { huskylens.popCachedResult(algoritmoActual); }
    } else {
      if (millis() - tiempoUltimoVisto > 2000) { ultimoID = -1; }
    }
  }
}