#pragma once

#include <iostream>
#include <string_view>
#include <chrono>
#include <format>
#include <source_location>
#include "LogEntry.h"

//Allows the logging of information

class Logger
{
private:
    static std::string CurrentDate();
public:
    Logger() {};
    ~Logger() = default;

    static LogEntry CreateLogEntry(LogLevel level, std::string_view message, std::source_location = std::source_location::current());
    static void Log(LogLevel level, std::string_view message, std::source_location = std::source_location::current());
    static std::string LogEntryFormatter(const LogEntry& log);
    static std::string LogLevelToString(LogLevel level);
};