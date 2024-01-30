#ifndef PROJEKTNI_ZADATAK_GSP_H
#define PROJEKTNI_ZADATAK_GSP_H

#pragma once
#include "Station.h"
#include "Line.h"
#include "FindRoute.h"
#include "Route.h"
#include <string>
#include <map>

class FindRoute;

using namespace std;

class GSP {
public:

    GSP()= default;
    void addStation(int id, const string& name, bool important);
    Line* addLine(const string& name);
    Station* getStation(int id) {return Stations_[id];};
    Line* getLine(const string& name) {return Lines_[name];};

    vector<Route*> getAllRoutes(int startId, int endId){
        return Stations_[startId]->findRoutesToStation(Stations_[endId]);
    };

    void printAllRoutesToFrom(int start, int destination);
    void printStationInfo(int id){Stations_[id]->printInfo();};
    void printLineInfo(const string& name){Lines_[name]->printInfo();};
    int getNumOfImpStations();

    friend class MakeConnections;
    friend class WriteRouteInterface;
    friend class PrintInfo;

private:

    // Stations_ are pairs of Station object pointers and their indexes
    map<int, Station*> Stations_;
    // Stations_ are pairs of Station object pointers and their names
    map<string, Line*> Lines_;
    FindRoute* cmd_;
};


#endif //PROJEKTNI_ZADATAK_GSP_H
