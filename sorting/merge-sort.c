// Merge Sort algorithm sorting algo with time complexity of O(nlogn)
#include <stdio.h>

void merge(int * arr, int s, int e){
    if(s<e){
        int arr1[e-s+1];
        int m = (s+e)/2;
        int i=s;
        int j=m+1;
        int k;
        for(k=0; k<e-s+1; k++){
            if(i==m+1 || j==e+1){
                break;
            }
            if(arr[i]<arr[j]){
                arr1[k] = arr[i];
                i++;
            }else{
                arr1[k] = arr[j];
                j++;
            }
        }
        while(i<m+1){
            arr1[k] = arr[i];
            k++;
            i++;
        }

        while(j<e+1){
            arr1[k] = arr[j];
            k++;
            j++;
        }

        for(int k=0; k<e-s+1; k++){
            arr[s+k] = arr1[k];
        }
    }
}

void mergeSort(int * arr, int s, int e){
    if(s<e){
        int m = (s+e)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, e);
    }
}

int main(){
    int arr[4] = {1,2,3,1};
    mergeSort(arr, 0, 3);

    for(int i=0; i<4; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}