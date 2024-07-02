#include <iostream>

using namespace std;
#define MAXN 150000

int binary_search(int a[], int left, int right, int val) {
    while(left <= right) {
        int middle = (left + right) / 2;
        if(a[middle] < val && val <= a[middle + 1]) {
            return middle;
        }
        if(val < a[middle]) {
            right = middle - 1;
        }
        else {
            left = middle;
        }
    }
}

void ChenTang(int x, int a[], int& n) 
{
    if(x >= a[n - 1]) {
        a[n] = x;
        n++;
        return;
    }
    if(x <= a[0]) {
        for(int i = n - 1; i >= 0; i--) {
            a[i + 1] = a[i];
        }
        a[0] = x;
        n++;
        return;
    }
    int idx = binary_search(a, 0, n - 1, x); 
    // insert idx -- idx + 1
    for(int i = n - 1; i >= idx + 1; i--) {
        a[i + 1] = a[i];
    }
    a[idx + 1] = x;
    n++;
}

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}