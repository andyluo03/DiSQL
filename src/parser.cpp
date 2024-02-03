#include "parser.hpp"
#include <stdexcept>
#include <variant>

std::vector<std::variant<TOKENS, std::string>> lex_sql(std::string sql){
    std::vector<std::variant<TOKENS, std::string>> lexxed;
    
    std::string buffer;
    for(int i = 0; i < sql.size(); i++){
        if(sql[i] == ',' || sql[i] == ' ' || sql[i] == ';'){
            if(to_token.find(buffer) != to_token.end()){
                lexxed.push_back(to_token.at(buffer));
            }else{
                lexxed.push_back(buffer);
            }

            switch (sql[i]){
                case ',':
                    lexxed.push_back(TOKENS::COMMA);
                    break;
                case ';':
                    lexxed.push_back(TOKENS::END_STMT);
                    return lexxed;
                    break;
            }
            
            buffer = "";
        }else{
            buffer += sql[i];
        }
    }

    throw std::invalid_argument("No end statement");
}

std::shared_ptr<AstNode> parse_sql(std::vector<TOKENS>){
    
}