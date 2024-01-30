#include "LoadLines.h"
#include <fstream>
#include <sstream>

using namespace std;

void LoadLines::command(GSP *gsp) {
    string filepath;
    getline(cin, filepath);
    if (filepath.empty()) filepath = this->defaultFileLocation;
    //filepath = "../test/" + filepath;
    fstream file;
    file.open(filepath, ios::in);

    // TODO: Exception for FileNotFound

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
