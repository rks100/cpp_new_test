/**
 * @file smart_ptr1.cpp
 * @brief Demonstrates the use of shared_ptr in C++ with a simple Person class.
 *
 * This program defines a Person class with a name attribute and demonstrates
 * the use of shared_ptr to manage Person objects. It includes both non-parameterized
 * and parameterized constructors, a destructor, and methods to get and set the name.
 * The main function initializes shared pointers to Person objects, prints their names,
 * and shows how shared pointers can be reassigned and modified.
 *
 * Functions:
 * - print_names(const shared_ptr<Person>& person1, const shared_ptr<Person>& person2): 
 *   Prints the names of two Person objects managed by shared_ptr.
 *
 * Classes:
 * - Person: Represents a person with a name. Includes constructors, a destructor, 
 *   and methods to get and set the name.
 *
 * Usage:
 * Compile and run the program to see the creation, modification, and destruction
 * of Person objects managed by shared_ptr.
 */
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Person {
private:
    string name;

public:
    // Non-parameterized constructor
    Person() : name{"Unknown"} {
        cout << "Person created with no name\n";
    }

    // Parameterized constructor
    Person(const string &name) : name{name} {
        cout << "Person created with name: " << name << endl;
    }

    // Destructor
    ~Person() {
        cout << "Person destroyed   " << name << endl;
    }

    // Getter for name
    string getName() const {
        return name;
    }

    // Setter for name
    void setName(const string &name) {
        this->name = name;
    }
};

void print_names(const shared_ptr<Person>& person1, const shared_ptr<Person>& person2) {
    cout << "Person 1 name: " << person1->getName() << endl;
    cout << "Person 2 name: " << person2->getName() << endl;
}

int main() {
    // Initialize shared pointers
    shared_ptr<Person> person1{make_shared<Person>()}; // Non-parameterized constructor
    shared_ptr<Person> person2{make_shared<Person>("John")}; // Parameterized constructor with round braces

    // Print names using the function
    print_names(person1, person2);

    // Copy person2 pointer to person1 and change the name of person1
    person1 = person2;
    person1->setName("Jane");

    // Print names again to see the changes
    print_names(person1, person2);

    return 0;
}