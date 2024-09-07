#include<stdio.h>
#include<stdlib.h>
# define N 300
int binarySearch(int arr[], int l , int h, int x){
	if(l==h){
		if(arr[l] == x)
			return l;
		else 
			return -1;
	}
	else{
		int mid = l + (h-l) / 2;
		if(arr[mid] == x)
			return mid;
		else if (arr[mid] > x) 
			return binarySearch(arr, l , mid-1, x);
		else
			return binarySearch(arr, mid+1, h , x);
	}
}
int main(){
	int i;
	int arr[N] = {0};
	int x;
	printf("Enter number to be searched: ");
	scanf("%d",&x);
	FILE *fp = fopen("inAsce.txt","r");
	printf("Contents of Array: ");
	for(i=0; i<N; i++){
		fscanf(fp, "%d ",&arr[i]);
		printf("%d ", arr[i]);
	}
	int index = binarySearch(arr, 0, N-1, x);
	index == -1 ? printf("\n%d is not in array\n",x) : printf("\n%d is present at index : %d\n",x,index);
	fclose(fp);
}
	
	
			 		
