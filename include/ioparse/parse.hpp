#pragma once

#include <string_view>
#include <utility>

// parse int to string
std::pair<int, bool> parse_int(std::string_view sv);

std::pair<double, bool> parse_double(std::string_view sv);
