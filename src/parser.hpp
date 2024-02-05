#ifndef PARSER
#define PARSER

#include "lexxer.hpp"
#include <memory>
#include <vector>
#include <variant>
#include <string>
#include <optional>

class AstNode {
    public:
    //return 1 if worked -- return 0 if full.
    virtual bool takeInput(std::variant<std::string, TOKENS> token, std::vector<std::shared_ptr<AstNode>>& stk) = 0;

    virtual void printName();
    
    std::optional<std::string> get_value();
    private:
    size_t state_;
    size_t max_state_;
};

class SelectNode : public AstNode {
    public:
    bool takeInput(std::variant<std::string, TOKENS> token, std::vector<std::shared_ptr<AstNode>>& stk);
    

    private:
    std::optional<std::string> value_;
    std::shared_ptr<AstNode> rows_;
    std::shared_ptr<AstNode> source_;
    std::shared_ptr<AstNode> qualifiers_;
};

class ColumnsNode : public AstNode {

    private:
    std::vector<std::shared_ptr<AstNode>> values_; 
};

class ExpressionNode : public AstNode {

    private:
    std::shared_ptr<AstNode> next_;
};

class WhereNode : public AstNode {

};

class ValueNode : public AstNode {
    
    private:
    std::optional<std::string> value_;
};

std::shared_ptr<AstNode> parse_sql(std::vector<std::variant<std::string,TOKENS>> tokens);

#endif
