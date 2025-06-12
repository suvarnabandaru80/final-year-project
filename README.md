# 🤖 Strandbeest: Coal Mine Robot for Detection of Hazardous Gas and Objects

A Theo-Jansen linkage-based walking robot designed to traverse uneven coal mine terrain and detect dangerous gases and obstacles, improving worker safety. 🏭💨🛑

---

## 🚀 Overview

Coal mines often contain hazardous gases like Methane (CH₄), Carbon Monoxide (CO), and Carbon Dioxide (CO₂). Traditional robots fail to adapt to rough terrains. Our solution? A **Strandbeest-inspired robot** 🦿 with gas detection and obstacle avoidance capabilities.

The robot:
- Moves using a **Theo-Jansen mechanical leg system**.
- Detects gases using the **MQ135 sensor**.
- Scans for obstacles with **ultrasonic + servo sweep**.
- Is controlled via **Bluetooth** using simple command characters.

---

## 🔧 Hardware & Software Requirements

### Hardware:
- 🔌 **Arduino Uno (ATmega328P)**
- 🦿 Theo-Jansen Leg Mechanism (acrylic, nuts & bolts)
- ⚙️ DC Gear Motors
- 🧠 L298N Motor Driver
- 🌫 MQ135 Gas Sensor
- 📡 HC-SR04 Ultrasonic Sensor
- 🔄 SG90 Servo Motor
- 🔋 Power Supply (9V–12V)
- 📶 HC-05 Bluetooth Module
- 🧰 Acrylic sheets, jumper wires, bolts, breadboard, etc.

### Software:
- 💻 Arduino IDE
- 📲 Bluetooth Terminal App (for Android or PC)
- 🛠 Optional: CAD software for chassis design

---

## 🧠 Features

- 🦿 **Strandbeest Leg Movement**: Walks like an animal over rough terrain using Theo-Jansen linkage.
- 🌫 **Gas Detection**: MQ135 continuously monitors air quality and logs data.
- 👀 **Obstacle Scanning**: 180° sweep with ultrasonic sensor to detect nearby objects.
- 🎮 **Bluetooth Control**: Commands via mobile phone (F = Forward, B = Backward, etc.)
- 💡 **Modular Design**: Easily add more sensors or enhance features.

---

## 📦 Installation & Setup

1. 🛠 **Assemble Robot Frame**
   - Use acrylic sheets and Theo-Jansen linkage for legs.
   - Mount motors, sensors, and servos securely.

2. 🔌 **Wiring**
   - Connect motors to L298N driver and Arduino (IN1–IN4).
   - MQ135 to A0, Ultrasonic to D10 (Trig), D11 (Echo).
   - Servo to D5, Bluetooth to RX/TX.

3. 💻 **Upload Code**
   - Open Arduino IDE, paste the gas detection or prototype code.
   - Select Arduino Uno board & COM port.
   - Upload.

4. 📲 **Bluetooth Pairing**
   - Pair phone with HC-05 (default password: 1234).
   - Use any Bluetooth terminal app to send commands.

---

## 🎮 How to Use

| Command | Action       |
|---------|--------------|
| F       | Move Forward |
| B       | Move Backward|
| L       | Turn Left    |
| R       | Turn Right   |
| S       | Stop         |
| U       | Obstacle Scan (servo) |

- View gas readings and obstacle distance via Serial Monitor (9600 baud).
- Modify thresholds in code if needed.

---

## 📸 Visuals

> Add these once captured from your prototype:

- 🖼 **Top View** of assembled robot
- 🖼 **Side View** showing Theo-Jansen linkage
- 🖼 **Gas sensor & Servo-mounted ultrasonic setup**

---

## 📑 Credits & References

- Designed & built by:  
  👤 S. Prabhas Akhil Reddy, B. Suvarna, G. Uday Rahul, D.V. Sai Ramesh  
- Guided by:  
  👩‍🏫 Prof. V. Rajya Lakshmi, ANITS  
- Inspired by: Theo Jansen’s walking kinetic sculptures  
- Sensors: MQ135 datasheet, HC-SR04 standard documentation  
- Arduino Community & GitHub open-source contributors ❤️

---

## 🔒 Safety & Limitations

- ⚠️ MQ135 is not a calibrated industrial gas detector.
- 🔥 Keep power away from flammable gases.
- 📶 Bluetooth range ~10 meters.
- ⚙️ Robot may struggle on steep slopes or wet ground.

---

## 🤝 Contribute

We welcome suggestions & improvements!  
Fork the repo, submit a pull request, or raise issues 💬.

---

## 📝 License

Licensed under the [MIT License](LICENSE). Feel free to remix, modify, and improve! 🚀
