#include "log.hpp"
#include <iostream>
#include <sstream>
int main() {
    LOGGER log("file.txt");
log.log(WARNING, "=============== Program begins============");
log.log(ERROR, "ERROR");
return 0;
}