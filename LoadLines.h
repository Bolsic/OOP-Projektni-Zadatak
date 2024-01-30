#ifndef PROJEKTNI_ZADATAK_LOADLINES_H
#define PROJEKTNI_ZADATAK_LOADLINES_H

#pragma once
#include "Command.h"

class LoadLines : public Command{
public:
    void command(GSP* gsp) override;
private:
    string defaultFileLocation = "../test/linije.txt";
};


#endif //PROJEKTNI_ZADATAK_LOADLINES_H
