#include "GSPSystem.h"
#include "LoadStations.h"
#include "LoadLines.h"
#include "MakeConnections.h"
#include "PrintInfo.h"
#include "PrintStationInfo.h"
#include "PrintLineInfo.h"
#include "PrintRouteInterface.h"

GSPSystem::GSPSystem() {
    loaded_=false;
    gsp_ = nullptr;
}

void GSPSystem::loadingInterface() {
    bool run = true;
    while (run) {

        cout << "   1. Učitavanje podataka o mreži gradskog prevoza" << endl;
        cout << "   0. Kraj rada" << endl;

        int command;
        cin >> command;

        switch (command) {
            case 1: // LOAD

                // TODO: Delete old GSP object
                gsp_ = new GSP;

                cout << "Unesite lokacije fajlova za stajališta i linije" << endl;
                cout << "Ili pritisnite ENTER za podrazumevane fajlove" << endl;
                this->cmd = new LoadStations();
                this->cmd->command(gsp_);
                delete this->cmd;

                this->cmd = new LoadLines();
                this->cmd->command(gsp_);
                delete this->cmd;

                // Making connections
                this->cmd = new MakeConnections();
                this->cmd->command(gsp_);
                delete this->cmd;

                cout << "Mreža gradskog prevoza je uspešno učitana!" << endl;
//                cout << "The data you loaded:" << endl;
//                this->cmd = new PrintInfo();
//                this->cmd->command(gsp_);
//                delete this->cmd;

                loaded_ = true;
                run = false;
                break;

            case 0:
                run = false;

                //TODO: DELETE EVERYTHING

                break;

            default:
                cout << "Uneli ste nepostojeću opciju, molimo Vas pokušajte ponovo." << endl;
                break;
        }
    }
}

void GSPSystem::userInterface() {
    bool run = true;
    while(run) {
        cout << "   1. Prikaz informacija o stajalištu" << endl;
        cout << "   2. Prikaz informacija o liniji gradskog prevoza" << endl;
        cout << "   3. Pronalazak putanje između dva stajališta" << endl;
        cout << "   0. Kraj rada" << endl;

        int command;
        cin >> command;

        switch (command) {
            case 1:
                this->cmd = new PrintStationInfo;
                this->cmd->command(gsp_);
                delete this->cmd;

                break;

            case 2:
                this->cmd = new PrintLineInfo;
                this->cmd->command(gsp_);
                delete this->cmd;

                break;

            case 3:

                // TODO: Putanja izmedju stajalista
                this->cmd = new PrintRouteInterface();
                this->cmd->command(gsp_);
                delete this->cmd;

                break;

            case 0:
                run = false;

                // TODO: DELETE EVERYTHING
                break;

            default:
                cout << "Uneli ste nepostojeću opciju, molimo Vas pokušajte ponovo." << endl;
                break;
        }
    }

}

void GSPSystem::openTerminal() {
    cout << "-----------------------------" << endl
         << "Dobrodošli u Basic GSP!" << endl
         << "-----------------------------" << endl
         << "Molimo Vas, odaberite opciju:" << endl << endl;

    this->loadingInterface();

    if (loaded_) this->userInterface();

}







