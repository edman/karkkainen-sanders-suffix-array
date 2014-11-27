
#include "karkkainen_sanders.hpp"
#include <iostream>

using namespace std;

int main() {
    int s[] = {2,1,4,4,1,4,4,1,3,3,1,0,0};
    int n = 11;
    int k = 4;
    // int s[] = {3,3,2,1,5,5,4,0,0,0};
    // int n = 7;
    // int k = 5;
    int sa[n];
    karkkainen_sanders_sa(s, sa, n, k);
    for (int i = 0; i < n; ++i)
        cout << sa[i] << ","; cout<<endl;
}

