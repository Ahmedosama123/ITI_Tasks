#include <stdio.h>
#include <stdlib.h>
struct complex{
    float real;
    float imagin;
};
typedef struct complex comp;
comp add(comp *c1 , comp *c2){
    comp c3;
    c3.real = c1->real + c2->real;
    c3.imagin = c1->imagin + c2->imagin;
    return c3;
}
comp multiply(comp *c1 , comp *c2){
    comp c3;
    c3.real = c1->real * c2->real - c1->imagin * c2->imagin;
    c3.imagin = c1->imagin * c2 ->real + c1->real * c2->imagin;
    return c3; 
}
int main(void){
    comp com1,com2,com3,com4;// com3 = com1 + com2 --- com4 = com1 * com2
    comp *p1 = &com1 , *p2 = &com2;
    printf("Enter the first complex number:\nreal:");
    scanf("%f",&com1.real);
    printf("Imagin:");
    scanf("%f",&com1.imagin);
    printf("Enter the second complex number:\nreal:");
    scanf("%f",&com2.real);
    printf("Imagin:");
    scanf("%f",&com2.imagin);
    com3=add(p1,p2);
    com4=multiply(p1,p2);
    printf("com1+com2=%.2f+%.2fi\n",com3.real,com3.imagin);
    printf("com1*com2=%.2f+%.2fi\n",com4.real,com4.imagin);

}