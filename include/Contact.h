#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;

        struct CompareContactsFirstNames {
            bool operator()(const Contact& a, const Contact& b) const {
                if (a.firstName == b.firstName) {
                    return a.lastName < b.lastName;
                }
                return a.firstName < b.firstName;
            }
        };

        struct CompareContactsLastNames {
            bool operator()(const Contact& a, const Contact& b) const {
                if (a.lastName == b.lastName) {
                    return a.firstName < b.firstName;
                }
                return a.lastName < b.lastName;
            }
        };

        Contact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber = "");
        bool operator==(const Contact& other) const;
    };

#endif //CONTACT_H
