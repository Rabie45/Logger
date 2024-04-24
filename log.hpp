#include <ctime>
#include <fstream>
#include <string>
enum LOG {
  DUBUG,
  INFO,
  WARNING,
  ERROR,
  FATAL,
};
class LOGGER {
public:
  LOGGER(const std::string &file);
  ~LOGGER();
  void log(LOG level, const std::string &msg);

private:
  std::ofstream logFile;
  std::string levelToString(LOG level);
};