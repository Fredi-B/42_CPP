#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

class BitcoinExchange
{   
private:
    BitcoinExchange();

    std::map<std::string, double>   exchange_rate;

    void fillExchangeRate(std:: string line, std::string delim);
    

public:
    BitcoinExchange(std::ifstream &data);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange &other);

    std::map<std::string, double>::const_iterator beginExchangeRate(void) const;
    std::map<std::string, double>::const_iterator endExchangeRate(void) const;

    std::pair<std::string, double>  getExchangeRate(std::string date) const;
};

#endif
