#include<stdio.h>
#define max 10

void mergesort(int array[], int beg, int end);
void merge(int array[], int beg, int mid, int end);
void quicksort(int array[], int beg, int end);
int partition(int array[], int beg, int end);

int main() {
    int choice, len, array[max];
    printf("\nEnter size:");
    scanf("%d", &len);

    printf("\nEnter values:");
    for (int i = 0; i < len; i++) {
        scanf("%d", &array[i]);
    }

    do {
        printf("\n1. Merge Sort");
        printf("\n2. Quick Sort");
        printf("\n3. Redefine array");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                mergesort(array, 0, len - 1);
                printf("\nSorted array using Merge Sort:\n");
                for (int i = 0; i < len; i++) {
                    printf("%d\t", array[i]);
                }
                break;

            case 2:
                quicksort(array, 0, len - 1);
                printf("\nSorted array using Quick Sort:\n");
                for (int i = 0; i < len; i++) {
                    printf("%d\t", array[i]);
                }
                break;

            case 3:
                printf("\nEnter new values for array:");
                for (int i = 0; i < len; i++) {
                    scanf("%d", &array[i]);
                }
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void mergesort(int array[], int beg, int end) {
    int mid;
    if (beg < end) {
        mid = (beg + end) / 2;
        mergesort(array, beg, mid);
        mergesort(array, mid + 1, end);
        merge(array, beg, mid, end);
    }
}

void merge(int array[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, k = 0, temp[end - beg + 1];

    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            temp[k] = array[i];
            i++;
        } else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= end) {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        array[beg + i] = temp[i];
    }
}

void quicksort(int array[], int beg, int end) {
    int pos;
    if (beg < end) {
        pos = partition(array, beg, end);
        quicksort(array, beg, pos - 1);
        quicksort(array, pos + 1, end);
    }
}

int partition(int array[], int beg, int end) {
    int left, right, loc, temp;

    loc = left = beg;
    right = end;

    while (1) {
        while (array[loc] <= array[right] && loc != right) {
            right--;
        }

        if (loc == right) {
            break;
        } else if (array[right] < array[loc]) {
            temp = array[right];
            array[right] = array[loc];
            array[loc] = temp;
            loc = right;
        }

        while (array[loc] >= array[left] && loc != left) {
            left++;
        }

        if (loc == left) {
            break;
        } else if (array[left] > array[loc]) {
            temp = array[left];
            array[left] = array[loc];
            array[loc] = temp;
            loc = left;
        }
    }

    return loc;
}
