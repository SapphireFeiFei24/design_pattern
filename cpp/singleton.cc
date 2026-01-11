/**
 * Usage: Global state, config, logging
 */

class Singleton {
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton& getInstance() {
        static Singleton instance; // thread-safe since C11
        return instance;
    }

private:
    Singleton() = default;
};
