#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
void merge(int array[], int low, int mid,int high){
	  	int s1 = mid - low +1 ;
	  	int s2 = high - mid ;
	  	int left[s1];
	  	int right[s2];
	  	for(int i = 0 ; i < s1 ; i++){
	  		left[i] = array[low+i];
	  	}	
	  	for(int i = 0 ; i < s2 ; i++){
	  		right[i] = array[mid+i+1];
	  	}
	  	int i = 0 ; 
	  	int j = 0 ; 
	  	int index = low ;
	  	while(i < s1 && j < s2){
	  		if(left[i] <= right[j]){
	  			array[index] = left[i];
	  			index++;
	  			i++;
	  		}
	  		else{
	  			array[index] = right[j];
	  			index++;
	  			j++;
	  		}
	  	}
	  	while(i < s1){
	  		array[index] = left[i];
	  		i++;
	  		index++;
	  	}
	  	while(j < s2){
	  		array[index] = right[j];
	  		index++;
	  		j++;
	  	}
	  	
	  	  
}
void mergesort(int array[],int low,int high){
	if(low < high){
	int mid = (low+high)/2;
		mergesort(array,low,mid);
		mergesort(array,mid+1,high);
		merge(array,low,mid,high);
	}
}
int swaps_quick = 0;
void swap(int *a,int *b){
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}
int partition(int arr[], int low, int high){
	int i = low -1 ;
    int pivot = arr[low];
    int j = high +1 ;
    while(true){
    	do{
    	i++;
    	}while(arr[i] < pivot);
    	do{
    	j--;
    	}while(arr[j] > pivot);
    	if(i >= j){
    	return j;
    	}
    	swap(&arr[i],&arr[j]);
		swaps_quick++;
    }
}

void quicksort(int arr[], int low, int high){
		//swaps_quick = 0 ;
    if (low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi);
        quicksort(arr, pi + 1, high);
    }
}



int main(){

  FILE *fptr;
  fptr = fopen("randomm.txt", "w");
  if (fptr == NULL){
    printf("ERROR Creating File!");
    exit(1);
  }

  int n = 100000;
  srand(time(0));
  for (int i = 1; i <= n; i++){
    int r = rand() % 100;
    fprintf(fptr, "%d\n", r);
  }
  fclose(fptr);

  int block = 1;
  printf("Block\tMergeSort\tQuicksort\tQuick_swaps\n");
  for (int i = 100; i <= n; i += 100){
    fptr = fopen("randomm.txt", "r");
    int arr[i];

    for (int j = 0; j < i; j++){
      fscanf(fptr, "%d", &arr[j]);
    }
    clock_t t;
    t = clock();
    mergesort(arr,0,i-1);
    t = clock() - t;
    double time_takenss = ((double)t) / CLOCKS_PER_SEC; 
    fclose(fptr);

    fptr = fopen("randomm.txt", "r");
    int arr2[i];
    for (int j = 0; j < i; j++){
      fscanf(fptr, "%d", &arr2[j]);
    }
    clock_t t2;
    t2 = clock();
    quicksort(arr2, 0,i-1);
    t2 = clock() - t2;
    double time_takenis = ((double)t2) / CLOCKS_PER_SEC;

    printf("%d\t%f\t%f\t%d\n", block, time_takenss, time_takenis,swaps_quick);

    fclose(fptr);
    block++;

  }
  return 0;
}
