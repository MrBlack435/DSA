#include <iostream>
using namespace std;

// Base class for Inheritance & Polymorphism
class StackBase
{
public:
    virtual void displayStatus()
    {
        cout << "This is the base Stack class." << endl;
    }
};

// Derived class - Stack implementation
class Stack : public StackBase
{
private:
    int *arr;     // Encapsulated data (pointer to dynamic array)
    int topIndex; // Index of the top element
    int size;     // Maximum size of the stack

public:
    // Constructor
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        topIndex = -1;
    }

    // Destructor to free memory
    ~Stack()
    {
        delete[] arr;
    }

    // Push method
    void push(int value)
    {
        if (!isFull())
        {
            arr[++topIndex] = value;
            cout << "Pushed " << value << " to the stack." << endl;
        }
        else
        {
            cout << "Stack is full! Cannot push." << endl;
        }
    }

    // Pop method
    void pop()
    {
        if (!isEmpty())
        {
            cout << "Popped " << arr[topIndex--] << " from the stack." << endl;
        }
        else
        {
            cout << "Stack is empty! Cannot pop." << endl;
        }
    }

    // Top method
    void top()
    {
        if (!isEmpty())
        {
            cout << "Top element is: " << arr[topIndex] << endl;
        }
        else
        {
            cout << "Stack is empty!" << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return topIndex == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return topIndex == size - 1;
    }

    // Overridden method (Polymorphism)
    void displayStatus() override
    {
        cout << "Current Stack: ";
        if (isEmpty())
        {
            cout << "Empty" << endl;
        }
        else
        {
            for (int i = 0; i <= topIndex; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Main function
int main()
{
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    Stack myStack(stackSize);

    int choice, value;

    do
    {
        cout << "\nOptions:\n";
        cout << "1. Push\n2. Pop\n3. Display Top\n4. Is Empty?\n5. Is Full?\n6. Display Stack\n7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            myStack.push(value);
            break;
        case 2:
            myStack.pop();
            break;
        case 3:
            myStack.top();
            break;
        case 4:
            cout << (myStack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << (myStack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 6:
            myStack.displayStatus();
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
