#include <fstream>
#include <sstream>
#include "LoadStations.h"
#include "Exceptions.h"
using namespace std;

void LoadStations::command(GSP *gsp) {

    cin.ignore();

    string filepath;
    getline(cin, filepath);
    if (filepath.empty()) filepath = this->defaultFileLocation;

    fstream file;
    file.open(filepath, ios::in);

    // TODO: Exception for FileNotFound
    if (!file.is_open()) {
        throw FileNotFount();
    }

    string inputLine;
    while(getline(file, inputLine)){

        // Parsing the string with stringstream
        istringstream ss(inputLine);
        string token;
        //Getting the first word - the station id
        getline(ss, token, ' ');
        int id = stoi(token);
        string name;
        bool important = false;

        while(getline(ss, token, ' ')){
            if ((token == "[!]\r") || (token == "[!]")) important = true;
            else name += token + " ";
        }
        name.pop_back(); // Removes the last space from the name
        if (!important) name.pop_back(); // Removes the '\r' character if necessary

        gsp->addStation(id, name, important);
    }
}

