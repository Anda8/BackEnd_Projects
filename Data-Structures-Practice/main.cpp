#include "SingleLinkedList.cpp"
#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
   SingleLinkedList lst;
    for (int i = 1; i <= 10; i++) {
        lst.insert_end(i);
    }
    lst.print();
    cout << "search(2): " << lst.search_improved(2) << endl;
    lst.print();
    cout << "search(3): " << lst.search_improved(3) << endl;
    lst.print();

    // Delete head
    lst.delete_first_node();
    lst.print();

    // Delete tail
    lst.delete_last_node();
    lst.print();

    // Delete nth node , n = 3
    lst.delete_nth_node(3);
    lst.print();

    lst.debug_verify_data_integrity();
    cout << "All tests passed!" << endl;

    return 0;
}
