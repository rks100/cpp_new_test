/**
 * @file shared_ptr02.cpp
 * @brief Demonstrates the usage of std::shared_ptr in C++.
 *
 * This program showcases the creation and management of shared pointers,
 * including sharing ownership, resetting pointers, and accessing the underlying
 * raw pointer. It also demonstrates the use of member functions such as use_count()
 * and unique().
 *
 * @details
 * - Creates a shared_ptr to an integer using make_shared.
 * - Shares ownership of the integer with another shared_ptr.
 * - Resets one of the shared_ptrs to nullptr and checks the use count.
 * - Accesses the raw pointer from a shared_ptr.
 * - Checks if a shared_ptr is unique.
 *
 * @author
 * Raj Kumar Sukhdeo
 *
 * @date
 * 2024-10-27
 */
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;

int main() {
    // Create a shared_ptr to an integer using uniform brace initialization
    shared_ptr<int> sp1{make_shared<int>(42)};
    cout << "sp1 points to: " << *sp1 << endl;
    cout << "sp1 use count: " << sp1.use_count() << endl;

    // Create another shared_ptr that shares ownership with sp1
    shared_ptr<int> sp2{sp1};
    cout << "After sp2 creation, sp1 use count: " << sp1.use_count() << endl;
    cout << "sp2 use count: " << sp2.use_count() << endl;

    // Reset sp1, making it nullptr
    sp1.reset();
    cout << "After resetting sp1, sp1 use count: " << (sp1 ? sp1.use_count() : 0) << endl;
    cout << "sp2 use count: " << sp2.use_count() << endl;

    // Check if sp1 is nullptr
    if (sp1 == nullptr) {
        cout << "sp1 is nullptr" << endl;
    }

    // Access underlying raw pointer and other member functions
    int* rawPtr = sp2.get();
    cout << "Raw pointer from sp2: " << *rawPtr << endl;

    // Check if sp2 is unique
    if (sp2.unique()) {
        cout << "sp2 is unique" << endl;
    } else {
        cout << "sp2 is not unique" << endl;
    }

    return 0;
}
