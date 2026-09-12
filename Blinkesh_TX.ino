// SENDER CODE v2.0 (Now with Wake-Up Slap)
const int lightPin = 4;       
const int bitDelay = 200;     

void setup() {
  pinMode(lightPin, OUTPUT);
  Serial.begin(115200);
  delay(1000); 
  Serial.println("\n[SENDER ONLINE] Type message and press Enter...");
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    message.trim(); 

    if (message.length() > 0) {
      Serial.println("\n[TRANSMITTING]: " + message);

      for (int i = 0; i < message.length(); i++) {
        char currentChar = message[i];
        Serial.print("Sending '"); Serial.print(currentChar); Serial.print("' -> ");

        // 🚨 THE WAKE-UP SLAP (START BIT) 🚨
        digitalWrite(lightPin, HIGH);
        delay(bitDelay); 

        // Send the 8 data bits
        for (int b = 7; b >= 0; b--) {
          int currentBit = (currentChar >> b) & 1; 
          if (currentBit == 1) {
            digitalWrite(lightPin, HIGH); Serial.print("1");
          } else {
            digitalWrite(lightPin, LOW);  Serial.print("0");
          }
          delay(bitDelay); 
        }
        
        Serial.println(); 
        
        // Turn light off and pause before the next letter
        digitalWrite(lightPin, LOW); 
        delay(bitDelay * 3); 
      }
      Serial.println("[DONE]\n");
    }
  }
}
