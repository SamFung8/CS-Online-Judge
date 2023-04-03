#include <iostream>
#include <set>
#include <stack>
#include <string> 
#include <queue> 
using namespace std;


struct Point
{
    long long int x, y;
};

Point p0;

Point nextToTop(stack<Point>& S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void swap(Point& p1, Point& p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

long long int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    long long int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 1; 
    return (val > 0) ? 1 : 2; 
}

int compare(const void* vp1, const void* vp2)
{
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;

    long long int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void convexHull(Point points[], long long int n)
{
    long long int ymin = points[0].y, min = 0;
    for (long long int i = 1; i < n; i++)
    {
        long long int y = points[i].y;

        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);


    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    long long int m = 1; 
    for (long long int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;


        points[m] = points[i];
        m++;  
    }

    if (m < 3) return;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (long long int i = 3; i < m; i++)
    {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    
    cout << S.size();
    cout << "\n";

    stack <Point> tem;
    long long int minX = S.top().x, minY = S.top().y;
    while (!S.empty())
    {
        Point p = S.top();
        tem.push(p);
        S.pop();
        if ((minX >= p.x && minY > p.y) || minX > p.x) {
            minX = p.x;
            minY = p.y;
        }
    }
    
    queue <Point> tem2;
    bool stop = false;
    while (!tem.empty())
    {
        Point p = tem.top();
        if (p.x == minX && p.y == minY)
            stop = true;
        if (stop)
            cout << p.x << " " << p.y << endl;
        else
            tem2.push(p);
        tem.pop();
    }

    while (!tem2.empty()) {
        Point p = tem2.front();
        cout << p.x << " " << p.y << endl;
        tem2.pop();
    }
}


Point points[100100] = { {} };

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
	
    long long int taskNum = 0;
	cin >> taskNum;

	while (taskNum > 0)
	{
		long long int n;
		cin >> n;

		for (long long int i = 0; i < n; i++) {
			long long int x = 0;
			long long int y = 0;

			cin >> x >> y;

			points[i] = { x,y };
		}

        convexHull(points, n);
		taskNum--;
	}


	return 0;
}
