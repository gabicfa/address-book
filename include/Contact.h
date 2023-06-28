#ifndef CONTACT_H
#define CONTACT_H

#include <string>

struct Contact {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;

    Contact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber = "");
};

#endif //CONTACT_H
