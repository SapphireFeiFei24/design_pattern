/**
 * One-to-many dependency between objects
 * Publish-Subscribe
 */
#include <vector>
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(int value) = 0;
};

class Subject {
public:
    void attach(Observer* obs) {
        observers_.push_back(obs);
    }

    void notify(int value) {
        for (auto* o : observers_) {
            o->update(value);
        }
    }

private:
    std::vector<Observer*> observers_;
};
