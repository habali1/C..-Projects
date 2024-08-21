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
### Automated Testing
```bash
bash test_helper.sh ./listen_up <testcase-number>
```
## What I Learned

- **Heap Data Structure**: I gained experience implementing and managing a max-heap using a priority queue in C++. This allowed for efficient retrieval of the song with the maximum listening time.
- **Red-Black Tree**: I reinforced my understanding of red-black tree operations for balancing and managing a dynamic set of elements, ensuring efficient insertions and deletions.
- **Automated Testing with TCL Expect**: I learned how to use TCL expect scripts to automate command-line interactions, facilitating the testing of the program with predefined test cases.
- **Advanced Memory Management**: I practiced advanced memory management techniques in C++, including handling dynamic allocation and ensuring proper cleanup of resources.
- **Complex Data Structures**: I developed and integrated complex data structures, such as the combination of a red-black tree and a max-heap, to manage songs effectively.
- **Error Handling**: I implemented robust error handling mechanisms to manage edge cases, such as attempting to listen to or remove non-existent songs or handling empty heaps.