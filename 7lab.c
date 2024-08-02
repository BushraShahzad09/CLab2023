#include <stdio.h>
float percentage(int a, int b, int c)
{
    float x = ((a + b + c) * 100) / 300;
    return x;
}
int main()

{

    printf("Enter the number of students.\n");
    int n;
    scanf("%d", &n);
    // int roll_no, age, sub1, sub2, sub3;
    int arr[n][5];
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < 5)
        {
            printf("Enter the roll no of student : \n");
            scanf("%d", &arr[i][j]);

            j++;

            printf("Enter the age of student: \n");
            scanf("%d", &arr[i][j]);

            j++;

            printf("Enter the marks of subject 1 of student: \n");
            scanf("%d", &arr[i][j]);

            j++;

            printf("Enter the marks of subject 2 of student: \n");
            scanf("%d", &arr[i][j]);

            j++;

            printf("Enter the marks of subject 3 of student: \n");
            scanf("%d", &arr[i][j]);

            j++;
        }
    }
    int choice, flag = 0, toppperArray[n];
    while (flag == 0)
    {

        printf("Press 0 to display the marks of all students.\n");
        printf("Press 1 to display percentage of each student along with roll no.\n");
        printf("Press 2 to display topper of each subject with roll no.\n");
        printf("Press 3 to display list of toppers.\n");
        printf("Press 4 to exit.\n");
        printf("Enter the choice:\n");

        scanf("%d", &choice);
        int s1, s2, s3;
        int max, top1;
        switch (choice)
        {
        case 0:
            printf("Roll No\t\tAge\t\tSub 1\t\tSub 2\t\tSub 3\n");

            for (int i = 0; i < n; i++)
            {
                for (int k = 0; k < 5; k++)
                {
                    printf("%d\t\t", arr[i][k]);
                }
                printf("\n");
            }
            break;
        case 1:
            // int s1, s2, s3;
            for (int i = 0; i < n; i++)
            {
                int j = 2;
                while (j < 5)
                {
                    s1 = arr[i][j];
                    j++;
                    s2 = arr[i][j];
                    j++;
                    s3 = arr[i][j];
                    j++;
                }
                printf("Percentage of Roll No %d is %f.\n", arr[i][1], percentage(s1, s2, s3));
            }

            break;
        case 2:
            for (int j = 2; j < 5; j++)
            {
                max = arr[0][j];
                for (int i = 1; i < n; i++)
                {
                    if (max < arr[i][j])
                    {
                        max = arr[i][j];
                        top1 = i;
                    }
                }
                printf("The topper in Subject 1 is roll no %d with %d marks.\n", arr[top1][j], max);
            }

            break;
        case 3:
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    int j = 2;
                    while (j < 5)
                    {
                        s1 = arr[i][j];
                        j++;
                        s2 = arr[i][j];
                        j++;
                        s3 = arr[i][j];
                        j++;
                    }
                    toppperArray[k] = percentage(s1, s2, s3);
                }
            }

            break;
        case 4:
            flag = 1;
            break;

        default:
            break;
        }
    }
    return 0;
}
