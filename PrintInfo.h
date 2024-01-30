#ifndef PROJEKTNI_ZADATAK_PRINTINFO_H
#define PROJEKTNI_ZADATAK_PRINTINFO_H


#include "GSP.h"
#include "Command.h"

class PrintInfo : public Command{
    void command(GSP* gsp) override;
};


#endif //PROJEKTNI_ZADATAK_PRINTINFO_H
