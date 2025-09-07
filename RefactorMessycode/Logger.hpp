#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>
#include <fstream>
/**
 * @brief Simple RAII Logger for timestamped entries.
 */
class Logger {
public:
    /**
     * @brief Construct a logger for a given file path.
     * @param path Log file path
     */
    explicit Logger(const std::string& path);
    /**
     * @brief Log a string entry with timestamp.
     * @param entry Log message
     */
    void log(const std::string& entry);
private:
    std::ofstream ofs_;
};
#endif // LOGGER_HPP
