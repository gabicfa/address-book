#include "AddressBook.h"
#include <vector>
#include <iostream>

auto FIRST = "FIRST";
auto LAST = "LAST";

void AddressBook::addContact(const Contact& contact) 
{
    m_contactsByFirstName.insert(std::make_pair(contact.firstName, contact));
    m_contactsByLastName.insert(std::make_pair(contact.lastName, contact));
}

void AddressBook::removeContact(const Contact& contact) 
{
    std::string lowerFirstName = contact.firstName;
    std::string lowerLastName = contact.lastName;
    std::transform(lowerFirstName.begin(), lowerFirstName.end(), lowerFirstName.begin(), ::tolower);
    std::transform(lowerLastName.begin(), lowerLastName.end(), lowerLastName.begin(), ::tolower);
    removeContactFromMultimap(FIRST, contact);
    removeContactFromMultimap(LAST, contact);
}


void AddressBook::removeContactFromMultimap(const std::string& type, const Contact& contact) 
{
    auto& contacts = (type == LAST) ? m_contactsByLastName : m_contactsByFirstName;
    auto range = (type == LAST) ? m_contactsByLastName.equal_range(contact.lastName) : m_contactsByFirstName.equal_range(contact.firstName);
    for (auto it = range.first; it != range.second; ) {
        bool isMatchingContact = it->second.firstName == contact.firstName && 
                                   it->second.lastName == contact.lastName && 
                                   it->second.phoneNumber == contact.phoneNumber;
        if (isMatchingContact) {
            it = contacts.erase(it++);
        } else {
            ++it;
        }
    }
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
