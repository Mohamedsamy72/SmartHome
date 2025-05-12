# Smart Home Automation Using ATmega32

## 📌 Project Overview

This project is a mini smart home automation system built using the **ATmega32** microcontroller and **FreeRTOS**, aiming to control home devices based on environmental conditions. It features lighting control, fan speed automation, and fire detection, all displayed on an LCD.

## 🎯 Objective

To design and implement a smart system that:
- Controls lighting using an LDR sensor.
- Adjusts fan speed with an LM35 temperature sensor using PWM.
- Detects fire using a flame sensor.
- Provides real-time feedback on a 16x2 LCD.

## 🛠️ Features

### ✅ Lighting Control
- **3 LEDs** (Red, Green, Blue) indicate light intensity from the LDR:
  - < 15%: All ON
  - 16–50%: Red + Green
  - 51–70%: Red only
  - > 70%: All OFF

### ✅ Fan Speed Control (PWM)
- Based on LM35 readings:
  - ≥ 40°C → 100% speed
  - 35–39°C → 75% speed
  - 30–34°C → 50% speed
  - 25–29°C → 25% speed
  - < 25°C → OFF

### ✅ Fire Detection
- Displays **"Critical alert!"** on the LCD
- Activates **buzzer**
- Stays in alert mode while flame is detected

### ✅ LCD Display
- Row 1: Fan status ("FAN is ON"/"FAN is OFF")
- Row 2: Temperature and LDR percentage

## 🔌 Hardware Components

| Component           | Details                         |
|--------------------|----------------------------------|
| Microcontroller     | ATmega32                         |
| LCD                 | 16x2 in 8-bit mode               |
| Temperature Sensor  | LM35 (ADC1, PA1)                 |
| Light Sensor (LDR)  | LDR (ADC0, PA0)                  |
| Flame Sensor        | Digital input (PD2)             |
| Motor Control       | H-Bridge + PWM (PB0, PB1, PB3)   |
| Buzzer              | PD3                              |
| LEDs                | Red (PB5), Green (PB6), Blue (PB7) |

## 🧩 Software Architecture

- Layered model architecture
- Custom drivers for:
  - **ADC**, **GPIO**
  - **PWM**, **LCD**
  - **LM35**, **LDR**
  - **LED**, **DC Motor**, **Flame Sensor**, **Buzzer**

## 🔧 Drivers Overview

| Driver        | Key Functions |
|---------------|---------------|
| **ADC**       | `ADC_init()`, `ADC_readChannel()` |
| **PWM**       | `PWM_Timer0_Start(duty_cycle)` |
| **LCD**       | 8-bit communication |
| **LDR**       | `LDR_getLightIntensity()` |
| **DC Motor**  | `DcMotor_Init()`, `DcMotor_Rotate()` |
| **Flame Sensor** | `FlameSensor_init()`, `FlameSensor_getValue()` |
| **LEDs**      | `LEDS_init()`, `LED_on(id)`, `LED_off(id)` |
| **Buzzer**    | `Buzzer_init()`, `Buzzer_on()`, `Buzzer_off()` |

## 🖥️ System Requirements

- **MCU**: ATmega32
- **Clock**: 16 MHz
- **Language**: C
- **Framework**: FreeRTOS

