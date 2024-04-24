#include "log.hpp"
#include <iostream>
#include <sstream>
LOGGER::LOGGER(const std::string &file) {
  logFile.open(file, std::ios::app);
  if (!logFile.is_open())
    std::cerr << "Error opening the file" << std::endl;
}
LOGGER::~LOGGER() { logFile.close(); }
void LOGGER::log(LOG level, const std::string &msg) {
  time_t now = time(0); // return time now
  tm *time = localtime(&now);
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time);
  std::ostringstream logEntry;
  logEntry << "[" << timestamp << "]" << levelToString(level) << ": " << msg
           << std::endl;
  std::cout << logEntry.str() << std::endl;
  if (logFile.is_open()) {
    logEntry << logEntry.str();
    logFile.flush();
  }
}

std::string LOGGER::levelToString(LOG level) {
  switch (level) {
  case DUBUG:
    return "DUBUG";
  case INFO:
    return "INFO";
  case WARNING:
    return "WARNING";
  case ERROR:
    return "ERROR";
  case FATAL:
    return "FATAL";
  }
  return 0;
}

