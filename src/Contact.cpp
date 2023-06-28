#include <stdexcept>
#include <cctype>
#include <algorithm>
#include "Contact.h"

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &phoneNumber)
{
    if (firstName.empty() || lastName.empty()) {
        throw std::invalid_argument("First name and last name must be provided. You entered firstName: " 
        + firstName + ", lastName: " + lastName);
    }
    
    if (!phoneNumber.empty() && !std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
        throw std::invalid_argument("Phone number must only contain digits. You entered: " + phoneNumber);
    }

    this->firstName = firstName;
    std::transform(this->firstName.begin(), this->firstName.end(), this->firstName.begin(), ::tolower);

    this->lastName = lastName;
    std::transform(this->lastName.begin(), this->lastName.end(), this->lastName.begin(), ::tolower);

    this->phoneNumber = phoneNumber;
}

