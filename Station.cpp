#include "Station.h"
#include "Route.h"

#include <utility>
#include <algorithm>

using namespace std;

Station::Station(int idx, string name, bool important) {
    idx_ = idx;
    name_ = std::move(name);
    important_ = important;
}


void Station::printInfo() {
    this->printIdx();
    cout << " ";
    this->printName();
    cout << " [";
    this->printLines();
    cout << "] ";
    cout << "{! ";
    this->printAdjacentImportantStations();
    cout << "!}";
}


void Station::printLines() {
    for (auto it = Lines_.begin(); it != Lines_.end(); it = next(it, 1)) {
        cout << (*it)->getName();
        if (next(it, 1) != Lines_.end()) cout << " ";
    }
}


void Station::printAdjacentImportantStations() {

    for (const auto &pair: importantConnections_) {
        pair.first->printIdx();
        cout << " ";
    }
}


void Station::addConnection(Station* station, Line* line) {

    if (!lineConnectionExists(station, line)) {
        connections_[station].push_back(line->getName());
        if (find(Lines_.begin(), Lines_.end(), line) == Lines_.end())
            Lines_.push_back(line);
        if (station->isImportant())
            importantConnections_[station].push_back((line->getName()));

    }
}


bool Station::connectionExists(Station *station, Line* line) {

    auto it = connections_.find(station);
    if (it != connections_.end()) return true;

    return false;
}


bool Station::lineConnectionExists(Station *station, Line *line) {

    for (const auto& name : connections_[station]){
        if (name == line->getName()) return true;
    }

    return false;
}


bool didTheRoutePassHere(Route* route, Station* target){
    for (const auto &station : route->stations_) {
        if (station->getIdx() == target->getIdx()) return true;
    }
    return false;
}

// Find all routes from this station to the given destination
// This function returns all routes that aren't cyclical
// The function returns a vector that contains all the routes
// Every route is represented as a vector of pairs - station and the line that leads to it
vector<Route*> Station::findRoutesToStation(Station* destination) {
    vector<Route*> allRoutes;
    queue<Route*> routesQueue;



    // Start from the current station and no line leading to it
    auto* initialRoute = new Route(this, "none", important_);
    routesQueue.push(initialRoute);

    while(!routesQueue.empty()){
        // Set the next route for the process and remove it from the queue
        Route* currentRoute = routesQueue.front();
        routesQueue.pop();
        Station* currentStation = currentRoute->stations_.back();

        // If the current station is the destination finnish that route and add it to allRoutes
        if (currentStation == destination){
            allRoutes.push_back(currentRoute);
            continue;
        }

        // Go through the stations neighbors
        for(auto& neighbor : currentStation->connections_){
            Station* nextStation = neighbor.first;

            // Go through the lines that lead to the given neighbour
            for(const auto& lineName : neighbor.second){
                // Check if the route already went through the station to avoid circles
                if (!didTheRoutePassHere(currentRoute, nextStation)){
                    Route* newRoute = new Route(*currentRoute);
                    //newRoute = &newRouteObj;
                    newRoute->addStation(nextStation, lineName, nextStation->isImportant());
                    routesQueue.push(newRoute);
                }
            }
        }
    }

    return allRoutes;
}


