
#include <stdio.h>
#include <string.h>

int main(){
       char pattern[] = "a";
       char s[]="aa";

       char* token;
       char *ptr = NULL;
       int len = 0, i= 0;

       if (pattern[0] == '*')
               i = 1;

       token  = strtok(pattern+1, "*");
       while (token != NULL) {
               if (token == NULL) continue;
               printf("%s\n", token);
               ptr = strstr(s+len, token);
               if (ptr != NULL){
                       len += strlen(token); len++;
               }
               else{
                       printf("Not found\n");
                       return 1;//exit(1);
               }
               token = strtok(NULL, "*");
       }
       printf("FOUND\n");
	   return 0;

}