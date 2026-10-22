#include <stdio.h>
int strlen(char *str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
int strcmp(char *str1, char *str2)
{
    int check = 0;
    int length1 = 0;
    int length2 = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        length1++;
    }
    for (int i = 0; str2[i] != '\0'; i++)
    {
        length2++;
    }
    if (length1 > length2)
    {
        for (int i = 0; i < length2; i++)
        {
            if (str1[i] > str2[i])
            {
                check = 1;
                break;
            }
            else if (str1[i] < str2[i])
            {
                check = -1;
                break;
            }
        }
        if (check == 0)
        {
            check = 1;
        }
    }
    else if (length1 < length2)
    {
        for (int i = 0; i < length1; i++)
        {
            if (str1[i] > str2[i])
            {
                check = 1;
                break;
            }
            else if (str1[i] < str2[i])
            {
                check = -1;
                break;
            }
        }
        if (check == 0)
        {
            check = -1;
        }
    }
    else
    {
        for (int i = 0; i < length1; i++)
        {
            if (str1[i] > str2[i])
            {
                check = 1;
                break;
            }
            else if (str1[i] < str2[i])
            {
                check = -1;
                break;
            }
        }
    }
    return check;
}
int strncmp(char *str1, char *str2, int n)
{
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] > str2[i])
        {
            check = 1;
            break;
        }
        else if (str1[i] < str2[i])
        {
            check = -1;
            break;
        }
    }
    return check;
}
char *strcpy(char *dest, char *src)
{
    int length = 0;
    for (int i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
        length++;
    }
    dest[length] = '\0';
    return dest;
}
char *strncpy(char *dest, char *src, int n)
{
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
        length++;
    }
    return dest;
}
char *strcat(char *dest, char *src)
{
    int length = 0;
    for (int i = 0; dest[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = 0; i < src[i] != 0; i++)
    {
        dest[length++] = src[i];
    }
    dest[length] = '\0';
    return dest;
}
char *strncat(char *dest, char *src, int n)
{
    int length = 0;
    for (int i = 0; dest[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = 0; i < n; i++)
    {
        dest[length++] = src[i];
    }
    dest[length] = '\0';
    return dest;
}
char *strchr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            return &str[i];
        }
    }
    return NULL;
}
char *strrchr(char *str, char c)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = length; i > 0; i--)
    {
        if (str[i] == c)
        {
            return &str[i];
        }
    }
    return NULL;
}
char *strstr(char *big, char *small)
{
    int check = 0;
    int index = -1;
    for (int i = 0; big[i] != '\0'; i++)
    {
        if (big[i] == small[0])
        {
            int w = i;
            for (int j = 0; small[j] != '\0'; j++)
            {
                if (big[w++] = small[j])
                {
                    check = 1;
                    break;
                }
            }
            if (check == 0)
            {
                index = i;
                break;
            }
            else
            {
                check == 0;
            }
        }
    }
    if (index >= 0)
    {
        return &big[index];
    }
    return NULL;
}
int strcspn(char *str , char c){
    int length = 0;
    for (int i = 0 ; str[i]!=c ; i++){
        length++;
    }
    return length;
}
void *memchr(void *ptr , int c , int n){
    int check = 0;
    for(int i = 0 ; i < n ; i++){
        if(ptr == &c){
        check = 1;
            break;
        }
        ptr+=1;
    }
    if(check == 1){
        return ptr;
    }
    return NULL;
}
int memcmp(void *ptr1 , void *ptr2 , int n){
    int cmp = 0;
    for(int i = 0 ; i < n ; i++){
        if(ptr1 > ptr2){
            cmp = 1;
            break;
        }
        else if (ptr1 < ptr2 ){
            cmp = -1;
            break;
        }
        ptr1+=1;
        ptr2+=1;
    }
    return cmp;
}

