#include <bits/stdc++.h>
using namespace std;

void convert(int n) {
    stack<int> s;
    while(n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

// (5 + 6) = 11
// 5 6 +


// (2 + 3) * (5 - 10) = 15


// 10 + (5 * 3 - 2) * (10 - 3 * 2) = 10 + 13 * 4 = 10 + 52 = 62

// 2 3 + 5 * 10 -
// 2 3 + 5 * 10 -

// 15

// 
// (((( ))))
// ()()()
// (()) ()
// ()())()

// int a[1000] = {0};

// a[i] = 1 --> i da xuat hien truoc do roi --> bo qua i, chuyen den thang ke tip



int main() {
    // convert(10);
    int a = 2, b = 3;
    foo(&a, b);
    cout << a << " " << b << "\n";
}