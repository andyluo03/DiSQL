#include "discord_credentials.hpp"

discord_credentials::discord_credentials(const std::string& token){
    this->token_ = token;
    this->last_used_ = std::time(nullptr);
}

bool discord_credentials::available(){
    if(this->usage_ < 50){
        return true;
    }

    std::time_t current_time = std::time(nullptr);

    //check if one second has elapsed
    if(current_time - this->last_used_ >= 1){
        this->usage_ = 0;
        this->last_used_ = current_time;
        return true;
    }

    return false;
}

std::string& discord_credentials::get_token(){
    usage_++;
    return this->token_;
}
