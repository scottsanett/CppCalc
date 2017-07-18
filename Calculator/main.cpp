//
//  main.cpp
//  Calculator
//
//  Created by Scott Sanett on 18/07/2017.
//  Copyright © 2017 Scott Sanett. All rights reserved.
//

#include "calculator.hpp"
#include "parser.hpp"
#include <iomanip>

int main(int argc, const char * argv[]) {
    Calculator calc;
    Parser parser;
    while (true) {
        std::cout << ">>> ";
        std::string input;
        std::getline(std::cin, input);
        double result;
        try {
            result = calc.calculate(parser.toPostFix(input));
        }
        catch (std::logic_error e) {
            std::cout << "Logic error detected: " << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "Unknown error detected." << std::endl;
        }
        std::cout << "Result: " << std::setprecision(9) << result << std::endl;
    }
}
