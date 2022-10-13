//
// Created by lee on 2022/10/10.
//

#pragma once

#include "log.h"
namespace nepnep {

void Logger::logging(LogLevel iLevel, LogEvent::LogEventPtr pEvent) {

}

void LogAppender::log(LogLevel iLevel, LogEvent::LogEventPtr pEvent) {

}

std::string LogFormatter::formatLog(LogEvent::LogEventPtr pEvent) {
    return std::string();
}


}

