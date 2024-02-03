#include <vector>
#include <memory>
#include <string>
#include <variant>
#include <map>

enum TOKENS {
    SELECT,
    FROM,
    WHERE,
    AND,
    OR,
    NOT,
    INSERT,
    INTO,
    UPDATE,
    SET,
    DELETE,
    CREATE,
    SPACE,
    END_STMT,
    COMMA,
    EQUALS,
};

const std::map<std::string, TOKENS> to_token = {
    {"SELECT", TOKENS::SELECT},
    {"FROM", TOKENS::FROM},
    {"WHERE", TOKENS::WHERE},
    {"AND", TOKENS::AND},
    {"OR", TOKENS::OR},
    {"NOT", TOKENS::NOT},
    {"INSERT", TOKENS::INSERT},
    {"INTO", TOKENS::INTO},
    {"UPDATE", TOKENS::UPDATE},
    {"SET", TOKENS::SET},
    {"DELETE", TOKENS::DELETE},
    {"CREATE", TOKENS::CREATE},
    {" ", TOKENS::SPACE},
    {";", TOKENS::END_STMT},
    {",", TOKENS::COMMA},
    {"=", TOKENS::EQUALS},
};

class AstNode {

};

std::vector<std::variant<TOKENS, std::string>> lex_sql(std::string sql);

std::shared_ptr<AstNode> parse_sql(std::vector<TOKENS>);
