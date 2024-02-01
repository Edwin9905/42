#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <map>
#include <sstream>
#include <iterator>
#include <iomanip>


class BitcoinExchange {
private:
    std::string inputFilePath;
    std::map<std::string, double> csvData;
    
    bool isValidLine(std::string line) const;
    void setFile();
    void calAndPrint();
    void printFiles();
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &BitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange& BitcoinExchange);
public:
    BitcoinExchange(char *input);
    ~BitcoinExchange();
    class CanNotOpenFile : public std::exception
    {
        const char* what() const throw();
    };
};
