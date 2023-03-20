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

    void fillExchangeRate(std:: string line, std::string delim);
    

public:
    BitcoinExchange(std::ifstream &data);
    ~BitcoinExchange();

    std::map<std::string, double>::const_iterator beginExchangeRate(void) const;
    std::map<std::string, double>::const_iterator endExchangeRate(void) const;

    std::pair<std::string, double>  getExchangeRate(std::string date);
};



#endif
