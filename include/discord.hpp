#ifndef DISQL_DISCORD
#define DISQL_DISCORD

#include <string>
#include <optional>
#include <memory>

#include <fmt/core.h>

#include "discord_credentials.hpp"
#include "qualifier.hpp"
#include "table.hpp"
#include "schema.hpp"
#include "row_node.hpp"
#include "nlohmann/json.hpp"
#include "cpr/cprtypes.h"
#include "qualifier.hpp"
#include <cpr/cpr.h>
#include <sstream>


namespace DiSQL {

//Really hacky solution... find something better... LOL!
class DIterator {
    public:
    virtual RowNode get(){return RowNode();}
    virtual void next(){}
};

class Discord {
    public:
    Discord(DiscordCredentials& credentials, std::string tables_channel_id, std::string tables_message_id) : 
        credentials_(credentials), tables_channel_id_(tables_channel_id), tables_message_id_(tables_message_id) {}

    LocalTable sql_select(Schema schema, DIterator table_iterator, Qualifier qualifier);

    bool sql_create_table(std::string name, Schema schema);

    RowNode getRow(std::string message_id);

    bool delete_rows(DIterator table_iterator, Qualifier qualifier);

    bool update_rows(DIterator table_iterator, Schema schema, Qualifier qualifier);

    bool insert_row(DIterator table_iterator, RowNode row_node);

    private:
    std::optional<std::string> get_table_start(std::string); //returns message_id of the first node of a table
    DiscordCredentials& credentials_;
    const std::string tables_message_id_; //This is the start node of the "tables" table
    const std::string tables_channel_id_;

    friend class TableIterator;
};

class TableIterator : public DIterator{
    public:
    //Find by table
    TableIterator(std::string table_name, std::shared_ptr<Discord> client);

    //Find by message_id
    TableIterator(const RowNode& current_row, std::shared_ptr<Discord> client) : current_row_(current_row) {}

    std::optional<std::string> get_message_id();

    RowNode get();

    void next();

    private:
    RowNode current_row_;
    std::shared_ptr<Discord> client_;
};


}

#endif