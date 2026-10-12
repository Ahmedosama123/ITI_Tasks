#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    NEW,
    OLD,
    RETURNED,
    SAILED,
    RENTED
} BookStatus;
typedef enum
{
    EMBEDDED,
    AUTOMATION,
    MOBILE_APP,
    WEB
} BookCategory;
typedef struct
{
    char title[50];
    char author[50];
    float price;
    int availability;
    BookCategory category;
    BookStatus status;
} book;
struct node
{
    book data;
    struct node *next;
};
struct node *head = NULL;
void add_newBook(book *ptr)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = *ptr;
    link->next = NULL;
    if (head == NULL)
    {
        head = link;
        return;
    }
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = link;
}
void searchByTitle(char T[50])
{
    struct node *p = head;
    int Is_Found = 0;
    for (int i = 0; p!= NULL; i++)
    {
        if (strcmp(p->data.title,T)==0)
        {
            Is_Found = 1;
            if (p->data.availability > 0)
            {
                printf("%s is availabile", p->data.title, p->data.availability);
            }
            else
            {
                printf("Sorry %s isn't availabile Now , It will be available later ", p->data.title);
            }
            break;
        }
        p = p->next;
    }
    if (Is_Found == 0)
    {
        printf("Sorry,Not_Found");
    }
}
void changeStatus(char T[50], BookStatus s)
{
    struct node *p = head;
    int Is_Found = 0;
    for (int i = 0; p != NULL; i++)
    {
        if (strcmp(p->data.title,T)==0)
        {
            Is_Found = 1;
            p->data.status = s;
            printf("Status Updated");
            break;
        }
        p=p->next;
    }
    if (Is_Found == 0)
    {
        printf("Sorry,Not_Found");
    }
}
void CountBookInCategory(void)
{
    struct node *p = head;
    int count[4]={0,0,0,0};
    for (int i = 0; p != NULL; i++)
    {
        if (p->data.category == EMBEDDED)
        {
            ++count[EMBEDDED];
        }
        else if (p->data.category == AUTOMATION)
        {
            ++count[AUTOMATION];
        }
        else if (p->data.category == MOBILE_APP)
        {
            ++count[MOBILE_APP];
        }
        else if (p->data.category == WEB)
        {
            ++count[WEB];
        }
        p=p->next;
    }
    printf("Number of books in Embedded = %d\n", count[EMBEDDED]);
    printf("Number of books in Automation = %d\n", count[AUTOMATION]);
    printf("Number of books in Mobile Application = %d\n", count[MOBILE_APP]);
    printf("Number of books in Web = %d\n", count[WEB]);
}
int main(void)
{
    int num = 0;
    book b;
    book *b_ptr = &b;
    int categg;
    int state;
    char ttl[50];
    printf("/*******************Library Management System*******************/");
    while (1)
    {
        printf("\n1-Add a Book.\n2-Search by title.\n3-Change Status.\n4-count books in each category\n5-EXIT\nchoose what do you want:");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Enter the book title:");
            scanf("%s", &b_ptr->title);
            printf("Enter the book Author:");
            scanf("%s", &b_ptr->author);
            printf("Enter the price:");
            scanf("%f", &b_ptr->price);
            printf("BooK Category:\n1-Embedded\n2-Automation\n3-Mobile App\n4-Web\n");
            scanf("%d", &categg);
            b_ptr->category = categg - 1;
            printf("Is Available Now:1-yes , 0-NO\n");
            scanf("%d",&b_ptr->availability);
            printf("BooK Status:\n1-New\n2-Old\n3-Returned\n4-Sailed\n5-Rented\n");
            scanf("%d", &state);
            b_ptr->status = state - 1;
            add_newBook(b_ptr);
            break;
        case 2:
            getchar();
            printf("Enter the title:");
            scanf("%s",&ttl);
            searchByTitle(ttl);
            break;
        case 3:
            getchar();
            printf("Enter the title:");
            scanf("%s",&ttl);
            printf("Enter the  newstatus:\n1-New\n2-Old\n3-Returned\n4-Sailed\n5-Rented\n");
            scanf("%d", &state);
            state = state - 1;
            changeStatus(ttl, state);
            break;
        case 4:
            CountBookInCategory();
            break;
        case 5:
            return 0;
        }
    }
}
