#include<cstdio>
#include<iostream>

using namespace std;

struct point
{
    int x,y;
};


//Returns true if p1 is clockwise from p2 with respect to origin
//false if p1 counterclockwise from p2
bool clockwise(point p1,point p2)
{
    return p1.x*p2.y-p2.x*p1.y>0?true:false;
}

int main()
{
    point p0,p1,p2;
    p0.x=0;
    p0.y=0;
    p1.x = 1;
    p1.y = 1;
    p2.x = 2;
    p2.y = 2;

    point a,b;
    //(p2-p0)*(p1-p0)
    a.x = p2.x - p0.x;
    a.y = p2.y - p0.y;
    b.x = p1.x - p0.x;
    b.y = p1.y - p0.y;

    if(clockwise(a,b))
     cout << "clock wise\tLeftturn\n";
     else cout << "counter clockwise\tRighturn\n";

    return 0;
}
