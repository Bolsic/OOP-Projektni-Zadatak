#include "PrintRouteInterface.h"
#include "Route.h"
//#include "FindShortestRoute.h"
#include <map>

void PrintRouteInterface::printRoute(Route *route) {
    cout << "->" << route->lines_[1] << endl;
    string currLine = route->lines_[1];
    for(int idx = 0; idx < route->numOfStations; idx++){
        if ((route->lines_[idx] != currLine) && (route->lines_[idx] != "none")){
            cout << endl << currLine << "->" << route->lines_[idx] << endl;
            cout << route->stations_[idx-1]->getIdx();
            currLine = route->lines_[idx];
        }
        if (idx != 0) cout << " ";
        cout << route->stations_[idx]->getIdx();
    }

}

void PrintRouteInterface::command(GSP* gsp) {
    cout << "Kakvu putanju želite naći?" << endl;
    cout << "   1. Najkraću putanju (najmanje stajališta)" << endl;
    cout << "   2. Putanju sa najmanje presedanja" << endl;
    cout << "   3. Turističku putanju (obilazi svr važne gradske destinacije)" << endl;
    int choice;
    cin >> choice;

    Route* route;
    bool run = true;

    while(run) {
        switch (choice) {
            case 1:

                gsp->cmd_ = new FindShortestRoute;

                run = false;
                break;

            case 2:
                gsp->cmd_ = new FindSimplestRoute;

                run = false;
                break;

            case 3:
                gsp->cmd_ = new FindTouristRoute;

                run = false;
                break;

            case 0:
                int start, end;
                cin >> start;
                cin >> end;
                gsp->printAllRoutesToFrom(start, end);

                run = false;
                break;

            default:
                cout << "Uneli ste nepostojeću opciju, molimo Vas pokušajte ponovo." << endl;
                return;
        }
    }
    cout << "Unesite šivru stajališta od kog krećete" << endl;
    int startId;
    cin >> startId;

    cout << "Unesite šivru stajališta do kog idete" << endl;
    int endId;
    cin >> endId;

    route = gsp->cmd_->findRoute(gsp, startId, endId);
    delete gsp->cmd_;

    this->printRoute(route);
    cout << endl;
}


