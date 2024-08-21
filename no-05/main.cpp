#include "SongMap.h"
#include <sstream>
#include <vector>



using namespace std;

void commandSong(std::vector<std::string> &words, SongMap &songMap)
{
    if (words.size() < 5 || words[1].empty() || words[2].empty() || words[3].empty() || words[4].empty())
    {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    try
    {
        int songId = std::stoi(words[1]); 
        std::string artist = words[2];
        int duration = std::stoi(words[3]);
        std::string title = words[4];
        songMap.addSong(songId, artist, duration, title); 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid input format!" << std::endl;
    }
}

void commandListen(std::vector<std::string> &words, SongMap &songMap)
{
    if (words[1].empty() == true || words[2].empty() == true)
    {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    try
    {
        songMap.listen(words[1], std::stoi(words[2]));
    }
    catch (const std::exception &e)
    {
        std::cerr << "Provide integer value!" << '\n';
    }
}

void commandRemove(std::vector<std::string> &words, SongMap &songMap)
{
    if (words[1].empty() == true)
    {
        std::cout << "Invalid input!" << std::endl;
        return;
    }
    songMap.remove(words[1]);
}

std::vector<std::string> splitLine(const std::string &line)
{
    std::vector<std::string> words;
    std::stringstream ss(line);
    std::string word;

    bool inQuotes = false;
    std::string currentWord;

    while (ss >> word)
    {
        if (!inQuotes && word.front() == '"')
        {
            inQuotes = true;
            currentWord = word.substr(1);
        }
        else if (inQuotes && word.back() == '"')
        {
            inQuotes = false;
            currentWord += " " + word.substr(0, word.size() - 1);
            words.push_back(currentWord);
        }
        else if (inQuotes)
            currentWord += " " + word;
        else
            words.push_back(word);
    }

    return words;
}

int main(void)
{
    SongMap songMap;
    static size_t id = 0;

    while (1)
    {
        std::cout << std::endl << "Enter command [song <songid> <artist> <duration> <title>, listen <songtitle> <listentime>, show_listen_time, remove <songtitle>, quit]: " << std::endl;

        std::string line;
        std::vector<std::string> words;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string word;
        words = splitLine(line);
        if (words.empty() == false)
        {
            if (words[0] == "quit")
                break;
            else if (words[0] == "song")
                commandSong(words, songMap);
            else if (words[0] == "listen")
                commandListen(words, songMap);
            else if (words[0] == "show_listen_time")
                songMap.showListenTime();
            else if (words[0] == "favorite")
                songMap.favorite();
            else if (words[0] == "remove")
                commandRemove(words, songMap);
            else
                std::cout << "Provide a valid input" << std::endl;
        }
        else
            std::cout << "Provide a valid input" << std::endl;
    }

    return (0);
}
