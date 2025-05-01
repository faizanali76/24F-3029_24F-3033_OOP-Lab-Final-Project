# StrongHold – Phase 1

## Introduction
StrongHold is a medieval kingdom simulation game that focuses on managing internal systems of a kingdom. This Phase 1 implementation provides a console-based interface for players to manage various aspects of their kingdom, including population, military, economy, and resources. The game simulates the challenges of maintaining a stable and prosperous medieval kingdom through strategic decision-making.

## Technologies Used
- **Programming Language**: C++
- **Input/Output**: Console-based interface
- **File Handling**: Save/Load game state functionality
- **Memory Management**: Dynamic memory allocation using new/delete operators

## Project Structure
The project follows a modular design with the following key components:

- **main.cpp**: Core game loop and menu system
- **Stronghold.h**: Header file containing class declarations
- **Individual Implementation Files**:
  - **army.cpp**: Military management system
  - **bank.cpp**: Banking and loan system
  - **economicsystem.cpp**: Economic and taxation system
  - **eventmanager.cpp**: Random event handling
  - **leader.cpp**: Leadership and policy system
  - **population.cpp**: Population management and social classes
  - **resourcemanager.cpp**: Resource tracking and management
  - **kingdom.cpp**: Kingdom name and basic information

## Features Implemented

### Social System
- Population divided into three classes: peasants, merchants, and nobles
- Dynamic class distribution affecting kingdom stability
- Happiness tracking and civil unrest simulation

### Military System
- Soldier recruitment and training
- Morale management
- Military rations and upkeep
- Army size limitations based on population

### Economic System
- Tax collection from different social classes
- Treasury management
- Inflation tracking
- Resource-based economy

### Banking System
- Loan issuance and repayment
- Treasury auditing
- Fraud detection
- Financial stability monitoring

### Resource Management
- Tracking of four key resources:
  - Food
  - Wood
  - Stone
  - Metal
- Resource gathering and consumption
- Resource-based events and consequences

### Event System
- Random event generation
- Multiple event types:
  - Agricultural crises
  - Epidemics
  - Military conflicts
  - Aristocratic treason
  - Natural disasters

### Leadership System
- Different leadership types (King/Tyrant)
- Policy implementation
- Impact on kingdom stability

## How to Run the Project

### Compilation
```bash
g++ main.cpp population.cpp resourcemanager.cpp eventmanager.cpp economicsystem.cpp bank.cpp army.cpp leader.cpp kingdom.cpp -o Stronghold
```

### Running
```bash
./Stronghold
```

## Team Members
- Faizan 24F-3029
- Abdul Rafey 24F-3033

## Contributions
Both team members contributed equally to:
- System design and architecture
- C++ implementation and logic
- File organization and modularity
- User interface flow
- Testing and debugging

The project was developed as part of a OOP Lab Final Project, focusing on implementing core C++ concepts and object-oriented programming principles. 
