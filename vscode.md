# Introduction

This documentation details how to setup vscode to send the code to the ESP8266.

## Context

This was done on VSCODE 1.47 and macOS 10.15

## Sources

Thanks to:

- This is mainly based on: https://maker.pro/arduino/tutorial/how-to-use-visual-studio-code-for-arduino#:~:text=To%20set%20the%20serial%20port,your%20Uno%20is%20connected%20to.

# Pre-requesite

- You need to have VSCODE installed
- VS Code requires that the standard Arduino IDE is installed, as it uses some of the libraries included in the IDE.
  This can be done with:
  > brew cask install arduino

# Install

## Arduino extension

In VSCODE: install the Arduino extension enter “Cntrl+Shift+x” to display the Extensions viewer and type “vscode-arduino” into the search bar. This should return just one result. Press the “Install” button to install.

## Select Programmer

To select AVR ISP as programme, select the option (with CMD+SHIFT+P):

> Aduino: Select Programmer

## Board Manager

To select the ESP as board type, select the option (with CMD+SHIFT+P):

> Arduino: Board Manager

And install required material for the esp8266 (at the end)

## Select Board

Select your board thanks to the "connection" icon on footer menu, bottom right, of VSCODE, select "Generic ESP8266 Module"

## Port

To get the proper communication port with the ESP, select the option (with CMD+SHIFT+P):

> Arduino: Select Serial Port

# Send code

## File type

File must be an .ino

## Upload code

When selecting .ino file vscode displays an upload icon (near the file tabs). Also the next icon helps to check the code.
