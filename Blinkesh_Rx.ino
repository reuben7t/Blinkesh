// RECEIVER CODE (The Decoder)
const int ldrPin = 34;        // LDR AO pin connected to D34
const int bitDelay = 200;     // MUST strictly match the sender

// 🚨 CALIBRATION NEEDED: ESP32 analog reads from 0 (pitch black) to 4095 (blinding bright). 
// 2000 is usually a safe middle ground, but you might need to change this!
const int threshold = 2000;   

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  delay(1000);
  Serial.println("\n==========================================");
  Serial.println("  RECEIVER ONLINE - WAITING FOR FLASHES");
  Serial.println("==========================================");
}

void loop() {
  int lightLevel = analogRead(ldrPin);
  
  // Step 1: Did the light just turn on? (The Wake-Up Slap)
  if (lightLevel > threshold) {
    
    char receivedChar = 0; // Empty container for our 8 bits
    
    // Step 2: Skip the Start Bit, plus wait half a cycle more 
    // so we sample precisely in the middle of the first actual data bit.
    delay(bitDelay + (bitDelay / 2)); 

    // Step 3: Run the stopwatch and read 8 times
    for (int b = 7; b >= 0; b--) {
      lightLevel = analogRead(ldrPin); // Check light level
      
      if (lightLevel > threshold) {
        receivedChar |= (1 << b); // Force that specific bit to be a 1
      }
      
      // Wait exactly 1 cycle for the next bit
      delay(bitDelay);
    }
    
    // Step 4: We got all 8 bits! Print it instantly.
    Serial.print(receivedChar);
    
    // Wait for the sender's pause gap to finish so we don't accidentally double-read
    delay(bitDelay * 2); 
  }
}
