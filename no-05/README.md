# Heap-Based Song Management System

## Project Description
This project implements a heap-based song management system in C++. The system manages songs using a priority queue (max-heap) to efficiently track and manage song favorites based on listening time. The project supports operations such as adding songs, listening to songs, marking songs as favorites, removing songs, and displaying listening times. Automated testing is facilitated through TCL expect scripts.

## Files
- `Heap.cpp`: Implements the `SongMap` class with functions to add songs, mark them as favorites, and manage the heap structure.
- `heap.h`: Header file for the `SongMap` class and related structures.
- `interaction.exp`: A TCL expect script for automating command-line interactions and testing the program.
- `main.cpp`: Entry point for the program, integrating with the `SongMap` class and handling user commands.
- `makefile`: A makefile for compiling the project and managing dependencies.
- `Song.h`: Header file for the `Song` class, representing individual songs.
- `SongMap.cpp`: Implements various operations related to song management, including tree-based operations and listening time tracking.
- `SongMap.h`: Header file for the `SongMap` class, managing the song collection using a red-black tree and a vector.
- `test_helper.sh`: A bash script for running automated tests using the TCL expect script.

## Usage

### Compilation
To compile the program, use the following command:
```bash
make
```
