#ifndef PROJEKTNI_ZADATAK_STATION_H
#define PROJEKTNI_ZADATAK_STATION_H

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Line.h"
//#include "Route.h"

using namespace std;

class Line;
class Route;

class Station {
public:

    Station(int idx, string name, bool important);
    int getIdx() const {return idx_;};
    string getName() {return name_;};
    bool isImportant() const{return important_;};
    void printInfo();

    void addConnection(Station* station, Line* line);
    vector<Route*> findRoutesToStation(Station* destination);

    friend class Line;

protected:

    void printIdx() const {cout << idx_;};
    void printName() {cout << name_;};
    void printLines();
    void printAdjacentImportantStations();
    bool connectionExists(Station* station, Line* line);
    bool lineConnectionExists(Station* station, Line* line);

private:

    int idx_;
    string name_;
    bool important_;
    // connections are pairs of pointers to stations and a lists of lines that lead there
    map<Station*, vector<string>> connections_;
    // same as connections just for important adjacent stations
    map<Station*, vector<string>> importantConnections_;
    // Vector of all the lines that go through the station
    vector<Line*> Lines_;
    
};


#endif //PROJEKTNI_ZADATAK_STATION_H
