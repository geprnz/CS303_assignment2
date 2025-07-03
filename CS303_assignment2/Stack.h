#pragma once
#include "LinkedList.h"
#include "EmptyStack.h"
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    T pop() {
        if (!empty()) {
            T value = data.back(); 
            data.pop_back();
            return value;
        }
        else {
            throw EmptyStack("Stack is empty");
        }
    }

    bool empty() const {
        return data.empty();
    }

    const T& top() const {
        if (!empty()) {
            return data.back();
        }
        else {
            throw EmptyStack("Stack is empty");
        }
    }

    double average() const {
        if (empty()) {
            throw EmptyStack("Stack is empty");
        }

        double sum = 0.0;
        for (const T& val : data) {
            sum += static_cast<double>(val);
        }

        return sum / data.size();
    }
};