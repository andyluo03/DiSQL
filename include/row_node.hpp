#ifndef DISQL_ROW
#define DISQL_ROW

#include <vector>
#include <string>
#include <variant>
#include <iostream>

#include <fmt/core.h>

#include "schema.hpp"

namespace DiSQL {

class RowNode {
    public:
    RowNode(std::string input);
    RowNode(){}
    RowNode(const RowNode& other){
        this->next_id_ = other.next_id_;
        this->version_ = other.version_;
        this->previous_id_ = other.previous_id_;
        this->values_ = other.values_;
    }

    RowNode(std::string version, std::string current_id, std::string previous_id, std::string next_id, std::vector<std::string> values) : 
        version_(version), current_id_(current_id), next_id_(next_id), previous_id_(previous_id), values_(values) {}

    std::string getNextId();
    std::string getPreviousId();
    std::string getCurrentId();
    std::vector<std::string> getValues();

    void setNextId(std::string next_id);
    void setPreviousId(std::string next_id);
    void setCurrentId(std::string current_id);

    std::string getRaw(Schema schema);
    std::string getRaw();

    void print(){
        std::cout << fmt::format("Version: {}\nNext ID: {}\nPrevious ID: {}\n", version_, next_id_, previous_id_);
        for(const std::string& column : values_){
            std::cout << column << std::endl;
        }
    }

    private:
    std::string version_;
    std::string next_id_;
    std::string previous_id_;
    std::string current_id_;
    std::vector<std::string> values_;
};

}

#endif