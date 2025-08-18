#include "../include/BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::tm;
using std::vector;

time_t BitcoinExchange::_dateToEpoch(string date) {
  struct tm tm;
  time_t epoch;
  if (strptime(date.c_str(), "%Y-%m-%d", &tm))
    epoch = timegm(&tm);
  else
    throw std::runtime_error("failed to convert epoch to str");
  return epoch;
}

string BitcoinExchange::_epochToDate(time_t epoch) {
  char dateBuf[11];
  if(!strftime(dateBuf, sizeof(dateBuf), "%Y-%m-%d", gmtime(&epoch)))
    throw std::exception();
  return string(dateBuf);
}

time_t BitcoinExchange::_findNearestEpoch(time_t epoch) {
    if (_dbMap->find(epoch) == _dbMap->end()) {
        time_t nearest = _dbMap->begin()->first;
        for (map<time_t, float >::iterator it = _dbMap->begin(); it != _dbMap->end(); ++it) {
            if (epoch > nearest && epoch < it->first) {
                epoch = nearest;
                break;
            }
            nearest = it->first;
        }
    }
    return epoch;
}

float BitcoinExchange::_multiplyRateByDate(time_t epoch, float value) {
   epoch = _findNearestEpoch(epoch);
   float rate = (*_dbMap)[epoch];
   return value * rate;
}

bool BitcoinExchange::_isValidDate(string date) {
  // check date format (length position of - and if they are digits in correct
  // places)
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  for (int i = 0; i < 10; i++) {
    if (i != 4 && i != 7 && !std::isdigit(date[i]))
      return false;
  }
  // num conversion
  int y, m, d;
  y = std::atoi(date.substr(0, 4).c_str());
  m = std::atoi(date.substr(5, 6).c_str());
  d = std::atoi(date.substr(8, 9).c_str());

  // Actually check if the dates are in the gregorian calendar
  // Reference from
  // http://www.zedwood.com/article/cpp-checkdate-function-date-validation
  if (!(1 <= m && m <= 12) || !(1 <= d && d <= 31))
    return false;
  if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
    return false;
  if ((d == 30) && (m == 2))
    return false;
  if ((m == 2) && (d == 29) && (y % 4 != 0))
    return false;
  if ((m == 2) && (d == 29) && (y % 400 == 0))
    return true;
  if ((m == 2) && (d == 29) && (y % 100 == 0))
    return false;
  if ((m == 2) && (d == 29) && (y % 4 == 0))
    return true;
  return true;
}

std::map<time_t, float > *
BitcoinExchange::_dbFileToMap(string filePath) {
  std::ifstream dbFile(filePath.c_str());
  if (!dbFile.good())
    throw std::exception();

  string line, date, value;
  std::map<time_t,  float > *dbMap = new std::map<time_t, float >;

  // Handle the first line
  std::getline(dbFile, line);
  if (line != "date,exchange_rate")
    throw std::exception();

  // We got to the values, lets parse!
  std::stringstream ss;
  while (std::getline(dbFile, line)) {
    // Get everything before the "," the date is there
    date = line.substr(0, line.find(","));
    // Call our date format checker
    if (!_isValidDate(date)) {
      std::cerr << "Error: bad date in .csv: " << date << std::endl;
      continue;
    }
    // Here we put everything after the "," inside a stringstream
    ss.str("");
    ss.clear();
    ss << line.substr(date.length() + 1);
    long double value;
    if (!(ss >> value)) {
      std::cerr << "Error: bad value in .csv: " << value << std::endl;
      continue;
    }
    time_t epoch = _dateToEpoch(date);
    // Check if the key with the unix timestamp is already created
    (*dbMap)[epoch] = value;
  }
  return dbMap;
}

std::map<time_t, vector<float> > *
BitcoinExchange::_inputFileToMap(string filePath) {
  std::ifstream inputFile(filePath.c_str());
  if (!inputFile.good())
    throw std::exception();

  string line, date, value;
  std::map<time_t, vector<float> > *inputMap =
      new std::map<time_t, vector<float> >;

  // Handle the first line
  std::getline(inputFile, line);
  if (line != "date | value")
    throw std::exception();

  // We got to the values, lets parse!
  std::stringstream ss;
  while (std::getline(inputFile, line)) {
    // Get everything before the "," the date is there
    date = line.substr(0, line.find(" | "));
    // Call our date format checker
    if (!_isValidDate(date)) {
      std::cerr << "Error: bad date in input.txt!: " << date << std::endl;
      continue;
    }
    // Here we put everything after the " | " inside a stringstream
    ss.str("");
    ss.clear();
    ss << line.substr(date.length() + 3);
    long double value;
    std::cout << "debug value: " << value << std::endl;
    if (!(ss >> value) || value > 1000 || value < 0) {
      std::cerr << "Error: bad value in input.txt!: " << value << std::endl;
      continue;
    }
    time_t epoch = _dateToEpoch(date);
    if (_dbMap->find(epoch) != _dbMap->end()) {
      (*inputMap)[epoch] = std::vector<float>();
    }
    (*inputMap)[epoch].push_back(value);
  }
  return inputMap;
}
/*
BitcoinExchange::BitcoinExchange(string dbPath, string inputPath) {
  _dbMap = _dbFileToMap(dbPath);
  _inputMap = _inputFileToMap(inputPath);
  std::map<time_t, vector<float> >::iterator mIt;
  for (mIt = _inputMap->begin(); mIt != _inputMap->end(); ++mIt) {
    std::cout << "Date: " << _epochToDate(mIt->first) << " Values: ";
    for (vector<float>::iterator vIt = mIt->second.begin();
         vIt != mIt->second.end(); ++vIt) {
      std::cout << *vIt << ", ";
    }
    std::cout << std::endl;
  }
}
*/

BitcoinExchange::BitcoinExchange(string dbPath, string inputPath) {
  _dbMap = _dbFileToMap(dbPath);
  _inputMap = _inputFileToMap(inputPath);
  std::map<time_t, vector<float> >::iterator mIt;
  for (mIt = _inputMap->begin(); mIt != _inputMap->end(); ++mIt) {
    time_t epoch = mIt->first;
    string date = _epochToDate(epoch);
    for (vector<float>::iterator vIt = mIt->second.begin();
         vIt != mIt->second.end(); ++vIt) {
    float rate = _multiplyRateByDate(epoch, *vIt);
      std::cout << date << " => " << *vIt << " = " << rate << std::endl;
  }
}
}

BitcoinExchange::~BitcoinExchange() { delete _dbMap; }
