
#pragma once

#include <iostream>
#include <optional>
#include <sstream>
#include <string_view>

// parse int to string
std::optional<int> parse_int(std::string_view sv);
std::optional<double> parse_double(std::string_view sv);
double get_value(std::string_view prompt);
std::size_t get_option(std::string_view prompt, size_t max_opts);

inline double get_value(std::string_view prompt) {

  std::string in;
  do {

    std::cout << prompt;
    std::getline(std::cin, in);

    std::optional<double> in_fp = parse_double(in);
    if (!in_fp.has_value()) {
      std::cerr << "Failed to parse your input. Try again.\n";
      continue;
    }

    return *in_fp;

  } while (true);
}

inline std::size_t get_option(std::string_view prompt, size_t max_opts) {

  std::string in;
  do {

    std::cout << prompt;
    std::getline(std::cin, in);

    std::optional<int> in_n = parse_int(in);
    if (!in_n.has_value()) {
      std::cerr << "Failed to parse your input. Try again.\n";
      continue;
    }
    size_t opt = static_cast<size_t>(*in_n);

    if (opt > max_opts || opt < 1) {
      std::cerr << "Your choice is impossible. Try again.\n";
      continue;
    }

    return opt;

  } while (true);
}
inline std::optional<int> parse_int(std::string_view s) {

  std::stringstream ss{};
  int out;
  if (!(ss << s) || !(ss >> out)) {
    return {};
  }
  return out;
}

inline std::optional<double> parse_double(std::string_view sv) {
  std::stringstream ss{};
  double out;
  if (!(ss << sv) || !(ss >> out)) {
    return {};
  }

  return out;
}
