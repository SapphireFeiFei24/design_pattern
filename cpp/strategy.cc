/**
 * Swap algorithms at runtime without having to change the code
 */

#include <memory>
#include <algorithm>
#include <vector>
class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void sort(std::vector<int>& data) = 0;
};

class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::sort(data.begin(), data.end());
    }
};

class Context {
public:
    explicit Context(std::unique_ptr<SortStrategy> s)
        : strategy_(std::move(s)) {}

    void execute(std::vector<int>& data) {
        strategy_->sort(data);
    }

private:
    std::unique_ptr<SortStrategy> strategy_;
};
