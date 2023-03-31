#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(char **argv) : operand1(0), operand2(0)
{
    this->expression = argv[1];
}

RPN::RPN(const RPN &other) { *this = other; }

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->operand1 = other.operand1;
        this->operand2 = other.operand2;
        this->operand_stack = other.operand_stack;
        this->expression = other.expression;
    }
    return (*this);
}

bool  RPN::calculate(void)
{
    for (size_t i = 0; i < this->expression.length(); i++)
    {
        if (isdigit(this->expression[i]))
        {
            this->operand_stack.push(this->expression[i] - '0');
            if (i + 1 < this->expression.length() && this->expression[i + 1] != ' ')
            {
                std::cout << "Error: invalid operand." << std::endl;
                return (false);
            }
        }
        else if (this->expression[i] == ' ')
            continue ;
        else
        {
            if (this->operand_stack.size() < 2)
            {
                std::cout << "Error: not enough operands." << std::endl;
                return (false);
            }
            if (i + 1 < this->expression.length() && this->expression[i + 1] != ' ')
            {
                std::cout << "Error: invalid operator. Missing space" << std::endl;
                return (false);
            }
            this->operand2 = this->operand_stack.top();
            this->operand_stack.pop();
            this->operand1 = this->operand_stack.top();
            this->operand_stack.pop();
            if (this->expression[i] == '+')
                this->operand_stack.push(this->operand1 + this->operand2);
            else if (this->expression[i] == '-')
                this->operand_stack.push(this->operand1 - this->operand2);
            else if (this->expression[i] == '*')
                this->operand_stack.push(this->operand1 * this->operand2);
            else if (this->expression[i] == '/')
                this->operand_stack.push(this->operand1 / this->operand2);
            else if (this->expression[i] == '%')
                this->operand_stack.push(this->operand1 % this->operand2);
            else
            {
                std::cout << "Error: invalid operator." << std::endl;
                return (false);
            }
        }
    }
    return (true);
}

    else if (this->expression[i] == '-' && isdigit(this->expression.at(i + 1)))
    {
        if (i + 2 < this->expression.length() && this->expression[i + 2] != ' ')
        {
            std::cout << "Error: invalid operand." << std::endl;
            return (false);
        }
        this->operand_stack.push((this->expression[i + 1] - '0') * -1);
        i++;
    }
bool    RPN::printResult()
{
    if (this->operand_stack.size() > 1)
    {
        std::cout << "Error: too many operands." << std::endl;
        return (false);
    }
    else if (this->operand_stack.size() < 1)
    {
        std::cout << "Error: no operands." << std::endl;
        return (false);
    }
    std::cout << this->operand_stack.top() << std::endl;
    return (true);
}
