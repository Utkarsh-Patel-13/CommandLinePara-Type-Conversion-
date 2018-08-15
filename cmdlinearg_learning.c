//To accept command line arguments and if the input string is a number, then to print it's decimal, binary and hexadecimal equivalent.

#include <stdio.h>
#include <string.h>
#include <math.h>

int char_check(char[]); // A function to check if the input string is a number or not
int to_int(char []); // A function to convert string to equivalent integer number
void to_bin(int); // A function to convert provided integer to binary equivalent

int main(int argc, char *argv[])
{

  int intnum, arr[16], cnt = 0;


  for(int i = 1 ; i < argc ; i++)
  {

    if(char_check(argv[i]))
    {
      int num = to_int(argv[i]);
      
      printf("\n %d ", num );
      printf("\t");
      
      to_bin(num);
      
      printf("\t");
      printf("%04x", num);
      printf("\n");
      cnt ++;
    }

  }
  if(cnt==0)
  {
    printf("\n No numerical characters !! \n" );
  }

  return 0;
}

int char_check(char str[])
{
  int count = 0, len = strlen(str);

  for(int i = 0 ; i < len ; i++)
  {
    if(str[i] >= 48 && str[i] <= 57)
    count++;
  }
  if(count==len)
  return 1;
  else
  return 0;

}

int to_int(char str[])
{
  int num = 0, len = strlen(str);

  for(int i = 0 ; i < len ; i++)
  {
    num += ((str[len - (i + 1)] - '0' ) * pow(10, i));
  }

  return num;
}

void to_bin(int num)
{
  int j, arr[16], i=0;

  for( j = 0 ; j < 16 ; j++)
  arr[j]= 0;

  while(num > 0)
  {
    arr[i] = num%2;
    num = num/2;
    i++;
  }
  for(j = i-1 ; j >= 0 ; j--)
  {
    printf("%d", arr[j] );
  }

}
