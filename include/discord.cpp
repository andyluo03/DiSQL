#include "discord.hpp"
#include <cstdio>
#include <optional>
#include <stdexcept>

namespace DiSQL {

RowNode Discord::getRow(std::string message_id){
    if(typeid(this->tables_message_id_) == typeid(std::string)){
        std::cout << "Heck yeah" << std::endl;
    }
    std::cout << this->tables_message_id_ << std::endl; //why is it 0
    std::string query = fmt::format("https://discord.com/api/channels/{}/messages/{}", this->tables_channel_id_, message_id);

    //(TODO): Add error handling...
    std::string result = nlohmann::json::parse(cpr::Get(cpr::Url(query), cpr::Header{
        {"Authorization", fmt::format("Bot {}", this->credentials_.get_token())}
    }).text)["content"];

    std::stringstream input(result);
    std::string buffer;
    int i = 0;

    std::string version;
    std::string prev_id;
    std::string next_id;
    std::vector<std::string> values;

    //Hopefully the lambda is determined at COMPILE TIME
    //(TODO): move logic to RowNode constructor
    auto read_row = [](const std::string& line, std::string& a, std::string& b)->void{
        bool flag = false;
        for(const char& c : line){
            if(c == ':'){
                flag = true;
                continue;
            }

            if(flag){
                b+=c;
            }else{
                a+=c;
            }
        }
    };

    while(std::getline(input, buffer)){
        std::string dummy;
        switch (i) {
            case 0:{
                read_row(buffer, dummy, version);
                break;
            }
            case 1:{
                read_row(buffer, dummy, prev_id);
                break;
            }
            case 2:{
                read_row(buffer, dummy, next_id);
                break;
            }
            default:{
                values.push_back("");
                read_row(buffer, dummy, values.back());
            }
        }
        i++;
    }

    return RowNode(version, message_id, prev_id, next_id, values);
}

/**
bool Discord::insert_row(DIterator table_iterator, RowNode row_node){
    //Insert at the top!
    row_node.setPreviousId(table_iterator.get().getCurrentId());
    row_node.setNextId(table_iterator.get().getNextId());

    auto endpoint = cpr::Url(fmt::format("https://discord.com/api/channels/{}/messages/", this->tables_channel_id_));
    auto headers = cpr::Header {{"Authorization: ", fmt::format("Bot {}", this->credentials_.get_token())}};
    
    nlohmann::json body;
    body["content"] = row_node.getRaw(); //update when schemas are supported.

    cpr::Post(endpoint, body.dump(), headers);

    return true;
}   

**/

bool Discord::sql_create_table(std::string name, DiSQL::Schema){
    //Create a new message + store begin and begin + 1 message_id_

    //

    return true;
}

std::optional<std::string> Discord::get_table_start(std::string name){
    //copying lol
    auto passin = std::make_shared<Discord>(this);
    TableIterator tables(getRow(this->tables_message_id_), passin);
    while(tables.get().getNextId() != "END"){
        if(tables.get().getValues().size() >= 2 && tables.get().getValues()[0] == name){
            return tables.get().getValues()[1];
        }
        tables.next();
    }

    return std::nullopt;
}

TableIterator::TableIterator(std::string name, std::shared_ptr<Discord> client) : client_(client) {
    std::optional<std::string> start = client->get_table_start(name);

    //catch this later? could be find if the error just goes upward...
    current_row_ = client->getRow(*start);
};

void TableIterator::next(){
    if(this->current_row_.getNextId() != "END"){
        std::string new_current_id = this->current_row_.getNextId();
        current_row_ = client_->getRow(current_row_.getNextId());
        current_row_.setCurrentId(new_current_id);
    }
}

RowNode TableIterator::get(){
    return this->current_row_;
}

}