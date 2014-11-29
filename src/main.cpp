
#include "karkkainen_sanders.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // int s[] = {2,1,4,4,1,4,4,1,3,3,1,0,0};
    // int n = 11;
    // int k = 4;
    // int s[] = {3,3,2,1,5,5,4,0,0,0};
    // int n = 7;
    // int k = 5;
    // int s[] = {10,10,0,0,0};
    // int n = 2;
    // int k = 10;
    int s[] = {2,2,2,2,2,0,0,0};
    int n = 5;
    int k = 2;
    int sa[n];

    karkkainen_sanders_sa(s, sa, n, k);
    for (int i = 0; i < n; ++i)
        cout << sa[i] << " "; cout<<endl;
}

