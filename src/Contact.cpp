#include <stdexcept>
#include <cctype>
#include <algorithm>
#include "Contact.h"
#include "StringUtils.h"

Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &phoneNumber)
{
    if (firstName.empty() || lastName.empty()) {
        throw std::invalid_argument("First name and last name must be provided. You entered firstName: " 
        + firstName + ", lastName: " + lastName);
    }
    
    if (!phoneNumber.empty() && !std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
        throw std::invalid_argument("Phone number must only contain digits. You entered: " + phoneNumber);
    }

    this->firstName = utils::toLowerCase(firstName);
    this->lastName = utils::toLowerCase(lastName);

    this->phoneNumber = phoneNumber;
}
bool Contact::operator==(const Contact& other) const 
{
    return firstName == other.firstName &&
            lastName == other.lastName &&
            phoneNumber == other.phoneNumber;
}

