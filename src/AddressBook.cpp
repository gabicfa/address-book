#include "AddressBook.h"
#include <vector>
#include <iostream>

auto FIRST = "FIRST";
auto LAST = "LAST";



void AddressBook::addContact(const Contact& contact) {
    m_contactsByFirstName.insert(contact);
    m_contactsByLastName.insert(contact);
}

void AddressBook::removeContact(const Contact& contact) 
{
    std::string lowerFirstName = contact.firstName;
    std::string lowerLastName = contact.lastName;
    std::transform(lowerFirstName.begin(), lowerFirstName.end(), lowerFirstName.begin(), ::tolower);
    std::transform(lowerLastName.begin(), lowerLastName.end(), lowerLastName.begin(), ::tolower);
    removeContactFromFirstNameSet(contact);
    removeContactFromLastNameSet(contact);
}


void AddressBook::removeContactFromFirstNameSet(const Contact& contact) 
{
    auto range = m_contactsByFirstName.equal_range(contact);
    for (auto it = range.first; it != range.second; ) {
        if (*it == contact) {
            it = m_contactsByFirstName.erase(it);
        } else {
            ++it;
        }
    }
}

void AddressBook::removeContactFromLastNameSet(const Contact& contact) 
{
    auto range = m_contactsByLastName.equal_range(contact);
    for (auto it = range.first; it != range.second; ) {
        if (*it == contact) {
            it = m_contactsByLastName.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<Contact> AddressBook::getContactsByFirstName() const
{
    std::vector<Contact> contacts;
    for (const auto& contact : m_contactsByFirstName) 
    {
        contacts.push_back(contact);
    }
    return contacts;
}

std::vector<Contact> AddressBook::getContactsByLastName() const 
{
    std::vector<Contact> contacts;
    for (const auto& contact : m_contactsByLastName) 
    {
        contacts.push_back(contact);
    }
    return contacts;
}

