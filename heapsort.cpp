#include<bits/stdc++.h>
using namespace std;

int n = 1000000, a[1000001];

void BuildMaxHeap(int n, int p)
{
    int res = p;
    int left = 2*p + 1;
    int right = 2*p + 2;
    if(left < n && a[res] < a[left]) res = left;
    if(right < n && a[res] < a[right]) res = right;
    if(res != p)
    {
        swap(a[p], a[res]);
        BuildMaxHeap(n, res);
    }
}

void HeapSort(int n)
{
    for(int i = (n-1)/2; i >= 0; i--)
        BuildMaxHeap(n, i);
    for(int i = n-1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        BuildMaxHeap(i, 0);
    }
}
bool check(long long left, long long right)
{
    for(int i = left+1; i <= right; i++)
        if(a[i] < a[i-1]) return false;
    return true;
}

int main()
{
    freopen("random8.txt", "r", stdin);

    clock_t start = clock();

    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> a[i];

    HeapSort(n);
    clock_t end = clock();

    cout << "Time run: " << (float)(end-start)/CLOCKS_PER_SEC << "s" << "\n";

    if(check(0, n-1)) cout << "Correct...^_^";
    else cout << "Wrong...x_x";
    //for(int i = 0 ; i < n; i++) cout << a[i] << " ";
}