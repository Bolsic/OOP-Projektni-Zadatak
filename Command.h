#ifndef PROJEKTNI_ZADATAK_COMMAND_H
#define PROJEKTNI_ZADATAK_COMMAND_H

#pragma once
#include "GSP.h"

class Command {
public:
    virtual void command(GSP* gsp) = 0;
};

class WriteStationInfo : public Command{
public:
    void command(GSP* gsp) override;
};

class WriteLineInfo : public Command{
public:
    void command(GSP* gsp) override;

};

class WriteRouteInterface : public Command{
public:
    void command(GSP* gsp) override;
    static void writeRoute(Route* route);
};

#endif //PROJEKTNI_ZADATAK_COMMAND_H
