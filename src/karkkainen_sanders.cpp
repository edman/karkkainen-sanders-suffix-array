
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "karkkainen_sanders.hpp"
using namespace std;

#define MAXN 200
#define MAXSIGMA 200

// int tmp[MAXN];
// int count[MAXSIGMA];

int fix0(int p0) {
    return p0 / 3;
}

int fix12(int p12) {
    return p12 - ceil(p12 / 3.);
}

bool lt(int a1, int b1, int a2, int b2, int a3, int b3) {
    return a1 != b1 ? a1 < b1 : (a2 != b2 ? a2 < b2 : a3 < b3);
}

void counting_sort(int *keys, int *a, int *b, int off, int n, int sigma) {
    int count[sigma + 1];
    memset(count, 0, sizeof(int) * (sigma + 1));

    for (int i = 0; i < n; ++i)
        count[keys[a[i] + off]]++;
    for (int d = 0, sum = 0; d <= sigma; ++d)
        sum += count[d], count[d] = sum - count[d];
    for (int i = 0; i < n; ++i)
        b[count[keys[a[i] + off]]++] = a[i];
}

void sort_triples(int *s, int *p12, int n12, int sigma) {
    int tmp[n12];
    counting_sort(s, p12, tmp, 2, n12, sigma);
    counting_sort(s, tmp, p12, 1, n12, sigma);
    counting_sort(s, p12, tmp, 0, n12, sigma);
    memcpy(p12, tmp, sizeof(int) * n12);
}

void sort_group0(int *s, int*p0, int n0, int sigma) {
    int tmp[n0];
    counting_sort(s, p0, tmp, 0, n0, sigma);
    memcpy(p0, tmp, sizeof(int) * n0);
}

int assign_names(int *s, int *names, int *p12, int n12) {
    int lex_name = 0, prev[3] = {-1, -1, -1};
    for (int i = 0; i < n12; ++i) {
        int *curr = &s[p12[i]];
        if (lt(prev[0], curr[0], prev[1], curr[1], prev[2], curr[2]))
            lex_name++;
        memcpy(prev, curr, sizeof(int) * 3);
        names[i] = lex_name;
    }
    return lex_name;
}

void karkkainen_sanders_sa(int *s, int *sa, int n, int sigma) {
    int n0 = (n + 2) / 3, n1 = n0, n2 = n / 3;
    int n12 = n1 + n2;

    // Get the indices of elements in group 0, and in groups 1 and 2
    int p12[n12];
    for (int i = 1, j = 0; j < n12; i += i % 3, j++)
        p12[j] = i;

    // Sort triples of groups 1 and 2
    sort_triples(s, p12, n12, sigma);


    // Assign names to triples in groups 1 and 2
    int names[n12], name_count;
    name_count = assign_names(s, names, p12, n12);

    // We now proceed to find the relative order of suffixes in groups 1 and 2
    int sa12[n12];

    // If names are not all distinct, find sa12 recursively
    if (name_count < n12) {
        // Initialize string of size 2n/3 from the lexicographic names
        int s12[n12 + 3]; s12[n12] = s12[n12 + 1] = s12[n12 + 2] = 0;
        for (int i = 0; i < n12; ++i)
            s12[p12[i] / 3 + (p12[i] % 3 == 1 ? 0 : n1)] = names[i];
        // Call the function recursively
        karkkainen_sanders_sa(s12, sa12, n12, name_count);
        // TODO: here we have to reassign the order of p12 based in sa12
    }
    // If names are all distinct, assign as12 from the sorted suffixes
    else
        for (int i = 0; i < n12; ++i)
            sa12[fix12(p12[i])] = i;

    // Next step is finding the relative order of suffixes in group 0
    int p0[n0];

    // Order in S(i+1) is implicit from sa12
    for (int i = 0, j = 0; j < n0; ++i) if (p12[i] % 3 == 1)
        p0[j++] = p12[i] - 1;

    // Sort suffixes in group 0
    sort_group0(s, p0, n0, sigma);


    // Find the relative order of suffixes in group 0 from the sorted suffixes
    // TODO: this might be unnecessary, check later.
    int sa0[n0];
    for (int i = 0; i < n0; ++i)
        sa0[fix0(p0[i])] = i;

    cout<<"i  : ";for (int i =0 ;i < n; ++i)
        cout << i<<" ";cout <<endl;
    cout<<"s  : ";for (int i =0 ;i < n; ++i)
        cout << s[i]<<" ";cout <<endl;
    cout<<"p0 : ";for (int i =0 ;i < n0; ++i)
        cout << p0[i]<<" ";cout <<endl;
    cout<<"p12: ";for (int i =(n%3==1?1:0) ;i < n12; ++i)
        cout << p12[i]<<" ";cout<<endl;

    // We now proceed for the merge step
    int i = 0, i0 = 0, i12 = (n % 3 == 1 ? 1 : 0);
    int a1, a2, a3, b1, b2, b3;
    while (i0 < n0 && i12 < n12) {
        // Comparison to suffix in group 1
        if (p12[i12] % 3 == 1) {
            a1 = s[ p0[ i0]], a2 = sa12[fix12( p0[ i0] + 1)];
            b1 = s[p12[i12]], b2 = sa12[fix12(p12[i12] + 1)];
        }
        // Comparison to suffix in group 2
        else {
            a1 = s[ p0[ i0]], a2 = s[ p0[ i0] + 1], a3 = sa12[fix12( p0[ i0] + 2)];
            b1 = s[p12[i12]], b2 = s[p12[i12] + 1], b3 = sa12[fix12(p12[i12] + 2)];
        }

        int win = lt(a1, b1, a2, b2, a3, b3) ? p0[i0] : p12[i12];
        cout << "comp " << p0[i0] << " | " << p12[i12] << " : " << win;
        cout<<"  .  "<<i0<<" | "<<i12<<endl;

        sa[i++] = lt(a1, b1, a2, b2, a3, b3) ? p0[i0++] : p12[i12++];
    }
    for (;  i0 <  n0;  ++i0) sa[i++] =  p0[ i0];
    for (; i12 < n12; ++i12) sa[i++] = p12[i12];
}





























