# Work In Progress (WIP) - External Feeder-Assisted Filament Change for Bambu Lab A1 (EFAC-A1)

> **Note**: This project is currently a **Work In Progress**. Some features are not yet implemented or require further testing. Please proceed with caution and ensure you understand the setup before implementation.

EFAC-A1 provides AMS-like behavior using an external feeder, without using the AMS port, AMS firmware, or internal printer hardware. This system is fully software-safe, supports multi-filament setups, and works seamlessly with Bambu Studio.  

## Gcodes
### Semi-Automatic Change Filament Gcode
For users who want the full EFAC-A1 (external hardware required):
[**Change Filament Gcode for EFAC-A1**](https://github.com/Hans930v/bambu-a1-g-code/blob/EFAC-A1-EXPERIMENTAL/change-filament/EFAC-A1.gcode)

### Manual Change Filament Gcode
For users who prefer manual filament change (no hardware):
[**Change Filament Gcode for EFAC-A1 - Manual**](https://github.com/Hans930v/bambu-a1-g-code/blob/EFAC-A1-EXPERIMENTAL/change-filament/EFAmC-A1.gcode)

> **Disclaimer**: These are **NOT** an official Bambu Lab Gcodes. They are a third-party solution for users who want a budget-friendly alternative to the AMS.

## Hardware
For a single system (4 Colors):
> These are Shopee links
1. 2pcs [Arduino nanos](https://shopee.ph/Nano-With-the-bootloader-compatible-Nano-3.0-controller-for-arduino-CH340-USB-driver-16Mhz-Nano-v3.0-ATMEGA328P-i.580325202.15423025127?extraParams=%7B%22display_model_id%22%3A114585175768%2C%22model_selection_logic%22%3A3%7D&sp_atk=36eab4fa-2527-4574-8daa-3c7e51b4ef66&xptdk=36eab4fa-2527-4574-8daa-3c7e51b4ef66)
<img width="444.4444444444" height="250" alt="image" src="https://github.com/user-attachments/assets/dd1ac275-4fca-4d79-b1e9-ea6a61e0cb97" />

---

2.  1pc [MCP23017 IO expansion board](https://shopee.ph/MCP23017-Serial-Interface-Module-IIC-I2C-SPI-Bidirectional-16-Bit-I-O-Expander-Pins-10Mhz-Serial-Interface-Module-i.580325202.27183227733?xptdk=74381da7-727c-4895-b49d-59258a37f182)
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/7a4aa11f-97c5-4041-973e-b8fb26e02787" />  

---

3. 2pcs [TB6612FNG motor drivers](https://shopee.ph/TB6612-Dual-Motor-Driver-1A-TB6612FNG-for-Arduino-Microcontroller-Better-than-L298N-i.580325202.18881766362?extraParams=%7B%22display_model_id%22%3A99396069681%2C%22model_selection_logic%22%3A3%7D&sp_atk=7dc76370-ea4b-476f-81e1-8f0ead94dba9&xptdk=7dc76370-ea4b-476f-81e1-8f0ead94dba9)
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/bdca9196-939e-471d-acd3-0f901ff4b480" />

---

4. 1pc [VL53L0X Time of Flight distance sensor](https://shopee.ph/VL53L0X-Time-of-Flight-(ToF)-Laser-Ranging-Sensor-Breakout-940nm-GY-530-GY-VL53L0XV2-Laser-Distance-Module-I2C-IIC-i.580325202.27108183854?extraParams=%7B%22display_model_id%22%3A246401161922%2C%22model_selection_logic%22%3A3%7D&sp_atk=188f71b5-4bed-4689-a428-8a2aee721844&xptdk=188f71b5-4bed-4689-a428-8a2aee721844)
<img width="261" height="193" alt="image" src="https://github.com/user-attachments/assets/cc841dfd-be87-420e-a4cf-bd3b84b0d4b4" />

---

5. 1pc [KY-003 Hall Magnetic Sensor Module](https://shopee.ph/KY-003-Hall-Magnetic-Sensor-Module-i.18252381.43202189164?extraParams=%7B%22display_model_id%22%3A270180022458%2C%22model_selection_logic%22%3A3%7D&sp_atk=d9ddf631-9e96-4209-9013-42243e51732f&xptdk=d9ddf631-9e96-4209-9013-42243e51732f)
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/f40281a7-c027-41f1-b7db-7921bcc7d7f7" />

---

6. 2pcs [MP1584EN step-down DC-DC buck converters](https://shopee.ph/MP1584EN-3A-Ultra-Small-Size-DC-DC-Step-Down-Supply-Module-Adjustable-power-step-down-descending-output-module-24V-12V-9V-5V-3V-i.580325202.14979146349?extraParams=%7B%22display_model_id%22%3A230170875619%2C%22model_selection_logic%22%3A3%7D&sp_atk=637238df-685a-4598-90fa-a7aba2099f75&xptdk=637238df-685a-4598-90fa-a7aba2099f75)
<img width="333.3333333333" height="250" alt="image" src="https://github.com/user-attachments/assets/897c7704-ac4f-41dd-88db-674f24ed4f2c" />

---

7. 5pcs [5mm slotted Photo Interrupters](https://shopee.ph/IR-Infrared-Slotted-Optical-Speed-Measuring-Sensor-Detection-Optocoupler-Module-For-Motor-Test-i.280657313.6543882781?xptdk=e45657b6-eab7-4e94-b209-f3b8557e7fda)
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/7058f09d-7daf-4041-a0b5-a100e422507c" />

---

8. 4pcs [25mm-3.5W-12V DC geared DC motors](https://shopee.ph/25mm-3.5W-DC-12V-25GA-370-Low-Speed-Metal-Gear-Motor-HG-i.1608647809.25996423159?xptdk=8b73b442-80d2-4de8-84ee-462355968faa)
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/e480f827-aa7e-467c-8811-ff7471a3a018" />

---

9. 4 sets of [Prusa MK3 extruder gears (or similar)](https://shopee.ph/BMG-Needle-Roller-Bearing-Gear-Set-3D-Printer-Accessories-Extruder-Material-Delivery-Silk-Stainless-Steel-Wheel-Holder-i.418282980.29485655417?xptdk=cd9329e0-f975-4a48-a71d-a3ccdf8d3131)
<img width="250" height="250" alt="image" src="https://github.com/user-attachments/assets/d5b1afb5-3879-4f47-93a2-4be14d516e63" />


## Features
- **Software-Safe**: No firmware modifications required.
- **External Feeder**: Works with an external filament feeder to replicate AMS behavior.
- **Multi-Filament Support**: Easily handle multiple filaments for diverse printing needs.
- **Compatible with Bambu Studio**: Fully compatible with Bambu Studio for filament changes.

## How It Works
EFAC-A1 uses external hardware (such as a stepper motor-controlled feeder) to change filaments automatically, mimicking the AMS behavior on Bambu Labs printers. It integrates seamlessly with the slicer’s Gcode and works without requiring any changes to the printer’s firmware.

### Step-by-Step Process:
1. **Gcode Workflow**: Use the provided Gcode files for semi-automatic or manual filament change.
2. **External Feeder Setup**: Connect your external filament feeder to the printer and ensure the Gcode works with your current setup.
3. **Filament Change**: The Gcode will control filament unloading, flushing, and loading, mimicking AMS behavior.
4. **Flush Volumes**: Supports automatic purging/flush volumes for clean filament transitions.

### Disclaimer
This project is intended as a budget-friendly alternative to AMS for Bambu Lab A1 users without breaking printer firmware and is **NOT** affiliated with Bambu Lab. Use at your own risk, and always ensure proper setup and testing before full implementation. Enjoy!
