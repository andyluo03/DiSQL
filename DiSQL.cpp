#include <iostream>
#include <vector>

#include <cpr/cpr.h>
#include "include/nlohmann/json.hpp"

#include "include/discord_credentials.hpp"
#include "include/discord.hpp"

//Usage: 
int main (int argc, char* argv[]) {
    //testing...

    std::string tables_channel_id = "1202825502432432148";
    std::string tables_message_id = "1205795425148473375";
    DiSQL::DiscordCredentials credentials("token");

    DiSQL::Discord client(credentials, tables_channel_id, tables_message_id);

    //auto result = client.getRow("1205796684769267722");
    //result.print();

    DiSQL::TableIterator a("Table_Name", std::make_shared<DiSQL::Discord>(client));

    //a.get().print();

    /**
    for(int i = 0; i < 3; i++){
        a.get().print();
        std::cout << std::endl;
        a.next();
    }
    **/

    //DiSQL::TableIterator b("Table_Name", std::make_shared<DiSQL::Discord>(client));
    
    DiSQL::RowNode example;
    //ceclient.insert_row(b, example);


    return 1;
}