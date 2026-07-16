#include "locomotion.h"
#include "globals.h"
#include "servos.h"

void trotStepRecto() {
  int q = PERIODO / 4; int t[12];
  setTargets(t, -1); t[F_FR]=fr_F-STRIDE; t[T_FR]=fr_T-LIFT; t[F_RL]=rl_F+STRIDE; t[T_RL]=rl_T+LIFT;
  t[F_FL]=fl_F-STRIDE; t[F_RR]=rr_F+STRIDE; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FR]=fr_T; t[T_RL]=rl_T; moverGrupo(t, q);
  setTargets(t, -1); t[F_FL]=fl_F+STRIDE; t[T_FL]=fl_T+LIFT; t[F_RR]=rr_F-STRIDE; t[T_RR]=rr_T-LIFT;
  t[F_FR]=fr_F+STRIDE; t[F_RL]=rl_F-STRIDE; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FL]=fl_T; t[T_RR]=rr_T; moverGrupo(t, q);
}

void trotStepAtras() {
  int q = PERIODO / 4; int t[12];
  setTargets(t, -1); t[F_FR]=fr_F+STRIDE; t[T_FR]=fr_T-LIFT; t[F_RL]=rl_F-STRIDE; t[T_RL]=rl_T+LIFT;
  t[F_FL]=fl_F+STRIDE; t[F_RR]=rr_F-STRIDE; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FR]=fr_T; t[T_RL]=rl_T; moverGrupo(t, q);
  setTargets(t, -1); t[F_FL]=fl_F-STRIDE; t[T_FL]=fl_T+LIFT; t[F_RR]=rr_F+STRIDE; t[T_RR]=rr_T-LIFT;
  t[F_FR]=fr_F-STRIDE; t[F_RL]=rl_F+STRIDE; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FL]=fl_T; t[T_RR]=rr_T; moverGrupo(t, q);
}

void trotStepIzquierda() { 
  int q = PERIODO / 4; int t[12];
  setTargets(t, -1); t[T_FR]=fr_T-LIFT; t[T_RL]=rl_T+LIFT; t[F_FR]=fr_F; t[F_RL]=rl_F; t[F_FL]=fl_F; t[F_RR]=rr_F;
  t[B_FR]=fr_B + TURN; t[B_RL]=rl_B + TURN; t[B_FL]=fl_B - TURN; t[B_RR]=rr_B - TURN; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FR]=fr_T; t[T_RL]=rl_T; moverGrupo(t, q);
  setTargets(t, -1); t[T_FL]=fl_T+LIFT; t[T_RR]=rr_T-LIFT; t[F_FR]=fr_F; t[F_RL]=rl_F; t[F_FL]=fl_F; t[F_RR]=rr_F;
  t[B_FL]=fl_B + TURN; t[B_RR]=rr_B + TURN; t[B_FR]=fr_B - TURN; t[B_RL]=rl_B - TURN; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FL]=fl_T; t[T_RR]=rr_T; moverGrupo(t, q);
}

void trotStepDerecha() { 
  int q = PERIODO / 4; int t[12];
  setTargets(t, -1); t[T_FR]=fr_T-LIFT; t[T_RL]=rl_T+LIFT; t[F_FR]=fr_F; t[F_RL]=rl_F; t[F_FL]=fl_F; t[F_RR]=rr_F;
  t[B_FR]=fr_B - TURN; t[B_RL]=rl_B - TURN; t[B_FL]=fl_B + TURN; t[B_RR]=rr_B + TURN; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FR]=fr_T; t[T_RL]=rl_T; moverGrupo(t, q);
  setTargets(t, -1); t[T_FL]=fl_T+LIFT; t[T_RR]=rr_T-LIFT; t[F_FR]=fr_F; t[F_RL]=rl_F; t[F_FL]=fl_F; t[F_RR]=rr_F;
  t[B_FL]=fl_B - TURN; t[B_RR]=rr_B - TURN; t[B_FR]=fr_B + TURN; t[B_RL]=rl_B + TURN; moverGrupo(t, q*2);
  setTargets(t, -1); t[T_FL]=fl_T; t[T_RR]=rr_T; moverGrupo(t, q);
}