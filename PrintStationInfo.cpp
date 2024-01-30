#include "PrintStationInfo.h"

void PrintStationInfo::command(GSP* gsp) {
    cout << "Unesite šifru stajališta:" << endl;
    int id;
    cin >> id;
    gsp->printStationInfo(id);
    cout << endl << endl;
}
