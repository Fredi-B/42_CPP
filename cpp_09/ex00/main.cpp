#include "BitcoinExchange.hpp"

bool    file_check(int argc, std::ifstream &input, std::ifstream &data);

int main(int argc, char** argv)
{
    std::ifstream input(argv[1]);
    std::ifstream data("./data.csv");
    
    if (!file_check(argc, input, data))
        return (1);
    BitcoinExchange(input, data);


    return (0);
}

bool    file_check(int argc, std::ifstream &input, std::ifstream &data)
{
    if (argc != 2)
    {
        std::cout << "Error: wrong number of arguments. Use: ./btc input.txt" << std::endl;
        return (false);
    }
    if (!input.is_open())
    {
        std::cout << "Error: could not open input file" << std::endl;
        return (false);
    }
    if (!data.is_open())
    {
        std::cout << "Error: could not open data file" << std::endl;
        return (false);
    }
    return (true);
}
