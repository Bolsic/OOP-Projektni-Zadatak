#ifndef PROJEKTNI_ZADATAK_COMMAND_H
#define PROJEKTNI_ZADATAK_COMMAND_H

#pragma once
#include "GSP.h"

class Command {
public:
    virtual void command(GSP* gsp) = 0;
    virtual ~Command() = default;
};


#endif //PROJEKTNI_ZADATAK_COMMAND_H
