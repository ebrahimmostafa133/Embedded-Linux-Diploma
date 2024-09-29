//---------  lec 6,7 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>

//---------------------- Task2 ----------------------
// Create Class to handle Logs with different Levels and
// store Msgs as well for dump and clear the buffer
// LOG::Level(level::warn)<<” forget to close file “ ;
// LOG::Dump();
// LOG::Clear

class Logger {
public:
    // Define log levels
    enum class Level { INFO, WARN, ERROR };

    // Get the single instance of Logger (Singleton Pattern)
    static Logger& getInstance() {
        static Logger instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    // Disable copy constructor and assignment operator
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;

    // Log message with a specified level
    void log(Level level, const std::string& msg) {
        logBuffer.push_back({ level, msg });
    }

    // Dump all log messages to the console
    void dump() {
        for (const auto& entry : logBuffer) {
            std::cout << "[" << levelToString(entry.first) << "] " << entry.second << std::endl;
        }
    }

    // Clear the log buffer
    void clear() {
        logBuffer.clear();
    }

    // Set the log level for the next message
    Logger& operator<<(Level level) {
        currentLevel = level;
        return *this;
    }

    // Overload for logging string messages
    Logger& operator<<(const std::string& msg) {
        log(currentLevel, msg);
        return *this;
    }

    // Overload for logging any other type (e.g., integers, floats)
    template <typename T>
    Logger& operator<<(const T& value) {
        std::stringstream ss;
        ss << value;
        log(currentLevel, ss.str());
        return *this;
    }

private:
    Logger() : currentLevel(Level::INFO) {} // Private constructor

    // Convert log level to string
    std::string levelToString(Level level) {
        switch (level) {
        case Level::INFO: return "INFO";
        case Level::WARN: return "WARN";
        case Level::ERROR: return "ERROR";
        default: return "UNKNOWN";
        }
    }

    Level currentLevel; // Current log level
    std::vector<std::pair<Level, std::string>> logBuffer; // Buffer to store logs
};

// Example usage:
int main() {
    Logger& log = Logger::getInstance();

    log << Logger::Level::INFO << "Program started";
    log << Logger::Level::WARN << "Low disk space";
    log << Logger::Level::ERROR << "Unable to open file";

    std::cout << "Dumping logs:" << std::endl;
    log.dump();

    log.clear();
    std::cout << "Logs cleared." << std::endl;
    
    return 0;
}
