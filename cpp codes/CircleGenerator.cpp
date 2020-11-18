// Creating circle using Second-Order Midpoint Algorithm
#include <vector>
class Circle {
public:
    struct Coordinate { // Pixel defined or any coordinate using integer (e.g. console cursor position)
        short x, y;
        Coordinate(short x_new, short y_new){
            x = x_new;
            y = y_new;
        };
    };
    std:: vector<Coordinate> points; // Array of each points of the circle

    Circle (short radius, short x_center, short y_center) // Generate circle point coordinates
    {
        this->points.clear();
        short x = 0;
        short y = radius;
        short d = 1 - radius;
        short d_cont = 3;
        short d_shift = (-2 * radius) + 5;
        while (x <= y) {
            // quadrant 1
            // (x, y)
            this->points.push_back(Coordinate(x_center + x, y_center + y));
            // (y, x)
            this->points.push_back(Coordinate(x_center + y, y_center + x));

            // quadrant 2
            // (-x, y)
            this->points.push_back(Coordinate(x_center - x, y_center + y));
            // (-y, x)
            this->points.push_back(Coordinate(x_center - y, y_center + x));

            // quadrant 3
            // (-x, -y)
            this->points.push_back(Coordinate(x_center - x, y_center - y));
            // (-y, -x)
            this->points.push_back(Coordinate(x_center - y, y_center - x));

            // quadrant 4
            // (x, -y)
            this->points.push_back(Coordinate(x_center + x, y_center - y));
            // (y, -x)
            this->points.push_back(Coordinate(x_center + y, y_center - x));

            if (d < 0)
            {
                d = d + d_cont;
                d_cont = d_cont + 2;
                d_shift = d_shift + 2;
            }
            else 
            {
                d = d + d_shift;
                d_cont = d_cont + 2;
                d_shift = d_shift + 4;
                y = y - 1;
            }
            x = x + 1;
        }
    }
};