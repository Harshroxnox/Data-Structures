//Pivot is 1st element 
//Time complexity of this is O(n^2) worst case
//Avg case time complexity is nlogn
//Based on divide and conquer

#include <stdio.h>

void quickSort(int * arr, int l, int h){
    if(l>=h){
        return;
    }
    int pivot = l;

    for(int i=l+1; i<=h; i++){
        if(arr[i] <= arr[pivot]){
            int j=i;
            while(j>=pivot+1){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
            pivot++;
        }
    }
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