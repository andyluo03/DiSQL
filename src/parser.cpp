#include "parser.hpp"
#include <variant>

bool SelectNode::takeInput(std::variant<std::string, TOKENS> token, std::vector<std::shared_ptr<AstNode>>& stk){

    if(std::holds_alternative<std::string>(token)){

    }
    return 0;
}

std::shared_ptr<AstNode> parse_sql(std::vector<std::variant<std::string,TOKENS>> tokens){
    std::vector<std::shared_ptr<AstNode>> stk;

    auto expression = std::make_shared<ExpressionNode>();
    stk.push_back(expression);

    for(const auto& token : tokens){
        stk.back()->takeInput(token, stk);
    }

    return expression;
}