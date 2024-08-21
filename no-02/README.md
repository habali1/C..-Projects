# Song Collection and Playlist Manager

## Project Description
This project demonstrates a simple C++ program that manages and displays information about songs and playlists. It provides a command-line interface for adding and removing songs, creating playlists, and managing song collections.

## Files
### Part 1: Song Collection Display
- `Listen.cpp`: The main file that drives the program. It creates instances of `Song` and `SongCollection`, displays song information, and manages memory.
- `Song.cpp`: Implementation of the `Song` class, which represents a song with a title, release year, and artist.
- `Song.h`: Header file for the `Song` class.
- `SongCollection.cpp`: Implementation of the `SongCollection` class, which represents a collection of songs.
- `SongCollection.h`: Header file for the `SongCollection` class.
- `Makefile`: A makefile to compile the program and manage dependencies.

### Part 2: Song and Playlist Manager
- `songmenu.cpp`: Implements a command-line menu for managing songs and playlists, including commands like `song`, `remove`, `playlist`, `add`, `drop`, `seesong`, `seeplaylist`, and `quit`.
- `Makefile`: A makefile to compile the `songmenu` program and manage dependencies.

## Usage
### Part 1: Song Collection Display
To compile and run the program:
1. **Compile the program**:
   ```bash
   make
   ```
2. **Run the executable**
    ```bash
    ./songmenu
    ```
3. **Use the command-line interface:**
- Type 'song <id> <artist> <duration> <title>' to add a new song