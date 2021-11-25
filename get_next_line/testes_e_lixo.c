#include <stdio.h>

int ft_strlen(char *str)
{
   int i;

   i = 0;
   while(str[i] != '\0')
      i++;
   return(i);
}

char  *get_next_line(int fd)
{
   FILE *the_file = fopen("the_text_file.txt", "r");
   if(the_file == NULL)
      return(0);
   char *line[BUFFER_SIZE];
   static int i;

   i = 0;
   while(str[i] !='\0')
   {
      line[i] = str[i];
      if (str[i] != '\n')
      {
         i++;
         line[i] = '\n';
         return(line);
      }
      else if (str[i] != '\0')
      {
         i++;
         line[i] = '\0';
         return(line);
      }
      else
         i++;
   }
}


/*to read a text file line by line é preciso chamar o nome do ficheiro, 
e inserir o tipo de modo de leitura, neste programa irei o usar only read "r",
depois tem que se fazer um protect caso nao funcione. Tem que se declarar a 
variavel em que se vao colocar as linhas de texto e dar-lhe um size. fgets é 
o get next line

*/

int main()
{
  FILE *the_file = fopen("the_text_file.txt", "r");
  if(the_file == NULL)
  {
    perror("Unable to open the file");
    exit(1);
  }
  char line[100];
  while(fgets(line, sizeof(line), the_file))
  {
      printf("%s", line);;
  }
  return 0;
}

char *fgets(char *str, int n, FILE *stream);
/*
The C library function char *fgets(char *str, int n, FILE *stream) reads a 
line from the specified stream and stores it into the string pointed to by str.
It stops when either (n-1) characters are read, the newline 
character is read, or the end-of-file is reached, whichever comes first.

Parameters:
--> str − This is the pointer to an array of chars where the string read is stored.

--> n − This is the maximum number of characters to be read (including the final null-character). 
            Usually, the length of the array passed as str is used.

--> stream − This is the pointer to a FILE object that identifies the stream where characters are read from.

Return Value
On success, the function returns the same str parameter. 
If the End-of-File is encountered and no characters have been read, 
the contents of str remain unchanged and a null pointer is returned.

If an error occurs, a null pointer is returned.


########## EXAMPLE ############

#include <stdio.h>

int main () {
   FILE *fp;
   char str[60];

   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      puts(str);
   }
   fclose(fp);
   
   return(0);
}


######## READ FUNCTION #########
https://stackoverflow.com/questions/19769542/reading-from-file-using-read-function



https://pubs.opengroup.org/onlinepubs/000095399/functions/read.html
