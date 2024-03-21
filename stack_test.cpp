#include <iostream>
#include "stack.h"

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Size of stack: " << intStack.size() << std::endl;
    std::cout << "Top element: " << intStack.top() << std::endl;

    intStack.pop();
    std::cout << "After pop, top element: " << intStack.top() << std::endl;

    return 0;
}
