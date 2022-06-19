////
#ifndef EX4_Exceptions_H
#define EX4_Exceptions_H

#include <stdexcept>
#include <string>

class InvalidNameInput : public std::runtime_error {
public:

    InvalidNameInput(const std::string& what): std::runtime_error(what) {}

};

#endif // EX4_Exceptions_H
////