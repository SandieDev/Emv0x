#pragma once
#include <string>

extern std::string logs_dir;
extern bool logs_enabled;

void logInfo(std::string message);

void logWarn(std::string message);

void logError(std::string message);