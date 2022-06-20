#ifndef EX4_Exceptions_H
#define EX4_Exceptions_H
#include <stdexcept>
#include <string>

class MtmchinException : public std::runtime_error {
public:
    MtmchinException(const std::string& what): std::runtime_error(what) {}
};

class InvalidNameInput : public MtmchinException {
public:
    InvalidNameInput(const std::string& what): MtmchinException(what) {}
};

class DeckFileNotFound : public MtmchinException {
public:
    DeckFileNotFound():
     MtmchinException("Deck File Error: File not found") {} 
};

class DeckFileFormatError : public MtmchinException {
public:
    DeckFileFormatError(int lineNum):
     MtmchinException("Deck File Error: File format error in line " + std::to_string(lineNum)) {} 
};

class DeckFileInvalidSize : public MtmchinException {
public:
    DeckFileInvalidSize():
     MtmchinException("Deck File Error: Deck size is invalid") {} 
};

class InvalidMonsterName : public MtmchinException {
public:
    InvalidMonsterName(const std::string& cardName):
     MtmchinException("Invalid monster name: " + cardName) {} 
};

#endif //EX4_Exceptions_H