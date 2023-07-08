#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getOperatorPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

double applyOperator(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}

double evaluateExpression(const std::string& expression) {
    std::stack<double> valueStack;
    std::stack<char> operatorStack;
    std::istringstream iss(expression);

    std::string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            double value = std::stod(token);
            valueStack.push(value);
        } else if (isOperator(token[0])) {
            char op = token[0];
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                   getOperatorPrecedence(operatorStack.top()) >= getOperatorPrecedence(op)) {
                char topOperator = operatorStack.top();
                operatorStack.pop();
                double operand2 = valueStack.top();
                valueStack.pop();
                double operand1 = valueStack.top();
                valueStack.pop();
                double result = applyOperator(operand1, operand2, topOperator);
                valueStack.push(result);
            }
            operatorStack.push(op);
        } else if (token[0] == '(') {
            operatorStack.push('(');
        } else if (token[0] == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                char topOperator = operatorStack.top();
                operatorStack.pop();
                double operand2 = valueStack.top();
                valueStack.pop();
                double operand1 = valueStack.top();
                valueStack.pop();
                double result = applyOperator(operand1, operand2, topOperator);
                valueStack.push(result);
            }
            operatorStack.pop();  // Discard the opening parenthesis
        }
    }

    while (!operatorStack.empty()) {
        char topOperator = operatorStack.top();
        operatorStack.pop();
        double operand2 = valueStack.top();
        valueStack.pop();
        double operand1 = valueStack.top();
        valueStack.pop();
        double result = applyOperator(operand1, operand2, topOperator);
        valueStack.push(result);
    }

    return valueStack.top();
}

