#include <iostream>

struct Restricted8200 {};

void check8200(int value) {
    if (value == 8200) throw Restricted8200{};
}

int add(int a, int b) {
    int result = a + b;
    check8200(result);
    return result;
}

int multiply(int a, int b) {
    int sum = 0;
    check8200(sum); // local variable

    for (int i = 0; i < b; i++) {
        check8200(i);     // loop variable
        sum = add(sum, a);
    }
    return sum;
}

int pow(int a, int b) {
    int exponent = 1;
    check8200(exponent);

    for (int i = 0; i < b; i++) {
        check8200(i);
        exponent = multiply(exponent, a);
    }
    return exponent;
}

void print8200Error() {
    std::cout << "This user is not authorized to access 8200, "
        "please enter different numbers, or try to get clearance in 1 year"
        << std::endl;
}

int main() {

    std::cout << "--- legal test ---" << std::endl;
    try {
        std::cout << "5 + 7 = " << add(5, 7) << std::endl;
    }
    catch (Restricted8200&) {
        print8200Error();
    }

    std::cout << "--- illegal test (8200 triggered) ---" << std::endl;
    try {
        std::cout << add(4100, 4100) << std::endl; // becomes 8200
    }
    catch (Restricted8200&) {
        print8200Error();
    }

    std::cout << "--- pow test ---" << std::endl;
    try {
        std::cout << pow(5, 5) << std::endl;
    }
    catch (Restricted8200&) {
        print8200Error();
    }

    return 0;
}
