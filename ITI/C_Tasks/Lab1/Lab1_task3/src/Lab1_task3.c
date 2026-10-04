/*
 ============================================================================
 Name        : Lab3_task3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int x ,y;
	printf("please enter two numbers : ");
	scanf("%d  %d",&x,&y);
	if(y!=0&&(x%y)==0){
		printf("the two numbers is multiplied.");
	}
	else if (x!=0 && (y%x)==0){
		printf("the two numbers is multiplied.");
	}
	else{
		printf("the two numbers isn't multiplied.");
	}
}
