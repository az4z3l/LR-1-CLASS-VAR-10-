#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Triangle
{
    private:

    double a;
    double b;
    double angle;

    double side()
    {
        return sqrt(a*a+b*b-2*a*b*cos(angle*PI/180));
    }

    public:

    Triangle(double x = 0, double y = 0, double z = 0)
    {
        cout << "|I am using constructor. [Triangle(x,y,z)]|" << endl;
        a = x;
        b = y;
        angle = z;
    }

    Triangle(const Triangle &t)
    {
        cout << "|I am using copy constructor. [ = Triangle(&t)]|" << endl;
        a = t.a;
        b = t.b;
        angle = t.angle;
    }

    ~Triangle()
    {
        cout << "|I am destroy the object. [~Triangle()]|" << endl;
        // WHY? FOR WHAT? JUST TO SUFFER?
        delete &a;
        delete &b;
        delete &angle;
    }

    double get_a()
    {
        cout << "|I am getting a. [Triangle.get_a()]|" << endl;
        return a;
    }

    double get_b()
    {
        cout << "|I am getting b. [Triangle.get_b()]|" << endl;
        return b;
    }

    double get_angle()
    {
        cout << "|I am getting angle. [Triangle.get_angle()]|" << endl;
        return angle;
    }

    void set_a(double x)
    {
        cout << "|I am setting a. [Triangle.set_a()]|" << endl;
        a = x;
    }

    void set_b(double x)
    {
        cout << "|I am setting b. [Triangle.set_b()]|" << endl;
        b = x;
    }

    void set_angle(double x)
    {
        cout << "|I am setting angle. [Triangle.set_angle()]|" << endl;
        angle = x;
    }

    void keyboardin()
    {
        cout << "|I am reading the input. [Triangle.keyboardin()]|" << endl;

        cout << "Triangle's first side: ";
        cin >> a ;

        cout << "Triangle's second side: ";
        cin >> b ;

        cout << "Triangle's angle: ";
        cin >> angle ;

        getchar();
    }

    void allout()
    {
        cout << "|May I show you? [Triangle.allout()]|" << endl;

        cout << "Triangle's first side:" << endl;
        cout << a << endl;

        cout << "Triangle's second side:" << endl;
        cout << b << endl;

        cout << "Triangle's angle:" << endl;
        cout << angle << endl;
    }

    double perimetr()
    {
        cout << "|I am counting perimetr. [Triangle.perimetr()]|" << endl;
        return side()+a+b;
    }

    double square()
    {
        cout << "|I am counting a square. [Triangle.square()]|" << endl;
        return 0.5*a*b*sin(angle*PI/180);
    }

    double height()
    {
        cout << "|I am counting height. [Triangle.perimetr()]|" << endl;
        return 2*square()/side();
    }

    void type()
    {
        cout << "|I am finding his type. [Triangle.type()]|" << endl;
        if (angle == 90)
            cout << "This triangle is right." << endl;
        else if (angle < 180 && angle > 90)
            cout << "This triangle is obtuse." << endl;
        else if (angle > 0 && angle < 90)
            cout << "This triangle is acute." << endl;
        else
            cout << "This isn't triangle. He is bad type." << endl;
    }

    int operator== (Triangle &t)
    {
        cout << "|I am complaining. [==]|" << endl;
        return angle  == t.angle && a == t.a && b == t.b;
    }

};

int main()
{
    short int choice;

    cout << "[Creating triangles:]" << endl;
    Triangle mytriangle1;
    Triangle mytriangle2 = Triangle(5, 6, 70);

    mytriangle1.allout();
    mytriangle2.allout();

    cout << "[Copy triangles:]" << endl;
    mytriangle1 = Triangle(mytriangle2);

    mytriangle1.allout();
    mytriangle2.allout();

    cout << "[Equalizing copy and triangle.]" << endl;
    if(mytriangle1 == mytriangle2)
        cout << "EQUAL" << endl;

    cout << "Press to continue..." << endl;
    getchar();

    system("CLS");

    do
    {
        cout << "1st triangle:" << endl;
        mytriangle1.allout();

        cout << "CHOOSE METHODE:" << endl;
        cout << "[1]     Get 1st side    [1]" << endl;
        cout << "[2]     Get 2nd side    [2]" << endl;
        cout << "[3]       Get angle     [3]" << endl;
        cout << "[4]     Set 1st side    [4]" << endl;
        cout << "[5]     Set 2nd side    [5]" << endl;
        cout << "[6]       Set angle     [6]" << endl;
        cout << "[7]    Keyboard input   [7]" << endl;
        cout << "[8]       Perimetr      [8]" << endl;
        cout << "[9]        Square       [9]" << endl;
        cout << "[10]       Height       [10]" << endl;
        cout << "[11]        Type        [11]" << endl;
        cout << "[12]        Exit        [12]" << endl;

        cin >> choice;
        getchar();

        switch(choice)
        {
            case 1:
            cout << mytriangle1.get_a() << endl;
            break;

            case 2:
            cout << mytriangle1.get_b() << endl;
            break;

            case 3:
            cout << mytriangle1.get_angle() << endl;
            break;

            case 4:
            double fs;
            cin >> fs;
            getchar();
            mytriangle1.set_a(fs);
            break;

            case 5:
            double ss;
            cin >> ss;
            getchar();
            mytriangle1.set_b(ss);
            break;

            case 6:
            double tangle;
            cin >> tangle;
            getchar();
            mytriangle1.set_angle(tangle);
            break;

            case 7:
            mytriangle1.keyboardin();
            break;

            case 8:
            cout << mytriangle1.perimetr() << endl;
            break;

            case 9:
            cout << mytriangle1.square() << endl;
            break;

            case 10:
            cout << mytriangle1.height() << endl;
            break;

            case 11:
            mytriangle1.type();
            break;

            case 12:
            break;
        }

        cout << "Press to continue..." << endl;
        getchar();

        system("CLS");

    }while(choice != 12);

    return 0;
}


