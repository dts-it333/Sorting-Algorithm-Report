#include<bits/stdc++.h>
using namespace std;

#define N 1000000

int n = N, a[N];

int main(){

    freopen("random8.txt", "r", stdin);

    clock_t start = clock();

    cin >> n;
    for(int i = 0 ; i < n; i++) cin >> a[i];

    sort(a, a+n);
 
    clock_t end = clock();

    cout << "Time run: " << (float)(end-start)/CLOCKS_PER_SEC << "s" << "\n";
}