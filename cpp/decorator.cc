/**
 * Add behavior without changing the original class
 */

#include <memory>
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual double cost() const = 0;
};

class SimpleCoffee : public Coffee {
public:
    double cost() const override { return 5.0; }
};

class MilkDecorator : public Coffee {
public:
    explicit MilkDecorator(std::unique_ptr<Coffee> coffee)
        : coffee_(std::move(coffee)) {}

    double cost() const override {
        return coffee_->cost() + 1.5;
    }

private:
    std::unique_ptr<Coffee> coffee_;
};

auto coffee = std::make_unique<MilkDecorator>(
    std::make_unique<SimpleCoffee>()
);
