#ifndef DISCORD_CREDENTIALS
#define DISCORD_CREDENTIALS

#include <string>
#include <ctime>
#include <iostream>

namespace DiSQL {
class DiscordCredentials {
    public:
    DiscordCredentials(std::string token) : token_(token), usage_(0), last_used_(std::time(nullptr)) {}

    bool available();

    std::string get_token();

    private:
    std::string token_;
    int usage_;
    std::time_t last_used_;
};
}

#endif
