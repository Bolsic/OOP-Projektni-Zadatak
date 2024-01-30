#include "PrintInfo.h"

void PrintInfo::command(GSP *gsp) {
    cout << endl << "STATIONS" << endl << endl;
    for (auto pair : gsp->Stations_){
        pair.second->printInfo();
        cout << endl;
    }

    cout << endl << "LINES" << endl << endl;
    for (auto pair : gsp->Lines_){
        pair.second->printInfo();
        cout << endl;
    }
}
