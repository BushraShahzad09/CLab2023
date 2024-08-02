// linear search, binary search
#include <stdio.h>
int linearSearch(int arr[], int n, int findEle)
{
    for (int i = 0; i < n; i++)
    {
        if (findEle == arr[i])
        return i;
        
    }
    return -1;
}
int binarySearch(int arr[], int n, int findEle)
{
       for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int start = 0, end = n - 1, mid;
       while (start <= end)
    {
        mid = (start + end) / 2;

        if (findEle == arr[mid])
        {
            return mid;
        }
        else if (findEle > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int i, n, choice;
    printf("Enter the no of ele : ");
    scanf("%d", &n);
    printf("Enter the ele : \n");
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
   while (1)
    {
        printf("\nEnter '1' for linear search, '2' for binary search and '3' for displaying array and '4' to exit! : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int findEle;
            printf(("Enter the element to be searched:\n"));
            scanf("%d", &findEle);
            int flag = linearSearch(arr, n, findEle);

            if (flag == -1)
            {
                printf("%d is not present.\n", findEle);
            }
            else
            {
                printf("%d is present at %d.\n", findEle, flag);
            }
            break;
        }
        case 2:
        {
            int findEle;
            printf("Enter the element to be searched : ");
            scanf("%d", &findEle);
            int flag = binarySearch(arr, n, findEle);
            if (flag == -1)
            {
                printf("%d is not present.\n", findEle);
            }
            else
            {
                printf("%d is present at %d in new sorted array.\n", findEle, flag);
            }
            break;
        }
        case 3:
        {
            printf("Displaying the elements of an array : \n");

            for (int i = 0; i < n; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        }
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid input.");
            break;
        }
    }
return 0;
}