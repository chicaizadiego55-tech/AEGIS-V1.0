#include "audio.h"
#include "globals.h"

void initAudio() {
  Serial.println("🔊 Iniciando MP3 en UART2...");
  mySerial2.begin(9600, SERIAL_8N1, 16, 17); 
  if (myDFPlayer.begin(mySerial2)) {  
    myDFPlayer.volume(29); 
    Serial.println("✅ DFPlayer Mini listo.");
  } else {
    Serial.println("⚠️ ALERTA: DFPlayer Mini no responde.");
  }
}