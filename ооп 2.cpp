#include <iostream>
#include <cmath>
using namespace std;
class Vector2D {
private:
    double x;
    double y;

public:
   
    Vector2D() : x(0), y(0) {}  

    Vector2D(double x, double y) : x(x), y(y) {
        if (isnan(x) || isnan(y) || isinf(x) || isinf(y)) {
            cerr << "Invalid initialization values. Setting to (0, 0)." << endl;
            this->x = 0;
            this->y = 0;
        }
        else {
            this->x = x;
            this->y = y;
        }
    }

    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {
        if (isnan(other.x) || isnan(other.y) || isinf(other.x) || isinf(other.y)) {
           cerr << "Invalid copy initialization values. Setting to (0, 0)." << endl;
            this->x = 0;
            this->y = 0;
        }
    }

    
    double& operator[](int index) {
        if (index == 0) return x;
        else if (index == 1) return y;
        else {
            static double error = 0;
            cout << "Index out of range." << endl;
            return error;
        }
    }

    const double& operator[](int index) const {
        if (index == 0) return x;
        else if (index == 1) return y;
        else {
            static double error = 0;
            cout << "Index out of range." << endl;
            return error;
        }
    }

   
    friend ostream& operator<<(ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    
    friend istream& operator>>(istream& is, Vector2D& vec) {
        is >> vec.x >> vec.y;
        if (std::isnan(vec.x) || std::isnan(vec.y) || std::isinf(vec.x) || std::isinf(vec.y)) {
            std::cerr << "Invalid input values. Setting to (0, 0)." << std::endl;
            vec.x = 0;
            vec.y = 0;
        }
        return is;
    }

    
    Vector2D& operator=(const Vector2D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

   
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector2D& other) const {
        return hypot(x, y) < hypot(other.x, other.y);
    }

    bool operator>(const Vector2D& other) const {
        return hypot(x, y) > hypot(other.x, other.y);
    }

    bool operator<=(const Vector2D& other) const {
        return !(*this > other);
    }

    bool operator>=(const Vector2D& other) const {
        return !(*this < other);
    }

   
    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    
    operator double*() {
        static double arr[2];
        arr[0] = x;
        arr[1] = y;
        return arr;
    }

    operator const double*() const {
        static double arr[2];
        arr[0] = x;
        arr[1] = y;
        return arr;
    }
};

int main() {
    int x, y, x1, y1;
    cout << "Enter first coordinates: ";
    cin >> x >> y;
    Vector2D v1(x,y);
    cout << "Enter second coordinates: ";
    cin >> x1 >> y1;
    Vector2D v2(x1, y1);

    
    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;

    
    Vector2D v5 = v1 * 2;

    
    double dotProduct = v1.dot(v2);

   
    bool isEqual = (v1 == v2);
    bool isNotEqual = (v1 != v2);
    bool isLess = (v1 < v2);
    bool isGreater = (v1 > v2);

    
   cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3 (v1 + v2): " << v3 << endl;
    cout << "v4 (v1 - v2): " << v4 << endl;
    cout << "v5 (v1 * 2): " << v5 << endl;
    cout << "Dot product (v1 . v2): " << dotProduct << endl;
    cout << "v1 == v2: " << boolalpha << isEqual << endl;
    cout << "v1 != v2: " << boolalpha << isNotEqual << endl;
    cout << "v1 < v2: " << boolalpha << isLess << endl;
    cout << "v1 > v2: " << boolalpha << isGreater << endl;

    return 0;
}