#include "GSPSystem.h"
#include "LoadStations.h"
#include "LoadLines.h"
#include "MakeConnections.h"
#include "PrintInfo.h"
#include "Exceptions.h"


GSPSystem::GSPSystem() {
    loaded_=false;
    gsp_ = nullptr;
}

GSPSystem::~GSPSystem() {
    delete gsp_;
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
                try {
                    delete gsp_;
                    gsp_ = new GSP;

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

                    loaded_ = true;
                    run = false;
                    break;
                }
                catch (FileNotFount ex){
                    cout << endl << "ERROR: " << ex.what() << endl << endl;
                    break;
                }
            case 0:
                run = false;

                cout << "Doviđenja!" << endl;
                run = false;
                delete this;
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
                this->cmd = new WriteStationInfo;
                this->cmd->command(gsp_);
                delete this->cmd;

                break;

            case 2:
                this->cmd = new WriteLineInfo;
                this->cmd->command(gsp_);
                delete this->cmd;

                break;

            case 3:

                // TODO: Putanja izmedju stajalista
                this->cmd = new WriteRouteInterface();
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









