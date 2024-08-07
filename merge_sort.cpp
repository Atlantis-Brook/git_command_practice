#include <iostream>

using namespace std;

int const N = 1e5 + 10;
int a[N], tmp[N];

void merge_sort(int q[], int l, int r) {
    if(l >= r) return;

    int mid = (l + r) >> 1;

    merge_sort(q, l, mid); merge_sort(q, mid + 1, r);
    int k = 0;
    int i = l, j = mid + 1;

    while(i <= mid && j <= r)
        if(a[i] > a[j]) tmp[k ++ ] = a[j ++ ];
        else tmp[k ++ ] = a[i ++ ];
    while(i <= mid) tmp[k ++ ] = a[i ++ ];
    while(j <= r) tmp[k ++ ] = a[j ++ ];
    
    for(int i = l, j = 0; i <= r; i ++ , j ++  ) q[i] = tmp[j];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    for(int i = 0; i < n; i ++ ) printf("%d ", a[i]);
    return 0;
}