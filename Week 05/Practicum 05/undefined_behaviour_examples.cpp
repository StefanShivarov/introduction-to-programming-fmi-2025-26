```cpp
#include <iostream>

int doOperation(int paramA, int paramB);
int calculateA();
int calculateB();

int noReturnStatement() {
    // Flowing off the end of a value-returning function
    // without a return statement is UNDEFINED BEHAVIOR
}

int &returnDanglingReference() {
    // Returning a reference to a local variable (which will be
    // destroyed at the end of the function) is UNDEFINED BEHAVIOR

    int value = 5;
    return value;
}

int main() {
    // Well-defined
    std::cout << 5 << std::endl;

    // ---

    // Implementation-defined behavior
    // The exact behavior depends on the implementation, i.e. the compiler, and is consistent and documented

    // sizeof(int) is likely 4, but the standard only requires a minimum value of 2
    std::cout << sizeof(int) << std::endl;

    // ---

    // Unspecified behavior
    // The exact behavior depends on the implementation and is not documented

    // calculateA() and calculateB() may be called in any order
    std::cout << doOperation(calculateA(), calculateB()) << std::endl;

    // For more information, see:
    // - https://en.wikipedia.org/wiki/Sequence_point
    // - https://en.cppreference.com/w/cpp/language/eval_order

    // ---

    // Undefined behavior (UB): anything could happen, AVOID AT ALL COSTS

    // Reading an uninitialized variable is UNDEFINED BEHAVIOR
    int uninitialized;
    std::cout << uninitialized << std::endl;

    // -

    std::cout << noReturnStatement() << std::endl;

    // -

    int &value = returnDanglingReference();
    std::cout << value << std::endl;

    // -

    // Changing the same memory location twice in one expression is UNDEFINED BEHAVIOR
    int i = 1;
    i = ++i + i++;

    // This is also UNDEFINED BEHAVIOR
    // (unspecified behavior after C++17, but still unpredictable)
    doOperation(++i, ++i);

    // -

    // Reading and writing the same memory location in one expression is UNDEFINED BEHAVIOR
    int j = 1;
    int n = ++i + i;

    // ---

    // Side note: If `main` has no return statement, "return 0" is implied
    // (this is the only case where no return statement in a non-void function isn't UB)
    return 0;
}

// Credits: https://github.com/elenatuparova/Introduction-to-Programming-23-24
