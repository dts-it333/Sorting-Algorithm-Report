#include<bits/stdc++.h>
using namespace std;

#define N 1000001

long long a[N], n;

int random(int l, int r)
{
    srand(time(0));
    return l + rand()%(r-l+1);
}

void quicksort(int left, int right)
{
    if(left >= right) return;
    int l = left, r = right;
    int mid = a[random(left, right)];
    while(l < r)
    {
        while(a[l] < mid) l++;
        while(a[r] > mid) r--;
        if(l <= r)
        {
            int t;
            t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }
    quicksort(left, r);
    quicksort(l, right);
}

bool check(long long left, long long right)
{
    for(int i = left+1; i <= right; i++)
        if(a[i] < a[i-1]) return false;
    return true;
}

int main()
{
    

    freopen("random7.txt", "r", stdin);
    clock_t start = clock();
    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> a[i];
    quicksort(0, n-1);

    clock_t end = clock();

    cout << "Time run: " << (float)(end-start)/CLOCKS_PER_SEC << "s" << "\n";

    if(check(0, n-1)) cout << "Correct...^_^";
    else cout << "Wrong...x_x";
    //cout << random(1, 10);
}

