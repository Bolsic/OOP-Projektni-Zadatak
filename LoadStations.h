#ifndef PROJEKTNI_ZADATAK_LOADSTATIONS_H
#define PROJEKTNI_ZADATAK_LOADSTATIONS_H

#pragma once
#include "Command.h"

class LoadStations : public Command{
public:
    void command(GSP* gsp) override;
private:
    string defaultFileLocation = "../test/stajalista.txt";
};


#endif //PROJEKTNI_ZADATAK_LOADSTATIONS_H
