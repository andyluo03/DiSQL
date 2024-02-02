#include "discord_client.hpp"
#include "models/discord_credentials.hpp"

//potentially buggy?
discord_client::discord_client(discord_credentials& credentials) : credentials_(credentials) {}

void discord_client::add_query(const std::string &query){
    this->queries_.push(query);
}

bool discord_client::execute(){
    if(credentials_.available()){
        std::string& token = credentials_.get_token();


        return true;
    }

    return false;
}