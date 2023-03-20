#include "inputCheck.hpp"

bool    fileCheck(int argc, std::ifstream &input, std::ifstream &data)
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

bool    InputDataCheck(std::pair<std::string, double> data_pair)
{
    if (!isValidDate(data_pair.first))
    {
        std::cout << "Error: invalid date => " << data_pair.first << std::endl;
        return (false);
    }

    if (data_pair.second <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }
    if (data_pair.second >= 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (false);
    }
    return (true);
}

bool    isValidDate(std::string date)
{
    int year;
    int month;
    int day;
    std::stringstream   magical_converter_stream;

    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue ;
        if (!isdigit(date[i]))
            return (false);
    }
    magical_converter_stream << date.substr(0, 4);
    magical_converter_stream >> year;
    magical_converter_stream.clear();
    magical_converter_stream << date.substr(5, 2);
    magical_converter_stream >> month;
    magical_converter_stream.clear();
    magical_converter_stream << date.substr(8, 2);
    magical_converter_stream >> day;
    magical_converter_stream.clear();
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            if (day > 29)
                return (false);
        }
        else
        {
            if (day > 28)
                return (false);
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return (false);
    }
    return (true);
}

bool    isLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return (true);
    return (false);
}
