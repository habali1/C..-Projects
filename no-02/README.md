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
## Use the Command-Line Interface

- **Add a new song**:  
  Type `song <id> <artist> <duration> <title>`  
  Example: `song 1 "Peter Gabriel" 300 "In Your Eyes"`

- **Remove a song by ID**:  
  Type `remove <id>`  
  Example: `remove 1`

- **Create a new playlist**:  
  Type `playlist <id> <name>`  
  Example: `playlist 1 "My Playlist"`

- **Add a song to a playlist**:  
  Type `add <song_id> <playlist_id>`  
  Example: `add 1 1`

- **Remove a song from a playlist**:  
  Type `drop <song_id> <playlist_id>`  
  Example: `drop 1 1`

- **View details of a song by ID**:  
  Type `seesong <id>`  
  Example: `seesong 1`

- **View songs in a playlist by ID**:  
  Type `seeplaylist <id>`  
  Example: `seeplaylist 1`

- **Exit the program**:  
  Type `quit`

## What I Learned in the Continuation Project

- **Advanced Command-Line Interface Design**: I enhanced my skills in designing a command-line interface that supports multiple commands for managing songs and playlists, providing a more interactive and user-friendly experience.
- **Complex Input Parsing**: I gained experience in parsing more complex user inputs, including handling multiple data types in a single command, using `istringstream` and `getline` effectively.
- **Playlist Management**: I learned how to implement functionality for creating and managing playlists, including adding and removing songs from playlists and viewing playlist contents.
- **Dynamic Duration Formatting**: I implemented and refined the `formatDuration` function to convert and display song durations in a standard `minutes:seconds` format.
- **Error Handling and User Feedback**: I improved my approach to handling incorrect or unrecognized commands, providing clear feedback to the user and ensuring a smoother interaction with the program.
- **Revised Makefile Techniques**: I practiced updating the Makefile to reflect new project requirements, ensuring proper compilation and linkage of the new command-line interface.