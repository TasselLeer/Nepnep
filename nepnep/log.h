//
// Created by lee on 2022/10/13.
//
#pragma once
#include <string>
#include <cstdint>
#include <memory>
#include <utility>

namespace nepnep
{
enum class LogLevel {
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
};

//日志本志
class LogEvent
{
public:
    using LogEventPtr = std::shared_ptr<LogEvent>;
//    LogEvent() = default;
//    ~LogEvent() = default;
private:

    const char* m_sFileName;
    uint32_t m_iThreadId;
    std::string m_sContent;
    //行数
    int32_t m_iLine;
    //时间
    uint64_t m_iTime;

};

//转换器
class LogFormatter {
public:
    using LogFormatterPtr = std::shared_ptr<LogFormatter>;
    std::string formatLog(LogEvent::LogEventPtr pEvent);

};

//输出地
class LogAppender {
public:
    using LogAppenderPtr = std::shared_ptr<LogAppender>;
    LogAppender() = default;
    virtual ~LogAppender() = default;
    void log(LogLevel iLevel, LogEvent::LogEventPtr pEvent);
private:
    LogLevel m_emLevel;
};

//日志器
class Logger {
public:
    using LoggerPtr = std::shared_ptr<Logger>;
    explicit Logger(std::string&& sName) : m_sName(std::forward<std::string>(sName)){}
    ~Logger() = default;
public:

    void logging(LogLevel iLevel, LogEvent::LogEventPtr pEvent);

private:
    std::string m_sName;
    LogLevel m_emLevel;
    LogAppender pAppender;
};

}