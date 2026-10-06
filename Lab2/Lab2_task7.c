#include "stdio.h"
#include "stdlib.h"
int main(){
    char c;
    printf("enter the alphabet: ");
    scanf("%c",&c);
    if(c == 'a'|| c == 'A'|| c == 'e'|| c == 'E'|| c == 'I'|| c == 'i'|| c == 'Y'|| c == 'y'|| c == 'O'|| c == 'o'){
        printf("vowel");
    }
    else{
        printf("consonant");
    }
}