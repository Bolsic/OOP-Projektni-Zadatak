#include "Line.h"
#include <iostream>
#include <fstream>

void Line::writeInfo(const string& fileLocation) {
    ofstream file(fileLocation);

    file << name_ << " ";

    file << Stations_.front()->getName();
    file << "->";
    file << Stations_.back()->getName() << endl;

    for (auto station : Stations_){
        file << station->getIdx() << " " << station->getName();
        if (station->important_) file << " [!]";
        file << endl;
    }
}



