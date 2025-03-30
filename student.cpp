#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// This is a simple student management system

template <typename T>
class MemoryCalculate {
private:
    T id;
    string name;

public:
    // Constructor
    MemoryCalculate(T id, string name) : id(id), name(name) {}

    // Display student details
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    // Get ID
    T getId() const {
        return id;
    }
};

int main() {
    vector<MemoryCalculate<int>> students;
    int choice;

    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            students.push_back(MemoryCalculate<int>(id, name));
            cout << "Student added successfully!" << endl;
            break;
        }
        case 2:
            if (students.empty()) {
                cout << "No students to display." << endl;
            } else {
                cout << "\nStudent List:" << endl;
                for (const auto &student : students) {
                    student.display();
                }
            }
            break;
        case 3: {
            int id;
            cout << "Enter Student ID to remove: ";
            cin >> id;
            auto it = remove_if(students.begin(), students.end(), [id](const MemoryCalculate<int> &s) {
                return s.getId() == id;
            });
            if (it != students.end()) {
                students.erase(it, students.end());
                cout << "Student removed successfully!" << endl;
            } else {
                cout << "Student ID not found!" << endl;
            }
            break;
        }
        case 4: {
            int id;
            cout << "Enter Student ID to search: ";
            cin >> id;
            bool found = false;
            for (const auto &student : students) {
                if (student.getId() == id) {
                    student.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student ID not found!" << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

