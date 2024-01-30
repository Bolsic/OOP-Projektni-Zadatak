#ifndef PROJEKTNI_ZADATAK_PRINTLINEINFO_H
#define PROJEKTNI_ZADATAK_PRINTLINEINFO_H

#pragma once
#include "Command.h"

class PrintLineInfo : public Command{
public:
    void command(GSP* gsp) override;

};


#endif //PROJEKTNI_ZADATAK_PRINTLINEINFO_H
