#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum
{
    FULL_TIME,
    PART_TIME,
    INTERN
} EmployeeType;
typedef struct
{
    char name[50];
    char department[50];
    int id;
    union
    {
        float salaryPerM;
        float salaryPerH;
    };
    EmployeeType type;

} employee;
struct node
{
    employee data;
    struct node *next;
};
struct node *head = NULL;
void ADD_Employee(employee *ptr)
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
void Remove_Employee(int ID)
{
    struct node *delete = NULL;
    struct node *current = NULL;
    struct node *prev = NULL;
    if (head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    if (head->data.id == ID)
    {
        delete = head;
        head = head->next;
        free(delete);
        return;
    }
    current = head->next;
    prev = head;
    while (current != NULL)
    {
        if (current->data.id == ID)
        {
            delete = current;
            prev->next = current->next;
            free(delete);
            return;
        }
        prev = current;
        current = current->next;
    }
    if (delete == NULL)
    {
        printf("%d not found in the List.", ID);
    }
}
void filterByDepartment(char Dep[50])
{
    struct node *p = head;
    int Is_Found = 0;
    for (int i = 0; p != NULL; i++)
    {
        if (strcmp(p->data.department, Dep) == 0)
        {
            printf("%s\n", p->data.name);
        }
        p = p->next;
    }
}
float calculateTotalPayroll()
{
    struct node *p = head;
    float total_salary = 0;
    for (int i = 0; p != NULL; i++)
    {
        if (p->data.type == PART_TIME || p->data.type == INTERN)
        {
            p->data.salaryPerM = p->data.salaryPerH * 240;
        }
        total_salary += p->data.salaryPerM;
        p = p->next;
    }
    return total_salary;
}
void searchEmployee(int ID)
{
    struct node *p = head;
    int is_found = 0;
    for (int i = 0; p != NULL; i++)
    {
        if (p->data.id == ID)
        {
            printf("%s", p->data.name);
            is_found = 1;
            break;
        }
        p = p->next;
    }
    if (is_found == 0)
    {
        printf("NOT_Found");
    }
}
int main(void)
{
    employee Emp;
    employee *emp = &Emp;
    int num = 0;
    int typ;
    int Id;
    char dep[50];
    printf("/*******************Employee Management System*******************/");
    while (1)
    {
        printf("\n1-Add Employee.\n2-Remove Employee.\n3-Filter by Department.\n4-Calculate Total Payroll.\n5-Search employee by id.\n6-Exit\nchoose what do you want:");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("Enter the ID : ");
            scanf("%d", &emp->id);
            printf("Enter the name : ");
            scanf(" %s", emp->name);
            printf("Enter the department : ");
            scanf("%s", emp->department);
            printf("Choose the type\n0-FULL Time\n1-Part Time\n2-Intern\nChoose:");
            scanf("%d", &typ);
            emp->type = typ;
            printf("Enter your salary:");
            if (emp->type == FULL_TIME)
            {
                scanf("%f", &emp->salaryPerM);
            }
            else
            {
                scanf("%f", &emp->salaryPerH);
            }
            ADD_Employee(emp);
            break;
        case 2:
            printf("Enter the id : ");
            scanf("%d", &Id);
            Remove_Employee(Id);
            break;
        case 3:
            printf("Enter department : ");
            scanf("%s", dep);
            filterByDepartment(dep);
            break;
        case 4:
            printf("Total payrol = %.2f/Month", calculateTotalPayroll());
            break;
        case 5:
            printf("Enter the ID : ");
            scanf("%d", &Id);
            searchEmployee(Id);
            break;
        case 6:
            return 0;
        }
    }
}