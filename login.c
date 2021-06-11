#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int arguments, char *argument[])
{
  if(arguments != 3)
  {
    printf("\nTHOU STRANGER MUST LEAVE!");
    printf("\nHow thou enter : ./(nameoffirstprogram), usename, password");
  }

  char usernameinput[50], passwordinput[50];
  strcpy(usernameinput, argument[1]);
  strcpy(passwordinput, argument[2]);


  FILE *fpr;

  if((fpr = fopen("login.bin", "rb")) == NULL)
  {
    printf("\nfile can't be opened!");
    return EXIT_FAILURE;
  }

  char account[100];
  fread(account, sizeof(char), sizeof(account)/sizeof(char), fpr);

  fclose(fpr);


  char *string[3];
  char username[50], password[50];
  int ctrl = 0;

  string[0] = strtok(account, "@");
  while(string[ctrl++] != NULL)
  {
    string[ctrl] = strtok(NULL, "@");
  }

  strcpy(username, string[0]);
  strcpy(password, string[1]);

  if( (strcmp(usernameinput, username) == 0) && (strcmp(passwordinput, password) == 0) )
  {
    printf("\nCONGRATULATIONS ON THOU REMEMBRENCE ENJOY YOUR STAY!");
  }
  else
  {
    printf("\nTHOU MIGHT HAVE BRAIN DAMAGE!");
  }



  return 0;

} 
