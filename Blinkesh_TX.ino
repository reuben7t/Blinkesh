// AirDrop (Temu Edition) - LIVE CHAT SENDER
const int lightPin = 4;       // Connect your LED/Bulb to GPIO 4
const int bitDelay = 200;     // 200ms per bit. 

void setup() {
  pinMode(lightPin, OUTPUT);
  Serial.begin(115200);
  delay(1000); 
  
  Serial.println("\n==========================================");
  Serial.println("   AIRDROP (TEMU EDITION) - ONLINE");
  Serial.println("==========================================");
  Serial.println("Type your message in the box above and hit Enter to flash-bang it...");
}

void loop() {
  // Check if you typed something in the Serial Monitor
  if (Serial.available() > 0) {
    // Read the text until you hit Enter
    String message = Serial.readStringUntil('\n');
    message.trim(); // Cleans up invisible newline characters that mess up the data

    if (message.length() > 0) {
      Serial.println("\n[TRANSMITTING]: " + message);

      // Loop through every single letter in your text
      for (int i = 0; i < message.length(); i++) {
        char currentChar = message[i];
        
        Serial.print("Sending '");
        Serial.print(currentChar);
        Serial.print("' -> ");

        // Loop through the 8 bits of the character (from left to right)
        for (int b = 7; b >= 0; b--) {
          int currentBit = (currentChar >> b) & 1; // Math magic to extract the exact bit
          
          if (currentBit == 1) {
            digitalWrite(lightPin, HIGH); 
            Serial.print("1");
          } else {
            digitalWrite(lightPin, LOW);  
            Serial.print("0");
          }
          
          delay(bitDelay); 
        }
        
        Serial.println(); 
        
        // Turn the light off and pause for a second between letters
        digitalWrite(lightPin, LOW); 
        delay(bitDelay * 3); 
      }
      
      Serial.println("[DONE] Awaiting next message...\n");
    }
  }
}
