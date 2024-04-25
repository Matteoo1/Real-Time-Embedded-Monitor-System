# Real-Time-Embedded-Monitor-System

## Project Overview

This real-time embedded system project uses the Arduino platform and FreeRTOS to efficiently manage synchronization between multiple producers and consumers interacting with a shared buffer. Designed specifically for embedded applications, it showcases precise task management and system reliability in real-time operations.

## Features

- **Embedded System Design**: Built on an Arduino microcontroller, this project is a true example of an embedded system with dedicated functionality tailored for specific control tasks.
- **Producers and Consumers**: Implements dual producer and consumer tasks that simulate a dynamic data flow within an embedded system environment.
- **Real-Time Operations**: Runs on FreeRTOS, ensuring that tasks operate within strict time constraints, crucial for real-time embedded applications.
- **Semaphore Synchronization**: Employs robust synchronization mechanisms using mutex and counting semaphores to manage access to a shared buffer and prevent data corruption.

## Hardware Requirements

- **Arduino Board** (Uno, Mega, etc.)

## Software Requirements

- Arduino IDE
- FreeRTOS for Arduino

## Setup Instructions

1. **Hardware Setup**: Connect your Arduino board to your computer.
2. **Software Setup**: Open this project in Arduino IDE.
3. **Library Installation**: Ensure the FreeRTOS library is installed in the Arduino IDE.
4. **Upload**: Compile and upload the program to the Arduino board.

## System Operation

- **Initialization**: Begins with the system initialization in the `setup()` function, where it sets up the random number generator, monitor structure, and tasks.
- **Producer Tasks**: Each producer generates random numbers and adds them to the buffer, secured by semaphore-based synchronization.
- **Consumer Tasks**: Consumers pull numbers from the buffer under real-time constraints, showcasing the efficiency of an embedded control system.
- **Dedicated Embedded Functionality**: The system's operations are fine-tuned for embedded environments, emphasizing performance and reliability.

## System Operation
 An image of the arduino used in this project

 <img src="https://github.com/mohamadd10/Real-Time-Embedded-Monitor-System/blob/main/assets/662ef1e6-01dc-4326-a086-c3fb8aaaa5ae" width="100" height="100">
  
 ![Skärmbild](https://github.com/mohamadd10/Real-Time-Embedded-Monitor-System/assets/119814738/662ef1e6-01dc-4326-a086-c3fb8aaaa5ae)


