#ifndef CONFIG_H
#define CONFIG_H

// Rango de pulsos PWM para los servos MG995 (a 50Hz)
#define SERVOMIN 100
#define SERVOMAX 640

// --- Mapeo de Canales PCA9685 (0 - 11) ---
const int B_FR = 0; const int F_FR = 1; const int T_FR = 2; // Pata Frontal Derecha
const int B_FL = 3; const int F_FL = 4; const int T_FL = 5; // Pata Frontal Izquierda
const int B_RR = 6; const int F_RR = 7; const int T_RR = 8; // Pata Trasera Derecha
const int B_RL = 9; const int F_RL = 10; const int T_RL = 11; // Pata Trasera Izquierda

// --- Ángulos base calibrados (Offsets de montaje) ---
const int fr_B = 140; const int fr_F = 90;  const int fr_T = 210;
const int fl_B = 135; const int fl_F = 180; const int fl_T = 50;
const int rr_B = 120; const int rr_F = 80;  const int rr_T = 225;
const int rl_B = 145; const int rl_F = 180; const int rl_T = 40;

#endif