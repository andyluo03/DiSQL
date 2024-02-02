#ifndef DISCORD_CLIENT
#define DISCORD_CLIENT

#include <memory>
#include <queue>
#include <string>
#include "models/discord_credentials.hpp"

class discord_client {
    public:

    discord_client(discord_credentials& credentials);

    bool execute();

    void add_query(const std::string& query);

    private:
    discord_credentials& credentials_;
    std::queue<std::string> queries_;
};

#endif