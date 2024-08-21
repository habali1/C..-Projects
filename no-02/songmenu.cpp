#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Time format func
string formatDuration(int duration) {
    int minutes = duration / 60;
    int seconds = duration % 60;
    stringstream ss;
    ss << minutes << ":" << (seconds < 10 ? "0" : "") << seconds;
    return ss.str();
}
int main() {
    std::string line;

    while (true) {
        std::cout << ": ";
        if (!std::getline(std::cin, line)) break;

        std::istringstream iss(line);
        std::string command;
        iss >> command;

	if (command == "song") {
	  int songId;
	  std::string artist;
	  int duration;
	  std::string title;
	  iss >> songId >> artist >> duration;
	  iss.ignore(); // Ignore leading whitespace before the title
	  std::getline(iss, title); // Now read the title

	  std::cout << "new song " << title << " by " << artist << " " << formatDuration(duration) << std::endl;
	}

	else if (command == "remove") {
            int songId;
            iss >> songId;
            cout << "removing song " << songId << endl;
        }

	else if (command == "playlist") {
            int playlistId;
            string name;
            iss >> playlistId >> name;
            cout << "new playlist " << playlistId << " called " << name << endl;
        }

	else if (command == "add") {
            int songId, playlistId;
            iss >> songId >> playlistId;
            cout << "add song " << songId << " to playlist " << playlistId << endl;
        }

	else if (command == "drop") {
            int songId, playlistId;
            iss >> songId >> playlistId;
            cout << "remove song " << songId << " from playlist " << playlistId << endl;
        }

	else if (command == "seesong") {
            int songId;
            iss >> songId;
            cout << "song " << songId << endl;
        }

	else if (command == "seeplaylist") {
            int playlistId;
            iss >> playlistId;
            cout << "Songs in playlist " << playlistId << endl;
        }

	else if (command == "quit") {
            break;
        }
	
	else {
	  
	  std::cout << "Command not recognized, please try again." << std::endl;
        }
    }

    return 0;
}
