#include "ioparse/parse.hpp"
#include <sstream>

std::pair<int, bool> parse_int(std::string_view sv) {
  std::stringstream ss;
  int out;

  if (!(ss << sv) || !(ss >> out)) {
    return {out, false};
  }

  return {out, true};
}

std::pair<double, bool> parse_double(std::string_view sv) {
  std::stringstream ss;
  double out;

  if (!(ss << sv) || !(ss >> out)) {
    return {out, false};
  }

  return {out, true};
}
