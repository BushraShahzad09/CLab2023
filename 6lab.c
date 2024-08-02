#include <stdio.h>
int strrlen(char *s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        count++;
    return count;
}
void strrcpy(char a[])
{
    int n = strrlen(a) - 1;
    char b[n];
    int i;
    for (i = 0; a[i] != '\0'; i++)
        b[i] = a[i];
    b[i] = '\0';
    printf("%s", b);
}
void concatenate(char *a, char *b)
{
    int n1 = strrlen(a);
    int i;
    for (i = 0; b[i] != '\0'; ++i, n1++)
        a[n1] = b[i];
    a[n1++] = '\0';
    printf("The concatenated string is %s", a);
}
void reverse(char a[])
{
    int n = strrlen(a) - 1;
    char b[n];
    int i, j;
    for (i = 0, j = n; a[i] != '\0'; i++, j--)
        b[j] = a[i];
    b[i++] = '\0';
    printf("The reversed string is %s", b);
}
void compare(char *a, char *b)
{
    int counter = 0;
    int n1 = strrlen(a);
    int n2 = strrlen(b);
    if (n1 == n2)
    {
        int i;
        for (i = 0; a[i] != '\0'; i++)
        {
            if (a[i] != b[i])
            {
                counter = 1;
                break;
            }
        }
    }
    else if (n1 != n2)
        counter = 1;
    if (counter == 0)
        printf("yes, the enetred strings are  same.\n");
    else
        printf("Noi, the enetred strings are NOT same.\n");
}
void isPalindorme(char a[])
{
    int n = strrlen(a);
    int i = 0, j = n - 1, counter = 0;
    while (i <= j)
    {
        if (a[i] != a[j])
        {
            counter = 1;
            break;
        }
        else
        {
            i++;
            j--;
        }
    }
    if (counter == 0)
        printf("yes, the enetred string is Palindome\n");
    else
        printf("Noi, the enetred strings are NOT palindome.\n");
}
void substring(char *a, char *b)
{
    int n1 = 0, n2 = 0, i, j, flag = 0;
    n1 = strrlen(a);
    n2 = strrlen(b);
    for (i = 0; i <= n1 - n2; i++)
    {
        for (j = i; j < i + n2; j++)
        {
            flag = 1;
            if (a[j] != b[j - i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        printf("yes, '%s' is a substring of '%s'!", b, a);
    else
        printf("no, '%s' is not a substring of '%s'!", b, a);
}
int main()
{
    int flag = 0, choice;
    char str1[100], str2[100], str3;
    while (flag == 0)
    {
        printf("\n\nPress '1' for finding length.\n");
        printf("Press '2' for copying strings\n");
        printf("Press '3' for concatenating two string.\n");
        printf("Press '4' for reversing the string\n");
        printf("Press '5' for comapring the two strings .\n");
        printf("Press '6' for checking if a string is palindrome.\n");
        printf("Press '7' for checking substring.\n");
        printf("Press '8' to Exit!.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter string:\n");
            getchar();
            gets(str1);
            printf("The length of the string is %d.", strrlen(str1));
            break;
        case 2:
            printf("Enter string:\n");
            getchar();
            gets(str1);
            printf("The copied string is:\n");
            strrcpy(str1);
            break;
        case 3:
            printf("Enter string 1:\n");
            getchar();
            gets(str1);
            printf("Enter string 2:\n");
            gets(str2);
            concatenate(str1, str2);
            break;
        case 4:
            printf("Enter string 1:\n");
            getchar();
            gets(str1);
            reverse(str1);
            break;
        case 5:
            printf("Enter string 1:\n");
            getchar();
            gets(str1);
            printf("Enter string 2:\n");
            gets(str2);
            compare(str1, str2);
            break;
        case 6:
            printf("Enter string 1:\n");
            scanf("%s", str1);
            isPalindorme(str1);
            break;
        case 7:
            printf("Enter string 1:\n");
            getchar();
            gets(str1);
            printf("Enter string 2:\n");
            gets(str2);
            substring(str1, str2);
            break;
        case 8:
            flag = 0;
            break;
        default:
            printf("Invalid Input!");
            break;
        }
    }
    return 0;
}