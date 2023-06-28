cmake_minimum_required (VERSION 3.0.0)
project (concordo VERSION 0.1 LANGUAGES CXX)

include_directories(include)

add_executable( program
                src/main.cpp
                src/System.cpp
                src/User.cpp
                src/Server.cpp)
