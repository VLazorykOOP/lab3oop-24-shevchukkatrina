#include <iostream>
#include <cmath>
#include <stdexcept>
#include<complex>

//завдання 1.5
class Triangle {
private:
    double side1, side2, side3;
    std::string color;

public:
    /*/ Конструктор з параметрами за замовчуванням для кольору
     Triangle(double s1, double s2, double s3, std::string c = "white") : side1(s1), side2(s2), side3(s3), color(c) {
         if (!is_valid_triangle(s1, s2, s3)) {
             throw std::invalid_argument("Invalid triangle sides");
         }
     }
     */
     // Конструктор без параметрів
    Triangle() : side1(0), side2(0), side3(0), color("white") {}

    // Конструктор з параметрами
    Triangle(double s1, double s2, double s3, std::string c = "white") : side1(s1), side2(s2), side3(s3), color(c) {
        if (!is_valid_triangle(s1, s2, s3)) {
            throw std::invalid_argument("Invalid triangle sides");
        }
    }
    // Функція для перевірки чи можливо побудувати трикутник із заданими сторонами
    static bool is_valid_triangle(double s1, double s2, double s3) {
        return (s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1);
    }
    // Функція для обчислення площі за формулою Герона
    double calculate_area() const {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Функція для обчислення периметру
    double calculate_perimeter() const {
        return side1 + side2 + side3;
    }
    // Функції-члени для встановлення значень сторін та кольору
    void set_sides(double s1, double s2, double s3) {
        if (!is_valid_triangle(s1, s2, s3)) {
            throw std::invalid_argument("Invalid triangle sides");
        }
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    void set_color(const std::string& c) {
        color = c;
    }

    // Функції-члени для отримання значень сторін та кольору
    double get_side1() const {
        return side1;
    }

    double get_side2() const {
        return side2;
    }

    double get_side3() const {
        return side3;
    }

    std::string get_color() const {
        return color;
    }
    // Функція для друку трикутника
    void print_triangle() const {
        std::cout << "Triangle with sides: " << side1 << ", " << side2 << ", " << side3 << " and color " << color << std::endl;
    }
};

