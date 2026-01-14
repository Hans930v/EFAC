# External Feeder-Assisted Filament Change for Bambu Lab A1 (EFAC-A1)

EFAC-A1 provides an AMS-like filament change workflow using an external feeder, without using the AMS port or modifying firmware. This system is fully software-safe, supports multi-filament setups, and works seamlessly with Bambu Studio.

## Semi-Automatic Change Filament Gcode
[**Change Filament Gcode for EFAC-A1**](https://github.com/Hans930v/bambu-a1-g-code/blob/EFAC-A1-EXPERIMENTAL/change-filament/EFAC-A1.gcode)

## Manual Change Filament Gcode
For users who prefer manual filament change:
[**Change Filament Gcode for EFAC-A1 - Manual**](https://github.com/Hans930v/bambu-a1-g-code/blob/EFAC-A1-EXPERIMENTAL/change-filament/EFAmC-A1.gcode)

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
3. **Filament Change**: The Gcode will control filament unloading, loading, and switching, mimicking AMS behavior.
4. **Flush Volumes**: Supports automatic purging/flush volumes for clean filament transitions.
