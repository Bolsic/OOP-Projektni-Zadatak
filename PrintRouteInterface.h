#ifndef PROJEKTNI_ZADATAK_PRINTROUTEINTERFACE_H
#define PROJEKTNI_ZADATAK_PRINTROUTEINTERFACE_H


#include "Command.h"
#include "GSP.h"

class PrintRouteInterface : public Command{
public:
    void command(GSP* gsp) override;
    static void printRoute(Route* route);
};


#endif //PROJEKTNI_ZADATAK_PRINTROUTEINTERFACE_H
