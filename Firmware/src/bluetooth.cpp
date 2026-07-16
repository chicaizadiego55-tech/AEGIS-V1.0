#include "bluetooth.h"
#include "globals.h"
#include "servos.h"

void initBluetooth() {
  SerialBT.begin("AEGIS_EduBot_BT"); 
}

void procesarBT(char c) {
  c = toupper(c); // Tolera mayúsculas o minúsculas de la aplicación móvil
  
  if (c == 'F') { estado = 1; }
  else if (c == 'X') { estado = 2; }
  else if (c == 'L') { estado = 3; }
  else if (c == 'R') { estado = 4; }
  else if (c == 'S') { estado = 0; standUp(); }
  
  else if (c == 'A') { modoActual = 'A'; huskylens.switchAlgorithm(ALGORITHM_FACE_RECOGNITION); ultimoID = -1; } 
  else if (c == 'B') { modoActual = 'B'; huskylens.switchAlgorithm(ALGORITHM_COLOR_RECOGNITION); ultimoID = -1; }
  else if (c == 'D') { modoActual = 'D'; huskylens.switchAlgorithm(ALGORITHM_SELF_LEARNING_CLASSIFICATION); ultimoID = -1; }
  else if (c == 'H') { modoActual = 'H'; huskylens.switchAlgorithm(ALGORITHM_HAND_RECOGNITION); ultimoID = -1; accionEjecutada = false; }
  else if (c == 'C') { myDFPlayer.play(26); tiempoUltimoAudio = millis(); duracionBloqueo = 18000; }
}