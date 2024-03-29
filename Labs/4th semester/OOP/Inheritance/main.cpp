#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265359

struct Point{
    double x;
    double y;
};

class Shape{
    protected:
        double angle;
        Point center;
        unsigned color;
        static unsigned s_id;

    public:
        Shape(Point cntr, unsigned tcolor, double tangle){
            color = tcolor;
            center = cntr;
            if(tangle >= 360) residue(tangle);
            else angle = tangle;
        }

        void residue(double tangle){
            double tmp;
            this->angle = modf(tangle, &tmp);
            tmp = static_cast<int>(tmp) % 360;
            this->angle += tmp;
        }

        void rotate(double tangle){
            if(angle + tangle > 360) residue(angle + tangle);
            else angle += tangle;
        }

        void set_color(unsigned tcolor){
            color = tcolor;
        }

        unsigned get_color(){
            return color;
        }

        void move(Point topoint){
            center.x = topoint.x;
            center.y = topoint.y;
        }

        virtual ~Shape(){
            std::cout <<"~shape\n";
            //printstr();
        }
        virtual ostream & print(ostream &) const = 0;

        friend ostream & operator << (ostream & out, Shape const & shape){
            out << endl <<  "Center: ( " << shape.center.x << " . " << shape.center.y << " )" << endl
                << "Angle of rotation: " << shape.angle << endl
                << "Color: " << shape.color << endl;
            return shape.print(out);
        }
        virtual void printstr(){
            cout << "shape" << endl;
        }
};

unsigned Shape :: s_id = 0;

class Square : public Shape{
    protected:
        unsigned id;
        double side;
        double area;

    public:
        Square(Point cntr, unsigned tcolor, double tangle, double tside)
            : Shape(cntr, tcolor, tangle)
        {
            s_id++;
            id = s_id;
            side = tside;
            calcArea();
        }

        virtual void scaling(double factor){
            if(factor > 0){
                side *= factor;
            }
			calcArea();
        }

        virtual void calcArea(){
            area = side * side;
        }

        virtual ostream & print(ostream & out) const override {
            out << "Id of square: " << this->id << endl
                << "Side of square: " << this->side << endl
                << "Area of square: " << this->area << endl;
            return out;
        }

        ~Square() {
            std::cout <<"~square\n";
        }
};

class Rhombus : public Square{
    protected:
        double formingAng;

    public:
        Rhombus(Point cntr, unsigned tcolor, double tangle, double tside, double tformingAng)
            : Square(cntr, tcolor, tangle, tside)
        {
            double tmp;
            formingAng = modf(tformingAng, &tmp);
            tmp = static_cast<int>(tmp) % 180;
            formingAng += tmp;
        }

        virtual void calcArea() override{
            area = side * side * sin(formingAng / 180 * PI);
            cout << sin(formingAng / 180 * PI);
        }

        virtual ostream & print(ostream & out) const override {
            out << "Id of rhombus: " << this->id << endl
                << "Side of rhombus: " << this->side << endl
                << "Forming angle of rhombus: " << this->formingAng << endl
                << "Area of rhombus: " << this->area << endl;
            return out;
        }

        ~Rhombus()  {
            std::cout <<"~rhombus\n";

        }

};

class Parallelogram : public Rhombus{
    private:
        double otherside;

    public:
        Parallelogram(Point cntr, unsigned tcolor, double tangle, double tside, double tformingAng, double totherside)
            : Rhombus(cntr, tcolor, tangle, tside, tformingAng)
        {
            otherside = totherside;
            calcArea();
        }

        void scaling(double factor) override {
            if(factor > 0){
                side *= factor;
                otherside *= factor;
            }
        }

        void calcArea() override{
            area = side * otherside * sin(formingAng / 180 * PI);
        }

        ostream & print(ostream & out) const override {
            out << "Id of parallelogram: " << this->id << endl
                << "Side of parallelogram: " << this->side << endl
                << "Other side of parallelogram: " << this->otherside << endl
                << "Forming angle of parallelogram: " << this->formingAng << endl
                << "Area of parallelogram: " << this->area << endl;
            return out;
        }

        ~Parallelogram()  {}

};
