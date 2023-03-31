#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
public:
    RPN(char **argv);
    RPN(const RPN &other);
    ~RPN();

    RPN     &operator=(const RPN &other);

    bool    calculate();
    bool    printResult();

private:
    std::stack<int> operand_stack;
    int             operand1;
    int             operand2;
    std::string     expression;

    bool    checkSyntax(size_t i);

    RPN(void);
};

#endif
