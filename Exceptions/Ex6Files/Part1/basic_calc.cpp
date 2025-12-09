#include <iostream>

void check8200(int value, bool& errorFlag) {
    if (value == 8200) {
        errorFlag = true;
    }
}

int add(int a, int b, bool& errorFlag) {
    int result = a + b;
    check8200(result, errorFlag);
    return result;
}

int multiply(int a, int b, bool& errorFlag) {
    int sum = 0;
    check8200(sum, errorFlag); // sum local variable

    for (int i = 0; i < b; i++) {
        check8200(i, errorFlag); // loop variable
        sum = add(sum, a, errorFlag);
    }
    return sum;
}

int pow(int a, int b, bool& errorFlag) {
    int exponent = 1;
    check8200(exponent, errorFlag);

    for (int i = 0; i < b; i++) {
        check8200(i, errorFlag);
        exponent = multiply(exponent, a, errorFlag);
    }
    return exponent;
}

void print8200Error() {
    std::cout << "This user is not authorized to access 8200, "
        "please enter different numbers, or try to get clearance in 1 year"
        << std::endl;
}

int main() {
    bool err = false;

    std::cout << "--- legal test ---" << std::endl;
    err = false;
    int r1 = add(5, 7, err);
    if (!err) std::cout << "5 + 7 = " << r1 << std::endl;
    else print8200Error();

    std::cout << "--- illegal test (should trigger 8200) ---" << std::endl;
    err = false;
    int r2 = add(4100, 4100, err);
    if (!err) std::cout << r2 << std::endl;
    else print8200Error();

    std::cout << "--- pow test ---" << std::endl;
    err = false;
    int r3 = pow(5, 5, err);
    if (!err) std::cout << r3 << std::endl;
    else print8200Error();

    return 0;
}
