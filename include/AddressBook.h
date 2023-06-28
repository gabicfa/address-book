#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <string>
#include <map>
#include "Contact.h"

class AddressBook {
    public:
        void addContact(const Contact& contact);
        std::vector<Contact> getContactsByFirstName() const;
        std::vector<Contact> getContactsByLastName() const;
    private:
        std::multimap<std::string, Contact> m_contactsByFirstName;
        std::multimap<std::string, Contact> m_contactsByLastName;
};

#endif
