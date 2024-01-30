#ifndef PROJEKTNI_ZADATAK_LINE_H
#define PROJEKTNI_ZADATAK_LINE_H

#pragma once
#include <utility>
#include "Station.h"

class Station;

using namespace std;

class Line {
public:

    explicit Line(string name){name_ = std::move(name);};
    ~Line() = default;
    void addStation(Station* station){Stations_.push_back(station);};
    void writeInfo(const string& fileLocation);
    string getName() {return name_;};
    vector<Station*> getStations() {return Stations_;};

protected:

    void printName(){cout << name_;};
    void printRange();
    void printStations();

private:

    string name_;
    vector<Station*> Stations_;

};


#endif //PROJEKTNI_ZADATAK_LINE_H
