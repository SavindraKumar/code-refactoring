#include "Logger.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>

Logger::Logger(const std::string& path) : ofs_(path, std::ios::app)
{

}

void Logger::log(const std::string& entry)
{
    if (!ofs_) return;
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    ofs_ << std::put_time(std::localtime(&t), "%F %T") << " " << entry << "\n";
    ofs_.flush();
}
