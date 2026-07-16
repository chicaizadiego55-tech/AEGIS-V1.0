#include "servos.h"
#include "globals.h"

void initServos() {
  pwm.begin();
  pwm.setPWMFreq(50);
}

void setServo(uint8_t canal, float angulo) {
  if (angulo < 0) angulo = 0;
  if (angulo > maxAngulos[canal]) angulo = maxAngulos[canal];
  currentAngles[canal] = angulo; 
  uint16_t pulso = SERVOMIN + (angulo / maxAngulos[canal]) * (SERVOMAX - SERVOMIN);
  pwm.setPWM(canal, 0, pulso);
}

void standUp() {
  setServo(B_FR, fr_B); setServo(F_FR, fr_F); setServo(T_FR, fr_T);
  setServo(B_FL, fl_B); setServo(F_FL, fl_F); setServo(T_FL, fl_T);
  setServo(B_RR, rr_B); setServo(F_RR, rr_F); setServo(T_RR, rr_T);
  setServo(B_RL, rl_B); setServo(F_RL, rl_F); setServo(T_RL, rl_T);
}

void moverGrupo(int targets[], int duracion) {
  unsigned long startTime = millis();
  float startAngles[12];
  for(int i=0; i<12; i++) startAngles[i] = currentAngles[i];

  while (millis() - startTime < (unsigned long)duracion) {
    float progreso = (float)(millis() - startTime) / duracion;
    float suave = (1.0 - cos(progreso * PI)) / 2.0; // Interpolación senoidal suave

    for (int i = 0; i < 12; i++) {
      if (targets[i] != -1) {
        float angIntermedio = startAngles[i] + (targets[i] - startAngles[i]) * suave;
        uint16_t pulso = SERVOMIN + (angIntermedio / maxAngulos[i]) * (SERVOMAX - SERVOMIN);
        pwm.setPWM(i, 0, pulso);
        currentAngles[i] = angIntermedio;
      }
    }
    if (SerialBT.available()) return; // Interrupción rápida por entrada de Bluetooth
  }
}

void setTargets(int t[], int val) { 
  for(int i = 0; i < 12; i++) t[i] = val; 
}