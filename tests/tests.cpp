
#include "gtest/gtest.h"
#include "src/karkkainen_sanders.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

bool eq(int a1, int b1, int a2, int b2, int a3 = 0, int b3 = 0) {
    return a1 == b1 && a2 == b2 && a3 == b3;
}

bool is_sorted(int *a, int *index, int n) {
    int a1, a2, a3, b1, b2, b3;
    for (int i = 0; i < n-1; ++i) {
        a1 = a[index[i]], a2 = a[index[i] + 1], a3 = a[index[i] + 2];
        b1 = a[index[i + 1]], b2 = a[index[i + 1] + 1], b3 = a[index[i + 1] + 2];
        if (!lt(a1, b1, a2, b2, a3, b3) && !eq(a1, b1, a2, b2, a3, b3))
            return false;
    }
    return true;
}

class KarkkainenSandersTest : public testing::Test {
    protected:
        virtual void SetUp() {
            n = 11;
            n0 = (n + 2) / 3, n1 = n0, n2 = n / 3;
            n12 = n1 + n2;
            sigma = 4;

            int s[] = {2,1,4,4,1,4,4,1,3,3,1,0,0,0};
            S = new int[n + 3];
            memcpy(S, s, sizeof(int) * (n + 3));

            int names[] = {3, 3, 2, 1, 5, 5, 4};
            expected_names = new int[n12];
            memcpy(expected_names, names, sizeof(int) * n12);

            p12 = new int [n12];
            for (int i = 1, j = 0; j < n12; i += i % 3, j++)
                p12[j] = i;
        }
        int *S;
        int *p12;
        int *expected_names;
        int n, n1, n2, n0, n12;
        int sigma;
};

TEST_F(KarkkainenSandersTest, TripleSorting) {
    sort_triples(S, p12, n12, sigma);
    ASSERT_EQ(true, is_sorted(S, p12, n12));
}

TEST_F(KarkkainenSandersTest, AssignNames) {
    int names[n12];
    sort_triples(S, p12, n12, sigma);
    assign_names(S, names, p12, n12);
    for (int i = 0; i < n12; ++i)
        if (p12[i] % 3 == 1)
            EXPECT_EQ(expected_names[p12[i] / 3], names[i]);
        else EXPECT_EQ(expected_names[p12[i] / 3 + n1], names[i]);
}


class KarkkainenSandersTest2 : public testing::Test {
    protected:
        virtual void SetUp() {
            n = 7;
            n0 = (n + 2) / 3, n1 = n0, n2 = n / 3;
            n12 = n1 + n2;
            sigma = 5;

            int s[] = {3,3,2,1,5,5,4,0,0,0};

            S = new int[n + 3];
            memcpy(S, s, sizeof(int) * (n + 3));

            int names[] = {3,5,1,2,4};
            expected_names = new int[n12];
            memcpy(expected_names, names, sizeof(int) * n12);

            p12 = new int [n12];
            for (int i = 1, j = 0; j < n12; i += i % 3, j++)
                p12[j] = i;
        }
        int *S;
        int *p12;
        int *expected_names;
        int n, n1, n2, n0, n12;
        int sigma;
};

TEST_F(KarkkainenSandersTest2, TripleSorting) {
    sort_triples(S, p12, n12, sigma);
    ASSERT_EQ(true, is_sorted(S, p12, n12));
}


TEST_F(KarkkainenSandersTest2, AssignNames) {
    int names[n12];
    sort_triples(S, p12, n12, sigma);
    assign_names(S, names, p12, n12);
    for (int i = 0; i < n12; ++i)
        if (p12[i] % 3 == 1)
            EXPECT_EQ(expected_names[p12[i] / 3], names[i]);
        else
            EXPECT_EQ(expected_names[p12[i] / 3 + n1], names[i]);
}









