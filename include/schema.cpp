#include "schema.hpp"

namespace DiSQL {

Schema::Schema(std::vector<std::string> schema){
    for(std::string s : schema)
        schema_.push_back(s);
}

const std::vector<std::string>& Schema::getSchema(){
    return schema_;
};


}