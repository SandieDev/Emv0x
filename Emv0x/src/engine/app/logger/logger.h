#pragma once
#include <string>

std::string logs_dir;
bool logs_enabled;

void logInfo(std::string message);

void logWarn(std::string message);

void logError(std::string message);