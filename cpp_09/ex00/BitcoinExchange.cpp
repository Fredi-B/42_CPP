#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream &input, std::ifstream &data)
{
    std::string next_line;

    // skip first line
    std::getline(input, next_line);
    std::getline(data, next_line);
    int i = 0;
    while (std::getline(data, next_line))
    {
        this->fill_exchange_rate(next_line, ",");
        i++;
        if (i > 500)
            break ;
    }
    //std::cout << this->exchange_rate.find("2011-01-03")->second << std::endl;
    //std::cout << this->exchange_rate.find("2011-01-03")->second * 3 << std::endl;

    
    while (std::getline(data, next_line))
    {
        std::cout << next_line << std::endl;
        break ;
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::fill_exchange_rate(std:: string line, std::string delim)
{
    std::string         _date;
    std::string         _value_string;
    std::stringstream   magical_converter_stream;
    std::pair<std::string, double>  data;

    data.first = line.substr(0, line.find(delim));
    data.second = -1;
    _value_string = line.erase(0, line.find(delim));
    if (_value_string != "")
        _value_string = line.erase(0, delim.length());
    magical_converter_stream << _value_string;
    magical_converter_stream >> data.second;
    this->exchange_rate.insert(data);
        std::cout << data.second << std::endl;

        std::cout << this->exchange_rate.end()->second << std::endl;
//    std::cout << this->exchange_rate.end()->second * 3 << std::endl;
    return ;
}
