//Pivot is 1st element 
//Time complexity of this is O(n^2) worst case
//Avg case time complexity is nlogn
//Based on divide and conquer

#include <stdio.h>

int partition(int * arr, int l, int h){
    int pivot = arr[l];
    int start = l;
    int end = h;

    while(start<end){
        while(arr[start]<= pivot){
            start++;
        }

        while(arr[end]>pivot){
            end--;
        }

        if(start<end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[l];
    arr[l] = arr[end];
    arr[end] = temp;
    return end;
}

void quickSort(int * arr, int l, int h){
    if(l>=h){
        return;
    }
    int pivot = partition(arr, l, h);

    quickSort(arr, l, pivot-1);
    quickSort(arr, pivot+1, h);

}

int main(){

    int arr[9] = {7,6,10,5,9,2,1,15,7};

    quickSort(arr, 0, 8);

    for(int i=0; i<9; i++){
        printf("%d\n", arr[i]);
    }


    return 0;
}