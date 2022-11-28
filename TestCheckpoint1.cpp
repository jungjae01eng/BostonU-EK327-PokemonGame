// Jungjae Lee
// Boston University College of Engineering
// EC 327 Programming Assignment 3
// November 23, 2022

// required header-file
#include <iostream>
#include <cmath>

using namespace std;


int main () {
    Point2D tp1 = Point2D();
    Point2D tp2 = Point2D(3.0, 4.5);
    Point2D tp3 = Point2d(5.5, 9.8);


    GameObject person1 = GameObject('j');
    GameObject person2 = GameObject(tp2, 55, 'k');

    Vector2D tvec1 = Vector2D();
    Vector2D tvec2 = Vector2D(8.2, 9.7);
    Vector2D tvec3 = Vector2D(5.5, 6.4);

    double distance1 = GetDistanceBetween(tp1, tp2);
    double distance2 = GetDistanceBetween(tp2, tp3);

    cout << distance1 << endl;
    cout << distance2 << endl

    person1.ShowStatus();
    person2.ShowStatus();
    tp1 = tp1 + tvec2;
    tvec2 = tvec2 * 2;
    Vector2D tvec5 = tp3 - tp2;

    cout << tp1 << endl;
    cout << tvec3 << endl;
    cout << tvec2 << endl;
    cout << tvec5 << endl;

    Vector2D tvec4 = Vector2D(11.5, 12.7);
    tvec4 = tvec4/2.5;
    cout << tvec4 << endl;
    tvec2 = tvec2/0;
    cout << tvec2 << endl;


    return 0;
}