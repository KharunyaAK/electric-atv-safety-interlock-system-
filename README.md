# electric-atv-safety-interlock-system-
An STM32-based safety monitoring system for electric ATVs that integrates temperature sensing, RPM monitoring, motion sensing, and LCD-based status display for enhanced vehicle safety and real-time diagnostics.

# Electric ATV Safety Interlock System

An embedded safety system designed for an electric All-Terrain Vehicle (ATV) that prevents the vehicle from starting unless critical safety conditions are met. The project was initially implemented using an STM32 microcontroller and later redesigned using digital logic gates for hardware-based operation.

---

## Overview

This project improves rider safety by ensuring that the electric ATV can only start when predefined operating conditions are satisfied. The STM32 continuously monitors the brake, accelerator, and gear status before activating the relay that powers the vehicle.

---

## Features

- Safety interlock for electric ATV startup
- Brake, accelerator, and neutral gear validation
- Push-button based vehicle start sequence
- LCD-based user feedback for failed safety checks
- Relay-controlled vehicle startup
- TSAL indicator control
- Interrupt-driven start button detection
- STM32 embedded implementation
- Hardware implementation using NAND/NOR logic gates

---

## Safety Conditions

The vehicle is allowed to start only when:

- Brake pedal is pressed
- Accelerator pedal is not pressed
- Gear is in Neutral

If any one of these conditions is not satisfied, the relay remains OFF and the vehicle cannot start.

---

## Hardware Components

- STM32 Microcontroller
- Brake Switch
- Accelerator Switch
- Neutral Gear Switch
- 12V Relay Module
- Power Supply
- PCB (Logic Gate Implementation)

---

## Technologies Used

- Embedded C++
- STM32
- PlatformIO
- Arduino Framework for STM32
- Digital Electronics
- Interrupt Programming
- GPIO Programming
- I2C LCD Interface

---

## System Workflow

1. Driver presses the start button.
2. STM32 reads the brake switch.
3. STM32 checks whether the accelerator is released.
4. STM32 verifies that the gear is in Neutral.
5. If all conditions are satisfied:
   - Relay is activated.
   - LCD displays "Vehicle Started!"
   - Vehicle startup is enabled.
6. If any condition fails:
   - Vehicle startup is blocked.
   - LCD displays the corresponding warning message.

---

## Future Enhancements

- Driver authentication using RFID
- Mobile app for vehicle diagnostics
- GPS tracking
- Battery health monitoring
- CAN Bus integration
- Fault logging and diagnostics

---

## Author

**Kharunya A**

Developed as part of an academic embedded systems project.

---

## License

This repository is intended for educational and academic purposes.
