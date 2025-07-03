#pragma once
#include "Stack.h"
#include "functions.h"

using namespace std;

int get_input() {
    string choice;
    int choiceInt;
    do {
        cout << "Choose desired function: ";
        cin >> choice;
        if (!is_valid_int(choice, choiceInt)) {
            cout << "Invalid choice, please choose an option 1-5.";
        }
    } while (!is_valid_int(choice, choiceInt));
    return choiceInt;
}

ifstream import() {
    string fname;
    ifstream file;

    do {
        cout << "Enter the path to the file (default file is 'data.txt'): ";
        getline(cin >> ws, fname);  // ensures leading whitespace doesn't block getline

        if (fname.empty()) {
            fname = "data.txt";
        }

        file.open(fname);
        if (!file.is_open()) {
            cout << "Failed to open the file. Please try again.\n";
        }
    } while (!file.is_open());

    cout << "File successfully opened." << endl;
    return file;
}

bool is_valid_int(const string& token, int& value) {
    stringstream ss(token);
    ss >> ws >> value;
    return !ss.fail() && ss.eof();
}

void data_infill(Stack<int>& stack, ifstream& file) {
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        while (ss >> token) {
            int value;
            if (is_valid_int(token, value)) {
                stack.push(value);
            }
            else {
                cout << "Warning: Invalid integer token skipped: \"" << token << "\"\n";
            }
        }
    }
}
