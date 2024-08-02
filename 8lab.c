#include <stdio.h>
int spaces(char *s)
{
    int cnt = 0;
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] == ' ')
            cnt++;
    }
    return cnt;
}
int tabs(char *s)
{
    int cnt = 0;
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] == '\t')
            cnt++;
    }
    return cnt;
}
int vowels(char *s)
{
    int cnt = 0;
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] == 'a' || 'e' || 'i' || 'o' || 'u' || 'A' || 'E' || 'I' || 'O' || 'U')
            cnt++;
    }
    return cnt;
}
int consonants(char *s)
{
    int count = 0;
    // int v = vowels(s);
    // printf("the vowels are %d",v);
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            if (s[i] != 'a' || 'e' || 'i' || 'o' || 'u' || 'A' || 'E' || 'I' || 'O' || 'U')
                count++;
        }

        if (s[i] >= 97 && s[i] <= 122)
        {
            if (s[i] != 'a' || 'e' || 'i' || 'o' || 'u' || 'A' || 'E' || 'I' || 'O' || 'U')
                count++;
        }
    }

    return count;
}
int sentences(char *s)
{
    int cnt = 0;
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] == '.')
            cnt++;
    }
    return cnt;
}
int lines(char *s)
{
    int cnt = 0;
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] == '\n')
            cnt++;
    }
    return cnt;
}
void replace(char *s)
{
    for (int i = 0; s[i] != '~'; i++)
    {
        if (s[i] == '\t' && '\n')
        {
            s[i] = ' ';
        }
    }
}
int main()
{

    int flag = 0, choice;
    char str1[5000];
    // char temp;
    printf("Enter string: ");
    int k = 0;
    while (str1[k - 1] != '~')
    {
        scanf("%c", &str1[k]);
        k++;
    }

    // int len;

    // scanf("%[^~]s", str1);
    //  getchar();
    // gets(str1);
    // gets(temp);
    // scanf("%c", temp);
    // len = 0;
    /* while (temp != '#')
     {
         str1[len++] = temp;
          //gets(temp);
         scanf("%c", temp);
     }
     str1[len] = '\0';
 */

    while (flag == 0)
    {

        printf("\nPress '1' for countig spaces, tabs,vowels,sentences,lines.\n");
        printf("Press '2' for replacing multiple space with single space.\n");
        printf("Press 3 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The no of spaces is %d.\n", spaces(str1));
            printf("The no of tabs is %d.\n", tabs(str1));
            printf("The no of vowels is %d \n", vowels(str1));

            printf("The no of consonants is %d \n", consonants(str1));
            printf("The no of sentences is %d \n", sentences(str1));
            printf("The no of lines is %d \n", lines(str1));

            break;
        case 2:
            replace(str1);
            printf("%s", str1);
            break;
        case 3:
            flag = 0;
            break;

            break;

        default:
            printf("Invalid Input!");
            break;
        }
    }
}