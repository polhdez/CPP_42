#pragma once
#include <ctime>
#include <map>
#include <string>
#include <list>

using std::map;
using std::pair;
using std::string;
using std::list;

class BitcoinExchange {
private:
  map<time_t, float> *_dbMap;
  map<time_t, list<float> > *_inputMap;
  map<time_t, float > *_dbFileToMap(string path);
  map<time_t, list<float> > *_inputFileToMap(string path);
  time_t _dateToEpoch(string date);
  string _epochToDate(time_t epoch);
  float _multiplyRateByDate(time_t epoch, float value);
  time_t _findNearestEpoch(time_t epoch);
  bool _isValidDate(string str);

public:
  BitcoinExchange(string dbPath, string inputPath);
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &be);
  BitcoinExchange &operator=(const BitcoinExchange& be);
};
