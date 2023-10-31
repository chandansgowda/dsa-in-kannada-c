#include <stdio.h>
#include <stdlib.h>

void arrayInput(int n, int *arr){
    printf("Enter array elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void arrayDisplay(int n, int *arr){
    if (n==0){
        printf("Array is Empty\n");
        return;
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int key, int n, int *arr){
    for (int i=0; i<n; i++){
        if (arr[i]==key){
            printf("Key found at index %d\n", i);
            return i;
        }
    }
    printf("Key not found\n");
    return -1;
}

void binarySearch(int *arr, int key, int low, int high) {
    while (low<=high){
        int mid = (low+high)/2;
        if (arr[mid]==key) {
            printf("Key found at index %d\n", mid);
            return;
        }
        else if (arr[mid]<key){
            low = mid + 1;
        }
        else {
            high = mid-1;
        }
    }
    printf("Key not found\n");
}

void insert(int *n,int *arr,int pos,int key){

    for(int i = *n;i>=pos-1;i--){
        *(arr+i)=*(arr+i-1);
    }

    *(arr+pos-1) = key;
    (*n)++;
}

void deleteIndex(int *n,int *arr,int index){

    for(int i=index;i<*n;i++){
        *(arr+i) = *(arr+i+1);
    }

    (*n)--;

    printf("Deleted Successfully :)\n");
}

void deleteValue(int *n,int *arr,int key){

    int index = linearSearch(key,*n,arr);

    if (index>=0) deleteIndex(n,arr,index);
    else printf("%d does not exist in array :(\n",key);
}

void reverse(int n, int *arr){
    int l = 0;
    int h = n-1;
    int temp;
    while (l<h){
        temp = arr[l];
        arr[l] = arr[h];
        arr[h] = temp;
        l++;
        h--;
    }
}

void bubble_sort(int n, int *arr){
    for (int step=0;step<n-1;step++){
        int swapped = 0;
        for (int i=0; i<n-1-step; i++){
            if (arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
        if (swapped==0){
            break;
        }
    }

}

int main(){
    int choice, n=0, key, pos, index;
    int arr[100];

    while(1){
        printf("---Array Operations---\n");
        printf("1.Input\n2.Output\n3.Linear Search\n"
        "4.Binary Search\n5.Insert at Position\n"
        "6.Delete at Index\n7.Delete using Value\n8.Reverse\n9.Bubble Sort\n"
        "Select option: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                printf("Enter array size: ");
                scanf("%d",&n);
                arrayInput(n,arr);
                break;
            }
            case 2: {
                arrayDisplay(n,arr);
                break;
            }
            case 3: {
                printf("Enter key to search: ");
                scanf("%d",&key);
                linearSearch(key,n,arr);
                break;
            }
            case 4: {
                printf("Enter key to search: ");
                scanf("%d",&key);
                binarySearch(arr, key, 0, n-1);
                break;
            }
            case 5: {
                printf("Enter value to insert>> ");
                scanf("%d",&key);
                printf("Enter position to insert>> ");
                scanf("%d",&pos);
                if ((pos<=0)|(pos>n+1)) {
                    printf("Position out of range :(\n");
                    break;
                }
                insert(&n,arr,pos,key);
                printf("Insertion Successfull :)\n");
                break;
            }
            case 6:{
                printf("Enter index of element to delete>> ");
                scanf("%d",&index);
                if ((index<0)|(index>n-1)) {
                    printf("Index out of range :(\n");
                    break;
                }
                deleteIndex(&n,arr,index);
                break;
            }
            case 7:{
                printf("Enter value to delete>> ");
                scanf("%d",&key);
                deleteValue(&n,arr,key);
                break;
            }
            case 8:{
                reverse(n, arr);
                break;
            }
            case 9:{
                bubble_sort(n, arr);
                break;
            }
            default: exit(1);
        }
    }


    return 0;
}
