cmake_minimum_required(VERSION 3.26)
project(Projektni_zadatak)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projektni_zadatak
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
        Exceptions.h
        source.cpp
        WritingCommands.cpp
        WritingCommands.h
        LoadingCommands.cpp
        LoadingCommands.h

)
