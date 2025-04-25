# OSI Binary to Text Converter (v0.1)

A Qt6-based utility for converting 6502 binary files into formats compatible with Ohio Scientific (OSI) computers. This tool assists in transferring programs to vintage OSI systems by converting modern assembled binaries into either OSI Monitor hex format or BASIC DATA statements.

## Features

- Read binary files produced by 6502 cross-assemblers
- Convert binaries to OSI C1P Monitor-compatible hex format
- Generate BASIC programs with DATA statements for loading machine code
- Modern Qt6-based graphical user interface
- Cross-platform compatibility

## Requirements

- Qt6 Library
- C++ compiler with C++17 support
- CMake (version 3.5 or higher)

## Building from Source

1. Ensure Qt6 is installed on your system
2. Configure the build:
```bash
cmake -B build
```
3. Build the project:
```bash
cmake --build build
```

## Usage

The application provides two main conversion options:

### OSI Monitor Hex Format
Converts binary files to hex format loadable through the OSI Monitor. The output format uses the `.xxxx` syntax for addresses followed by hex values, ending with a `G` command for execution.

Example hex output:
```
.0222/A2
00
BD
...
.0222G
```

### BASIC Format
Generates a BASIC program that uses DATA statements to load the machine code. The program includes the necessary POKE commands to load the data into memory and set up the USR function call.

Example BASIC output:
```basic
9000 DATA 546
9010 DATA 162, 0, 189, 50, 2, 240, 7, 157, 168, 208
...
9120 X = USR(X)
```

## Example Files

The project includes sample files for testing and demonstration:

- `test1.s` - Example 6502 assembly source file showing a simple "HELLO" program
- `test1.bin` - The assembled binary output
- `test1.hex` - Sample hex format output for OSI Monitor
- `test1.bas` - Sample BASIC program format
