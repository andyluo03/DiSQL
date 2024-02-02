#include <string>

enum class TOKENS {
    CREATE,
    TABLE,
    JOIN,
    FROM,
    SELECT,
};

std::string parse_sql(std::string& sql_query);