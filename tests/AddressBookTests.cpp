#include <gtest/gtest.h>
#include "AddressBook.h"

TEST(AddressBookTest, AddContact) {
    AddressBook ab;
    ab.addContact(Contact("Jane", "Doe", "1234567890"));
    ab.addContact(Contact("Jane", "Zoe"));
    ab.addContact(Contact("John", "Doe", "9999999999"));
    
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

TEST(AddressBookTests, RetrieveContactsSortedByFirstName) {
    AddressBook ab;
    ab.addContact(Contact("Jane", "Bath", "2345678901"));
    ab.addContact(Contact("Jane", "Arthur", "1234567890"));
    ab.addContact(Contact("Bob", "Arthur", "1234567890"));
    ab.addContact(Contact("Alice", "Johnson", "3456789012"));

    std::vector<Contact> contacts = ab.getContactsByFirstName();

    ASSERT_EQ(contacts.size(), 4);
    EXPECT_EQ(contacts[0].firstName, "alice");
    EXPECT_EQ(contacts[0].lastName, "johnson");
    EXPECT_EQ(contacts[1].firstName, "bob");
    EXPECT_EQ(contacts[1].lastName, "arthur");
    EXPECT_EQ(contacts[2].firstName, "jane");
    EXPECT_EQ(contacts[2].lastName, "arthur");
    EXPECT_EQ(contacts[3].firstName, "jane");
    EXPECT_EQ(contacts[3].lastName, "bath");
}

TEST(AddressBookTests, RetrieveContactsSortedByLastName) {
    AddressBook ab;
    ab.addContact(Contact("Jane", "Bath", "2345678901"));
    ab.addContact(Contact("Jane", "Arthur", "1234567890"));
    ab.addContact(Contact("Bob", "Arthur", "1234567890"));
    ab.addContact(Contact("Alice", "Johnson", "3456789012"));

    std::vector<Contact> contacts = ab.getContactsByLastName();

    ASSERT_EQ(contacts.size(), 4);
    EXPECT_EQ(contacts[0].lastName, "arthur");
    EXPECT_EQ(contacts[0].firstName, "bob");
    EXPECT_EQ(contacts[1].lastName, "arthur");
    EXPECT_EQ(contacts[1].firstName, "jane");
    EXPECT_EQ(contacts[2].lastName, "bath");
    EXPECT_EQ(contacts[2].firstName, "jane");
    EXPECT_EQ(contacts[3].lastName, "johnson");
    EXPECT_EQ(contacts[3].firstName, "alice");

}