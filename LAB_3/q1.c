#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 300

int comparisons = 0;

void merge(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;  
    int left_size = mid - left + 1;
    int right_size = right - mid;

 
    int left_arr[left_size];
    int right_arr[right_size];


    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }


    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size) {
        comparisons++;
        if (left_arr[i] <= right_arr[j]) {
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
        }
    }

   
    while (i < left_size) {
        arr[k++] = left_arr[i++];
    }

   
    while (j < right_size) {
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, right);
    }
}

int main() {
    int choice;
    int data[MAX_SIZE];
    int size;
    FILE *fp;
    clock_t start, end;
    double time_taken;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
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
                start = clock();
                merge_sort(data,0, size-1);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;
                fp = fopen("outMergeAsce.dat", "w");
                printf("After Sorting: ");
                for (int i = 0; i < size; i++) {
                    fprintf(fp, "%d ", data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                printf("Number of Comparisons: %d\n", comparisons);
                printf("Execution Time: %.2f ns\n", time_taken);
                comparisons = 0;
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
                start = clock();
                merge_sort(data,0, size-1);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;
                fp = fopen("outMergeDesc.dat", "w");
                printf("After Sorting: ");
                for (int i = 0; i < size; i++) {
                    fprintf(fp, "%d ", data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                printf("Number of Comparisons: %d\n", comparisons);
                printf("Execution Time: %.2f ns\n", time_taken);
                comparisons = 0;
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
                start = clock();
                merge_sort(data,0, size-1);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9;
                fp = fopen("outMergeRand.dat", "w");
                printf("After Sorting: ");
                for (int i = 0; i < size; i++) {
                    fprintf(fp, "%d ", data[i]);
                    printf("%d ", data[i]);
                }
                printf("\n");
                fclose(fp);
                printf("Number of Comparisons: %d\n", comparisons);
                printf("Execution Time: %.2f ns\n", time_taken);
                comparisons = 0;
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
