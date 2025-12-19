#include "ioparse/prompt.hpp"
#include "ioparse/parse.hpp"

#include <iostream>

double get_value(std::string_view prompt) {

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

size_t get_option(std::string_view prompt, size_t max_opts) {

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
