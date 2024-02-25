#ifndef DISQL_TABLE
#define DISQL_TABLE

#include <string>
#include <vector>

//Should be a fully local return type. Will be translated into bits and sent over the networking interface later...
namespace DiSQL {

class Table {
    Table(std::string name, std::string channel_id) : name_(name), channel_id_(channel_id) {}

    std::string getId() const;
    std::string getName() const;
    std::string getBegin() const;
    std::string getEnd() const;

    private:
    std::string name_;
    std::string channel_id_;

};

class LocalTable : public Table {
    public:

};

class ExpiringTable : public Table {

};



}

#endif