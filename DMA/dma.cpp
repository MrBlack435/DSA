// Dynamic Memory Allocation
#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Base class: Dynamic Memory Allocation
class DynamicMemoryAllocation {
private:
    Node* head;

public:
    // Constructor
    DynamicMemoryAllocation() {
        head = nullptr;
    }

    // Append node at the end
    void append(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at beginning
    void insert_at_beginning(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    // Search for a value
    bool search(int key) {
        Node* current = head;
        int position = 0;
        while (current != nullptr) {
            if (current->data == key) {
                cout << "Element " << key << " found at position " << position << endl;
                return true;
            }
            current = current->next;
            position++;
        }
        cout << "Element " << key << " not found in the list." << endl;
        return false;
    }

    // Delete a node by value
    void delete_node(int key) {
        Node* current = head;
        Node* prev = nullptr;

        // If head node holds the key
        if (current != nullptr && current->data == key) {
            head = current->next;
            delete current;
            cout << "Element " << key << " deleted from the list." << endl;
            return;
        }

        // Search for the key
        while (current != nullptr && current->data != key) {
            prev = current;
            current = current->next;
        }

        // Key not found
        if (current == nullptr) {
            cout << "Element " << key << " not found in the list." << endl;
            return;
        }

        // Delete the node
        prev->next = current->next;
        delete current;
        cout << "Element " << key << " deleted from the list." << endl;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;  // Store next
            current->next = prev;  // Reverse current node's pointer
            prev = current;        // Move prev one step ahead
            current = next;        // Move current one step ahead
        }

        head = prev;  // Reset head to the new front
        cout << "Linked list reversed." << endl;
    }
};

// Main function
int main() {
    DynamicMemoryAllocation list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.display();  // 10 -> 20 -> 30 -> NULL

    list.insert_at_beginning(5);
    list.display();  // 5 -> 10 -> 20 -> 30 -> NULL

    list.search(20); // Found
    list.search(100); // Not Found

    list.delete_node(10);
    list.display();  // 5 -> 20 -> 30 -> NULL

    list.reverse();
    list.display();  // 30 -> 20 -> 5 -> NULL

    return 0;
}
