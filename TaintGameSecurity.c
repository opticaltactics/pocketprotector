/*
  Game Password Demo Program
  A Sample c coded program to demonstrate reading a user command line 
  entered paswword and verifying the validity. 
  Feb 13, 2022
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE  -1

// Define subroutine used.
int ReadUserPassword (char *password);
void remove_char_from_string (char c, char *str);
void DecryptString (char *Encryp, char *DecryptedString);

int
main (int argc, char *argv[])
{
  int i;
  int strsize = 0;
  int PasswordStatus = 0;
  char *cmdstring;
  char PasswordString[512];

  // Check for correct entry.
  if (argc < 1)
    return 0;

//Make room for user entered password  
  cmdstring = malloc (strsize);
  cmdstring[0] = '\0';

// Retrive user passer word from command line.
  for (i = 1; i < argc; i++)
    {
      strcat (cmdstring, argv[i]);
      if (argc > i + 1)
	strcat (cmdstring, " ");
    }

  strcpy (PasswordString, cmdstring);

  // All Enter commands have a carrage return code.
  remove_char_from_string ('\n', PasswordString);

  PasswordStatus = ReadUserPassword (PasswordString);

  if (PasswordStatus == TRUE)
    {
      printf ("\n\n");
      fprintf (stderr, "*************************************\n");
      fprintf (stderr, "*************************************\n");
      fprintf (stderr, "****   THE PASSWORD IS CORRECT   ****\n");
      fprintf (stderr, "****        ENJOY THE GAME       ****\n");
      fprintf (stderr, "*************************************\n");
      fprintf (stderr, "*************************************\n");
      printf ("\n\n");
    }
  else
    {
      printf ("\n\n");
      fprintf (stderr, "***************************************\n");
      fprintf (stderr, "***************************************\n");
      fprintf (stderr, "***************************************\n");
      fprintf (stderr, "****   THE PASSWORD IS INCORRECT   ****\n");
      fprintf (stderr, "****       PLEASE TRY AGAIN        ****\n");
      fprintf (stderr, "***************************************\n");
      fprintf (stderr, "***************************************\n");
      fprintf (stderr, "***************************************\n");
      printf ("\n\n");
    }

  return 0;
}



int
ReadUserPassword (char *PasswordString)
{
  FILE *fin;
  int STRLEN;
  int PasswordCompare;
  int PasswordStatus = 0;
  char DecryptedString[512];
  char SecurePasswd[512];

// Open the Encrypted password file for reading.  
  fin = fopen ("PasswordFile.dat", "r");
  if (fin == NULL)
    {
      printf ("*************************************\n");
      printf ("      cannot open GamePasswordFile\n");
      printf ("*************************************\n");
      return (FALSE);
    }

// Read the Encrypted password from file;
// Compare Encrypted password to the user entered password.
// Read up to 256 characters.
  while (fgets (SecurePasswd, 256, fin) != NULL)
    {
      STRLEN = strlen (SecurePasswd);

      printf ("==>> Encrypted %s <<==\n", SecurePasswd);
      remove_char_from_string ('\n', SecurePasswd);

      DecryptString (SecurePasswd, DecryptedString);

      PasswordCompare = strncmp (PasswordString, SecurePasswd, STRLEN);

      if (PasswordCompare == 0)
	{
	  fclose (fin);
	  return (TRUE);
	}
      else
	{
	  fclose (fin);
	  return (FALSE);
	}
    }

}

void
remove_char_from_string (char c, char *str)
{
  int i = 0;
  int len = strlen (str) + 1;

  for (i = 0; i < len; i++)
    {
      if (str[i] == c)
	{
	  // Move all the char following the char "c" by one to the left.
	  strncpy (&str[i], &str[i + 1], len - i);
	}
    }
}


void
DecryptString (char *Encrypted, char *DecryptedPassword)
{
  int i, x;
  char str[100];

  for (i = 0; (i < 100 && Encrypted[i] != '\0'); i++)
    Encrypted[i] = Encrypted[i] - 3;	//the key for encryption is 3 that is subtracted to ASCII value

  printf ("\n++++ Decrypted Password: %s\n", Encrypted);

  strcpy (DecryptedPassword, Encrypted);
}
