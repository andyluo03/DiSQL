#ifndef DISCORD_CREDENTIALS
#define DISCORD_CREDENTIALS

#include <string>
#include <ctime>

class discord_credentials {
    public:
    discord_credentials(const std::string& token);

    bool available();

    std::string& get_token();

    private:
    std::string token_;
    int usage_;
    std::time_t last_used_;
};

#endif
