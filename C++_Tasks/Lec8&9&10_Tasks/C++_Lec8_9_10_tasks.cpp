//---------  lec 8,9,10 ----------
// author: Ebrahim Mostafa

#include <bits/stdc++.h>

//---------------------- Task1 ----------------------
//-----------push_back vs emplace_back---------------
/*
push _ back
    • Function: It adds a copy of the object (or moves the object) 
        passed as an argument to the end of the container.
    • Usage: You need to pass an already constructed object or move an object to the container.

    std::vector<std::string> vec;
    vec.emplace_back("emplaced");  // directly constructs std::string with "emplaced" 
    at the end of the vector
*/
/*
emplace_back
    • Function: It constructs the element in place at the end of the container. 
        This avoids extra copies or moves by directly constructing the object
        using the provided arguments.
    • Usage: You pass the constructor arguments of the element you want to add to the container.

    std::vector<std::string> vec;
    vec.emplace_back("push_back");  // // directly constructs std::string with 
    "emplaced" at the end of the vector
*/

//---------------------- Task2 ----------------------
//https://cplusplus.com/reference/
//            Containers
/*
1-  array
2-  vector
3-  set       & multiset
4-  map       & unordered_map
5-  list      & forward_list
6-  queue     & priority_queue 
7-  stack
*/
//---------------------- Task3 ----------------------
/*
    Interface and Multiple Inheritance:
    -Create an interface class Drawable with a pure virtual function draw().
    -Derive classes like Circle, Rectangle, and Triangle from Shape and 
    implement the Drawable interface.
    -Create objects of these derived classes and call the draw() function 
    through a pointer to th Drawable interface
*/

class Drawable {
    public:
    virtual void draw() = 0;
    virtual void resize(double factor) = 0;
    virtual ~Drawable(){
        std::cout << "Drawable destructor called" << std::endl;
    }
};
class Shape{
    protected:
        std::string name;
    public:
        Shape(const std::string& shapeName):name(shapeName){}
        virtual double area()const =0;
        virtual double perimeter()const=0;
        virtual ~Shape(){
            std::cout << "Shape destructor called" << std::endl;
        }
};
// Derived class Circle from Shape and implementing Drawable
class Circle: public Shape,public Drawable {
    private:
        double radius;
    public:
        Circle(double r) : Shape("Circle"), radius(r) {}
        void draw()  override {
            std::cout << "Drawing circle: " << radius << std::endl;
        }
        void resize(double factor) override {
        radius *= factor;
        std::cout << "Resized Circle to radius " << radius << std::endl;
        }
        // Implementing Shape::area
        double area() const override {
            return M_PI * radius * radius;
        }
        // Implementing Shape::perimeter
        double perimeter() const override {
            return 2 * M_PI * radius;
        }
        ~Circle() {
            std::cout << "Circle specific destruction." << std::endl;
        }
};

// Derived class Rectangle from Shape and implementing Drawable
class Rectangle : public Shape, public Drawable {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h) : Shape("Rectangle"), width(w), height(h) {}
        // Implementing Drawable::draw
        void draw()  override {
            std::cout << "Drawing a Rectangle with width " << width << " and height " << height << std::endl;
        }
        // Implementing Drawable::resize
        void resize(double factor) override {
            width *= factor;
            height *= factor;
            std::cout << "Resized Rectangle to width " << width << " and height " << height << std::endl;
        }
        // Implementing Shape::area
        double area() const override {
            return width * height;
        }
        // Implementing Shape::perimeter
        double perimeter() const override {
            return 2 * (width + height);
        }
        ~Rectangle() {
            std::cout << "Rectangle specific destruction." << std::endl;
        }
};

// Derived class Triangle from Shape and implementing Drawable
class Triangle : public Shape, public Drawable {
    private:
        double a, b, c;  // Sides of the triangle
    public:
        Triangle(double sideA, double sideB, double sideC) : Shape("Triangle"), a(sideA), b(sideB), c(sideC) {}
        // Implementing Drawable::draw
        void draw()  override {
            std::cout << "Drawing a Triangle with sides " << a << ", " << b << ", " << c << std::endl;
        }
        // Implementing Drawable::resize
        void resize(double factor) override {
            a *= factor;
            b *= factor;
            c *= factor;
            std::cout << "Resized Triangle sides to " << a << ", " << b << ", " << c << std::endl;
        }
        // Implementing Shape::area using Heron's formula
        double area() const override {
            double s = (a + b + c) / 2;
            return std::sqrt(s * (s - a) * (s - b) * (s - c));
        }
        // Implementing Shape::perimeter
        double perimeter() const override {
            return a + b + c;
        }
        ~Triangle() {
            std::cout << "Triangle specific destruction." << std::endl;
        }
};


int main() {
    // Create objects of derived classes
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Triangle triangle(3.0, 4.0, 5.0);

    // Array of Drawable pointers
    Drawable* shapes[3];
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &triangle;
    
    // Loop to draw all shapes and display their area and perimeter
    for (int i = 0; i < 3; ++i) {
        shapes[i]->draw();  // Call draw function through Drawable interface
        Shape* shapePtr = dynamic_cast<Shape*>(shapes[i]);  // Downcast to Shape to access area and perimeter
        if (shapePtr) {
            std::cout << "Area: " << shapePtr->area() << std::endl;
            std::cout << "Perimeter: " << shapePtr->perimeter() << std::endl;
        }
        std::cout << std::endl;
    }
    // Resizing the shapes
    std::cout << "Resizing shapes by a factor of 2." << std::endl;
    for (int i = 0; i < 3; ++i) {
        shapes[i]->resize(2.0);
        shapes[i]->draw();  // Draw again after resizing
        std::cout << std::endl;
    }
    return 0;
}


