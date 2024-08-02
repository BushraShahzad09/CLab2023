#include <stdio.h>
void hexa(int n)
{
    int remainder;
    int i = 0;
    char hexa[100];
    while (n != 0)
    {
        remainder = n % 16;
        if (remainder >= 10)
            remainder = remainder + 55;
        else
            remainder = remainder + 48;

        hexa[i++] = remainder;
        n = n / 16;
    }
    printf("The hexa decimal no is\n");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexa[j]);
    }
}
void decimal(char *no)
{
    int i, sum = 0, factor = 1, count = 0;
    for (i = 0; no[i] != '\0'; i++)
    {
        count++;
    }

    for (i = count - 1; i >= 0; i--)
    {
        if (no[i] >= 'A' && no[i] <= 'F')
            sum += (no[i] - 55) * factor;
        else if (no[i] >= 'a' && no[i] <= 'f')
            sum += (no[i] - 87) * factor;
        else if (no[i] >= '0' && no[i] <= '9')
            sum += (no[i] - 48) * factor;
        factor *= 16;
    }
    printf("The decimal no is %d.\n", sum);
}
int main()
{
    int n, flag = 1, key;
    char no[100];
    while (flag == 1)
    {
        printf("\nPress '1' to convert decimal no. into hexadecimal\n");
        printf("Press '2' to convert hexadecimal  no. into decimal \n");
        printf("Press '3' to Exit!\n");
        scanf("%d", &key);
        switch (key)
        {
        case 1:
            printf("Enter the decimal no.\n");
            scanf("%d", &n);
            hexa(n);

            break;
        case 2:
            printf("Enter the hexadecimal no.\n");
            scanf("%s", no);
            decimal(no);
            break;
        case 3:
            flag = 0;
            if (flag == 0)
            {
                break;
            }

            break;

        default:
            printf("Invalid Input!\n");
            break;
        }
    }

    return 0;
}