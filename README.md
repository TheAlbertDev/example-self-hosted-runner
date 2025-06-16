# CI Server for Embedded Systems

This repository contains example projects for microcontrollers with Continuous Integration and Continuous Delivery (CI/CD) implemented through a Raspberry Pi-based self-hosted GitHub Actions runner.

This code accompanies the blog post: [CI Server for embedded systems based on Raspberry Pi](https://thealbert.dev/en/posts/ci-server-for-embedded-systems-based-on-raspberry-pi/)

## Project Overview

This repository demonstrates how to implement automated testing for embedded systems using a Raspberry Pi as a self-hosted GitHub Actions runner. The examples include simple LED blinking applications for both Arduino and STM32 platforms, with comprehensive unit and acceptance testing.

The setup allows for:
- Running unit tests on the code directly on the Raspberry Pi
- Compiling and flashing firmware to actual hardware
- Running acceptance tests to verify hardware behavior
- Providing automated feedback through GitHub's pull request system

## Repository Structure

```
.
├── .devcontainer       # Development container configuration
├── .github             # GitHub-related files
│   └── workflows       # GitHub Actions workflows for CI/CD
├── arduino             # Arduino-based projects
│   └── blink_led       # LED blinking example for Arduino
├── stm32cube           # STM32Cube-based projects
│   └── blink_led       # LED blinking example for STM32
└── test                # Automated tests
    ├── arduino         # Tests for Arduino projects
    │   └── blink_led   # Tests for Arduino example
    │       ├── acceptance  # Acceptance tests
    │       └── unit        # Unit tests
    └── stm32cube       # Tests for STM32 projects
        └── blink_led   # Tests for STM32 example
            ├── acceptance  # Acceptance tests
            └── unit        # Unit tests
```

## Components Description

### Projects

- **Arduino**: The `arduino` directory contains projects developed for the Arduino platform. The example project `blink_led` demonstrates a simple LED blinking application using structured code with separate `.cpp` and `.h` files.

- **STM32**: The `stm32cube` directory includes projects developed with the STM32Cube framework. The `blink_led` example is adapted for STM32 microcontrollers, demonstrating the same functionality but using the STM32 HAL libraries.

### Tests

- **Unit Tests**: Located in the `unit` subdirectories, these tests verify the internal logic of the code using the CppUTest framework. They use mocks to simulate hardware interactions, allowing for testing without physical hardware.

- **Acceptance Tests**: Found in the `acceptance` subdirectories, these tests validate the behavior of the code on actual hardware. They use Python with pytest to verify that the LED blinks at the expected rate.

### CI/CD Configuration

- **GitHub Actions**: The `.github/workflows` directory contains workflow configurations that automatically run tests when code is pushed or a pull request is created. These workflows use the self-hosted runner on the Raspberry Pi.

- **Development Container**: The `.devcontainer` directory provides a consistent development environment using containers, ensuring all developers work with the same tools and dependencies.

## Getting Started

To use this repository with your own CI setup:

1. Set up a Raspberry Pi with the necessary tools as described in the [blog post](https://thealbert.dev/en/posts/ci-server-for-embedded-systems-based-on-raspberry-pi/)
2. Configure a self-hosted GitHub Actions runner on your Raspberry Pi
3. Connect your development board (NUCLEO-F401 or compatible) to the Raspberry Pi
4. Fork or clone this repository and push to your own GitHub account
5. Create a pull request to see the CI workflows in action

## Usage in Education

This setup was specifically designed for educational environments to provide automated feedback to students in embedded systems programming courses. It allows instructors to:

1. Define test cases that verify student code meets requirements
2. Provide immediate feedback when students submit their work via pull requests
3. Ensure consistent evaluation of code quality and functionality

## License

This project is available under the [MIT License](LICENSE).
