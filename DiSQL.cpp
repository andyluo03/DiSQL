#include <iostream>
#include <vector>

#include "src/connection.hpp"
#include "src/discord_client.hpp"
#include "src/models/discord_credentials.hpp"
#include "src/parser.hpp"

//Usage: 
int main (int argc, char* argv[]) {
    std::string token = argv[1];

    discord_credentials creds(token);
    discord_client client(creds);

    std::vector<std::string> sample_flow;

    for(std::string& sql_query : sample_flow){
        client.add_query(parse_sql(sql_query));
    }

    for(int i = 0; i < 5; i++){
        client.execute();
    }

    return 1;
}