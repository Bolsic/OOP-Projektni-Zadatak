#ifndef PROJEKTNI_ZADATAK_EXCEPTIONS_H
#define PROJEKTNI_ZADATAK_EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

using namespace std;

class Exception : public exception {
public:

    Exception(){ this->msg = "Error";};
    explicit Exception(const string& msg){ this->msg = msg;};
    string what() {return this->msg;};

private:
    string msg;
};

class FileNotFount : public Exception {
public:

    FileNotFount() : Exception("Fajl koji ste naveli ne postoji!") {}
};

class FilesNotLoaded : public Exception {
public:

    FilesNotLoaded() : Exception("Fajlovi nisu učitani!") {}
};

class StationDoesntExist : public Exception {
public:

    StationDoesntExist() : Exception("Tražena stanica ne postoji!") {}
};

class LineDoesntExist : public Exception {
public:

    LineDoesntExist() : Exception("Tražena linija ne postoji!") {}
};


#endif //PROJEKTNI_ZADATAK_EXCEPTIONS_H
