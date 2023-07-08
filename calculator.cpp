#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include "calculator_lib.h"

int main() {
    std::string expression;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, expression);

    double result = evaluateExpression(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
