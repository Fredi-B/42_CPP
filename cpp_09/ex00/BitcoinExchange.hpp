#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{   
private:
    std::map<std::string, double>   exchange_rate;
    std::ifstream                   &input;

    void fillExchangeRate(std:: string line, std::string delim);
    

public:
    BitcoinExchange(std::ifstream &input, std::ifstream &data);
    ~BitcoinExchange();

    std::pair<std::string, double>  getExchangeRate(std::string date);
    double                          getAmount(std::string date);
};



#endif