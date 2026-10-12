#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*****************************************************/
typedef struct
{
    char name[20];
    int age;
    float total_marks;
} student;
void add_student(student *stu)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d-Enter your name:", i + 1);
        fgets(stu->name, sizeof(stu->name), stdin);
        printf("%d-Enter your age:", i + 1);
        scanf("%d", &stu->age);
        printf("%d-Enter your Total Marks:", i + 1);
        scanf("%f", &stu->total_marks);
        getchar();
        stu++;
    }
}
void print_students(student *stu)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d-Name:%s,Age:%d,TotalMarks:%0.2f\n", i + 1, stu->name, stu->age, stu->total_marks);
        stu++;
    }
}
void getTop3(student *stu)
{
    float top1 = 0, top2 = 0, top3 = 0;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (stu[i].total_marks >= top1)
        {
            top1 = stu[i].total_marks;
            count = i;
        }
    }
    printf("Top(1) %s,%0.2f\n", stu[count].name, stu[count].total_marks);
    count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (stu[i].total_marks >= top2 && stu[i].total_marks < top1)
        {
            top2 = stu[i].total_marks;
            count = i;
        }
    }
    printf("Top(2) %s,%0.2f\n", stu[count].name, stu[count].total_marks);
    count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (stu[i].total_marks >= top3 && stu[i].total_marks < top2)
        {
            top3 = stu[i].total_marks;
            count = i;
        }
    }
    printf("Top(3) %s,%0.2f\n", stu[count].name, stu[count].total_marks);
    count = 0;
}
int main(void)
{
    student s[5];
    student *p = s;
    float Total = 0;
    float averaga = 0;
    add_student(p);
    print_students(p);
    for (int i = 0; i < 5; i++)
    {
        Total += p->total_marks;
        p++;
    }
    averaga = Total / 5;
    p = s;
    printf("The average of total marks = %0.2f\n", averaga);
    getTop3(p);
}