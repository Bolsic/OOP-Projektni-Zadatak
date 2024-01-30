cmake_minimum_required(VERSION 3.26)
project(Projektni_zadatak)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projektni_zadatak
        main.cpp
        Route.h
        Station.h
        Station.cpp
        Line.h
        Line.cpp
        FindRoute.h
        FindRoute.cpp
        GSP.h
        GSP.cpp
        GSPSystem.h
        GSPSystem.cpp
        Command.h
        Command.cpp
        LoadStations.h
        LoadStations.cpp
        LoadLines.h
        LoadLines.cpp
        MakeConnections.h
        MakeConnections.cpp
        PrintInfo.h
        PrintInfo.cpp

)
