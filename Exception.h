#ifndef EX4_Exceptions_H
#define EX4_Exceptions_H
#include <stdexcept>
#include <string>

class InvalidNameInput : public std::runtime_error {
public:
    InvalidNameInput(const std::string& what): std::runtime_error(what) {}

};

class DeckFileNotFound : public std::runtime_error {
public:
    DeckFileNotFound():
     std::runtime_error("Deck File Error: File not found") {} 
};

class DeckFileFormatError : public std::runtime_error {
public:
    DeckFileFormatError(int lineNum):
     std::runtime_error("Deck File Error: File format error in line " + std::to_string(lineNum)) {} 
};

class DeckFileInvalidSize : public std::runtime_error {
public:
    DeckFileInvalidSize():
     std::runtime_error("Deck File Error: Deck size is invalid") {} 
};

class InvalidMonsterName : public std::runtime_error {
public:
    InvalidMonsterName(const std::string& cardName):
     std::runtime_error("Invalid monster name: " + cardName) {} 
};

#endif //EX4_Exceptions_H