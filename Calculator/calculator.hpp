#ifndef calculator_h
#define calculator_h

#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <stack>

class Calculator {
private:
    double result;
    std::stack<double> numbers;

private:
    void add();
    void minus();
    void multiply();
    void divide();
    void power();
    
public:
    double calculate(std::string const &);
};

void Calculator::add() {
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto rhs = numbers.top();
    numbers.pop();
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto lhs = numbers.top();
    numbers.pop();
    auto temp = lhs + rhs;
    numbers.push(temp);
}

void Calculator::minus() {
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto rhs = numbers.top();
    numbers.pop();
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto lhs = numbers.top();
    numbers.pop();
    auto temp = lhs - rhs;
    numbers.push(temp);
}

void Calculator::multiply() {
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto rhs = numbers.top();
    numbers.pop();
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto lhs = numbers.top();
    numbers.pop();
    auto temp = lhs * rhs;
    numbers.push(temp);
}

void Calculator::divide() {
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto rhs = numbers.top();
    numbers.pop();
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto lhs = numbers.top();
    numbers.pop();
    auto temp = lhs / rhs;
    numbers.push(temp);
}

void Calculator::power() {
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto rhs = numbers.top();
    numbers.pop();
    if (numbers.empty()) throw std::runtime_error("An error has occurred");
    auto lhs = numbers.top();
    numbers.pop();
    double temp = 1;
    for (int i = 0; i < rhs; ++i) {
        temp *= lhs;
    }
    numbers.push(temp);
}

double Calculator::calculate(const std::string & input) {
    result = 0.0;
    while (!numbers.empty()) { numbers.pop(); }
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        if (token == "+") add();
        else if (token == "-") minus();
        else if (token == "*") multiply();
        else if (token == "/") divide();
        else if (token == "^") power();
        else {
            numbers.push(std::stod(token));
        }
    }
    if (numbers.size() != 1) {
        throw std::logic_error("An unknown error has occurred");
    }
    else {
        auto result = numbers.top();
        numbers.pop();
        return result;
    }
}

#endif /* calculator_h */
