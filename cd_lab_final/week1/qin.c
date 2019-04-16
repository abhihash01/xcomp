//c program for removal of space and tab and preprocessor in a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE *fa,*fb;
	int ca,cb;
    fa=fopen("qin.c","r");
    fb=fopen("qout.c","w");
    if(fa==NULL){
    	printf("\n the file that you requested for does not exist");
    	exit(0);
    }
    else{
             ca=getc(fa);
             while(ca!=EOF){
            
                if(ca=='#'){
                
                        do{
                            ca=getc(fa);
                        }while(ca!='\n');
                        ca=getc(fa);
            
                    
                }
                else if(ca==' '){
                    cb=getc(fa);
                    if(cb==' '){
                      do{
                        ca=getc(fa);
                        }while(ca!=' ');
                   }
                }

                putc(ca,fb);
                ca=getc(fa);
             }
    }
}
