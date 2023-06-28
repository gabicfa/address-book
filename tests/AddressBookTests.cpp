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