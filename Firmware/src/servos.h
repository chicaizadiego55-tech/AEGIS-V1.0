#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>

void initServos();
void setServo(uint8_t canal, float angulo);
void standUp();
void moverGrupo(int targets[], int duracion);
void setTargets(int t[], int val);

#endif