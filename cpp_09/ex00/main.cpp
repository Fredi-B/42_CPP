#include "BitcoinExchange.hpp"
#include "inputCheck.hpp"

std::pair<std::string, double>  getInputData(std::string next_line, std::string delim);

int main(int argc, char** argv)
{
    std::ifstream   input(argv[1]);
    std::ifstream   data("./data.csv");
    std::string     next_line;
    std::pair<std::string, double>  input_pair;

    if (!fileCheck(argc, input, data))
        return (1);

    BitcoinExchange ftx(data);

    /* Read data from input file */
    std::map<std::string, double>::const_iterator it = ftx.beginExchangeRate();
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
            if ((input_pair.first == it->first))
            {
                std::cout << it->first << " => " << input_pair.second << " = " << input_pair.second * it->second << std::endl;
                break ;
            }
            if (input_pair.first > it->first)
            {
                std::cout << input_pair.first << " => " << input_pair.second << " = " << input_pair.second * it->second << std::endl;
                break ;
            }
            //std::cout << it->first << " and now second " << it->second << std::endl;
            it++;
        }

        // std::cout << input_pair.first << " and now second " << input_pair.second << std::endl;
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
