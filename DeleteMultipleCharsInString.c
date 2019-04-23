#include<stdio.h>
#include<string.h>

// The function for delete a character
int deleteChar(char *p, const char *charOfDelete){

    int countOfDelete = 0;

    // Save chars to bucket with bucketing.
    int Remove[256] = { 0 };
    while(*charOfDelete){
        Remove[*charOfDelete++] = 1;      
    }

    // Initialize p
    char *arrayOfDelete = p;

    while (*p){
        if(!Remove[*p])
            *arrayOfDelete++ = *p;           
        p++;         
    }

    //Count of delete chars assing to a variable for return value.
    countOfDelete = strlen(arrayOfDelete);

    *arrayOfDelete = '\0';
    return countOfDelete;
}

int main(){

    char str[100], str2[10];
  	int deleted = 0;
    
    // Input of arrays
  	printf("\nInput a string:  ");
  	gets(str);
  	
  	printf("\nInput chars for deleting:  ");
  	gets(str2);

    if(strlen(str) < 100 && strlen(str2) < 10) {
        printf("Before to delete: %s\n", str);
        deleted = deleteChar(str, str2); 
        printf("Char to delete: %s\n", str2);
        printf("Count of delete chars = %d\n", deleted);
        printf("Arfter to delete: %s\n", str);
    } else {
        printf("Enter arrays again.\n");
        main();
    }
}
/* Referances 
https://www.youtube.com/watch?v=WZGunxpIwYs
Bucketing: https://softwareengineering.stackexchange.com/questions/144983/what-does-bucket-mean
*/