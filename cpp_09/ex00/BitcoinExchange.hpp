#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{   
private:
    std::map<std::string, double> value;
    std::map<std::string, double> exchange_rate;

    void fill_exchange_rate(std:: string line, std::string delim);
    

public:
    BitcoinExchange(std::ifstream &input, std::ifstream &data);
    ~BitcoinExchange();
};



#endif