#include "BitcoinExchange.hpp"

bool    file_check(int argc, std::ifstream &input, std::ifstream &data);

int main(int argc, char** argv)
{
    std::ifstream input(argv[1]);
    std::ifstream data("./data.csv");
    
    if (!file_check(argc, input, data))
        return (1);
    BitcoinExchange ftx(input, data);
    /* Iterate through ftx->exchange_rate and printing second */
    std::map<std::string, double>::iterator it = ftx.getexchange_rate.begin();
    while (it != ftx.exchange_rate.end())
    {
        std::cout << it->first << " and now second " << it->second << std::endl;
        it++;
    }


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
