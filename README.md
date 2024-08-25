# ESP32 Firebase Random Data Logger

This project demonstrates how to use an ESP32 microcontroller to generate random floating-point numbers and log them to a Firebase Realtime Database. The code also synchronizes time using an NTP server for timestamping the data entries.

## Overview

- **WiFi Connection**: Connects to a specified WiFi network.
- **Time Synchronization**: Uses the NTPClient library to synchronize time.
- **Firebase Integration**: Logs random floating-point numbers to a Firebase Realtime Database.
- **Random Number Generation**: Generates random numbers every second.

## Prerequisites

1. **ESP32 Board**: Ensure you have an ESP32 development board.
2. **Libraries**: Install the following libraries via the Arduino Library Manager or manually:
   - `WiFi`
   - `Firebase`
   - `NTPClient`
   - `WiFiUdp`

3. **Firebase Setup**: Set up a Firebase project and obtain the `REFERENCE_URL` for your Firebase Realtime Database.

## Installation

1. **Clone the Repository**: Clone or download the code to your local machine.

2. **Set Up Secrets**:
   - Create a file named `secrets.h` in the same directory as the main code.
   - Add the following contents to `secrets.h`:
     ```cpp
     #define SSID "your_wifi_ssid"
     #define PASSWORD "your_wifi_password"
     #define REFERENCE_URL "https://your-firebase-app.firebaseio.com/"
     ```
   - Replace `"your_wifi_ssid"`, `"your_wifi_password"`, and `"https://your-firebase-app.firebaseio.com/"` with your actual WiFi credentials and Firebase URL.

3. **Upload the Code**:
   - Open the code in the Arduino IDE or compatible development environment.
   - Select the appropriate board and port from the Tools menu.
   - Upload the code to the ESP32 board.

## Code Explanation

- **Includes**: The code includes necessary libraries for WiFi, Firebase, and NTPClient functionality.
- **Global Variables**:
  - `GMT_OFFSET`: Time offset for NTP.
  - `fb`: Firebase object initialized with `REFERENCE_URL`.
  - `ntpUDP` and `timeClient`: Used for time synchronization.

- **`setup()` Function**:
  - Initializes serial communication and connects to the WiFi network.
  - Prints the local IP address of the ESP32.
  - Initializes the NTPClient to get time and sets the time offset.
  - Seeds the random number generator with the current epoch time.

- **`loop()` Function**:
  - Updates the NTPClient to get the current time.
  - Generates a random floating-point number between 0 and 10.
  - Logs the random number to Firebase with the current time as a key.
  - Waits for 1 second before repeating.

## Troubleshooting

- **WiFi Connection Issues**: Ensure that the SSID and password in `secrets.h` are correct and that your WiFi network is working.
- **Firebase Connectivity**: Verify that the `REFERENCE_URL` is correct and that your Firebase Realtime Database rules allow writing data.
- **Time Synchronization**: Ensure that your ESP32 is connected to the internet for NTP time synchronization.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For questions or issues, please open an issue on the project's repository or contact [your_email@example.com](mailto:your_email@example.com).

Happy coding!
