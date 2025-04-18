# Fish_Feeder_Mini_Project

> A smart fish feeder using STM32 (Arduino IDE), ultrasonic hand detection, and an LCD for safe, automatic food dispensing. Arduino board used as a 5V power source for components.

---

## 🐟 Smart Fish Feeder with Hand Detection (STM32 + Arduino IDE)

This project is a **smart fish feeder** built using an **STM32 Nucleo board** (e.g. Nucleo-F429ZI) programmed via the **Arduino IDE**. It uses an **ultrasonic sensor** to detect nearby objects, a **servo motor** to dispense food, and a **16x2 I2C LCD** to display system status. The feeder only operates when the area in front is clear, preventing accidental dispensing if a hand is detected.

An **Arduino board** was also used purely as a **5V power supply** to power the ultrasonic sensor and servo motor.

---

### 🔹 Features
- STM32-powered logic using Arduino IDE
- **Ultrasonic sensor** for hand detection
- **Servo motor** for controlled food dispensing
- **LCD display** with live status updates
- 10-second countdown before feeding
- Real-time safety checks to prevent accidental dispensing
- Uses **Arduino board for power supply**

---

### 🔧 Components
- STM32 Nucleo board (e.g. F429ZI)
- HC-SR04 ultrasonic sensor
- SG90 or compatible servo motor
- 16x2 I2C LCD display
- **Arduino Uno/Nano** (used only for 5V power output)
- Jumper wires, breadboard or custom PCB

---

### 🛠️ Possible Improvements
- Scheduled feeding using an RTC module
- Manual feed button or touch sensor
- Wi-Fi/Bluetooth app control
- Enclosure design for waterproofing or aesthetic finish

> Project desgin and final prototype:

![Image alt](https://github.com/HaniHatim/Fish_Feeder_Mini_Project/blob/26f633680405a54cc4c047b609cc4c2919cd196a/Fish_Feeder_Desgin.jpeg)

![Image alt](https://github.com/HaniHatim/Fish_Feeder_Mini_Project/blob/26f633680405a54cc4c047b609cc4c2919cd196a/Fish_Feeder.jpeg)
