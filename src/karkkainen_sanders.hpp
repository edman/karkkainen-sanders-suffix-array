
#ifndef DEFINED_KARKKAINEN_SANDERS_HPP
#define DEFINED_KARKKAINEN_SANDERS_HPP


bool lt(int a1, int b1, int a2, int b2, int a3 = 0, int b3 = 0);
int fix(int p);
void sort_triples(int *s, int *p12, int n12, int sigma);
void sort_group0(int *s, int*p0, int n0, int sigma);
int assign_names(int *s, int *names, int *p12, int n12);
void karkkainen_sanders_sa(int *s, int *sa, int n, int sigma_size);

#endif

