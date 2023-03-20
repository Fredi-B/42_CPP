#ifndef INPUTCHECK_HPP
# define INPUTCHECK_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>

bool                            fileCheck(int argc, std::ifstream &input, std::ifstream &data);
std::pair<std::string, double>  getInputData(std::string next_line, std::string delim);
bool                            InputDataCheck(std::pair<std::string, double> data_pair);
bool                            isValidDate(std::string date);
bool                            isLeapYear(int year);

#endif
