#include <stdio.h>
#include <string.h>

#define MAX_BIT     (32)
#define SHIFT_BIT   (4)

// 2進数表示用の関数
void printBI( unsigned int num ){
    char temp[MAX_BIT];
    unsigned int t = 0;

    memset( temp, '0', MAX_BIT );

    for( int i=0 ; i<MAX_BIT ; i++ ){
        t = 1 << i;
        if(num & t){
            temp[MAX_BIT-i-1]='1';
        }
    }

    printf("0b");
    for( int j=0 ; j<MAX_BIT ; j++){
        printf("%c", temp[j]);
    }
    printf("\n");
    printf("0x%016X\n",num);
}

int main(void){

    printf("Enter decimal value(max %d bit)\n",MAX_BIT);
    unsigned int in_decimal=0;

    printf("input value:");
    scanf("%ud", &in_decimal);
    if( 0x100000000 <= in_decimal ){
        printf("over max value\n");
        return -1;
    }

    printBI( in_decimal );
    printf("\n");

    int j=0;
    while( j < SHIFT_BIT ){
        j++;
        printf("%dbit right shift\n",j);
        printBI( (in_decimal >> j));
        printf("\n");
        printf("%dbit left shift\n",j);
        printBI( (in_decimal << j));
        printf("\n");

    }

    return 0;
}



