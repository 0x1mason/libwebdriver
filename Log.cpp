#include "Log.h"


void Log::print() {
  std::cout << "[" << timestamp << "]" << "[" << level << "]" << message << std::endl;
}