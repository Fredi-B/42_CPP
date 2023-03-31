#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::ifstream &data)
{
    std::string next_line;

    // skip first line
    std::getline(data, next_line);
    while (std::getline(data, next_line))
    {
        this->fillExchangeRate(next_line, ",");
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->exchange_rate = other.exchange_rate;
    return (*this);
}

void BitcoinExchange::fillExchangeRate(std:: string line, std::string delim)
{
    std::string                     _date;
    std::string                     _value_string;
    std::stringstream               magical_converter_stream;
    std::pair<std::string, double>  data;

    data.first = line.substr(0, line.find(delim));
    data.second = -1;
    _value_string = line.erase(0, line.find(delim));
    if (_value_string != "")
        _value_string = line.erase(0, delim.length());
    if (_value_string.length() > 9)
        _value_string = _value_string.substr(0, 9);
    magical_converter_stream << _value_string;
    magical_converter_stream >> data.second;
    magical_converter_stream.clear();
    this->exchange_rate.insert(data);
    return ;
}

std::map<std::string, double>::const_iterator BitcoinExchange::beginExchangeRate(void) const
{
    return (this->exchange_rate.begin());
}

std::map<std::string, double>::const_iterator BitcoinExchange::endExchangeRate(void) const
{
    return (this->exchange_rate.end());
}

std::map<std::string, double>   BitcoinExchange::getExchange_rate() const { return (this->exchange_rate); }

std::pair<std::string, double>  BitcoinExchange::getExchangeRate(std::string date) const
{
    std::pair<std::string, double>  data;

    std::map<std::string, double>::const_iterator it = this->exchange_rate.begin();
    while (it != this->exchange_rate.end())
    {
        if (it->first == date)
        {
            data.first = it->first;
            data.second = it->second;
            return (data);
        }
        it++;
    }
    data.first = "Error";
    data.second = -1;
    return (data);
}
