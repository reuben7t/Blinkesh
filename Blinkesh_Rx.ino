// RECEIVER CODE v2.2 (Inverted Logic for Pull-Down LDR Modules)
const int ldrPin = 34;         // AO pin from 4-pin LDR module connected to GPIO 34
const int threshold = 1500;    // Threshold set between ambient (2000+) and flash (0-500)
const int bitDelay = 200;      // Must match sender's bitDelay

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("\n[RECEIVER READY v2.2] Waiting for OptiGlitch transmission...");
}

void loop() {
  int val = analogRead(ldrPin);

  // 1. DETECT THE WAKE-UP SLAP (Start Bit: Light turns ON, so value DROPS below threshold)
  if (val < threshold) {
    String fullSentence = "";
    Serial.println("\n--- Incoming Transmission Started ---");

    while (true) {
      char currentByte = 0;

      // Wait out the remainder of the 200ms start bit so we align precisely
      delay(bitDelay);

      // 2. READ THE 8 DATA BITS (Bit 7 down to Bit 0)
      for (int b = 7; b >= 0; b--) {
        int bitVal = analogRead(ldrPin);
        
        // If value drops below threshold, the light is ON (it's a 1)
        if (bitVal < threshold) {
          currentByte |= (1 << b);  
        }
        delay(bitDelay);            // Wait for the next bit slot
      }

      // 3. DISPLAY LETTER BY LETTER IMMEDIATELY
      Serial.print(currentByte);
      fullSentence += currentByte;

      // 4. CLEAN SYNC FOR THE NEXT CHARACTER
      // Wait for the light to turn OFF (value goes back above threshold)
      unsigned long dropTimeout = millis();
      while (analogRead(ldrPin) < threshold && millis() - dropTimeout < 500) {
        delay(5);
      }

      // Now, listen for the NEXT character's wake-up slap (value drops below threshold)
      unsigned long startTimeout = millis();
      bool nextCharIncoming = false;

      while (millis() - startTimeout < 1500) { // 1.5 second window to look for next letter
        if (analogRead(ldrPin) < threshold) {
          nextCharIncoming = true;
          break; // Caught the exact start of the next wake-up slap!
        }
        delay(5);
      }

      // If no new wake-up slap appeared within the window, the message has ended
      if (!nextCharIncoming) {
        break;
      }
    }

    // 5. DISPLAY THE WHOLE SENTENCE AT THE END
    Serial.println("\n----------------------------------------");
    Serial.println("Full Sentence Received: " + fullSentence);
    Serial.println("----------------------------------------\n");
  }
}
