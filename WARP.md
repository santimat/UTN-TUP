# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Overview

This repository contains coursework from the Tecnicatura Universitaria en Programación (UTN), organized by academic semesters. The project follows a structured learning progression from C fundamentals to Java object-oriented programming.

## Repository Structure

- `first-four-months/` - C programming exercises covering fundamentals through advanced data structures
- `second-four-months/` - Java programming exercises focusing on OOP concepts

### First Semester (C Programming)
Contains exercises progressing from basic syntax to complex algorithms and data structures:
- Basic exercises in numbered directories (`ejercicios1/`, `semana4/`, `semana5/`)
- Specialized topics (`ejerciciosStructs/`, `ejerciciosPunteros/`, `ejerciciosEstructsYArrayBidimensional/`)
- Complete projects (`BatallaNaval.c`, `Sistema de gestion de biblioteca/`)
- Data structures (`Listas/` - linked lists)
- Exam preparation (`practicaParcial/`)

### Second Semester (Java Programming)
Organized by practice sessions (`practica0/`, `practica1/`, etc.) with focus on:
- OOP fundamentals (classes, inheritance, polymorphism)
- Interface implementation
- Package organization

## Commands for Development

### C Programming

**Compile and run a single C file:**
```powershell
gcc -o program file.c
.\program.exe
```

**Compile with debugging symbols:**
```powershell
gcc -g -o program file.c
```

**Compile with all warnings enabled:**
```powershell
gcc -Wall -Wextra -o program file.c
```

**For Windows-specific code (using windows.h):**
```powershell
gcc -o program file.c
```

### Java Programming

**Compile Java files with package structure:**
```powershell
# From repository root
javac second-four-months/practica1/*.java
```

**Run Java programs:**
```powershell
# From second-four-months directory
java practica1.Main
```

**Compile all Java files in a package:**
```powershell
javac second-four-months/practica*/*.java
```

## Code Architecture Patterns

### C Programming Architecture

**Typical C File Structure:**
1. Headers (`#include` statements)
2. Type definitions (`typedef struct`)
3. Function declarations
4. Main function
5. Function implementations

**Common Patterns:**
- **Data Structure Management**: Files typically define custom structs (Book, datosEnteros) with associated utility functions
- **Menu-Driven Programs**: Most complete programs use do-while loops with switch statements for user interaction
- **Algorithm Implementation**: Sorting algorithms (bubble, selection, insertion) with performance tracking
- **Memory Management**: Dynamic allocation patterns using malloc/free for linked lists

**Key C Components:**
- **Struct-based Data Models**: Library management system uses Book struct with ISBN-based searching
- **Linked Lists**: Custom implementation using typedef structs with pointer chains
- **Binary Search**: Implemented for sorted data with ISBN keys
- **Game Logic**: Complete implementations like BatallaNaval.c with board management

### Java Programming Architecture

**Package Organization:**
- Each practice session is a separate package (`practica1`, `practica3`, etc.)
- Main classes typically in root of each package
- Related classes grouped by functionality

**OOP Hierarchy Examples:**
```
Instrumento (base class)
└── InstrumentoCuerda (inheritance)
    └── GuitarraElectrica (multiple interface implementation)
```

**Interface Implementation:**
- `Electrico` interface for electronic devices
- `Afinable` interface for tunable instruments
- Multiple interface implementation in `GuitarraElectrica`

**Design Patterns:**
- **Constructor Overloading**: Multiple constructors with default parameter patterns
- **Encapsulation**: Private fields with public getter/setter methods
- **Method Overriding**: Customized behavior in subclasses using @Override
- **Polymorphism**: Interface-based behavior contracts

## Common Data Structures

### C Implementations
- **Arrays**: Fixed-size collections with bounds checking
- **Structs**: Complex data types (Book, Employee, Student entities)
- **Linked Lists**: Dynamic data structures with pointer navigation
- **2D Arrays**: Matrix operations and board games

### Java Implementations
- **Classes**: Encapsulated data with behavior methods
- **Inheritance Hierarchies**: Base classes with specialized subclasses
- **Interface Contracts**: Behavioral specifications for multiple inheritance

## Testing and Validation

### C Programs
- Most programs include input validation and error handling
- Manual testing through console interaction
- Algorithm performance tracking (comparisons, swaps)

### Java Programs
- Object state validation in constructors and setters
- toString() method overrides for debugging output
- Method chaining and fluent interfaces where applicable

## Development Notes

- **C Programming**: Focus on procedural programming, manual memory management, and algorithm implementation
- **Java Programming**: Emphasis on OOP principles, encapsulation, inheritance, and polymorphism
- **Windows Compatibility**: C code includes Windows-specific headers and console manipulation
- **Educational Progression**: Repository reflects learning path from basic programming to advanced OOP concepts
