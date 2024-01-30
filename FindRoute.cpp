#include "FindRoute.h"


Route* FindShortestRoute::findRoute(GSP *gsp, int startId, int endId) {
    Route* finalRoute;
    auto allRoutes = gsp->getAllRoutes(startId, endId);
    vector<Route*> shortestRoutes;

    // The first route is always the shortest
    int length = allRoutes.front()->numOfStations;

    // Gather all the routes of the same length as the shortest one
    for (const auto& route : allRoutes){
        if (route->numOfStations <= length){
            shortestRoutes.push_back(route);
        }else break;
    }

    // Out of the gathered routes, choose one with the fewest line hops
    int minHops = shortestRoutes.front()->numOfLineHops;
    finalRoute = shortestRoutes.front();
    for (const auto& route : shortestRoutes){
        if (route->numOfLineHops < minHops){
            finalRoute = route;
            minHops = route->numOfLineHops;
        }
    }

    return finalRoute;
}

Route* FindSimplestRoute::findRoute(GSP *gsp, int startId, int endId) {

    auto allRoutes = gsp->getAllRoutes(startId, endId);
    vector<Route*> simplestRoutes;

    // Out of all the routes, find the lowes number of line hops
    int minHops = allRoutes.front()->numOfLineHops;
    for (const auto& route : allRoutes){
        if (route->numOfLineHops < minHops) minHops = route->numOfLineHops;
    }
    for (const auto& route : allRoutes){
        // The first route found is the shortest one
        if (route->numOfLineHops <= minHops) return route;
    }

    // TODO: Error of some kind
    return allRoutes.front();
}

Route *FindTouristRoute::findRoute(GSP *gsp, int startId, int endId) {
    int targetNum = gsp->getNumOfImpStations();

    auto allRoutes = gsp->getAllRoutes(startId, endId);
    vector<Route*> impRoutes;

    // Get all the routes that go through the important stations
    for (const auto& route : allRoutes){
        if (route->numOfImpStations == targetNum) impRoutes.push_back(route);
    }

    cout << "Da li želite da ruta bude:" << endl;
    cout << "   1. Što kraća" << endl;
    cout << "   2. Sadrži što manje presedanja" << endl;

    int choice;
    cin >> choice;

    if (choice == 1){
        return impRoutes.front();
    }else if(choice == 2){
        int minHops = impRoutes.front()->numOfLineHops;
        for (const auto& route : impRoutes){
            if (route->numOfLineHops < minHops) minHops = route->numOfLineHops;
        }
        for (const auto& route : impRoutes){
            if (route->numOfLineHops <= minHops) return route;
        }
    }
    // TODO: Wrong choice error

}
