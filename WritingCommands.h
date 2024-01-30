#ifndef PROJEKTNI_ZADATAK_WRITINGCOMMANDS_H
#define PROJEKTNI_ZADATAK_WRITINGCOMMANDS_H

#include "Command.h"

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


#endif //PROJEKTNI_ZADATAK_WRITINGCOMMANDS_H
