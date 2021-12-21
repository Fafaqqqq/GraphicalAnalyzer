cmake_minimum_required(VERSION 3.21)
set(PROJECT_NAME LogConverter)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)


add_executable(${PROJECT_NAME} main.cpp LogConverter.cpp LogConverter.h
                                        ScriptParser.cpp ScriptParser.h
        )
