#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n= 0;
    int d = 0;
    scanf("%d",&n);
    scanf("%d",&d);
    int *arr = malloc(sizeof(int) * n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    printf("%d ",arr[d]);
    for(int j = (d+1)%n; j != d; j = (++j)%n){
        printf("%d ",arr[j]);
    }
    return 0;
}

