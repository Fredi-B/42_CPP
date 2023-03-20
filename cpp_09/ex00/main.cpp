#include "BitcoinExchange.hpp"
#include "inputCheck.hpp"

std::pair<std::string, double>  getInputData(std::string next_line, std::string delim);
bool    foundInData(std::string date, std::map<std::string, double>::const_iterator it, std::map<std::string, double>::const_iterator it_end);

int main(int argc, char** argv)
{
    std::ifstream   input(argv[1]);
    std::ifstream   data("./data.csv");
    std::string     next_line;
    std::pair<std::string, double>  input_pair;

    if (!fileCheck(argc, input, data))
        return (1);

    BitcoinExchange ftx(data);
    std::map<std::string, double>::const_iterator it;
    std::map<std::string, double>::const_iterator it_end = ftx.endExchangeRate();

    std::getline(input, next_line); // skip first line
    while (std::getline(input, next_line))
    {
        input_pair = getInputData(next_line, " | ");
        if (!InputDataCheck(input_pair))
            continue ;
        /* find exchange rate, multiply it with amount and print result */
        it = ftx.beginExchangeRate();
        while (it != ftx.endExchangeRate())
        {
            if (foundInData(input_pair.first, it, it_end))
            {
                std::cout << input_pair.first << " => " << input_pair.second << " = " << input_pair.second * it->second << std::endl;
                break ;
            }
            it++;
        }
        if (it == it_end)
        {
            std::cout << input_pair.first << " => " << input_pair.second << " = " << input_pair.second * (--it)->second << std::endl;
        }
    }
    return (0);
}

std::pair<std::string, double>  getInputData(std::string next_line, std::string delim)
{
    std::pair<std::string, double>  data;
    std::string                     _date;
    std::string                     _amount_string;
    std::stringstream               magical_converter_stream;

    data.first = next_line.substr(0, next_line.find(delim));
    data.second = -1;
    _amount_string = next_line.erase(0, next_line.find(delim));
    if (_amount_string != "")
        _amount_string = next_line.erase(0, delim.length());
    magical_converter_stream << _amount_string;
    magical_converter_stream >> data.second;
    return (data);
}

bool    foundInData(std::string date, std::map<std::string, double>::const_iterator it, std::map<std::string, double>::const_iterator it_end)
{
    if (date == it->first)
        return (true);
    if (++it != it_end) // it++: check if next entry is later than input date
    {
        int data_year = std::stoi(it->first.substr(0, 4));
        int data_month = std::stoi(it->first.substr(5, 2));
        int data_day = std::stoi(it->first.substr(8, 2));
        int input_year = std::stoi(date.substr(0, 4));
        int input_month = std::stoi(date.substr(5, 2));
        int input_day = std::stoi(date.substr(8, 2));
        if (input_year <= data_year && input_month <= data_month && input_day <= data_day)
            return (true);
    }
    return (false);
}
