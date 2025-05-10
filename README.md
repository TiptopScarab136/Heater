# Heater
This project was built as an assignment for Upliance.ai internship.
It is a simple heater actuating system with feeback. The actuating mechanism is substituted by a pink LED that turns on when the heating assembly is supposed to be on. The simulation was done on Wokwi and the files are provided in this repo.
It consists of an arduino sketch, a diagram.json file which describes the circuit for Wokwi and a libraries.txt file which contains all the libraries used by this project.
All these files can be directly uploaded into a Wokwi blank project and it will run the simulation.

**Working:**
1. When the system starts, the idle LED lights up. 
2. The system uses a potentiometer dial to set the temperature, it is decided to be from 0 to 100 in this system. The temperature to be attained is displayed on the LCD           display. When a temperature is set, the system uses the  DS18B20 to continuously check the current temperature. And if it is below the desired value, it turns on the           red “heating” LED and starts the heater only when the switch is on.
3. When the set temperature is reached the first time, the system turns on the stabilizing LED and waits for 3 seconds, and switches the heater on or off depending on             whether the temperature needs correction.
5. After this stage, the “Target Reached” LED is turned on.
6. The system alternates between the “Stabilizing” and “Target Reached” state as the temperature is in range.
7. In the unlikely event that the heating element actuator malfunctions and the element stays on, the “Overheating” LED is turned on along with the buzzer to signal the           user to turn off the device manually.
8. A BLE Module HM-10 can be added but cannot be simulated due to its unavailability in Wokwi. If it is to be added, then we can just connect the digital pins 0 and 1 to          HM-10 TX and RX respectively. This will enable us to send the Serially printed data through BLE.
