#include "GSP.h"
#include "Exceptions.h"

void GSP::addStation(int id, const string& name, bool important) {

    // TODO: Exception for StationIdAlreadyExists

    auto* station = new Station(id, name, important);
    Stations_.insert(pair<int, Station*>(id, station));
}

Line* GSP::addLine(const string& name) {

    // TODO: Exception for LineNameAlreadyExists

    auto* line = new Line(name);
    Lines_.insert(pair<string, Line*>(name, line));
    return line;
}

void GSP::printAllRoutesToFrom(int start, int destination) {
    auto allRoutes = Stations_[start]->findRoutesToStation(Stations_[destination]);
    for (const auto& route : allRoutes){
        for (int i = 0; i < route->numOfStations; i++){
            cout << route->stations_[i]->getIdx()  << "<" << route->lines_[i] << ">" << " ";
        }
        cout << endl;
    }
}

int GSP::getNumOfImpStations() {
    int count = 0;
    for(auto station : Stations_) if(station.second->isImportant()) count++;
    return count;
}

GSP::~GSP() {
    for (auto pair : Stations_) delete pair.second;
    Stations_.clear();
    for (const auto& pair : Lines_) delete pair.second;
    Lines_.clear();
}

void GSP::writeStationInfo(int id, const string& fileLocation) {
    if (Stations_[id] == nullptr) throw StationDoesntExist();
    Stations_[id]->writeInfo(fileLocation);
}

void GSP::writeLineInfo(const string &name, const string& fileLocation) {
    if (Lines_[name] == nullptr) throw LineDoesntExist();
    Lines_[name]->writeInfo(fileLocation);
}

