#ifndef PROJEKTNI_ZADATAK_LOADINGCOMMANDS_H
#define PROJEKTNI_ZADATAK_LOADINGCOMMANDS_H

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

class LoadLines : public Command{
public:
    void command(GSP* gsp) override;
private:
    string defaultFileLocation = "../test/linije.txt";
};

class LoadStations : public Command{
public:
    void command(GSP* gsp) override;
private:
    string defaultFileLocation = "../test/stajalista.txt";
};


#endif //PROJEKTNI_ZADATAK_LOADINGCOMMANDS_H
