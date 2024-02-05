#include <vector>
#include <variant>
#include <iostream>

#include "../lexxer.hpp"

#include <gtest/gtest.h>

TEST(ParseTest, ParseSelectStatement) {
  std::string stmt = "SELECT * FROM employees WHERE name = Jill;";
  auto tokens = lex_sql(stmt);

  for(auto i : tokens){
      try {
          std::cout << std::get<std::string>(i) << " ";
      } catch (...) {
          std::cout << std::get<TOKENS>(i) << " ";
      }
  }
}