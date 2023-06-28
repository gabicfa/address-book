#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <string>
#include <set>
#include "Contact.h"

class AddressBook {
    public:
        void addContact(const Contact& contact);
        void removeContact(const Contact& contact);
        void removeContactFromFirstNameSet(const Contact& contact); 
        void removeContactFromLastNameSet(const Contact& contact);
        std::vector<Contact> getContactsByFirstName() const;
        std::vector<Contact> getContactsByLastName() const;
    private:
        std::multiset<Contact, CompareContactsLastNames> m_contactsByFirstName;
        std::multiset<Contact, CompareContactsFirstNames> m_contactsByLastName;
};

#endif
