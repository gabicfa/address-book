#include "AddressBook.h"
#include <vector>

void AddressBook::addContact(const Contact& contact) 
{
    m_contactsByFirstName.insert(std::make_pair(contact.firstName, contact));
    m_contactsByLastName.insert(std::make_pair(contact.lastName, contact));
}

std::vector<Contact> AddressBook::getContactsByFirstName() const
{
    std::vector<Contact> contacts;
    for (const auto& pair : m_contactsByFirstName) 
    {
        contacts.push_back(pair.second);
    }
    return contacts;
}

std::vector<Contact> AddressBook::getContactsByLastName() const 
{
    std::vector<Contact> contacts;
    for (const auto& pair : m_contactsByLastName) 
    {
        contacts.push_back(pair.second);
    }
    return contacts;
}
