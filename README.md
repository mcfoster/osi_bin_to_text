# OSI Binary to Text Converter

A GUI application that converts 6502 binary files to text formats compatible with the Ohio Scientific C1P computer system.

## Overview

This application provides a graphical user interface for converting 6502 binary files into two different text formats:
- Hex format that can be loaded using the Ohio Scientific C1P monitor
- BASIC format that can be loaded by BASIC interpreter

## Features

- User-friendly GUI interface using Qt6
- Support for two output formats:
  - Ohio Scientific C1P monitor-compatible hex format
  - BASIC-loadable format
- Simple file selection and conversion process

## Requirements

- Qt6 library
- C++17 compatible compiler

## Sample Files

The project includes several sample files for testing:

- `test1.s` - Sample 6502 assembly language source file that displays "HELLO" on the C1P screen
- `test1.bin` - Binary file compiled from test1.s (input file example)
- `test1.hex` - Sample hex format output
- `test1.bas` - Sample BASIC format output

## Building the Project

You will need to modify the CMAKE_PREFIX_PATH in CMakeLists.txt so that the path points to your installation folder for the Qt6 prefix path.

The project uses CMake as its build system. To build:

```bash
mkdir build
cd build
cmake ..
make
```
