// this class parses infix to postfix

#ifndef parser_h
#define parser_h
#include <string>
#include <stack>
#include <array>

struct Operator {
    char content;
    int priority;
    Operator() = default;
    Operator(char _c, int _p): content(_c), priority(_p) {}
    Operator(char _c, int _p, int _l, int _i): content(_c) { priority = _p + _i * _l; }
    
    friend bool operator< (Operator& lhs, Operator& rhs) { return lhs.priority < rhs.priority; }
};

class Parser {
public:
    std::string toPostFix(std::string const & str);
    
public:
    void parse(const std::string &);
};

std::string Parser::toPostFix(std::string const & str) {
    std::string result = "";
    std::stack<Operator> operators;
    int level = 0x0;
    for (auto && i : str) {
        if (std::isdigit(i) || i == '.') {
            result.append(1, i);
        }
        else if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^') {
            result.append(1, ' ');
            Operator op;
            if (i == '+') { op = Operator('+', 0x0, level, 0x100); }
            else if (i == '-') { op = Operator('-', 0x0, level, 0x100); }
            else if (i == '*') { op = Operator('*', 0x10, level, 0x100); }
            else if (i == '/') { op = Operator('/', 0x10, level, 0x100); }
            else if (i == '^') { op = Operator('^', 0x20, level, 0x100); }
            else break;
            if (operators.empty()) {
                operators.push(op);
            }
            else if (operators.top() < op) {
                operators.push(op);
            }
            else {
                while (!operators.empty()) {
                    auto temp = operators.top();
                    result.append(1, ' ');
                    result.append(1, temp.content);
                    result.append(1, ' ');
                    operators.pop();
                }
                operators.push(op);
            }
        }
        else if (i == '(') ++level;
        else if (i == ')') {
            if (level <= 0) { throw std::logic_error("Unbalanced parentheses"); }
            --level;
        }
    }
    while (!operators.empty()) {
        auto temp = operators.top();
        result.append(1, ' ');
        result.append(1, temp.content);
        result.append(1, ' ');
        operators.pop();
    }
    return result;
}

#endif /* parser_h */
