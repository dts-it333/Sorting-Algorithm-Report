#include<bits/stdc++.h>
using namespace std;

long long n = 1000000, a[1000001];


int main()
{
    ofstream inputfile("random8.txt");

    random_device rd;
    mt19937 res(rd());
    uniform_int_distribution<int> reg(INT_MIN, INT_MAX);

    inputfile << n << "\n";
    for(int i = 0; i < n; i++)
        a[i] = reg(res);
    //sort(a, a+n);
    //sort(a, a+n, greater<long long>());
    for(int i = 0; i < n; i++) inputfile << a[i] << " ";
    cout << "SUCCESS...";
}