/*
 ============================================================================
 Name        : Lab1_task2.c
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
	int seconds,sec,min,hr;
	printf("please enter the seconds :");
	scanf("%d",&seconds);
	hr=seconds/3600;
	seconds %=3600;
	min = seconds / 60 ;
	seconds %=60;
	sec = seconds;
	printf("hr=%d,min=%d,sec=%d",hr,min,sec);
}
