#ifndef PROJEKTNI_ZADATAK_MAKECONNECTIONS_H
#define PROJEKTNI_ZADATAK_MAKECONNECTIONS_H

#pragma once
#include "Command.h"
#include "GSP.h"
#include <fstream>
#include <iostream>
#include <sstream>

class GSP;

class MakeConnections : public Command {
public:
    void command(GSP* gsp) override;
};


#endif //PROJEKTNI_ZADATAK_MAKECONNECTIONS_H
