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
        std::vector<Contact> getContactsByName(const std::string& searchName) const;
    private:
        std::multiset<Contact, Contact::CompareContactsFirstNames> m_contactsByFirstName;
        std::multiset<Contact, Contact::CompareContactsLastNames> m_contactsByLastName;
};

#endif
