#include<bits/stdc++.h>
using namespace std;

#define N 1000000

int n = N, a[N];

void merge(int l, int mid, int r)
{
    int nl = mid-l+1;
    int nr = r-mid;
    
    vector<int> b(nl), c(nr);

    for(int i = 0; i < nl; i++)
        b[i] = a[l+i];
    for(int j = 0; j < nr; j++)
        c[j] = a[mid+j+1];

    int i = 0, j = 0, d = l-1;

    while(i < nl && j < nr)
    {
        if(b[i] <= c[j])
        {
            d++;
            a[d] = b[i];
            i++;
        }
        else
        {
            d++;
            a[d] = c[j];
            j++;
        }
    }

    while(i < nl)
    {
        d++;
        a[d] = b[i];
        i++;
    }
    while(j < nr)
    {
        d++;
        a[d] = c[j];
        j++;
    }
}
void MergeSort(int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        merge(left, mid, right);
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
    //freopen("output.txt", "w", stdout);
    clock_t start = clock();

    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> a[i];

    MergeSort(0, n-1);
 
    clock_t end = clock();

    cout << "Time run: " << (float)(end-start)/CLOCKS_PER_SEC << "s" << "\n";

    if(check(0, n-1)) cout << "Correct...^_^";
    else cout << "Wrong...x_x";
}