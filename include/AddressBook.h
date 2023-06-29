#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <string>
#include <set>
#include "Contact.h"

class AddressBook {
    public:
        AddressBook();
        ~AddressBook();
        void addContact(const Contact& contact);
        void removeContact(const Contact& contact);

        // Remove a contact from the first name set
        void removeContactFromFirstNameSet(const Contact& contact);

        // Remove a contact from the last name set
        void removeContactFromLastNameSet(const Contact& contact);

        // Get all contacts sorted by first name
        std::vector<Contact> getContactsByFirstName() const;

        // Get all contacts sorted by last name
        std::vector<Contact> getContactsByLastName() const;

        // Get contacts matching a search name
        std::vector<Contact> getContactsByName(const std::string& searchName) const;

    private:
        std::multiset<Contact, Contact::CompareContactsFirstNames> m_contactsByFirstName;
        std::multiset<Contact, Contact::CompareContactsLastNames> m_contactsByLastName;
};

#endif
