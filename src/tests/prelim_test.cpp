#include "../lexxer.hpp"
#include <iostream>

int main(){
    std::string sql_stmt = "SELECT * FROM ID, PRICE FROM shop WHERE name = sugar OR name = spice";
    
    auto output = lex_sql(sql_stmt);

    std::cout << output.size();
    for(auto i : output){
        try {
            std::cout << std::get<std::string>(i) << " ";
        } catch (...) {
            std::cout << std::get<TOKENS>(i) << " ";
        }
    }
}