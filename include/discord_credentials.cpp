#include "discord_credentials.hpp"

namespace DiSQL {

bool DiscordCredentials::available(){
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

std::string DiscordCredentials::get_token(){
    usage_++;
    return this->token_;
}

}
