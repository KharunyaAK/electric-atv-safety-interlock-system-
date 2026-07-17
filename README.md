# electric-atv-safety-interlock-system-
An STM32-based safety monitoring system for electric ATVs that integrates temperature sensing, RPM monitoring, motion sensing, and LCD-based status display for enhanced vehicle safety and real-time diagnostics.

# Electric ATV Safety Interlock System

An STM32-based embedded system developed to improve the safety and monitoring of an electric All-Terrain Vehicle (ATV). The system continuously monitors key vehicle parameters such as temperature, RPM, and motion while providing real-time status updates through an LCD display.

---

## Overview

This project focuses on developing an embedded safety monitoring solution for electric ATVs using an STM32 microcontroller. Multiple sensors are integrated to monitor vehicle health and operating conditions, helping improve reliability and safety.

---

## Features

- Real-time vehicle parameter monitoring
- Temperature sensing for thermal protection
- RPM measurement for motor performance
- Motion sensing using MPU6050
- LCD display for live system status
- Modular firmware developed using PlatformIO

---

## Technologies Used

- STM32 Microcontroller
- C++
- PlatformIO
- Embedded Systems
- I2C Communication

---

## Hardware Components

- STM32 Development Board
- MPU6050 Accelerometer & Gyroscope
- LCD Display (I2C)
- Temperature Sensor
- RPM Sensor

## Workflow

1. Read sensor values from the connected modules.
2. Measure vehicle RPM and operating temperature.
3. Acquire motion data using the MPU6050 sensor.
4. Process the collected data using the STM32 controller.
5. Display system information on the LCD.
6. Continuously monitor vehicle conditions for safe operation.

---

## Future Enhancements

- Wireless telemetry using Wi-Fi or Bluetooth
- Cloud-based vehicle diagnostics
- Mobile application for remote monitoring
- GPS tracking integration
- Battery health monitoring

---

## Author

**Kharunya A**

Developed as part of an academic embedded systems project.

---

## License

This repository is intended for educational and academic purposes.
