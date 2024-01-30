#include "PrintStationInfo.h"
#include "PrintLineInfo.h"


void PrintLineInfo::command(GSP *gsp) {
    cout << "Unesite šifru stajališta:" << endl;
    string name;
    cin >> name;
    gsp->printLineInfo(name);
    cout << endl;
}
