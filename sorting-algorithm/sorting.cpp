#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Best case: O(n)
 * Average case: O(n^2)
 * Worst case: O(n^2)
 */
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

/**
 * Best case: O(n^2)
 * Average case: O(n^2)
 * Worst case: O(n^2)
 */
void interchange_sort(int arr[], int n)
{
    /**
     * (i = 0)
     * 50 43 41 40 10 13 44 16 12 33
     * 43 50 41 40 10 13 44 16 12 33
     * 41 50 43 40 10 13 44 16 12 33
     * 40 50 43 41 10 13 44 16 12 33
     * 10 50 43 41 40 13 44 16 12 33
     * (i = 1)
     * 10 43 50 41 40 13 44 16 12 33
     * 10 41 50 43 40 13 44 16 12 33
     * 10 40 50 43 41 13 44 16 12 33
     * 10 13 50 43 41 40 44 16 12 33
     *
     *
     * 10 12 50 43 41 40 44 16 13 33
     */
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

/**
 * Best case: O(n^2)
 * Average case: O(n^2)
 * Worst case: O(n^2)
 */
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

// O(log(n))
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// O(n)
void build_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
/**
 * Best case: O(nlog(n))
 * Average case: O(nlog(n))
 * Worst case: O(nlog(n))
 */
void heap_sort(int arr[], int n)
{
    build_heap(arr, n); // O(n)

    for (int i = n - 1; i >= 0; i--)
    { // O(n)
        swap(arr[0], arr[i]);
        cout << "\nSwapped, no heapify: ";
        print_arr(arr, n);
        heapify(arr, i, 0); // O(log(n))
        cout << "\nHeapified: ";
        print_arr(arr, n);
    }
}

// O(right - left) ~ O(n)
void merge(int arr[], int left, int right)
{
    int mid = (left + right) / 2;
    int n1 = mid - left + 1; // size of arr[left..mid]
    int n2 = right - mid;    // size of arr[mid+1..right] right - (mid + 1) + 1 = right - mid

    int L[n1], R[n2]; // declare two arrays to store the left and right subarrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    // [15, 23, 40, 60]
    // [9, 25, 55]
    // target: [9, 15, 23, 25, 40, 55, 60]
    // [9 15 23 25 40 55 60]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void print_arr(int arr[], int left, int right)
{
    cout << "{ ";
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}
// worst case: O(nlog(n))
// average case: O(nlog(n))
// best case: O(nlog(n))
void merge_sort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    if (left < right)
    {
        int mid = (left + right) / 2;
        cout << "before merge: "; print_arr(arr, left, right);
        merge_sort(arr, left, mid);
        print_arr(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        print_arr(arr, mid + 1, right);
        merge(arr, left, right);
        cout << "afted merge: "; print_arr(arr, left, right);
    }
}

int main()
{
    int arr[] = {27, 12, 49, 23, 34, 19, 10, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    // selection_sort(arr, n);
    // build_heap(arr, n);
    // heap_sort(arr, n);
    // int arr2[] = {15, 23, 40, 60, 9, 25, 55};
    // merge(arr2, 0, 6);
    merge_sort(arr, 0, n - 1);
    print_arr(arr, n);
} 