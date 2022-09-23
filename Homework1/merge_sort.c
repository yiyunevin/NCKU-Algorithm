#include<stdio.h>
#include<stdlib.h>

void MergeSort(int *list, int start, int end);          // Divide & Conquer
void Merge(int *list, int start, int middle, int end);  // Conquer & Combine

void MergeSort(int *list, int start, int end)
{
    if (end > start){
        int middle = (end + start) / 2;
        MergeSort(list, start, middle);
        MergeSort(list, middle+1, end);
        Merge(list, start, middle, end);
    }
}

void Merge(int *list, int start, int middle, int end)
{
    // Two Diveded Group
    int len1 = middle - start + 1;
    int len2 = end - middle;
    int *first;
    int *second;
    first = (int*)malloc(len1 * sizeof(int));
    second = (int*)malloc(len2 * sizeof(int));
    int i, j, k;
    for (i=0; i<len1; i++){
        first[i] = list[start+i]; 
    }
    for (j=0; j<len2; j++){
        second[j] = list[middle+1+j];
    }
    // Conquer and Merge
    i = 0; j = 0; k = start;
    while(i<len1 && j<len2)
    {
        if(first[i] <= second[j]){
            list[k] = first[i];
            i++; k++;
        }
        else{
            list[k] = second[j];
            j++; k++;
        }
    }

    while(i<len1){
        list[k] = first[i];
        i++; k++;
    }

    while(j<len2){
        list[k] = second[j];
        j++; k++;
    }
}

int main(int argc, char *argv[])
{
    FILE *fin, *fout;
    fin = fopen("input.txt", "r");
    if(fin == NULL){
        printf("Failed to open input file input.txt.\n");
        return 1;
    }
    fout = fopen("out.txt", "w");
    if(fout == NULL){
        printf("Failed to open output file out.txt. \n");
        return 1;
    }
    
    // Read File (num. of keys , list of keys)
    
    int n, key, i=0;
    fscanf(fin, "%d", &n);
        
    int *arr = (int*)malloc(n * sizeof(int));
    while(fscanf(fin, "%d ", &key) != EOF)
        arr[i++] = key;

    printf("Original: \n");
    for(i=0; i<7; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    // Merge Sort
    
    MergeSort(arr, 0, 6);
    
    // Write File (num. of keys, keys line b line)
    
    fprintf(fout, "%d\n", n);
    printf("Sorted: \n");
    for(i=0; i<7; i++){
        printf("%d ", arr[i]);
        fprintf(fout, "%d ", arr[i]);
    }
    return 0;
}

