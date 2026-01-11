/**
 * Create objects without actually exposing concrete class
 */

#include <iostream>
#include <ostream>
#include <memory>

class Shape {
public:
    virtual ~Shape() =default;
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    virtual ~Rectangle() =default;
    void draw() override {
        std::cout<<"Rectangle draw"<<std::endl;
    }
};

class Circle : public Shape {
public:
    virtual ~Circle() =default;
    void draw() override {
        std::cout<<"Circle draw"<<std::endl;
    }
};

class FactoryMethod {
public:
    virtual ~FactoryMethod() =default;
    std::unique_ptr<Shape> create_shape(const std::string& type) {
        if (type == "circle") return std::make_unique<Circle>();
        if (type == "rectangle") return std::make_unique<Rectangle>();
        return nullptr;
    }
};