#include <iostream>
#include "functions.h"

int main() {
    int choice;
    cout << "WELCOME TO THE STACK PROGRAM" << endl;;
    cout << "Creating stack..." << endl;

    Stack<int> stack;
    cout << "Stack successfully created." << endl;

    while (true) {
        cout << MENU;
        choice = get_input();

        try {
            switch (choice) {
            case 1: {
                ifstream file = import();
                data_infill(stack, file);
                cout << "Stack successfully updated." << endl;
                break;
            }
            case 2: {
                cout << "Stack is currently ";
                if (stack.empty()) cout << "empty" << endl;
                else cout << "not empty" << endl;
                break;
            }
            case 3: {
                string value;
                int valueInt;
                do {
                    cout << "Enter value: ";
                    cin >> value;
                    if (!is_valid_int(value, valueInt)) {
                        cout << "Invalid integer, please try again.\n";
                    }
                } while (!is_valid_int(value, valueInt));
                stack.push(valueInt);
                cout << "Value successfully added." << endl;
                break;
            }
            case 4: {
                if (stack.empty()) {
                    cout << "Stack is empty, cannot remove value." << endl;
                    break;
                }
                cout << "Removing value..." << endl;
                int popped = stack.pop();
                cout << "Removed value " << popped << endl;
                break;
            }
            case 5: {
                if (stack.empty()) {
                    cout << "Stack is empty, cannot remove value." << endl;
                    break;
                }
                cout << "The top value is " << stack.top() << endl;
                break;
            }
            case 6: {
                if (stack.empty()) {
                    cout << "Stack is empty, cannot remove value." << endl;
                    break;
                }
                cout << "The average value is " << stack.average() << endl;
                break;
            }
            case 0: {
                cout << "Exiting program..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            }
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
