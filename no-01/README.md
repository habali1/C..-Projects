# Song Collection Display

## Project Description
This project demonstrates a simple C++ program that manages and displays information about songs. It uses classes to represent individual songs and a song collection, allowing basic operations such as displaying song details.

## Files
### Part 1: Song Collection Display
- `Listen.cpp`: The main file that drives the program. It creates instances of `Song` and `SongCollection`, displays song information, and manages memory.
- `Song.cpp`: Implementation of the `Song` class, which represents a song with a title, release year, and artist.
- `Song.h`: Header file for the `Song` class.
- `SongCollection.cpp`: Implementation of the `SongCollection` class, which represents a collection of songs.
- `SongCollection.h`: Header file for the `SongCollection` class.
- `Makefile`: A makefile to compile the program and manage dependencies.

## Usage
To compile and run the program, use the following commands:

1. **Compile the program**:
   ```bash
   make
   ```
2. **Run Executable**:
    ```bash
    ./listen
    ```
3. **Clean the build files**
    ```bash
    make clean
    ```
## What I Learned

- **Class Encapsulation**: I learned how to encapsulate data within classes in C++, allowing for better organization and management of related data.
- **Constructor Overloading**: I gained experience in using constructor overloading to create objects with different initial states.
- **Memory Management**: I practiced dynamic memory management using `new` and `delete` in C++, ensuring that dynamically allocated memory is properly handled.
- **Object-Oriented Programming**: I reinforced my understanding of object-oriented programming principles, such as creating and using objects, as well as understanding the relationship between different classes.
- **Makefile Usage**: I learned how to create a `Makefile` to automate the compilation process, manage dependencies, and clean up build files effectively.