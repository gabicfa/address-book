#include "gtest/gtest.h"
#include "Contact.h"

TEST(ContactTest, EmptyName) {
    EXPECT_THROW(Contact("", "Doe", "1234567890"), std::invalid_argument);
    EXPECT_THROW(Contact("John", "", "1234567890"), std::invalid_argument);
    EXPECT_THROW(Contact("", "", "1234567890"), std::invalid_argument);
}

TEST(ContactTest, NonDigitPhoneNumber) {
    EXPECT_THROW(Contact("John", "Doe", "123abc"), std::invalid_argument);
}

TEST(ContactTest, NamesToLowerCase) {
    Contact c1("John", "Doe", "1234567890");
    EXPECT_EQ(c1.firstName, "john");
    EXPECT_EQ(c1.lastName, "doe");

    Contact c2("JANE", "DOE", "1234567890");
    EXPECT_EQ(c2.firstName, "jane");
    EXPECT_EQ(c2.lastName, "doe");
}

TEST(ContactTest, PhoneNumbers) {
    Contact c1("John", "Doe", "1234567890");
    EXPECT_EQ(c1.phoneNumber, "1234567890");

    Contact c2("John", "Doe", "");
    EXPECT_EQ(c2.phoneNumber, "");
}
