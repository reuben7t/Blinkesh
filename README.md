<img width="1280" height="640" alt="git (1)" src="https://github.com/user-attachments/assets/8920b256-2ba8-4988-b824-5351134eb4bd" />



# Blinkesh 🎯


## Basic Details
### Team Name: Radiants


### Team Members
- Member 1: Joe George James - Saintgits College of Engineering
- Member 2: Reuben Mathew Thomas - Saintgits College of Engineering


### Project Description
A device that converts the input file or text or anything to their binary and uses an led to transmit it. A receiver on the other with an LDR detects the sequence of 1 and 0 and reconstructs it into the corresponding message at Receiver's end.

### The Problem (that doesn't exist)
Nowadays, sending a message is insanely fast and we have different mediums for it too. But, what if we try a new method? using visible light as a medium? and no we are not talking about optical fibre or any of that usual boring things.   

### The Solution (that nobody asked for)
We are talking a torch LED that blinks according to the 1s and 0s and a receiver that detects it converts it back to the original message. In short, an unusual, slow and visibly funny way to communicate. Also, wouldn't it be good to make sure your message is being transmitted by actually seeing it and not some screen telling you it did.

## Technical Details
### Technologies/Components Used
For Software:
- [Languages used] - C++
- [Libraries used] - ESP32 Dev Kit by Espressif

For Hardware:
- ESP32
- Flashlight
- LDR Sensor
- Resistor

### Implementation
For Software:
- Arduino IDE
- Visual Studio with PlatformIO

[commands]

-Flash Blinkesh_TX.ino to the transmitting ESP32 and Blinkesh_Rx.ino to the receiving ESP32.

-Open two separate Serial Monitors (Baud rate 115200, Line Ending set to Newline).

-Type a message into the Sender's Serial Monitor and hit Enter.

-Watch the flashlight strobe and the text slowly reconstruct on the Receiver's monitor.


# Run

### Project Documentation

# Screenshots 
<img width="1917" height="1078" alt="image" src="https://github.com/user-attachments/assets/40bc27ae-78cc-49ea-95d2-7a83a5228c95" />
Transmitter (Tx) side serial monitor.

<img width="1002" height="575" alt="Rx Side Serial Monitor" src="https://github.com/user-attachments/assets/2c40e735-e6c3-495d-a2b8-8038eb37654c" />
Receiver (Rx) side serial monitor

# Diagrams
<img width="1650" height="655" alt="image" src="https://github.com/user-attachments/assets/86b53e1a-b46b-43e7-a1c9-b49e08186b88" />
Figure: System architecture for text communication using light, where data is transmitted from Laptop 1 to Laptop 2 through an ESP32-controlled flashlight and LDR-based optical link.

For Hardware:

# Schematic & Circuit
![Circuit](Add your circuit diagram here)
*Add caption explaining connections*

![Schematic](Add your schematic diagram here)
*Add caption explaining the schematic*

# Build Photos
![Components]
<img width="960" height="1280" alt="Esp32 with LDR sensor" src="https://github.com/user-attachments/assets/d49337c9-ad29-466a-b7db-e504e05935b3" />
ESP 32 with LDR Sensor (Receiver side)

![Build]<img width="960" height="1280" alt="Esp32 with LED" src="https://github.com/user-attachments/assets/6deab62b-618a-428e-8634-7deca564ebbe" />
ESP 32 with LED light (Transmitter side) 

![Final]
<img width="1280" height="960" alt="WhatsApp Image 2026-09-13 at 9 39 11 AM (1)" src="https://github.com/user-attachments/assets/bb959eda-7967-4dce-8797-5cd35e182288" />

The Transmitter side on the left converts the input to binary and blinks the LED in respect to the binary sequence. The Receiver side on the left converts the sequence back to the original message and displays it.

### Project Demo
# Video


https://github.com/user-attachments/assets/216a6dd6-2df5-421e-af4f-54ca1ba06b06




## Team Contributions
- Joe George James: Hardware & Software + Emotional, Moral, Mental Support
- Reuben Mathew Thomas: Hardware & Software + Emotional, Moral, Mental Support

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--26-26?link=https%3A%2F%2Ftinkerhub.org%2Fevents%2F1M8ORET9A1%2Fuseless-projects-3.0)



