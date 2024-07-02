#include <bits/stdc++.h>

using namespace std;

struct Point
{
    float x, y, z;

    bool operator==(const Point &p)
    {
        return (x == p.x) && (y == p.y) && (z == p.z);
    }
    bool operator>(const Point &p)
    {
        if (x == p.x && y == p.y)
        {
            return z > p.z;
        }
        if (x == p.x)
        {
            return y > p.y;
        }
        return x > p.x;
    }

    bool operator<(const Point &p)
    {
        if (x == p.x && y == p.y)
        {
            return z < p.z;
        }
        if (x == p.x)
        {
            return y < p.y;
        }
        return x < p.x;
    }
};

int binary_search(Point points[], int left, int right, Point to_find)
{
    int cnt = 0;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        cnt++;
        if (points[middle] == to_find)
        {
            return cnt;
        }
        if (to_find < points[middle]) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        Point to_find;
        cin >> to_find.x >> to_find.y >> to_find.z;

        int cnt = binary_search(points, 0, n - 1, to_find);
        if (cnt == -1)
        {
            cout << "KHONG\n";
        }
        else
            cout << cnt << "\n";
    }
}