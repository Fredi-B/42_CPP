#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: wrong number of arguments. Use: ./RPN \"7 7 * 7 -\"" << std::endl;
        return (1);
    }
    RPN rpn(argv);
    if (!rpn.calculate())
        return (2);
    if (!rpn.printResult())
        return (3);
    return (0);
}
