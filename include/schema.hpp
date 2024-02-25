#ifndef DISQL_SCHEMA
#define DISQL_SCHEMA

#include <vector>
#include <string>

namespace DiSQL {

class Schema {
    public:

    Schema(std::vector<std::string> schema);

    const std::vector<std::string>& getSchema();

    private:
    std::vector<std::string> schema_;
};

}

#endif