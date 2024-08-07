#include <iostream>

using namespace std;

int const N = 1e5 + 10;
int a[N];

void quick_sort(int a[], int l , int r) {
    int x = a[(l + r) >> 1];
    if(l >= r) return;

    int i = l - 1, j = r + 1;
    do i ++ ; while (x > a[i]);
    do j -- ; while (x < a[j]);
    if(l < r) swap(a[i], a[j]); 

    quick_sort(a, l, j); quick_sort(a, j + 1, r);
    return;
}

int main() {
    int x;
    scanf("%d", &x);
    for(int i = 0; i < x; i ++ ) scanf("%d", &a[i]);

    quick_sort(a, 0, x - 1);
    for(int i = 0; i < x; i ++ ) printf("%d ", a[i]);
}


