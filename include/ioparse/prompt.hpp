#pragma once

#include <string_view>

double get_value(std::string_view prompt);
size_t get_option(std::string_view prompt, size_t max_opts);
