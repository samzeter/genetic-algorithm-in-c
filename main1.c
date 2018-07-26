#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

  //seeding the rand() function
    time_t t;
    srand((unsigned) time(&t));

    // list of the available words
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // initialising char pointer array to null
    char *randomString = NULL;

    char *theWord = "cat";

    // to count number of iterations through the algorithm it took to find the word
    unsigned int iter = 0;

    // size of the words being generated
    unsigned char str_len = 3;
	clock_t begin = clock();
    while(1)
      {
	// time the program's search speed

	
	// set memory allocation for the word
	randomString =  malloc((str_len + 1) * sizeof(char));

	// make the word
	for (int k = 0; k < str_len; k++)
	  {
	    int key = rand() % (int)(sizeof(charset) - 1);
	    randomString[k] = charset[key];
	  }

    randomString[str_len] = '\0';

    // print words to terminal
    printf("%s", randomString);
    printf("\n");

    // end of loop - see if formed word equals target word
    if (strcmp(randomString,theWord) == 0){


      free(randomString);
      break;
    }
    free(randomString);
    iter++;
      }
      clock_t end = clock();    
      double time_spent = ((double)(end-begin)) / CLOCKS_PER_SEC;
      printf("Found the cat after %d iterations and %f seconds\n", iter, time_spent);
      printf("Search took %f seconds\n", time_spent);
    return 0;
}
