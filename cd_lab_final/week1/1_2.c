#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char ca,cb;
    FILE *fa,*fb;
    fa=fopen("out.txt","r");
    fb=fopen("out1.txt","w");
    ca=' ';
    while(ca!=EOF){
        ca=getc(fa);
        if(ca=='#'){
            do{
                ca=getc(fa);
            }while(ca!='\n');
            ca=getc(fa);
            putc(ca,fb);
        }
        else if(ca==' '){
            cb=getc(fa);
            if(cb==' '){
                while(ca==' '){
                    ca=getc(fa);
                }
                putc(' ',fb);
                putc(ca,fb);
            }
            else{
                putc(cb,fb);
            putc(ca,fb);
            }
        }
        else
            putc(ca,fb);

    }
    fclose(fa);
    fclose(fb);
}