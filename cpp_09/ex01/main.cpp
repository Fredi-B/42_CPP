#include    <iostream>
#include    <stack>

int main(int argc, char** argv)
{
    std::stack<int>             operand_stack;
    int                         operand1 = 0;
    int                         operand2 = 0;
    std::string                 expression;

    if (argc != 2)
    {
        std::cout << "Error: wrong number of arguments. Use: ./RPN \"7 7 * 7 -\"" << std::endl;
        return (1);
    }
    expression = argv[1];
    for (size_t i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            operand_stack.push(expression[i] - '0');
            if (i + 1 < expression.length() && expression[i + 1] != ' ')
            {
                std::cout << "Error: invalid operand." << std::endl;
                return (1);
            }
        }
        else if (expression[i] == ' ')
            continue ;
        else
        {
            if (operand_stack.size() < 2)
            {
                std::cout << "Error: not enough operands." << std::endl;
                return (1);
            }
            if (i + 1 < expression.length() && expression[i + 1] != ' ')
            {
                std::cout << "Error: invalid operator. Missing space" << std::endl;
                return (1);
            }
            operand2 = operand_stack.top();
            operand_stack.pop();
            operand1 = operand_stack.top();
            operand_stack.pop();
            if (expression[i] == '+')
                operand_stack.push(operand1 + operand2);
            else if (expression[i] == '-')
                operand_stack.push(operand1 - operand2);
            else if (expression[i] == '*')
                operand_stack.push(operand1 * operand2);
            else if (expression[i] == '/')
                operand_stack.push(operand1 / operand2);
            else if (expression[i] == '%')
                operand_stack.push(operand1 % operand2);
            else
            {
                std::cout << "Error: invalid operator." << std::endl;
                return (1);
            }
        }
    }
    if (operand_stack.size() == 1)
        std::cout << operand_stack.top() << std::endl;
    else if (operand_stack.size() > 1)
        std::cout << "Error: too many operands." << std::endl;
    else
        std::cout << "Error: no operands." << std::endl;
    return (0);
}
