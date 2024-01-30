#ifndef PROJEKTNI_ZADATAK_ROUTE_H
#define PROJEKTNI_ZADATAK_ROUTE_H

#include "Station.h"

class Station;

class Route{
public:
    Route(Station* beginningStation, const string& lineName, bool isImportant){
        stations_.push_back(beginningStation);
        lines_.push_back(lineName);
        numOfStations = 1;
        numOfLineHops = 0;
        numOfImpStations = isImportant ? 1 : 0;
    };

    // Copy constructor
    Route(const Route& other) = default;

    // Assignment operator
    Route& operator=(const Route& other) {
        if (this != &other) { // Check for self-assignment
            numOfLineHops = other.numOfLineHops;
            numOfStations = other.numOfStations;
            numOfImpStations = other.numOfImpStations;
            stations_ = other.stations_;
            lines_ = other.lines_;
        }
        return *this;
    }

//    ~Route() {delete this;};

    void addStation(Station* station, const string& lineName, bool isImportant){
        if (lineName != lines_.back() && lines_.back() != "none") numOfLineHops++;
        stations_.push_back(station);
        lines_.push_back(lineName);
        numOfStations++;
        if (isImportant) numOfImpStations++;
    };

    void addLineHop(){numOfLineHops++;};

    int numOfLineHops;
    int numOfStations;
    int numOfImpStations;
    vector<Station*> stations_;
    vector<string> lines_;
};


#endif //PROJEKTNI_ZADATAK_ROUTE_H
