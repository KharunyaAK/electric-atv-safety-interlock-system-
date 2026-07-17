# electric-atv-safety-interlock-system-
An STM32-based safety monitoring system for electric ATVs that integrates temperature sensing, RPM monitoring, motion sensing, and LCD-based status display for enhanced vehicle safety and real-time diagnostics.

# Electric ATV Safety Interlock System

An embedded safety system designed for an electric All-Terrain Vehicle (ATV) that prevents the vehicle from starting unless critical safety conditions are met. The project was initially implemented using an STM32 microcontroller and later redesigned using digital logic gates for hardware-based operation.

---

## Overview

This project improves rider safety by ensuring that the electric ATV can only start when predefined operating conditions are satisfied. The STM32 continuously monitors the brake, accelerator, and gear status before activating the relay that powers the vehicle.

---

## Features

- Prevents unsafe vehicle startup
- Monitors brake pedal status
- Detects accelerator pedal position
- Verifies neutral gear condition
- Controls vehicle startup using a 12V relay
- Embedded implementation using STM32
- Hardware implementation using NAND and NOR logic gates

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

- Embedded C/C++
- STM32
- PlatformIO
- Digital Electronics
- NAND & NOR Logic Gates

---

## System Workflow

1. Read the status of the brake switch.
2. Read the accelerator input.
3. Read the neutral gear switch.
4. Verify that all safety conditions are satisfied.
5. If all conditions are true:
   - Activate the relay.
   - Allow the vehicle to start.
6. Otherwise:
   - Keep the relay OFF.
   - Prevent vehicle startup.

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
