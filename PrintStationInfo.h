#ifndef PROJEKTNI_ZADATAK_PRINTSTATIONINFO_H
#define PROJEKTNI_ZADATAK_PRINTSTATIONINFO_H

#pragma once
#include "Command.h"
#include "GSP.h"

class PrintStationInfo : public Command{
public:
    void command(GSP* gsp) override;
};


#endif //PROJEKTNI_ZADATAK_PRINTSTATIONINFO_H
