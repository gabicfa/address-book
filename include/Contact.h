#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
    public:
        Contact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber = "");
        ~Contact();
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;

        struct CompareContactsFirstNames {
            bool operator()(const Contact& a, const Contact& b) const {
                // Compare contacts by first name, and if equal, by last name
                if (a.firstName == b.firstName) {
                    return a.lastName < b.lastName;
                }
                return a.firstName < b.firstName;
            }
        };

        struct CompareContactsLastNames {
            bool operator()(const Contact& a, const Contact& b) const {
                // Compare contacts by last name, and if equal, by first name
                if (a.lastName == b.lastName) {
                    return a.firstName < b.firstName;
                }
                return a.lastName < b.lastName;
            }
        };

        // Overload the equality operator
        bool operator==(const Contact& other) const;
    };

#endif
