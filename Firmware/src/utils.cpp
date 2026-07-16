#include "utils.h"
#include "globals.h"

void imprimirSenales() {
  Serial.print("Modo: "); Serial.print(modoActual);
  Serial.print(" | Estado: "); Serial.println(estado);
}