#include <bits/stdc++.h>
using namespace std;

// Constants
const int INF = 1e9 + 7;
const long long LINF = 1e18 + 7;

// Type Aliases
using ll = long long;
using pii = pair<int, int>;

// Macros
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

// Fast I/O
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

struct Point
{
    double x, y;
};

double polarAngle(Point p1, Point p0)
{
    return atan2(p1.y - p0.y, p1.x - p0.x);
}

bool compareByAngle(Point p1, Point p2, Point p0)
{
    double angle1 = polarAngle(p1, p0);
    double angle2 = polarAngle(p2, p0);
    return angle1 < angle2;
}

void sortPoints(vector<Point> &points)
{
    int idx = 0;
    for (unsigned int i = 1; i < points.size(); i++)
    {
        if (points[i].y < points[idx].y || (points[i].y == points[idx].y && points[i].x < points[idx].x))
        {
            idx = i;
        }
    }

    swap(points[0], points[idx]);

    Point p0 = points[0];
    sort(points.begin() + 1, points.end(), [&p0](Point p1, Point p2)
         { return compareByAngle(p1, p2, p0); });
}

double dotProduct(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}

double magnitude(Point a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

pair<double, double> MBR(vector<Point> &points)
{
    int n = points.size();
    double minArea = INT_MAX;
    double minLength = 0, minBreadth = 0;

    for (int i = 0; i < n; i++)
    {
        // Current edge
        Point edge = {points[(i + 1) % n].x - points[i].x, points[(i + 1) % n].y - points[i].y};
        double edgeLength = magnitude(edge);
        Point unitEdge = {edge.x / edgeLength, edge.y / edgeLength};
        Point perp = {-unitEdge.y, unitEdge.x};

        double minProjEdge = INT_MAX;
        double maxProjEdge = INT_MIN;
        double minProjPerp = INT_MAX;
        double maxProjPerp = INT_MIN;

        for (const auto &point : points)
        {
            Point vec = {point.x - points[i].x, point.y - points[i].y};
            double projEdge = dotProduct(vec, unitEdge);
            double projPerp = dotProduct(vec, perp);

            minProjEdge = min(minProjEdge, projEdge);
            maxProjEdge = max(maxProjEdge, projEdge);
            minProjPerp = min(minProjPerp, projPerp);
            maxProjPerp = max(maxProjPerp, projPerp);
        }

        double length = maxProjEdge - minProjEdge;
        double breadth = maxProjPerp - minProjPerp;
        double area = length * breadth;

        if (area < minArea)
        {
            minArea = area;
            minLength = length;
            minBreadth = breadth;
        }
    }

    return {minLength, minBreadth};
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    sortPoints(points);

    auto dimensions = MBR(points);
    int length = ceil(dimensions.F), breadth = ceil(dimensions.S);

    cout << min(length, breadth) << ' ' << max(length, breadth);

    return 0;
}
