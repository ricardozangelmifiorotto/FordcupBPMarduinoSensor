#define USE_ARDUINO_INTERRUPTS true // Gera mais precisÃ£o a mediÃ§Ã£o dos BPM
#include <PulseSensorPlayground.h> 

// Variables
const int PulseWire = 0; 
const int LED13 = 13; 
int Threshold = 550;
int buzzer = 8;

PulseSensorPlayground pulseSensor; 
void setup() {

Serial.begin(9600); 
pinMode(13, OUTPUT);
    pinMode(buzzer,OUTPUT);   



pulseSensor.analogInput(PulseWire);
pulseSensor.setThreshold(Threshold);


if (pulseSensor.begin()) {
Serial.println("â™¥ *** INICIALIZADO *** â™¥"); //Mensagem que confirma o inicio do ciclo


}
}

void loop() {
int myBPM = pulseSensor.getBeatsPerMinute(); 
  

if (pulseSensor.sawStartOfBeat()) { 
Serial.println("â™¥ *** PULSO RECONHECIDO *** â™¥"); 
Serial.print("â™¡BPM: â™¡"); 
Serial.println(myBPM); 
 if (myBPM < 70 )
  {
    Serial.print("Precisa de um DescanÃ§o \n");
        tone(buzzer,261);    
    // Espera um tempo para Desativar
    delay(200);
    //Desativa o buzzer
    noTone(buzzer); 
  digitalWrite(13, HIGH);   
      delay(1000);
  digitalWrite(13, LOW);
    delay(1000); 
  }  
}
delay(20); 
}
