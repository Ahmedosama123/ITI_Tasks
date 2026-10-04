/*
 ============================================================================
 Name        : Lab1_task1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float x1,x2,y1,y2,distance,x,y;
	printf("please enter first point\nx1:");
	scanf("%f",&x1);
	printf("y1:");
	scanf("%f",&y1);
	printf("\nSecond point\nx2:");
	scanf("%f",&x2);
	printf("y2:");
	scanf("%f",&y2);
	x=x2-x1;
	y=y2-y1;
	distance = sqrt((x*x)+(y*y));
	printf("\nthe ditance = %0.2f",distance);
	return 0;
}
