/**
 * Make incompatible codes work together
 * Advantage: Make the code compatible without changing existing code
 * Disadvantage: Potential overhead and increased complexity
 */


class OldLogger {
public:
    void writeLog(const char* msg) {
        std::cout << msg << std::endl;
    }
};

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& msg) = 0;
};

class LoggerAdapter : public Logger {
public:
    explicit LoggerAdapter(OldLogger& old) : old_(old) {}

    void log(const std::string& msg) override {
        old_.writeLog(msg.c_str());
    }

private:
    OldLogger& old_;
};
