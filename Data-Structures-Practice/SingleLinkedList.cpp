#include "SingleLinkedList.h"
#include <cassert> // for assert
SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr), length(0){}//constructor

SingleLinkedList::~SingleLinkedList()//destructor
{
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    length = 0;
}
void SingleLinkedList::insert_end(int dt)
{
    Node* node = new Node(dt);
    // if head is null => empty => head and tail to the new node
    //else current tail's next to the new node and the tail to the new node
    if(head==nullptr){
        head = node;
        tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
     length++;
}
int SingleLinkedList::srch(int value)
{
        Node* current = head;
         for (int i = 0; i < length; i++) {
        if (current->data == value) {
            return i;
        }
        current = current->next;
        }
        return -1;
}

int SingleLinkedList::search_improved(int value)
{
     Node* current = head;
    Node* previous = nullptr;
    for (int i = 0; i < length; i++) {
        if (current->data == value) {
            if (previous == nullptr)
                return i;
            swap(current->data, previous->data);
            return i - 1;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}
void SingleLinkedList::debug_verify_data_integrity()
{
    if (length == 0) {
        assert(head == nullptr);
        assert(tail == nullptr);
    } else {
        assert(head != nullptr);
        assert(tail != nullptr);
        if (length == 1)
            assert(head == tail);
        else
            assert(head != tail);
        assert(tail->next == nullptr);
    }
    // check infinite loop
    Node* current = head;
    int cnt = 0;
    while (current != nullptr) {
        assert(cnt < length);
        current = current->next;
        cnt++;
    }
}


Node* SingleLinkedList::get_nth_node(int n)
{
    if (n < 0 || n >= length) {
        return nullptr;
    }
    Node* current = head;
    for (int i = 0; i < n; i++) {
        current = current->next;
    }
    return current;
}
void SingleLinkedList::delete_first_node()
{

    if(head==nullptr){
        cout << "List is empty!" << endl;
        return;
    }

        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    cout << "Deleted!" << endl;
    // if the list becomes empty, then we need to set the tail to null
    if(head==nullptr){
        cout << "List became empty!" << endl;
        tail = nullptr;
        return;

    }
}
     void SingleLinkedList::delete_last_node()
{
    // if list is empty or has only one node
    if (length <= 1) {
        delete_first_node();
        return;
    }
        Node* temp = tail;
         Node* prev = get_nth_node(length - 2);//tail will updated
        prev->next = nullptr;
        tail = prev;
        delete temp;
       length--;
    cout << "Deleted!" << endl;
        /*
        Node* prev = head;
    for (int i = 0; i < n-2; i++) {
        prev = prev->next;
    }
    prev->next = nullptr;
        tail = prev ;
    */
    }
    void SingleLinkedList::delete_nth_node(int n)
{
    if (n < 0 || n >= length) {
        cout << "Invalid index!" << endl;
        return;
    }
    if (length <= 1) {
        delete_first_node();
        return;
    }
    if (n == length - 1) {
        delete_last_node();
        return;
    }
    Node* temp = get_nth_node(n); // to be deleted
    Node* prev = get_nth_node(n - 1);
    prev->next = temp->next;
    delete temp;
    length--;
}
void SingleLinkedList::print()
{
    cout << "Length: " << length << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n"<<string(30,'=') << endl;
}






