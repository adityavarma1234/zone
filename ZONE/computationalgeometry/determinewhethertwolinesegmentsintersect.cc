#include<iostream>

using namespace std;

inline int min(int a,int b)
{
    return a>b?b:a;
}

inline int max(int a,int b)
{
    return a>b?a:b;
}

struct point
{
    int x,y;
};

int direction(point pi,point pj,point pk)
{
    pk.x = pk.x - pi.x;
    pk.y = pk.y - pi.y;
    pj.x = pj.x - pi.x;
    pj.y = pj.y - pi.y;

    return pk.x*pj.y - pj.x*pk.y;
}

bool onSegment(point pi,point pj,point pk)
{
    if(min(pi.x,pj.x)<=pk.x && pk.x<= max(pi.x,pj.x) && (min(pi.y,pj.y)<=pk.y && pk.y<=max(pi.y,pj.y)))
        return true;
    else
        return false;
}

bool segementsIntersect(point p1,point p2,point p3,point p4)
{
    int d1,d2,d3,d4;
    d1 = direction(p3,p4,p1);
    d2 = direction(p3,p4,p2);
    d3 = direction(p1,p2,p3);
    d4 = direction(p1,p2,p4);

    if((d1>0 && d2<0) || (d1<0 && d2>0) && (d3>0 && d4<0) || (d3<0 && d4>0))
        return true;

    else if(d1==0 && onSegment(p3,p4,p1))
        return true;
    else if(d2==0 && onSegment(p3,p4,p2))
        return true;
    else if(d3==0 && onSegment(p1,p2,p3))
        return true;
    else if (d4==0 && onSegment(p1,p2,p4))
        return true;
    else
        return false;
}

int main()
{
    point p1,p2,p3,p4;
    p1.x =0;
    p1.y = 0;
    p2.x = 1;
    p2.y = 1;
    p3.x = 1;
    p3.y = 2;
    p4.x = 0;
    p4.y = -1;
    if(segementsIntersect(p1,p2,p3,p4))
        cout << "Segments Intersect\n";
    else
        cout << "Segementes don't Intersect\n";
    return 0;
}
