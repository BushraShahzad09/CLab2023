// ascending and descending order
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *arr, int n)
{
    printf("\nDisplaying Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void ascending(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
    display(arr, n);
}
void descending(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
    display(arr, n);
}
int max(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int arr[100];
    int n;
    printf("Enter the no of ele in an array:\n");
    scanf("%d", &n);
    printf("Enter the ele in an array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int counter = 0;
    while (counter != 1)
    {
        printf("\n\nEnter '1' for ascending order, '2' for descending order, '3' to find max, '4' to exit!\n");
        int choice, index, element;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ascending(arr, n);

            break;
        case 2:
            descending(arr, n);
            break;
        case 3:
            printf("The maximum element is %d", max(arr, n));
            break;
        case 4:
            counter = 1;
            break;

        default:
            printf("Wrong Input!");
            break;
        }
    }

    return 0;
}