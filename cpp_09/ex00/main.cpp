#include "BitcoinExchange.hpp"
#include "inputCheck.hpp"

std::pair<std::string, double>  getInputData(std::string next_line, std::string delim);
void                            calculate_results(BitcoinExchange ftx, std::pair<std::string, double> input_pair);
bool                            foundInData(std::string date, std::map<std::string, double>::const_iterator it, \
                                                std::map<std::string, double>::const_iterator it_end);

int main(int argc, char** argv)
{
    std::ifstream   input(argv[1]);
    std::ifstream   data("./data.csv");
    std::string     next_line;
    std::pair<std::string, double>  input_pair;

    if (!fileCheck(argc, input, data))
        return (1);

    BitcoinExchange ftx(data);

    std::getline(input, next_line); // skip first line
    while (std::getline(input, next_line))
    {
        input_pair = getInputData(next_line, " | ");
        if (!InputDataCheck(input_pair))
            continue ;
        calculate_results(ftx, input_pair);
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

/* finds exchange rate, multiplies it with amount and prints result */
void    calculate_results(BitcoinExchange ftx, std::pair<std::string, double> input_pair)
{
    std::map<std::string, double>::const_iterator it = ftx.beginExchangeRate();
    std::map<std::string, double>::const_iterator it_end = ftx.endExchangeRate();
    
    for ( ; it != it_end; it++)
    {
        if (foundInData(input_pair.first, it, it_end))
        {
            std::cout << input_pair.first << " => " << input_pair.second << " = " << input_pair.second * it->second << std::endl;
            break ;
        }
    }
    if (it == it_end)
    {
        std::cout << input_pair.first << " => " << input_pair.second << " = " << input_pair.second * (--it)->second << std::endl;
    }
}

bool    foundInData(std::string date, std::map<std::string, double>::const_iterator it, std::map<std::string, double>::const_iterator it_end)
{
    int data_year, data_month, data_day;
    int input_year, input_month, input_day;
    std::stringstream   magical_converter_stream;

    if (date == it->first)
        return (true);
    if (++it != it_end) // it++: check if next entry is later than input date
    {
        magical_converter_stream << it->first.substr(0, 4);
        magical_converter_stream >> data_year;
        magical_converter_stream.clear();
        magical_converter_stream << it->first.substr(5, 2);
        magical_converter_stream >> data_month;
        magical_converter_stream.clear();
        magical_converter_stream << it->first.substr(8, 2);
        magical_converter_stream >> data_day;
        magical_converter_stream.clear();
        magical_converter_stream << date.substr(0, 4);
        magical_converter_stream >> input_year;
        magical_converter_stream.clear();
        magical_converter_stream << date.substr(5, 2);
        magical_converter_stream >> input_month;
        magical_converter_stream.clear();
        magical_converter_stream << date.substr(8, 2);
        magical_converter_stream >> input_day;
        magical_converter_stream.clear();
        if (input_year <= data_year && input_month <= data_month && input_day < data_day)
            return (true);
    }
    return (false);
}
