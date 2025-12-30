
#pragma once

#include <iostream>
#include <sstream>
#include <string_view>
#include <utility>

// parse int to string
std::pair<int, bool> parse_int(std::string_view sv);
std::pair<double, bool> parse_double(std::string_view sv);
double get_value(std::string_view prompt);
size_t get_option(std::string_view prompt, size_t max_opts);

inline double get_value(std::string_view prompt) {

  std::string in;
  do {

    std::cout << prompt;
    std::getline(std::cin, in);

    auto [value, status] = parse_double(in);

    if (!status) {
      std::cout << "Failed to parse your input. Try again.\n";
      continue;
    }

    return value;

  } while (true);
}

inline size_t get_option(std::string_view prompt, size_t max_opts) {

  std::string in;
  do {

    std::cout << prompt;
    std::getline(std::cin, in);

    auto [o, status] = parse_int(in);
    size_t opt = static_cast<size_t>(o);

    if (!status) {
      std::cout << "Failed to parse your input. Try again.\n";
      continue;
    }

    if (opt > max_opts || opt < 1) {
      std::cout << "Your choice is impossible. Try again.\n";
      continue;
    }

    return opt;

  } while (true);
}
inline std::pair<int, bool> parse_int(std::string_view sv) {
  std::stringstream ss;
  int out;

  if (!(ss << sv) || !(ss >> out)) {
    return {out, false};
  }

  return {out, true};
}

inline std::pair<double, bool> parse_double(std::string_view sv) {
  std::stringstream ss;
  double out;

  if (!(ss << sv) || !(ss >> out)) {
    return {out, false};
  }

  return {out, true};
}
