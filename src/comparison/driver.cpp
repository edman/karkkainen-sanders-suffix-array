#include <iostream>
#include <sys/time.h>
#include <cmath>
#include <cstdlib>
#include "../karkkainen_sanders.hpp"
#include "../tryall/drittel.cpp"

using namespace std;

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp () {
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(int argc, char *argv[]) {
    timestamp_t t0, t1;
    int type = atoi(argv[1]);

    int N, n, k;
    cin >> N >> n >> k;

    // int s[n+3]; s[n] = s[n+1] = s[n+2] = 0;
    int s[N][n+3];
    int sa[n];

    // Read all test cases
    for (int z = 0, per = 1; z < N; ++z) {
        if (double(z) / N > per/10.) cout << per++ << " ";
        // Read current string
        for (int i = 0; i < n; ++i) cin >> s[z][i];
        s[z][n] = s[z][n+1] = s[z][n+2] = 0;
    }

    // Time suffix array construction implementations
    t0 = get_timestamp();
    if (type == 0) for (int z = 0; z < N; ++z)
        karkkainen_sanders_sa(s[z], sa, n, k);
    else for (int z = 0; z < N; ++z)
        suffixArray(s[z], sa, n, k);
    t1 = get_timestamp();
    cout << endl << "time: " << t1 - t0 << endl;
}

