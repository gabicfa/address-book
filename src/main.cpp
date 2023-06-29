#include <iostream>
#include <vector>
#include "AddressBook.h"
#include "Contact.h"

int main() {
    // Creating an AddressBook instance
    AddressBook myAddressBook;

    // Creating some Contact instances
    Contact contact1("John", "Doe", "1234567890");
    Contact contact2("Jane", "Doe", "0987654321");
    Contact contact3("Daniel", "Craig", "1122334455");
    Contact contact4("Adam", "West", "1234123412");
    Contact contact5("Bruce", "Wayne", "");
    Contact contact6("Clark", "Joan", "");
    Contact contact7("Peter", "Parker", "3232323232");
    Contact contact8("John", "Stark", "3434343434");
    Contact contact9("Bruce", "Banner", "3535353535");
    Contact contact10("Diana", "Prince", "3636363636");
    Contact contact11("John", "Wayne", "");
    Contact contact12("Peter", "Stark", "3737373737");

    // Adding contacts to the address book
    myAddressBook.addContact(contact1);
    myAddressBook.addContact(contact2);
    myAddressBook.addContact(contact3);
    myAddressBook.addContact(contact4);
    myAddressBook.addContact(contact5);
    myAddressBook.addContact(contact6);
    myAddressBook.addContact(contact7);
    myAddressBook.addContact(contact8);
    myAddressBook.addContact(contact9);
    myAddressBook.addContact(contact10);
    myAddressBook.addContact(contact11);
    myAddressBook.addContact(contact12);

    // Getting all contacts sorted by first name
    auto contactsByFirstName = myAddressBook.getContactsByFirstName();
    std::cout << "Contacts sorted by first name:\n";
    for (const auto& contact : contactsByFirstName) {
        std::cout << contact.firstName << " " << contact.lastName << "\n";
    }

    // Getting all contacts sorted by last name
    auto contactsByLastName = myAddressBook.getContactsByLastName();
    std::cout << "\nContacts sorted by last name:\n";
    for (const auto& contact : contactsByLastName) {
        std::cout << contact.lastName << ", " << contact.firstName << "\n";
    }

    // Searching for contacts by name (e.g. "John")
    auto contactsByName = myAddressBook.getContactsByName("jo");
    std::cout << "\nContacts with the 'jo':\n";
    for (const auto& contact : contactsByName) {
        std::cout << contact.firstName << " " << contact.lastName << "\n";
    }
}