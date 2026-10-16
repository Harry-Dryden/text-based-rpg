#pragma once

//This is an entry to the Log
//It is worked on by Logger.cpp
//It contains:
//A Timestamp
//A Level [INFO], [WARNING], [ERROR]
//Some source information
//A Message

#include <string>

enum class LogLevel {
    INFO, WARNING, ERROR, DEBUG
};

struct LogEntry {
    std::string timeStamp;
    LogLevel level;
    std::string fileName;
    int line;
    std::string function;
    std::string message;
};