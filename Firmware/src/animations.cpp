#include "animations.h"
#include "globals.h"
#include "servos.h"

void sentarseYDarMano() {
  int t[12]; int vel = 600; 
  setTargets(t, -1); t[F_RR] = rr_F - 40; t[T_RR] = rr_T + 50; t[F_RL] = rl_F + 40; t[T_RL] = rl_T - 50;  
  moverGrupo(t, vel); if (SerialBT.available()) return; delay(200); 

  setTargets(t, -1); t[F_FR] = fr_F + 50; t[T_FR] = fr_T + 20;  
  moverGrupo(t, vel); if (SerialBT.available()) return;

  for (int i = 0; i < 2; i++) { 
    setTargets(t, -1); t[F_FR] = fr_F + 70; moverGrupo(t, 250); if (SerialBT.available()) return;
    setTargets(t, -1); t[F_FR] = fr_F + 30; moverGrupo(t, 250); if (SerialBT.available()) return;
  }
  delay(500); 

  setTargets(t, -1); t[B_FR] = fr_B; t[F_FR] = fr_F; t[T_FR] = fr_T;
  moverGrupo(t, 400); if (SerialBT.available()) return;
  
  setTargets(t, -1); t[B_RR] = rr_B; t[F_RR] = rr_F; t[T_RR] = rr_T + 40; 
  moverGrupo(t, 250); if (SerialBT.available()) return;

  setTargets(t, -1); t[T_RR] = rr_T; moverGrupo(t, 200); if (SerialBT.available()) return;

  setTargets(t, -1); t[B_RL] = rl_B; t[F_RL] = rl_F; t[T_RL] = rl_T;
  moverGrupo(t, 400); if (SerialBT.available()) return;

  setTargets(t, -1); t[B_FL] = fl_B; t[F_FL] = fl_F; t[T_FL] = fl_T;
  moverGrupo(t, 200); if (SerialBT.available()) return;
  delay(200); estado = 0;
}