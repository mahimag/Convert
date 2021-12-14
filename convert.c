#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void usage(){
    printf("Usage: ./convert [-x|-b] num1 [num2 num3]");
}

char* itoa(int n, char buf[], int base){
    int rem = 0;
    char temp = 0;
    char* px = buf;
    int i = 0;
    int space = 0;
    while(n>=0){
        if(n==0){
            buf[i] = '\0';
            break;
        }
        if(base == 2 && space == 4){
            buf[i] = ' ';
            space = -1;
        }
        else{
            rem = n%base;
            n = n/base;
            if(rem < 10){
                temp = rem + '0';
            }
            else{
                temp = (rem-10) + 'a';
            }
            buf[i] = temp;
        }
        space++;
        i++;
    }
    return px;
}

int main(int argc, char* argv[]){

    int option, bflag, xflag;

    if(argc < 3){
        usage();
    }
    else{
    /*
    else{
        //0 is the same
        char first = 'x';
        char second = 'b';
        int result = strcmp(*argv, &first);
        int result2 = strcmp(*argv, &second);
        if(result != 0 || result2 != 0){
            usage();
        }
    }
    */
        while((option = getopt(argc, argv, "xb:")) != -1) {
            //option is int that gives x or b
            //printf("opt:%d\n", option); // x is 120, b is 98
            switch(option) { //options - x or b
                case 'x':
                    for(int i=2; i<argc; i++){
                        int result = atoi(argv[i]); //takes char and converts to int
                        printf("%d=", result);
                        if(result == 0){
                            printf("0\n");
                        }
                        else{
                            char cbuf[100];
                            char *px = cbuf;
                            int charCount = 0;

                            px = itoa(result, cbuf, 16);
                            
                            while(*px != '\0'){
                                px++;
                                charCount++;
                            }

                            int countChar = asprintf(&px, "%s", px);
                            
                            printf("0x");
                            for(int i=0; i<charCount; i++){
                                printf("%c", cbuf[charCount - 1 - i]);
                            }
                            printf("\n");
                        }
                        
                    }
                    xflag = 1;
                    break;


                case 'b':
                    for(int i=2; i<argc; i++){

                        int result = atoi(argv[i]);
                        printf("%d=", result);
                        if(result == 0){
                            printf("0\n");
                        }
                        else{
                            char cbuf[100] = {' '}; 
                            char *px = cbuf;

                            px = itoa(result, cbuf, 2);
                            
                            int countChar = asprintf(&px, "%s", px);

                            for(int i=0; i<countChar; i++){
                                printf("%c", cbuf[countChar - 1 - i]);
                            }
                            printf("\n");
                        }
                        
                    }
                    bflag = 1;
                    break;
                default:
                    usage();
            }
        }
        int n = atoi(argv[1]);
        if(n != 0){
            usage();
        }
    }   
}