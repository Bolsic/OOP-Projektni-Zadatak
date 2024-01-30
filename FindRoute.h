#ifndef PROJEKTNI_ZADATAK_FINDROUTE_H
#define PROJEKTNI_ZADATAK_FINDROUTE_H

#include <map>
#include "Line.h"
#include "Station.h"
#include "GSP.h"
#include "Route.h"

class GSP;

class FindRoute {
public:
    virtual Route* findRoute(GSP* gsp, int startId, int endId) = 0;
};


class FindShortestRoute : public FindRoute{
public:
    Route* findRoute (GSP* gsp, int startId, int endId) override;
};

class FindSimplestRoute : public FindRoute{
public:
    Route* findRoute (GSP* gsp, int startId, int endId) override;
};

class FindTouristRoute : public FindRoute{
public:
    Route* findRoute (GSP* gsp, int startId, int endId) override;
};

#endif //PROJEKTNI_ZADATAK_FINDROUTE_H
