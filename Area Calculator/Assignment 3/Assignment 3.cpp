

#include <iostream>

using namespace std;

struct ShapeVtable;

struct Shape {
    ShapeVtable* vtable;
};

struct ShapeVtable {
    double (*GetArea)(Shape*);
};

double GetArea(Shape* shape)
{
    return shape->vtable->GetArea(shape);
}

struct Circle {
    Shape parent;
    double radius;
};

double CircleArea(Circle* circle) 
{
   return circle->radius* circle->radius* 3.14;
}

ShapeVtable circle_vtable =
{
    (double(*)(Shape*)) CircleArea
};

void CircleInitialize(Circle* circle, int radius)
{
    circle->parent.vtable = &circle_vtable;
    circle->radius = radius;
}

struct Rectangle {
    Shape parent;
    int width;
    int height;
};

double RectangleArea(Rectangle* rectangle)
{
    return rectangle->width * rectangle->height;
}

ShapeVtable rectangle_vtable =
{
    (double(*)(Shape*)) RectangleArea
};

void RectangleInitialize(Rectangle* rectangle, int width, int height)
{
    rectangle->parent.vtable = &rectangle_vtable;
    rectangle->width = width;
    rectangle->height = height;
}

struct Square {
    Shape parent;
    int length;
};

double SquareArea(Square* square)
{
    return square->length * square->length;
}

ShapeVtable square_vtable =
{
    (double(*)(Shape*)) SquareArea
};

void SquareInitialize(Square* square, int length)
{
    square->parent.vtable = &square_vtable;
    square->length = length;
}

int main()
{
    Circle circle;
    CircleInitialize(&circle, 10); // circle with radius 10

    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5); // rectangle with width 3 and height 5

    Square square;
    SquareInitialize(&square, 7); // square with side length 7

    Shape* shapes[3];
    shapes[0] = (Shape*)&circle;
    shapes[1] = (Shape*)&rectangle;
    shapes[2] = (Shape*)&square;

        double total_area = 0;

    int i;
    for (i = 0; i < 3; i++)
    {
        double d = GetArea(shapes[i]);
        total_area += d;
    }

    cout << total_area << endl; // check if the value is correct

    return 0;
}


