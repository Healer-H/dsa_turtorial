#include <bits/stdc++.h>

using namespace std;

int cnt[1000] = {0}; // cnt[x] = số lần xuất hiện của x, cnt[500] = 3 --> sdt 500 xuat hien 3 lan || cnt[sdt[i]] = 2  --> sdt[i] xuat hien 2 lan
int cnt2[1000] = {0};

void print_k_lastest(int sdt[], int n, int k)
{
    for (int i = n - 1; i >= 0, k > 0; i--)
    {
        if(cnt2[sdt[i]] == 1) continue;
        cnt2[sdt[i]] = 1;

        if (cnt[sdt[i]] == 1)
            cout << sdt[i] << " ";
        else
            cout << sdt[i] << "(" << cnt[sdt[i]] << ") ";
        k--;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> k >> n;
    int sdt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sdt[i];
        cnt[sdt[i]] = cnt[sdt[i]] + 1;
    }
    print_k_lastest(sdt, n, k);
}