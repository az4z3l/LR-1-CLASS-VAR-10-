#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Triangle
{
    private:

    double a;
    double b;
    double side()
    {
        return sqrt(a*a+b*b-2*a*b*cos(angle*PI/180));
    }

    double angle;
    double cos2ndangle()
    {
        return (side()*side()+a*a-b*b)/2*side()*a;
    }
    double cos3rdangle()
    {
        return (side()*side()+b*b-a*a)/2*side()*b;
    }

    public:

    Triangle(double x = 3, double y = 4, double z = 90)
    {
        cout << "|I am using constructor. [Triangle(x,y,z)]|" << endl;

        set_a(x);
        set_b(y);
        set_angle(z);
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

        if(x <= 0)
        {
            throw invalid_argument("[a>0]");
        }

        else
            a = x;
    }

    void set_b(double x)
    {
        cout << "|I am setting b. [Triangle.set_b()]|" << endl;

        if(x <= 0)
        {
            throw invalid_argument("[b>0]");
        }

        else
            b = x;
    }

    void set_angle(double x)
    {
        cout << "|I am setting angle. [Triangle.set_angle()]|" << endl;

        if(x <= 0 || x >= 180)
        {
            throw invalid_argument("[0<angle<180]");
        }

        else
            angle = x;
    }

    void keyboardin()
    {
        cout << "|I am reading the input. [Triangle.keyboardin()]|" << endl;

        double x;

        cout << "Triangle's first side: ";

        while(true)
        {
            cin >> x;
            getchar();

            if(x <= 0)
                cout << "Type correct value. [a>0]" << endl;
            else
                break;
        }

        set_a(x);

        cout << "Triangle's second side: ";

        while(true)
        {
            cin >> x;
            getchar();

            if(x <= 0)
                cout << "Type correct value. [b>0]" << endl;
            else
                break;
        }

        set_b(x);


        cout << "Triangle's angle: ";

        while(true)
        {
            cin >> x;
            getchar();

            if(x <= 0 || x >= 180)
                cout << "Type correct value. [0<angle<180]" << endl;
            else
                break;
        }

        set_angle(x);
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
        if (angle == 90 || cos2ndangle() == 0 || cos3rdangle() == 0)
            cout << "This triangle is right." << endl;
        else if (angle < 180 && angle > 90 || cos2ndangle() < 0 || cos3rdangle() < 0)
            cout << "This triangle is obtuse." << endl;
        else if (angle > 0 && angle < 90 && cos2ndangle() > 0 && cos3rdangle() > 0)
            cout << "This triangle is acute." << endl;
        else
            cout << "This isn't triangle. It is a bad type." << endl;
    }

    bool operator== (Triangle &t)
    {
        cout << "|I am complaining. [==]|" << endl;
        return (a == t.a || a == t.b || a == t.side()) && (b == t.a || b == t.b || b == t.side()) && (this->side() == t.a || this->side() == t.b || this->side() == t.side());
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

    cout << "Press to continue..." << endl;
    getchar();

    system("CLS");

    do
    {
        cout << "[1st triangle:]" << endl;
        mytriangle1.allout();

        cout << "[2nd triangle:]" << endl;
        mytriangle2.allout();

        cout << "CHOOSE METHODE:" << endl;
        cout << "[1]     Get 1st side    [1]" << endl;
        cout << "[2]     Get 2nd side    [2]" << endl;
        cout << "[3]       Get angle     [3]" << endl;
        cout << "[4]     Set 1st side    [4]" << endl;
        cout << "[5]     Set 2nd side    [5]" << endl;
        cout << "[6]       Set angle     [6]" << endl;
        cout << "[7]  1st triangle(Keyb.)[7]" << endl;
        cout << "[8]  2nd triangle(Keyb.)[8]" << endl;
        cout << "[9]  Complain triangles [9]" << endl;
        cout << "[10]      Perimetr      [10]" << endl;
        cout << "[11]       Square       [11]" << endl;
        cout << "[12]       Height       [12]" << endl;
        cout << "[13]        Type        [13]" << endl;
        cout << "[14]        Exit        [14]" << endl;

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
            while(true)
            {
                cin >> fs;
                getchar();

                if(fs <= 0)
                    cout << "Type correct value. [a>0]" << endl;
                else
                    break;
            }
            mytriangle1.set_a(fs);
            break;

            case 5:
            double ss;
            while(true)
            {
                cin >> ss;
                getchar();

                if(ss <= 0)
                    cout << "Type correct value. [b>0]" << endl;
                else
                    break;
            }
            mytriangle1.set_b(ss);
            break;

            case 6:
            double tangle;
            while(true)
            {
                cin >> tangle;
                getchar();

                if(tangle <= 0 || tangle >= 180)
                    cout << "Type correct value. [0<angle<180]" << endl;
                else
                    break;
            }
            mytriangle1.set_angle(tangle);
            break;

            case 7:
            mytriangle1.keyboardin();
            break;

            case 8:
            mytriangle2.keyboardin();
            break;

            case 9:

            if(mytriangle1 == mytriangle2)
                cout << "EQUAL" << endl;

            else
                cout << "NON-EQUAL" << endl;

            break;

            case 10:
            cout << mytriangle1.perimetr() << endl;
            break;

            case 11:
            cout << mytriangle1.square() << endl;
            break;

            case 12:
            cout << mytriangle1.height() << endl;
            break;

            case 13:
            mytriangle1.type();
            break;

            case 14:
            break;
        }

        cout << "Press to continue..." << endl;
        getchar();

        system("CLS");

    }while(choice != 14);

    return 0;
}
