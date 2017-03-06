#include <stdio.h>
#include <string.h>
int main()
{
   FILE * pFile;
   char mystring [1000];
   pFile = fopen ("test.ini" , "r");
   if (pFile == NULL)
      perror ("Error opening file");
   else
   {
     if ( fgets (mystring , 1000 , pFile) != NULL )//读取一行字符串
       puts (mystring);//输出该字符串
      printf("%d\n", strlen(mystring));
     fclose (pFile);
   }
   return 0;
}
