// Define ESP32 pins for the LDR Analog Outputs
const int ldr3Pin = 32; // Analog output from the 3-pin LDR
const int ldr4Pin = 33; // Analog output from the 4-pin LDR

void setup() {
  // Initialize serial communication at 115200 baud rate (standard for ESP32)
  Serial.begin(115200);
  
  // Wait a moment for serial connection to establish
  delay(1000); 
  Serial.println("LDR Sensor Test Starting...");
}

void loop() {
  // Read the analog values from both pins
  // ESP32 ADC reads from 0 to 4095
  int ldr3Value = analogRead(ldr3Pin);
  int ldr4Value = analogRead(ldr4Pin);

  // Print the values to the Serial Monitor
  Serial.print("3-Pin LDR: ");
  Serial.print(ldr3Value);
  Serial.print("  |  4-Pin LDR: ");
  Serial.println(ldr4Value);

  // Wait half a second before taking the next reading
  delay(500);
}
