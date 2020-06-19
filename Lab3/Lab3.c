#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

int max;
int min;
int avg=0;

void swap(int* xp, int* yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n){ 
    int i, j, min_idx; 
  
    for (i = 0; i < n - 1; i++){ 
        min_idx = i; 
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx]){ 
                min_idx = j; 
            }
        swap(&arr[min_idx], &arr[i]); 
        } 
    } 
    min = arr[0];
    max = arr[n-1];
}

void generateRandomNumbers(int arr[], int n){
    int i;

    printf("The %d random numbers generated: \n", n);
    for(i=0;i<n;i++){
        arr[i]= rand()% 101;
        printf("%d ", arr[i]);
    }
}

void averageValue(int arr[], int n){
    int sum=0;
    int i;
    
    for(i=0;i<n;i++){
        sum+=arr[i];    
    }
    avg = sum/n;  
}

void *minValue(void *param){
   printf("\nThe min value is: %d", min);
}

void *maxValue(void *param){
     printf("\nThe max value is: %d", max);
}

void *printAvgValue(void *param){
     printf("\nThe average value is: %d", avg);
}

int main(){
    int userInput;
    srand(time(NULL));
    pthread_t smNum;
    pthread_t avgNum;
    pthread_t maxNum;

    printf("How many random numbers would you like to generate?\n");
    scanf("%d",&userInput);
    
    int numArray[userInput];
    int size = sizeof(numArray)/ sizeof(numArray[0]);
   
    generateRandomNumbers(numArray, size);
    selectionSort(numArray, size);
    averageValue(numArray, size);

    pthread_create(&avgNum,NULL,printAvgValue,NULL);
    pthread_create(&smNum,NULL,minValue,NULL);
    pthread_create(&maxNum,NULL,maxValue,NULL);

    pthread_join(avgNum,NULL);
    pthread_join(smNum,NULL);
    pthread_join(maxNum,NULL);

    printf("\n"); 
    return (0);
}
