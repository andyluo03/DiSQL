cmake_minimum_required(VERSION 3.28.2)

project(DiSQLLib)

file(GLOB SOURCES 
    discord.cpp
    discord_credentials.cpp
    row_node.cpp
    schema.cpp
)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git
                     GIT_TAG e69e5f9)
FetchContent_MakeAvailable(fmt)

add_library(DiSQLLib STATIC ${SOURCES})
set_property(TARGET DiSQLLib PROPERTY CXX_STANDARD 20)
target_link_libraries(DiSQLLib PRIVATE cpr::cpr fmt)