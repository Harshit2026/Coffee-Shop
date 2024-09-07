#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 400

int comparisons = 0;
int split_index = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    // initialize pivot to be the last element
    int pivot = arr[low];
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;
    
    // Traverse arr[low..high-1] and move all smaller
    // elements on the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        comparisons++;  // Increment comparison count
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &pivot);
    split_index = i + 1;  // Set split_index to the pivot's final position
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call Partition function to find Partition Index
        int partitionIndex = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on partition Index
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int choice;
    int data[MAX_SIZE];
    int size;
    FILE *fp;

    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen("inAsce.dat", "r");
                printf("Before Sorting: ");
                for (int i = 0; i < MAX_SIZE; i++) {
                    fscanf(fp, "%d", &data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                size = MAX_SIZE;
                quickSort(data, 0, size - 1);
                fp = fopen("outQuickAsce.dat", "w");
                printf("After Sorting: ");
                for (int i = 0; i < size; i++) {
                    fprintf(fp, "%d ", data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                printf("Number of Comparisons: %d\n", comparisons);
                if (split_index == 0 || split_index == size - 1) {
                    printf("Scenario: Worst-case\n");
                } else {
                    printf("Scenario: Best-case\n");
                }
                comparisons = 0;
                split_index = 0;
                break;

            case 2:
                fp = fopen("inDesc.dat", "r");
                printf("Before Sorting: ");
                for (int i = 0; i < MAX_SIZE; i++) {
                    fscanf(fp, "%d", &data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                size = MAX_SIZE;
                quickSort(data, 0, size - 1);
                fp = fopen("outQuickDesc.dat", "w");
                printf("After Sorting: ");
                for (int i = 0; i < size; i++) {
                    fprintf(fp, "%d ", data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                printf("Number of Comparisons: %d\n", comparisons);
                if (split_index == 0 || split_index == size - 1) {
                    printf("Scenario: Worst-case\n");
                } else {
                    printf("Scenario: Best-case\n");
                }
                comparisons = 0;
                split_index = 0;
                break;

            case 3:
                fp = fopen("inRand.dat", "r");
                printf("Before Sorting: ");
                for (int i = 0; i < MAX_SIZE; i++) {
                    fscanf(fp, "%d", &data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                size = MAX_SIZE;
                quickSort(data, 0, size - 1);
                fp = fopen("outQuickRand.dat", "w");
                printf("After Sorting: ");
                for (int i = 0; i < size; i++) {
                    fprintf(fp, "%d ", data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                printf("Number of Comparisons: %d\n", comparisons);
                if (split_index == 0 || split_index == size - 1) {
                    printf("Scenario: Worst-case\n");
                } else {
                    printf("Scenario: Best-case\n");
                }
                comparisons = 0;
                split_index = 0;
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}
