/*Problem: Implement Insertion Sort - Implement the algorithm.s
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the sorted array or search result*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // insertion sort
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        printf("\nInserting %d into sorted part\n", key);

        while(j >= 0 && arr[j] > key)
        {
            printf("Shifting %d to right\n", arr[j]);
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // print array after each pass
        printf("After pass %d: ", i);
        for(int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }

    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}