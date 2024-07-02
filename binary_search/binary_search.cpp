#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int left, int right, int val) 
{
    int middle = (left + right) / 2;

    if(val == a[middle]) {
        return middle;
    }

    if(val > a[middle]) {
        return binary_search(a, middle + 1, right, val);
    }
    else {
        return binary_search(a, left, middle - 1, val);
    }
    return -1;
}          

int bsearch(int a[], int left, int right, int val) {
    while(left <= right) {
        int middle = (left + right) / 2;
        if(val == a[middle]) {
            return middle;
        }
        else if (val > a[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}

int bs(const int a[], int left, int right, const int& val) {
    while(left <= right) {
        int middle = left + right >> 1;
        if(val == a[middle]) {
            return middle;
        }
        else if (val > a[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 3, 5, 6, 10};
    int n = sizeof(a) / sizeof(a[0]); // n = 6
    cout << bs(a, 0, n - 1, 6) << "\n";
    cout << binary_search(a, 0, n - 1, 6) << "\n";
    cout << bsearch(a, 0, n - 1, 6) << "\n";

}