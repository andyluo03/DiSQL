#include "row_node.hpp"
#include <stdexcept>

namespace DiSQL {

    std::string RowNode::getNextId(){
        return this->next_id_;
    }

    std::string RowNode::getPreviousId(){
        return this->previous_id_;
    }

    std::vector<std::string> RowNode::getValues(){
        return this->values_;
    }

    std::string RowNode::getCurrentId(){
        return this->current_id_;
    }

    void RowNode::setNextId(std::string next_id){
        this->next_id_ = next_id;
    }

    void RowNode::setPreviousId(std::string previous_id){
        this->previous_id_ = previous_id;
    }

    void RowNode::setCurrentId(std::string current_id){
        this->current_id_ = current_id;
    }

    std::string RowNode::getRaw(){
        std::string raw;
        raw = fmt::format("Version: {}\nPrevious:{}\nNext:{}\n", this->version_, this->previous_id_, this->next_id_);
        
        for(int i = 0; i < this->values_.size(); i++){
            raw += ':';
            raw += this->values_.at(i);
            raw += "\n";
        }
        
        return raw;
    }

    std::string RowNode::getRaw(Schema schema){
        if(schema.getSchema().size() != values_.size())
            throw std::invalid_argument("Schema and values do not match");
        std::string raw;
        raw = fmt::format("Version: {}\nPrevious:{}\nNext:{}\n", this->version_, this->previous_id_, this->next_id_);
        
        for(int i = 0; i < schema.getSchema().size(); i++){
            raw += schema.getSchema().at(i);
            raw += ':';
            raw += this->values_.at(i);
            raw += "\n";
        }
        
        return raw;
    }
}
