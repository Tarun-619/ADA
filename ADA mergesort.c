#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void split(int[], int, int);
void combine(int[], int, int, int);

void main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;
    while (1) {
        printf("\n1: For manual entry of N value and array ele");
        printf("\n2: To display TT for sorting nums of ele N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the num of eles: ");
                scanf("%d", &n);
                printf("\nEnter array eles: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                split(a, 0, n - 1);
                end = clock();
                printf("\nSorted array is: ");
                for (i = 0; i < n; i++) printf("%d\t", a[i]);
                printf("\nTT to sort %d nums is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                break;
            case 2:
                n = 500;
                while (n <= 14500) {
                    for (i = 0; i < n; i++) a[i] = n - i;
                    start = clock();
                    split(a, 0, n - 1);
                    for (j = 0; j < 500000; j++) temp = 38 / 600;
                    end = clock();
                    printf("\nTT to sort %d nums is %f Secs", n, (((double)(end - start)) / CLOCKS_PER_SEC));
                    n += 1000;
                }
                break;
            case 3: exit(0);
        }
        getchar();
    }
}

void split(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        split(a, low, mid);
        split(a, mid + 1, high);
        combine(a, low, mid, high);
    }
}

void combine(int a[], int low, int mid, int high) {
    int c[15000], i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) c[k++] = a[i++];
        else c[k++] = a[j++];
    }
    while (i <= mid) c[k++] = a[i++];
    while (j <= high) c[k++] = a[j++];
    for (i = low; i <= high; i++) a[i] = c[i];
}
