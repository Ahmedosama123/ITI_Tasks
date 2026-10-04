/*
 ============================================================================
 Name        : Lab1_task5.c
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
	int num;
	printf("please enter a specified number :");
	scanf("%d",&num);
	while(num <=0){
		printf("Please enter a number from 1 : 100 : ");
		scanf("%d",&num);
	}
	for(int i = 1 ; i <= 100 ; i++){
		if(num%i == 0){
			printf("%d ",i);
		}
	}
}
