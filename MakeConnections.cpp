#include "MakeConnections.h"

void MakeConnections::command(GSP *gsp) {
    for (const auto& pair : gsp->Lines_){

        // line is the current line
        Line* line = pair.second;
        // stations is a list of stations that the current line goes through
        vector<Station*> stations = pair.second->getStations();

        // Iterate over the stations the given line goes through
        for (auto it = stations.begin(); it != stations.end(); it = next(it, 1)){
            // Add a connection to the next
            if (it == prev(stations.end(), 1)) (*it)->addConnection(*stations.begin(), line);
            else (*it)->addConnection(*next(it, 1), line);
            // Add a connection to the previous station
            if (it == stations.begin()) (*it)->addConnection(*prev(stations.end()), line);
            else (*it)->addConnection(*prev(it, 1), line);
        }
    }
}
