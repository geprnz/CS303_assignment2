#pragma once
#include "Stack.h"

const string MENU = "1. FILE IMPORT\n2. EMPTY STATUS\n3. ADD VALUES\n4. REMOVE VALUES\n5. TOP VALUE\n6. AVERAGE VALUE\n";

int get_input();

ifstream import();

bool is_valid_int(const string& token, int& value);

void data_infill(Stack<int>& stack, ifstream& file);
