# Turchyn_TR-41z_KR.cydsn
# Functional Signal Generator based on PSoC 4

This project is a functional signal generator based on a programmed system on chip (PSoC) 4. It uses the CY8CKIT-042 PSoC 4 Pioneer Kit along with an LCD 1602, buttons, LEDs, and a 10k potentiometer. The analog signal is generated using a digital-to-analog converter to obtain an exponentially decaying signal equal to:

![image](https://github.com/user-attachments/assets/d9e66583-5af9-439d-aff5-546a754f1a4a)


When the 'Start' button is pressed, a decaying oscillatory transient process begins. After 2 seconds, a signal equal to:

![image](https://github.com/user-attachments/assets/a1b30262-d353-4740-8143-42c832dac879)the function appears at the output and continues until the 'Start' button is pressed again.

Frequency = 450 Hz. The damping coefficient a = 0.3 corresponds to operating mode 1, a = 0.1 to operating mode 2.
С<sub>0</sub> = 127. A = 127.


.

## Features

- **Signal Generation**: Generates an exponentially decaying signal.
- **User Interface**: Includes an LCD 1602 for display, and buttons for user input.
- **LED Indicators**: Uses LEDs to indicate the status of the signal generator.
- **Adjustable Output**: A 10k potentiometer is used to adjust the brightness of LCD 1602.

## Hardware Requirements

- CY8CKIT-042 PSoC 4 Pioneer Kit
- LCD 1602
- Buttons
- LEDs
- 10k Potentiometer
- Resistors (10kΩ, 5.1kΩ, 220Ω)

## Hardware Connections
## LCD1602 to to PSoC 4 GPIOs
- VSS -> GND
- VCC -> +5V
- RW -> P2[6]
- RS -> P2[5]
- E -> P2[4]
- D4-D7 connected to P2[0]-P2[3]
- Potentiometer (RP1) (10kΩ) connected to adjust contrast, one terminal connected to +5V, other terminal connected to GND, wiper connected to LCD  pin VO

## Buttons
- **KEY1 (Start_Button_External)**
  - One terminal connected to +5V
  - Other terminal connected to P0[0] PSoC GPIO with 10kΩ pull-down resistor
- **KEY2 (Mode_1_Button)**
  - One terminal connected to +5V
  - Other terminal connected to P3[6] PSoC GPIO with 10kΩ pull-down resistor
- **KEY3 (Mode_2_Button)**
  - One terminal connected to +5V
  - Other terminal connected to P2[7] PSoC GPIO with 10kΩ pull-down resistor
 
## LEDs
- **LED1 (Green_Led_Start)**
  - Anode connected to +5V
  - Cathode connected to P3[5] PSoC GPIO via 220Ω resistor
- **LED2 (Mode_1_LED)**
  - Anode connected to +5V
  - Cathode connected to P3[4] PSoC GPIO via 220Ω resistor
- **LED3 (Mode_2_LED)**
  - Anode connected to +5V
  - Cathode connected to P1[0] PSoC GPIO via 220Ω resistor
 
## Potentiometer (RP1)
- One terminal connected to +5V
- Other terminal connected to GND
- Wiper connected to LCD contrast pin VO

## Oscilloscope Connection
- Output signal connected via 5.1kΩ resistor to GND and P3[0]

## Software Requirements

- PSoC Creator (or any suitable IDE for PSoC development)

## Getting Started

1. **Clone the repository**:
    ```sh
    git clone https://github.com/ivant-nick/Turchyn_TR-41z_KR.cydsn.git
    ```
2. **Connect all components** according to the project diagram
3. **Open the project** in PSoC Creator.
4. **Build and program** the project to the CY8CKIT-042 PSoC 4 Pioneer Kit.

## Usage

- Use the buttons to control the signal generator.
- Adjust the 10k potentiometer to adjust the brightness of LCD 1602.
- The LCD 1602 will display the current status and settings of the signal generator.
- LEDs will indicate the operational status.

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests.

## Acknowledgements

- Special thanks to the creators of the PSoC 4 Pioneer Kit and PSoC Creator.

## Functional signal generator circuit based on the CY8CKIT-042 PSoC 4 Pioneer Kit programmable system
![Schematic_Сoursework_2023-11-04](https://github.com/user-attachments/assets/904e1580-2a09-4b26-b139-e21f6dcd002f)

## Connecting all hardware components of the project
![image](https://github.com/user-attachments/assets/3074fffd-b87f-48c7-abcd-4f6ed22e0005)


## Mode 1
![Screenshot_2023-11-04-17-21-37-002_com miui videoplayer](https://github.com/user-attachments/assets/7e749431-a39a-4f55-8c56-1783422a299b)
![Screenshot_2023-11-04-17-20-04-084_com miui videoplayer](https://github.com/user-attachments/assets/82956059-eea4-4392-8245-a3cbcc3d815a)
![Screenshot_2023-11-04-17-16-29-000_com miui videoplayer](https://github.com/user-attachments/assets/352d6251-34a5-4875-93e4-c8140083d522)
![Screenshot_2023-11-04-17-16-00-788_com miui videoplayer](https://github.com/user-attachments/assets/8d35e0aa-a020-4ad6-ab0e-c79208b026f9)

## Mode 2
![Screenshot_2023-11-04-17-48-42-458_com miui videoplayer](https://github.com/user-attachments/assets/bbf5dd42-f3b3-4a94-a959-28b189602b27)
![Screenshot_2023-11-04-17-46-38-576_com miui videoplayer](https://github.com/user-attachments/assets/f9d33365-eaaf-4b95-9d7f-8ce624cd7151)
![Screenshot_2023-11-04-17-39-52-274_com miui videoplayer](https://github.com/user-attachments/assets/68ed6b05-3c3e-4195-8f21-07805abc70f2)
![Screenshot_2023-11-04-17-37-57-752_com miui videoplayer](https://github.com/user-attachments/assets/941bde68-d426-4224-a1a9-f0f72bc72ec0)

