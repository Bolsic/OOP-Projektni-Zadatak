#include "LoadingCommands.h"
#include "Exceptions.h"

using namespace std;

void LoadStations::command(GSP *gsp) {

    cin.ignore();

    string filepath;
    getline(cin, filepath);

    if (filepath.empty()){
        filepath = this->defaultFileLocation;
        gsp->defaultFiles = true;
    }

    fstream file;
    file.open(filepath, ios::in);

    if (!file.is_open()) throw FileNotFount();

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


void LoadLines::command(GSP *gsp) {

    // If the station file is the default one load the default line file
    string filepath;
    if (gsp->defaultFiles) filepath = this->defaultFileLocation;
    else getline(cin, filepath);

    fstream file;
    file.open(filepath, ios::in);

    if (!file.is_open()) {
        throw FileNotFount();
    }

    string inputLine;
    while(getline(file, inputLine)){

        // Parsing the string with stringstream
        istringstream ss(inputLine);
        string token;
        // Getting the first word - the line name
        getline(ss, token, ' ');
        auto* line = gsp->addLine(token);

        while(getline(ss, token, ' ')){
            // Adding the station to the Stations_ list of the Line object
            Station* station = gsp->getStation(stoi(token));
            line->addStation(station);
        }
    }

}


void MakeConnections::command(GSP *gsp) {
    for (const auto& pair : gsp->Lines_){

        // line is the current line
        Line* line = pair.second;
        // stations is a list of stations that the current line goes through
        vector<Station*> stations = pair.second->getStations();

        // Iterate over the stations the given line goes through
        for (auto it = stations.begin(); it != stations.end(); it = next(it, 1)){
            // Add a connection to the next
            if (it == prev(stations.end(), 1)) (*it)->addConnection(*stations.begin(), line);
            else (*it)->addConnection(*next(it, 1), line);
            // Add a connection to the previous station
            if (it == stations.begin()) (*it)->addConnection(*prev(stations.end()), line);
            else (*it)->addConnection(*prev(it, 1), line);
        }
    }
}