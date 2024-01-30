#include "Line.h"

void Line::printInfo() {
    this->printName();
    cout << " ";
    this->printRange();
    cout << endl;
    this->printStations();
}

void Line::printRange() {
    Stations_[0]->printName();
    cout << "->";
    Stations_[size(Stations_) - 1]->printName();
}

void Line::printStations() {
    for (auto station : Stations_){
        station->printIdx();
        cout << " ";
        station->printName();
        if (station->important_) cout << " [!]";
        cout << endl;
    }
}


