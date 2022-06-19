
////
#ifndef EX4_Exceptions_H
#define EX4_Exceptions_H
#include <stdexcept>

class InvalidDeckFile : public std::runtime_error {
public:
    InvalidDeckFile(const std::string& deckName):
     std::runtime_error("Invalid deck file name: " + deckName) {} 
};

class InvalidCardName : public std::runtime_error {
public:
    InvalidCardName(const std::string& cardName):
     std::runtime_error("Invalid card name: " + cardName) {} 
};

class InvalidMonsterName : public std::runtime_error {
public:
    InvalidMonsterName(const std::string& cardName):
     std::runtime_error("Invalid monster name: " + cardName) {} 
};

#endif //EX4_Exceptions_H
////