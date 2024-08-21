# Song Collection and Playlist Manager

## Project Description
This project demonstrates a simple C++ program that manages and displays information about songs and playlists. It provides a command-line interface for adding and removing songs, creating and managing playlists, and viewing song details. The project is divided into three parts:

1. **Song Collection Display**: Displays individual songs and collections.
2. **Song and Playlist Manager**: Provides a command-line interface for managing songs and playlists.
3. **Advanced Playlist Management**: Introduces more complex playlist operations, including copying, renaming, and dynamic management of song arrays.

## Files
### Part 3: Advanced Playlist Management
- `main.cpp`: The main file that now includes additional commands for advanced playlist management, such as copying, renaming, and deleting playlists.
- `Playlist.cpp`: Implementation of the `Playlist` class, which represents a playlist of songs. Includes methods for adding, deleting, copying, renaming, and managing playlists.
- `Playlist.h`: Header file for the `Playlist` class.
- `Song.cpp`: Updated implementation of the `Song` class with additional error handling and dynamic memory management.
- `Song.h`: Header file for the `Song` class.
- `Makefile`: A makefile to compile the `SongCollection` program and manage dependencies.

## Usage
### Part 1: Song Collection Display
To compile and run the program:
1. **Compile the program**:
   ```bash
   make
   ```
2. **Run the executable**
    ```bash
    ./SongCollection
    ```
## Use the Command-Line Interface

- **Add a new song**:  
  Type `song <songid> "<artist>" <duration> "<title>"`  
  Example: `song 1 "Peter Gabriel" 300 "In Your Eyes"`

- **Remove a song by ID**:  
  Type `remove <songid>`  
  Example: `remove 1`

- **View details of a song by ID**:  
  Type `seesong <songid>`  
  Example: `seesong 1`

- **Create a new playlist**:  
  Type `addplaylist <id> "<name>"`  
  Example: `addplaylist 1 "My Playlist"`

- **Delete a playlist by ID**:  
  Type `deleteplaylist <id>`  
  Example: `deleteplaylist 1`

- **Copy an existing playlist to a new one**:  
  Type `copyplaylist <sourceId> <newId> "<newName>"`  
  Example: `copyplaylist 1 2 "Copied Playlist"`

- **Rename a playlist**:  
  Type `renameplaylist <id> "<newName>"`  
  Example: `renameplaylist 1 "New Playlist Name"`

- **View songs in a playlist by ID**:  
  Type `seeplaylist <id>`  
  Example: `seeplaylist 1`

- **Add a song to a playlist**:  
  Type `addsongtoplaylist <songId> <playlistId>`  
  Example: `addsongtoplaylist 1 1`

- **Remove a song from a playlist**:  
  Type `dropsongfromplaylist <songId> <playlistId>`  
  Example: `dropsongfromplaylist 1 1`

- **Exit the program**:  
  Type `quit`

## What I Learned in Part 3: Advanced Playlist Management

- **Dynamic Array Management**: I learned how to manage dynamic arrays, including resizing arrays when they reach capacity and ensuring memory is properly allocated and deallocated.
- **Playlist Operations**: I implemented advanced playlist operations, such as copying and renaming playlists, and managing the addition and removal of songs from playlists.
- **Error Handling**: I improved error handling mechanisms to ensure the program provides informative feedback when operations fail, such as attempting to add a song to a non-existent playlist.
- **Enhanced Input Parsing**: I refined input parsing to handle more complex commands and to ensure that inputs are validated correctly before processing.
- **Memory Management Best Practices**: I reinforced the importance of properly managing memory in C++, particularly when working with dynamic data structures, to prevent memory leaks and ensure program stability.
- **Code Organization and Modularity**: I practiced organizing code into separate classes and files, improving code readability, reusability, and maintainability.