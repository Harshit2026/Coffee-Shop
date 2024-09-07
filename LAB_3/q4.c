#include<stdio.h>
#include<stdlib.h>
#define N 300
typedef struct{
	int max; 
	int min;
}Pair;
Pair MaxMin(int arr[], int low, int high){
	Pair res;
	Pair left;
	Pair right;
	if(low == high){
		res.max = res.min = arr[low];
		return res;
	}
	if(low == high - 1){
		if(arr[low] < arr[high]){
			res.min = arr[low];
			res.max = arr[high];
		}
		else{
			res.min = arr[high];
			res.max = arr[low];
		}
		return res;
	}
	int mid = (low + high) / 2;
	left = MaxMin(arr , low, mid );
	right = MaxMin(arr, mid + 1, high);
	res.max = (left.max > right.max) ? left.max : right. max;
	res.min = (left.min < right.min) ? left.min : right. min;
	return res;
}
int main(){
	int arr[N];
	FILE *fp = fopen("inRand.txt","r");
	printf("Contents of Array: ");
	for(int i=0; i<N; i++){
		fscanf(fp, "%d",&arr[i]);
		printf("%d ", arr[i]);
	}
	Pair res = MaxMin(arr,0,N-1);
	printf("\nMax Element: %d\n",res.max);
	printf("\nMin Element: %d\n",res.min);
	fclose(fp);
}

			
