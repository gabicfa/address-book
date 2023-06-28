# Address Book

This is a simple Address Book application built in C++. It allows for adding and removing contacts, searching for contacts by exactly or partially matching names, and retrieving contacts in alphabetical order. 

## Requirements

- C++14 compatible compiler
- CMake (version 3.0 or above)
- GTest (optional, for running tests)

## Design Choices

The Address Book is designed with simplicity and efficiency in mind. It uses the STL containers (`std::multiset`) to hold the contact information in alphabetical order, which provides efficient storage and retrieval operations. 

Each `Contact` is an object that has a first name, last name, and an optional phone number. 

Two separate multisets, `m_contactsByFirstName` and `m_contactsByLastName`, are used to store contacts, allowing for efficient searching by first or last name. 

### Nested Comparators

To support alphabetical sorting, the `Contact` class includes two nested structs, `CompareContactsLastNames` and `CompareContactsFirstNames`, that provide a custom comparison for sorting the contacts in the multisets.

These comparators are specifically designed to be flexible. If two contacts have the same first name, their ordering is decided by their last name, and vice versa. This allows for more precise alphabetical sorting.

## API Documentation

The `AddressBook` class provides the following public methods:

- `void addContact(const Contact& contact)`: Adds a contact to the address book.
- `void removeContact(const Contact& contact)`: Removes a contact from the address book.
- `std::vector<Contact> getContactsByFirstName() const`: Retrieves all contacts, sorted by first name.
- `std::vector<Contact> getContactsByLastName() const`: Retrieves all contacts, sorted by last name.
- `std::vector<Contact> getContactsByName(const std::string& searchName) const`: Searches for contacts whose first or last names match the provided string, either partially or fully.

## Building The Code

This project uses CMake for building. The project includes tests, which can be optionally included in the build using a CMake option.

To build the project, navigate to the project root and run:

```bash
mkdir build
cd build
cmake ..
make
```

To include tests in the build, pass -DBUILD_TESTS=ON to cmake:
```bash
cmake -DBUILD_TESTS=ON ..
make
```

To run the tests, after building with the tests included, run:

```bash
./AddressBookTests
```

## Running The Program

After building the program, you can run it with:

```bash
./AddressBook
```
