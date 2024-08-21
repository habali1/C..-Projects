#include "Song.h"
#include "Playlist.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip> 
#include <algorithm>
#include <cctype>

bool isInteger(const std::string& s) {
	return !s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isdigit(c); });
}

std::vector<std::string> splitInput(const std::string& input) {
    std::istringstream stream(input);
    std::vector<std::string> tokens;
    std::string token;
    while (stream >> std::quoted(token)) {
        tokens.push_back(token);
    } 
    return tokens;
}

int main() {
    std::string line;
    std::cout << "Commands:\n"
              << "  song <songid> \"<artist>\" <duration> \"<title>\"\n"
              << "  remove <songid>\n"
              << "  seesong <songid>\n"
              << "  addplaylist <id> \"<name>\"\n"
              << "  deleteplaylist <id>\n"
              << "  copyplaylist <sourceId> <newId> \"<newName>\"\n"
              << "  renameplaylist <id> \"<newName>\"\n"
              << "  seeplaylist <id>\n"
              << "  addsongtoplaylist <songId> <playlistId>\n"
              << "  dropsongfromplaylist <songId> <playlistId>\n"
              << "Type 'quit' to exit the program.\n";

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line) || line == "quit") {
            break;
        }

        auto tokens = splitInput(line);


        if (tokens.empty()) {
            std::cout << "Unrecognized command or incorrect format." << std::endl;
            continue;
        }

        try {
            if (tokens[0] == "song" && tokens.size() == 5) {
            	if (!isInteger(tokens[1]) || !isInteger(tokens[3])) {
                std::cout << "song ID and the duration must be integers!" << std::endl;
                continue; 
            }
                int id = std::stoi(tokens[1]);
                int duration = std::stoi(tokens[3]);
                Song::addSong(id, tokens[2], duration, tokens[4]);
            }

	    else if (tokens[0] == "remove" && tokens.size() == 2) {
                int id = std::stoi(tokens[1]);
                Song::removeSong(id);
            }

	    else if (tokens[0] == "seesong" && tokens.size() == 2) {
                int id = std::stoi(tokens[1]);
                Song::seeSong(id);
            }

	    else if (tokens[0] == "addplaylist" && tokens.size() == 3) {
                int id = std::stoi(tokens[1]);
                Playlist::addPlaylist(id, tokens[2]);
            }

	    else if (tokens[0] == "deleteplaylist" && tokens.size() == 2) {
                int id = std::stoi(tokens[1]);
                Playlist::deletePlaylist(id);
            }

	    else if (tokens[0] == "copyplaylist" && tokens.size() == 4) {
                int sourceId = std::stoi(tokens[1]);
                int newId = std::stoi(tokens[2]);
                Playlist::copyPlaylist(sourceId, newId, tokens[3]);
            }

	    else if (tokens[0] == "renameplaylist" && tokens.size() == 3) {
                int id = std::stoi(tokens[1]);
                Playlist::renamePlaylist(id, tokens[2]);
            }

	    else if (tokens[0] == "seeplaylist" && tokens.size() == 2) {
                int id = std::stoi(tokens[1]);
                Playlist::seePlaylist(id);
            }

	    else if (tokens[0] == "add" && tokens.size() == 3) {
                int songId = std::stoi(tokens[1]);
                int playlistId = std::stoi(tokens[2]);
                Playlist* playlist = Playlist::findPlaylistById(playlistId);
                if (playlist != nullptr) {
                    playlist->addSongToPlaylist(songId);
                } else {
                    std::cout << "Playlist is not found." << std::endl;
                }
            } else if (tokens[0] == "drop" && tokens.size() == 3) {
                int songId = std::stoi(tokens[1]);
                int playlistId = std::stoi(tokens[2]);
                Playlist* playlist = Playlist::findPlaylistById(playlistId);
                if (playlist != nullptr) {
                    playlist->dropSongFromPlaylist(songId);
                } else {
                    std::cout << "Playlist is not found." << std::endl;
                }
            } else {
                std::cout << "Unrecognized command or incorrect format." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error! processing command: " << e.what() << std::endl;
        }
    }

    return 0;
}
