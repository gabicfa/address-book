#include <gtest/gtest.h>
#include "AddressBook.h"

TEST(AddressBookTest, AddContact) {
    AddressBook ab;
    Contact c1{"Jane", "Doe", "1234567890"};
    Contact c2{"Jane", "Zoe" };
    Contact c3{"John", "Doe", "9999999999"};

    ab.addContact(c1);
    ab.addContact(c2);
    ab.addContact(c3);

    std::vector<Contact> cFirstNames = ab.getContactsByFirstName();
    std::vector<Contact> cLastNames = ab.getContactsByLastName();
    ASSERT_EQ(cFirstNames.size(), 3);
    ASSERT_EQ(cLastNames.size(), 3);
}

TEST(AddressBookTest, RemoveContact) {
    AddressBook ab;
    Contact c1{"John", "Doe", "1234567890"};
    Contact c2{"Alice", "Smith", "9999999999"};

    ab.addContact(c1);
    ab.addContact(c2);

    ab.removeContact(c2);

    std::vector<Contact> cFirstNames = ab.getContactsByFirstName();
    ASSERT_EQ(cFirstNames.size(), 1);
    ASSERT_EQ(cFirstNames[0].firstName, "john");

    std::vector<Contact> cLastNames = ab.getContactsByLastName();
    ASSERT_EQ(cLastNames.size(), 1);
    ASSERT_EQ(cLastNames[0].firstName, "john");
}

TEST(AddressBookTest, RemoveContactWithSameNameButDifferentPhones) 
{
    AddressBook ab;
    Contact c1{"John", "Doe", "1234567890"};
    Contact c2{"John", "Doe"};
    Contact c3{"John", "Smith"};

    ab.addContact(c1);
    ab.addContact(c2);
    ab.addContact(c3);

    ab.removeContact(c2);

    std::vector<Contact> cFirstNames = ab.getContactsByFirstName();
    ASSERT_EQ(cFirstNames.size(), 2);
    ASSERT_EQ(cFirstNames[0].phoneNumber, "1234567890");
    ASSERT_EQ(cFirstNames[1].lastName, "smith");

    std::vector<Contact> cLastNames = ab.getContactsByLastName();
    ASSERT_EQ(cLastNames.size(), 2);
    ASSERT_EQ(cLastNames[0].phoneNumber, "1234567890");
    ASSERT_EQ(cLastNames[1].lastName, "smith");
}