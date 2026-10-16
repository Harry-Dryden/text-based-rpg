#include "Logger.h"

//Gets the current date from the clock, formats it and returns it as a string
std::string Logger::CurrentDate()
{
    using namespace std::chrono;

    auto now = system_clock::now();

    return std::format("{:%Y-%m-%d %H:%M:%S}", now);
}

//The master method for logging, that calls the other methods
//Takes in the level of severity, the message, and the source location
void Logger::Log(LogLevel level, const std::string_view message, std::source_location location)
{
    LogEntry newLog = CreateLogEntry(level, message, location); //create a log entry
    std::string logStr = LogEntryFormatter(newLog); //format the entry into a string
    std::cout << logStr; //output the string
}

//creates a new log entry and sets its vars, then returns the struct
LogEntry Logger::CreateLogEntry(LogLevel level, const std::string_view message, std::source_location location)
{
    LogEntry newLog;
    newLog.timeStamp = CurrentDate(); //get the current date from the method
    newLog.level = level;
    newLog.fileName = location.file_name();
    newLog.line = location.line();
    newLog.function = location.function_name();
    newLog.message = message;
    return newLog;
}

//passes the log entry in as a reference, then formats it into a string
std::string Logger::LogEntryFormatter(const LogEntry& log){
    std::string levelStr = LogLevelToString(log.level); //convert the level into a string from an enum
    return std::format("[{}] [{}] {}:{} ({}) {} \n", log.timeStamp, levelStr, log.fileName, log.line, log.function, log.message);
}

//converts the level to a string, with a default unknown
std::string Logger::LogLevelToString(LogLevel level)
{
    switch (level)
    {
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}