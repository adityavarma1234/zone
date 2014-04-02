/*
 * Needles and Pins
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>

const int NUM_VERTICES = 51;
const int MAX_LEN = 10000;
typedef long long int_t;

inline int_t abs(int_t a)
{
    return (a < 0 ? -a : a);
}

inline int_t gcd(int_t a, int_t b)
{
    return (b ? gcd(b, a%b) : a);
}

template<typename T>
struct TFraction
{
    T n, d;

    TFraction(T _n = 0, T _d = 1)
    {
        if (_d < 0)
            set(-_n, -_d);
        else
            set(_n, _d);
    }
    void operator=(int i)
    {
        n = i;
        d = 1;
    }
    bool undefined() const
    {
        return !d;
    }
    bool operator==(const TFraction& rhs) const
    {
        if (d && rhs.d)
            return (n * rhs.d) == (rhs.n * d);
        else
            return (n == rhs.n) && (d == rhs.d);
    }
    bool operator<(const TFraction& rhs) const
    {
        return (n * rhs.d) < (rhs.n * d);
    }
    bool operator>(const TFraction& rhs) const
    {
        return (n * rhs.d) > (rhs.n * d);
    }
    bool operator<=(const TFraction& rhs) const
    {
        return (n * rhs.d) <= (rhs.n * d);
    }
    bool operator>=(const TFraction& rhs) const
    {
        return (n * rhs.d) >= (rhs.n * d);
    }
    TFraction operator+(const TFraction& rhs) const
    {
        return TFraction(n*rhs.d + rhs.n*d, d*rhs.d);
    }
    void operator+=(const TFraction& rhs)
    {
        set(n*rhs.d + rhs.n*d, d*rhs.d);
    }
    void operator-=(const TFraction& rhs)
    {
        set(n*rhs.d - rhs.n*d, d*rhs.d);
    }
    TFraction operator*(const TFraction& rhs) const
    {
        return TFraction(n*rhs.n, d*rhs.d);
    }
    static T floor(TFraction f)
    {
        return f.n/f.d;
    }
    static T ceil(TFraction f)
    {
        return (f.n + f.d - 1)/f.d;
    }
    bool isInteger() const
    {
        return d == 1;
    }

private:
    void set(T _n, T _d)
    {
        if (!_n && !_d)
        {
            n = d = 0;
        }
        else
        {
            T g = gcd(abs(_n), abs(_d));
            n = _n/g;
            d = _d/g;
        }
    }
};

typedef TFraction<int_t> Fraction;

template<typename T>
struct TPoint
{
    T x, y;

    TPoint() : x(0), y(0) {}
    TPoint(T _x, T _y) : x(_x), y(_y) {}

    TPoint operator+(const TPoint &rhs) const
    {
        return TPoint(x + rhs.x, y + rhs.y);
    }
    TPoint operator-(const TPoint &rhs) const
    {
        return TPoint(x - rhs.x, y - rhs.y);
    }
    bool operator==(const TPoint &rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }
};

typedef TPoint<int_t> Point;
typedef TPoint<Fraction> PointF;

inline PointF operator*(Fraction f, Point p)
{
    return PointF(f*p.x, f*p.y);
}

inline Point integralPoint(PointF pf)
{
    return Point(pf.x.n, pf.y.n);
}

inline bool isIntegral(PointF pf)
{
    return pf.x.isInteger() && pf.y.isInteger();
}

struct Line
{
    Point p1, p2;
    Line() {}
    Line(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
    Fraction slope()
    {
        return Fraction(p2.y - p1.y, p2.x - p1.x);
    }
    int_t gcd()
    {
        return ::gcd(abs(p2.x - p1.x), abs(p2.y - p1.y));
    }
};

struct Vector
{
    int_t i, j;
    Vector() : i(0), j(0) {}
    Vector(int_t _i, int_t _j) : i(_i), j(_j) {}
    Vector(Point p) : i(p.x), j(p.y) {}
    int_t dot(Vector v) const
    {
        return (i*v.i) + (j*v.j);
    }
};

struct NormalVector : public Vector
{
    NormalVector() {}
    NormalVector(int_t _i, int_t _j)
    {
        int_t g = gcd(abs(_i), abs(_j));
        i = _i/g;
        j = _j/g;
    }
};

enum EventType
{
    E_START,
    E_END,
};

typedef std::multimap<int_t, Line*>::iterator MMIT;

struct Event
{
    int_t x;
    Line *line;
    EventType etype;
    MMIT mmit;

    Event() {}
    Event(int_t _x, Line *_line) : x(_x), line(_line), etype(E_START) {}
    Event(int_t _x, MMIT _mmit) : x(_x), etype(E_END), mmit(_mmit) {}
    bool operator<(const Event rhs) const
    {
        //STL makes it max priority_queue, but we need it ascending
        return x > rhs.x || (x == rhs.x && etype == E_END);
    }
};

class NeedlesPins
{
    std::vector<Point> vertices;
    std::vector<NormalVector> normals;
    std::list<Line> lines;
    std::priority_queue<Event> events;
    std::multimap<int_t, Line*> activeLines;

    int m_n, m_m;       //n-vertices, m-lines
    int_t boundaryNeedles, pins, innerNeedles;

    bool onright(Point, int) const;

public:
    NeedlesPins() : vertices(NUM_VERTICES), normals(NUM_VERTICES) {}
    void read();
    void solve();
};

void NeedlesPins::read()
{
    Point p;
    Line l;
    int i;

    std::cin >> m_n >> m_m;
    for (i = 0; i < m_n; i++)
    {
        std::cin >> p.x >> p.y;
        vertices[i] = p;
    }

    //Close the polygon
    vertices[i] = vertices[0];

    lines.clear();
    for (i = 0; i < m_m; i++)
    {
        std::cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
        lines.push_back(l);
    }
};

void NeedlesPins::solve()
{
    int_t area = 0;
    boundaryNeedles = pins = innerNeedles = 0;
    for (int i = 0; i < m_n; i++)
    {
        area += (vertices[i].x + vertices[i+1].x)
                *(vertices[i].y - vertices[i+1].y);
        boundaryNeedles += gcd(abs(vertices[i].x - vertices[i+1].x),
                          abs(vertices[i].y - vertices[i+1].y));
        normals[i] = NormalVector(vertices[i].y - vertices[i+1].y,
                                  vertices[i+1].x - vertices[i].x);
    }
    area = abs(area)/2;
    /*
     * Pick's Theorem
     */
    pins = area + 1 - boundaryNeedles/2;

    /*
     * Cyrus Beck Line Clipping
     */
    Fraction t, t1, t2;
    bool update, reject;

    std::list<Line>::iterator lit = lines.begin();
    while (lit != lines.end())
    {
        Point &pa = lit->p1;
        Point &pb = lit->p2;
        t1 = 0;
        t2 = 1;
        reject = false;
        for (int i = 0; i < m_n; i++)
        {
            int_t d = normals[i].dot(pa - pb);
            t = Fraction(normals[i].dot(pa - vertices[i]), d);

            if (t.undefined())  //parallel lines
            {
                if (!t.n || onright(pa, i))     //trivial reject
                {
                    reject = true;
                    break;
                }
                continue;
            }
            update = false;
            if (d < 0)          //entering
            {
                if (t >= t1)
                {
                    t1 = t;
                    update = true;
                }
            }
            else
            {
                if (t <= t2)
                {
                    t2 = t;
                    update = true;
                }
            }
            if (update)
            {
                if (t1 > t2)
                {
                    reject = true;
                    break;
                }
                int_t g = gcd(abs(pa.x - pb.x), abs(pa.y - pb.y));
                if (d < 0)
                {
                    if (!(g % t1.d))
                        t1 += Fraction(1, g);
                    Fraction k(Fraction::ceil(t1*g), g);
                    pa = pa + integralPoint(k*(pb - pa));
                    t1 = 0;
                }
                else
                {
                    if (!(g % t2.d))
                        t2 -= Fraction(1, g);
                    Fraction k(Fraction::floor(t2*g), g);
                    pb = pa + integralPoint(k*(pb - pa));
                    t2 = 1;
                }
            }
        }

        if (reject)
            lit = lines.erase(lit);
        else
        {
            innerNeedles++;
            if (!(pa == pb))
                innerNeedles += gcd(abs(pa.x - pb.x), abs(pa.y - pb.y));
            if (pa.x > pb.x)
                std::swap(pa, pb);
            events.push(Event(pa.x, &*lit));
            lit++;
        }
    }
    //clipping ends

    /*
     * Sweep Line
     */
    Event e;
    int_t x;
    int_t intersectionCount;
    typedef std::pair<int, int> point_t;
    std::set<point_t> points;

    while (!events.empty())
    {
        do
        {
            points.clear();

            intersectionCount = 0;
            e = events.top();
            events.pop();
            x = e.x;

            if (e.etype == E_END)
            {
                activeLines.erase(e.mmit);
                continue;
            }

            Point pa = e.line->p1;
            Point pb = e.line->p2;
            bool done = false;
            MMIT al_it = activeLines.lower_bound(std::min(pa.y, pb.y) - MAX_LEN);
            const MMIT al_it_end = activeLines.upper_bound(std::max(pa.y, pb.y) + MAX_LEN);

            for (; al_it != al_it_end && !done; al_it++)
            {
                Point pc = al_it->second->p1;
                Point pd = al_it->second->p2;
                int_t d = (pb.x - pa.x)*(pd.y - pc.y) - (pb.y - pa.y)*(pd.x - pc.x);
                Fraction r((pa.y - pc.y)*(pd.x - pc.x) - (pa.x - pc.x)*(pd.y - pc.y), d);
                Fraction s((pa.y - pc.y)*(pb.x - pa.x) - (pa.x - pc.x)*(pb.y - pa.y), d);
                if (d == 0) //parallel
                {
                    if (r.n == 0) //collinear
                    {
                        done = true;
                        if (pa == pb) //point
                        {
                            Fraction f1(pa.y-pc.y, pd.y-pc.y);
                            Fraction f2(pa.x-pc.x, pd.x-pc.x);
                            if (pa == pc || (f1 == f2 && pa.x <= pd.x && (pa.y-pd.y)*(pa.y-pc.y) <= 0))
                                intersectionCount = 1;
                            else
                                done = false;
                        }
                        else if (pc == pd) //point
                        {
                            done = false;
                            if (pa == pc)
                                points.insert(point_t(pc.x, pc.y));
                        }
                        else if (pa.x == pb.x) //vertical
                        {
                            if (pa.y > pb.y) std::swap(pa.y, pb.y);
                            if (pc.y > pd.y) std::swap(pc.y, pd.y);
                            if (pd.y >= pb.y && pc.y <= pa.y)
                            {
                                intersectionCount = e.line->gcd() + 1;
                            }
                            else if (pd.y <= pb.y && pc.y >= pa.y)
                            {
                                if (pb.y != pd.y)
                                {
                                    pd.y++;
                                    lines.push_back(Line(pb, pd));
                                    events.push(Event(e.x, &lines.back()));
                                }
                                if (pa.y != pc.y)
                                {
                                    pc.y--;
                                    lines.push_back(Line(pc, pa));
                                    events.push(Event(e.x, &lines.back()));
                                }
                                intersectionCount = al_it->second->gcd() + 1;
                            }
                            else if (pb.y >= pc.y && pc.y > pa.y)
                            {
                                intersectionCount = pb.y - pc.y + 1;
                                pc.y--;
                                lines.push_back(Line(pc, pa));
                                events.push(Event(e.x, &lines.back()));
                            }
                            else if (pd.y >= pa.y && pa.y > pc.y)
                            {
                                intersectionCount = pd.y - pa.y + 1;
                                pd.y++;
                                lines.push_back(Line(pb, pd));
                                events.push(Event(e.x, &lines.back()));
                            }
                            else
                                done = false;
                        }
                        else if (pb.x <= pd.x) //contained
                        {
                            intersectionCount = e.line->gcd() + 1;
                        }
                        else
                        {
                            intersectionCount = gcd(pd.x - pa.x, abs(pd.y - pa.y)) + 1;

                            int_t g = e.line->gcd();
                            Fraction k(intersectionCount, g);
                            e.line->p1 = pa + integralPoint(k*(pb - pa));
                            e.x = e.line->p1.x;
                            events.push(e);
                        }
                    }
                }
                else if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
                {
                    PointF pf = r*(pb - pa);
                    if (isIntegral(pf))
                    {
                        Point p = pa + integralPoint(pf);
                        points.insert(point_t(p.x, p.y));
                    }
                }
            }
            if (!done) //current line is not added in active lines
            {
                if (e.etype == E_START)
                {
                    MMIT it = activeLines.insert(std::make_pair(std::max(pa.y, pb.y), e.line));
                    events.push(Event(e.line->p2.x, it));
                }
                intersectionCount = points.size();
            }
            innerNeedles -= intersectionCount;
        }while (!events.empty() && x == events.top().x);
    }

    std::cout << boundaryNeedles + innerNeedles << ' ' << pins - innerNeedles << '\n';
}

bool NeedlesPins::onright(Point p, int i) const
{
    Vector v1(vertices[i+1] - vertices[i]);
    Vector v2(p - vertices[i]);
    if (v1.j*v2.i < v1.i*v2.j)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    int t;
    NeedlesPins npin;
    std::cin >> t;
    while (t--)
    {
        npin.read();
        npin.solve();
    }
    return 0;
}