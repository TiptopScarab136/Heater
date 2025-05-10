# Heater Simulation
This project was built as an assignment for Upliance.ai internship.
It is a simple heater actuating system with feeback. The actuating mechanism is substituted by a pink LED that turns on when the heating assembly is supposed to be on. The simulation was done on Wokwi and the files are provided in this repo.


## Files Included
- `heater.ino`: Arduino sketch controlling the logic.
- `diagram.json`: Wokwi simulation circuit configuration.
- `libraries.txt`: List of required libraries for compiling the sketch.

## How It Works
1. **Idle State**: On startup, the idle LED lights up.
2. **Temperature Setting**: 
   - Set desired temperature (0–100) using a potentiometer.
   - Value is shown on the LCD display.
3. **Heating**:
   - A DS18B20 sensor monitors current temperature.
   - If current temp < setpoint *and* the switch is ON:
     - Heating LED (pink) activates to simulate the heater.
     - Heating status LED (Red) also activates.
4. **Stabilizing Phase**:
   - When the desired temperature is first reached:
     - Stabilizing LED turns on for 3 seconds.
     - System continues adjusting as needed.
5. **Target Reached**:
   - LED indicates stable target temp.
6. **Overheating Protection**:
   - If the system keeps heating despite reaching the target (actuator fault), 
     - Overheating LED turns on.
     - Buzzer alerts user.
    
## Optional: BLE Integration
A Bluetooth module (HM-10) can be added for serial data transmission. Not supported in Wokwi, but to integrate:
- Connect HM-10 TX to Arduino RX (pin 0)
- Connect HM-10 RX to Arduino TX (pin 1)

## Simulation
Use [Wokwi](https://wokwi.com/) to simulate the setup:
1. Upload `heater.ino` and `diagram.json`.
2. Add necessary libraries listed in `libraries.txt`.
