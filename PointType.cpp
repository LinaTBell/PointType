#include <cmath> // for sqrt function
#include <iostream>
template<typename T>
class PointType {
private:
    T x;
    T y;

public:
    // Constructors
    PointType() : x(0), y(0) {}
    PointType(T x, T y) : x(x), y(y) {}

    // Setters
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    // Getters
    T getX() const { return x; }
    T getY() const { return y; }

    // Calculate distance between this point and another point
    double distanceTo(const PointType<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    // Overload subtraction operator -
    double operator-(const PointType<T>& other) const {
        return distanceTo(other);
    }
};

// Example usage
int main() {
    // Example with integer coordinates
    PointType<int> p1(1, 2);
    PointType<int> p2(4, 6);

    // Calculate distance between p1 and p2
    double dist = p1 - p2;
    std::cout << "Distance between p1 and p2: " << dist << std::endl;

    // Example with decimal coordinates
    PointType<double> p3(1.5, 2.5);
    PointType<double> p4(4.5, 6.5);

    // Calculate distance between p3 and p4
    double dist2 = p3 - p4;
    std::cout << "Distance between p3 and p4: " << dist2 << std::endl;

    return 0;
}