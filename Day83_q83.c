/*Problem: Implement Selection Sort - Implement the algorithm.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the sorted array or search result
*/
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

    // selection sort
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap
        if(minIndex != i)
        {
            printf("Swapping %d and %d\n", arr[i], arr[minIndex]);

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        // print array after each pass
        printf("After pass %d: ", i + 1);
        for(int k = 0; k < n; k++)
            printf("%d ", arr[k]);
        printf("\n");
    }

    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}