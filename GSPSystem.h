#ifndef PROJEKTNI_ZADATAK_GSPSYSTEM_H
#define PROJEKTNI_ZADATAK_GSPSYSTEM_H

#pragma once
#include "GSP.h"
#include "Command.h"

enum command {LOAD, printRoutes, SHORTEST_ROUTE, QUICKEST_ROUTE, IMPORTANT_ROUTE};
static std::map<std::string, command> choose { {"LOAD", LOAD}, {"print", printRoutes}};

class GSPSystem{
public:

    GSPSystem();
    ~GSPSystem();
    void openTerminal();

private:

    void loadingInterface();
    void userInterface();

    GSP* gsp_;
    Command* cmd;
    bool loaded_;
};

#endif //PROJEKTNI_ZADATAK_GSPSYSTEM_H
