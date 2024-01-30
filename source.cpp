#include <iostream>
#include "GSPSystem.h"
#include "Exceptions.h"
int main() {
    auto* System = new GSPSystem;

    try {
        cout << "START" << endl;
        System->openTerminal();
    }
    catch (Exception ex){
        delete System;
        cout << endl << "ERROR: " << ex.what() << endl << endl;
    }
    return 0;
}

