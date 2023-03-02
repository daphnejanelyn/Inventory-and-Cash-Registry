/*****************************************
This is to certify that this project 
is my own work, based on my personal
efforts in studying and applying the
concepts learned. I have constructed
the functions and their respective 
algorithms and corresponding code 
by myself. The program was run, 
tested, and debugged by my own efforts.
I further certify that I have not 
copied in part or whole or otherwise 
plagiarized the work of other students
and/or persons.
Daphne Janelyn L. Go, DLSU ID# 12131210
*****************************************/
/*
  Description: This program performs a 
  set of user-responsive 
  processes similar to a
  a pizza-vending machine. 
  Programmed by: Daphne Janelyn L. Go
                 S21
  Last modified: January 30, 2022
  Version: 9
*/

 /* Preprocessor directives */
 
#include <stdio.h>
#include <time.h>

/* Function Prototypes */

void displaywelcome ();
void displayline ();
void displayAmount (float *);
void displaymenu (int);

int choosecrust ();
int checkCrust (int);

char choosesize ();
int checkSize (char);
float getprice (float *, char); 

void displaytop (char);
int choosetop (int *, 
               int *,
               int *, 
               int *, 
               int *,
               char );
int getcheesetype (int,
                   int *,
                   int *, 
                   int *,
                   int *); 
int checkTopping (char);
int checkCheese (char);

float gettopprice (float, char);
float gettotaltoppings (float *, 
                        int, 
                        int, 
                        int, 
                        int,
                        int, 
                        char);
				  
char choosestuff ();
int checkStuff (char);
float getstuffingprice (float *, char);

float getbills (float);
int checkPay (int); 

void displaychange (float, int *);
void displayif (int, float);

void displayreceipt (int, 
                     char, 
                     int, 
                     int, 
                     int, 
                     int, 
                     int, 
                     int, 
                     int,
                     int, 
                     int, 
                     int,
                     char, 
                     float, 
                     float, 
                     float);
int countnum (int);
void displayspace (int,
                   int); 

int calculatetime (int, 
                   int,
                   int,
                   int, 
                   int, 
                   char);

void displaytimer (int, 
                   int, 
                   int, 
                   int, 
                   int,
                   char); 
void displaytime ();

void updatevariables (int,
                      int,
                      int,
                      int,
                      int,
                      int,
                      int,
                      int,
                      int,
                      char, 
                      int *,
                      int *,					  
                      int *,
                      int *);
void generatereport (int *,
                     int *,
                     int *, 
                     int *, 
                     int *,
                     int, 
                     float); 
/* function implementation */

int
main ()
{
  /* variable declarations */
  
  char csize, cstuff;
  int ncrust, ntopping, nctype;
  float fpayment, fchange; 	
  float fAmount = 0; 
	
  int ncheese = 0;
  int nham = 0;
  int npapple = 0; 
  int nsausage = 0;
  int nolives = 0;
 
  
  int nMoz = 0;
  int nFon = 0;
  int nGorg = 0;
  int nPar = 0;
  
  int ncrusttotal[2] = {0};
  int ntoptotal[4] = {0};
  int ncheesetotal[4] = {0};
  int nstufftotal[2] = {0};
  int nbilltotal[12] = {0};
	
  int nStep;  
  int ntransact = 0;
  float fbalance = 0; 
	
  /* 
     The number in the loop 
     corresponds to the 
	 respective step in the 
	 vending machine. 
  */
	 
  for (nStep = 1; nStep <= 7; nStep++)
  {
    if (nStep == 1)
    {
      displayline (); 
      printf ("\n");
	  
	  /* welcome statement */
	  
      displaywelcome(); 
      displayline(); 
	  
      /* 
	     allow user to choose 
	     crust type 
	  */
	  
	  ncrust = choosecrust();
	  displayline();
	      
	  if (checkCrust (ncrust) == 2)
	  {
		/* code for maintenance */
		
	    printf("\nTerminating");
		printf(" machine...\n");
		printf("Machine Under");
		printf(" Maintenance\n");
		
		generatereport (ncrusttotal,
                        ntoptotal,
                        ncheesetotal,
                        nstufftotal,
                        nbilltotal, 
                        ntransact,
                        fbalance);
        ntransact = 0;				
        ncrusttotal[2] = 0;
        ntoptotal[4] = 0;
        ncheesetotal[4] = 0;
        nstufftotal[2] = 0;
        nbilltotal[12] = 0; 
		
        nStep += 7;  
	  }
	      
	}
		
	else if (nStep == 2)
	{
	  /* 
	     allow user to choose 
	     pizza size 
	  */
	  
	  csize = choosesize ();
	  
	  if (checkSize (csize) == 1)
	  {
		/* get current amount */
		getprice (&fAmount, csize);
		
        /* Note for the user */	
	    printf("Has tomato sauce and");
        printf(" mozzarella cheese\n");
		
		/* display current amount */
		displayAmount(&fAmount); 
        displayline();
	  }
	  
	  /*
        user input is X or x
        : cancel order 
      */
	  
	  else if (checkSize (csize) == 2)
	  {
	    printf ("\nCancelling order");
        printf ("...\n");
		/* initializing to 0 */
        fAmount = 0;
        cstuff = '\0';
        ncheese = 0;
        nham = 0;
        npapple = 0; 
        nsausage = 0;
        nolives = 0;
	
        nMoz = 0;
        nFon = 0;
        nGorg = 0;
        nPar = 0;
	    nStep -= 2; 
	  }
	}
		
	else if (nStep == 3)
	{
	  /* 
	    allow user to choose 
	    pizza topping 
	  */
	  
	  ntopping = choosetop(&ncheese,
                           &nham,
                           &npapple, 
                           &nsausage,
                           &nolives,
                           csize);	  
	  if (ntopping == 1)
	  {
		if (ncheese > 0)
		{
		 /* 
	       allow user to choose 
	       cheese type 
	     */
		 
		  nctype = getcheesetype(ncheese, 
		                         &nMoz,
                                 &nGorg, 
                                 &nFon,
                                 &nPar);
		  /* 
		    conditions based on
			cheese type
		  */
		  
          if (nctype == 1)
		  {
		    gettotaltoppings (&fAmount,
                              nham,
                              npapple,
                              nsausage,
                              ncheese, 
                              nolives,
                             csize); 
	  		displayAmount (&fAmount);
	        displayline();
		  }
		  
		 /*
     	   user input is X or x
           : cancel order 
         */
		 
		  else if (nctype == 2)
		  {
	        printf ("\nCancelling ");
			printf ("order...\n");
			/* initializing to 0 */
            fAmount = 0;
            cstuff = '\0';
            ncheese = 0;
            nham = 0;
            npapple = 0; 
            nsausage = 0;
            nolives = 0;
	
            nMoz = 0;
            nFon = 0;
            nGorg = 0;
            nPar = 0;
	        nStep -= 3; 
	      }
		}
		
		/* 
		   if the user did not
		   choose cheese as
		   a topping, output
		   the amount based
		   on the chosen toppings
		 */
		 
		else if (ncheese == 0)
		{
		  gettotaltoppings (&fAmount, 
                            nham,
                            npapple,
                            nsausage,
                            ncheese, 
                            nolives,
                            csize); 
	  	  displayAmount (&fAmount);
	      displayline();
		}
	  }
	  
      /*
     	user input is X or x
        : cancel order 
      */
	  
      else if (ntopping == 2)
	  {
	    printf("\nCancelling order");
		printf ("...\n");
		/* initializing to 0 */
        fAmount = 0;
        cstuff = '\0';
        ncheese = 0;
        nham = 0;
        npapple = 0; 
        nsausage = 0;
        nolives = 0;
	
        nMoz = 0;
        nFon = 0;
        nGorg = 0;
        nPar = 0;
	    nStep -= 3; 
	  }
	     
		  
    }	  
		
	else if (nStep == 4)
	{
	  if (ncrust == 2)
	  {
		/* 
		  allow user to choose
		  stuffing type if crust
		  is thick crust 
		*/
		
		cstuff = choosestuff (ncrust); 
			  
		if (checkStuff (cstuff) == 1)
		{
		  getstuffingprice (&fAmount,
		                    cstuff);
	      displayAmount (&fAmount);
	      displayline();  
		}
		
		/*
     	  user input is X or x
          : cancel order 
        */
		
		else if(checkStuff(cstuff)== 2)
		{
	      printf("\nCancelling order");
	      printf ("...\n");
		  
		  /* initializing to 0 */
          fAmount = 0;
          cstuff = '\0';
          ncheese = 0;
          nham = 0;
          npapple = 0; 
          nsausage = 0;
          nolives = 0;
	
          nMoz = 0;
          nFon = 0;
          nGorg = 0;
          nPar = 0;
		  nStep -= 4; 
	    }
	  }
	}
		
	else if (nStep == 5)
	{
	  /*
	    allow user to 
		insert payment 
	  */
	  
	  fpayment = getbills (fAmount);
		  
	  if (fpayment > 0)
	  {
		fchange = fpayment - fAmount; 
		displaychange (fchange, 
		               nbilltotal); 
		
		/* 
		  increment transaction
		  number
		*/
		ntransact += 1; 
		
		/* update cash balance */
	    fbalance += fAmount;
	  }
	  
	  /*
     	user input is X or x
        : cancel order 
      */
	  
	  else if (fpayment == 0)
	  {
	    printf ("\nCancelling order");
		printf ("...\n");
		
		/* initializing to 0 */
        fAmount = 0;
        cstuff = '\0';
        ncheese = 0;
        nham = 0;
        npapple = 0; 
        nsausage = 0;
        nolives = 0;
	
        nMoz = 0;
        nFon = 0;
        nGorg = 0;
        nPar = 0;
	    nStep -= 5; 
	  }
	}
	  
	else if (nStep == 6)
	{
	  displayline();
	  
	  /* display receipt */
	  displayreceipt(ncrust, 
                     csize, 
                     ncheese,
                     nham, 
                     npapple, 
                     nsausage, 
                     nolives, 
                     nMoz, 
                     nFon, 
                     nGorg, 
                     nPar, 
                     ntransact,
                     cstuff, 
                     fAmount, 
                     fpayment,
                     fchange);
					 
	 updatevariables(ncrust,
	                 nham,
                     npapple,
                     nsausage,
                     nolives,
                     nMoz,
                     nGorg,
                     nFon,
                     nPar, 
                     cstuff, 
                     ncrusttotal,
                     ntoptotal,
                     ncheesetotal,
                     nstufftotal);
                					 
	}
	 
	else if (nStep == 7)
	{
      displayline();
	  printf ("\nPlease wait ");
	  printf ("for your order...\n");
	  
	  /* display countdown timer */
	  displaytimer(nham, npapple, 
	               ncheese, nsausage,
                   nolives, cstuff);
				   
	  printf ("\nOrder is now ready.");
	  printf ("\nThank you!\n");
	  
	  /* 
	     initializing all count 
	     variables back to 0 
	  */
	  
	  fAmount = 0;
      cstuff = '\0';
	  
	  ncheese = 0;
      nham = 0;
      npapple = 0; 
      nsausage = 0;
      nolives = 0;
	
      nMoz = 0;
      nFon = 0;
      nGorg = 0;
      nPar = 0;
	  
      nStep -= 7; 
	}
	  		
   }  
	
	return 0; 
	
}

/* This function displays 
   the welcoming message 
   (date, time and machine name)
   of the vending machine.
*/ 

void 
displaywelcome ()
{
  printf("Current Date & Time:\n"); 
  displaytime ();
  printf("Welcome to ");
  printf("AuthenticPizza!\n");
}


/* This function displays 
   a dashed-line divider.
*/

void 
displayline ()
{
  int nCount;
	
  for (nCount = 1; nCount <= 40; nCount++)
	printf("-"); 
}


/* This function displays the 
   current amount per section to 
   be paid by the user.
   
   Precondition: pAmount is the
                 address of a 
                 float value

   @param pAmount is the address where 
   the current amount will be stored

*/

void
displayAmount (float *pAmount)
{
  printf ("Current Amount:");
  printf ("%.2f\n", *pAmount);
}

/* This function displays the 
   user options per section.
   
   Precondition: nNum is an
   integer value.

   @param nNum refers to
   the case number in which 
   the program wants to display.

*/

void
displaymenu (int nNum)
{
  switch (nNum)
  {
	/* Display type of crust options */
	
	case 1: printf("\nCrust Type\n");
	        printf("Thin Crust [1]\n");
            printf("Thick Crust [2]\n");
            break;
			
	/* Display pizza size options */
	
	case 2: printf("\nPizza Sizes\n");
	        printf("Small [S] - ");
            printf("100\n");
            printf("Medium [M] - ");
            printf("175\n");
            printf("Large [L] - ");
            printf("225\n");
            printf("Cancel [X]\n");
            break;
	
	/* Display cheese type options */
	
	case 3: printf("\nCheese Type\n");
	        printf("Mozzarella [M]\n");
            printf("Gorgonzola [G]\n");
            printf("Fontina [F]\n");
            printf("Parmesan [P]\n");
            printf("Cancel [X]\n");
            break;
	
	/* Display stuffing type options */
	
	case 4: printf("\nStuffing Type\n");
	        printf("Cheese [C]\n");
            printf("Spam [S]\n");
            printf("Both [B]\n");
            printf("None [N]\n");
            printf("Cancel [X]\n");
            break; 
	
    /* Display payment options */
	
	case 5: printf("\nAccepted Bills");
	        printf(" or Coins\n");
            printf("1000 [1]\n");
            printf("500 [2]\n");
            printf("100 [3]\n");
            printf("50 [4]\n");
            printf("20 [5]\n");
            printf("10 [6]\n");
            printf("5 [7]\n");
            printf("1 [8]\n");
            printf("0.25 [9]\n");
            printf("0.10 [10]\n");
            printf("0.05 [11]\n");
            printf("0.01 [12]\n");
            printf("Cancel [0]\n");
            break;
  }
}

/* This function allows the user to 
   choose the preferred crust type. 


   @return 1 if the user chose 
           thin crust
           2 if the user chose 
		   thick crust
           80808 if the program
           is being terminated
*/

int
choosecrust ()
{
  int ncrust;
  
  /*Display options*/ 
  
  displaymenu (1);
  displayline ();

  /* User input */
  
  printf("\nChoose Type of Crust:");
  scanf("%d", &ncrust);
  
  /* 
     Ask for user input until
     input is valid  
  */
  
  while(checkCrust (ncrust) == 0)
  {
    printf("Invalid input!\n");
    printf("Choose Type of Crust:");
    scanf("%d", &ncrust);
  }
  
  return ncrust; 
  
}


/* This function checks if
   the user input for crust type
   is valid. 

   Precondition: Crust type is an 
   integer value.

   @param ncrust is the chosen 
   crust type by the user

   @return 1 if the user inputted 
           a valid input (1 or 2)
		
           2 if the user inputted 
           a terminating value (80808)
		
           0 if the user inputted 
           an invalid input
   
*/

int 
checkCrust (int ncrust)
{
  if (ncrust == 1 || ncrust == 2)
	  return 1;
  else if (ncrust == 80808)
	  return 2;
  else 
	  return 0; 
}

/* This function allows the
   user to choose the preferred
   pizza size (Small, Medium or
   Large).
   
   @return S or s if the user 
           chose Small
           M or m if the user 
		   chose Medium
           L or l if the user 
           chose Large
*/

char
choosesize ()
{
  char csize; 
  
  /* Display Options */
  
  displaymenu (2);
  displayline ();
  
  /* User input */
  
  printf("\nChoose Size: ");
  scanf(" %c", &csize);
  
  /* 
     Ask for user input until
     input is valid  
  */
  
  while (checkSize (csize) == 0)
  {
	printf("Invalid input!\n");
	printf("Choose Size: ");
    scanf(" %c", &csize);
  }
  
  return csize; 
  
}
/* This function checks if
   the user input for pizza size
   is valid. 

   Precondition: pizza size is a
   character value.

   @param csize is the chosen 
   pizza size by the user

   @return 1 if the user inputted
           a valid input
		   
           2 if the user inputted
           a value to cancel 
           the order
		   
           0 if the user inputted 
           an invalid input
   
*/

int 
checkSize (char csize)
{
  if (csize == 'S' ||
      csize == 's' ||
      csize == 'M' ||
      csize == 'm' ||
      csize == 'L' ||
      csize == 'l')
	return 1;
	
  else if (csize == 'X' ||
           csize == 'x')
	return 2;
	
  else
	return 0;
}

/* This function obtains the current
   amount based on the pizza size.

   Precondition: csize is a valid input
                 for pizza size. 
   
   @param pAmount is the address where
          the current amount will 
		  be stored

   @param csize is the chosen
          pizza size by the user

   @return the amount based on size

*/
 
float
getprice (float *pAmount, char csize)
{
  /* 
     Varying prices based 
     on pizza size
  */	
  if (csize == 'S' 
      || csize == 's')
    *pAmount = 100; 

  else if (csize == 'M' 
           || csize == 'm')
	*pAmount = 175;

  else
	*pAmount = 225;

  return *pAmount; 
}

/* This function displays
   the possible topping 
   options and its price 
   based on size. 

   Precondition: csize is a valid input
                 for pizza size. 

   @param csize is the chosen
          pizza size by the user

*/

void 
displaytop (char csize)
{
  float fham, fpapple, fcheese,
	    fsausage, folives;
	
  printf("\nTopping Options\n");	
	
  /* display ham menu */	
	
  printf("Ham [H] - "); 
  fham = gettopprice (10, csize);
  printf("%.2f\n",fham);
	
  /* display pineapple menu */
	
  printf("Pineapple [P] - ");
  fpapple = gettopprice (6, csize);
  printf("%.2f\n", fpapple);
	
  /* display cheese menu */
	
  printf("Cheese [C] - ");
  fcheese = gettopprice (12, csize);
  printf("%.2f\n", fcheese);
	
  /* display sausage menu */
	
  printf("Sausage [S] - ");
  fsausage = gettopprice (15, csize);
  printf("%.2f\n", fsausage);
	
  /* display olives menu */
	
  printf("Olives [O] - ");
  folives = gettopprice (10, csize);
  printf("%.2f\n", folives);
  
  printf("Stop Choosing [N]\n");
  printf("Cancel [X]\n");
  displayline ();
	
}

/* This function allows the user
   to choose the pizza topping. 

   Precondition: all values stored into
   the parameters are to be 
   non-negative integers only

   @param pcheese is the address where
   the number of times cheese is 
   chosen is stored.
   
   @param pham is the address where
   the number of times ham is chosen
   is stored.
   
   @param ppapple is the address 
   where the number of times pineapple 
   is chosen is stored.
   
   @param psausage is the address where
   the number of times sausage is 
   chosen is stored.
   
   @param polives is the address where
   the number of times olives is chosen
   is stored.
   
   @param csize is the chosen pizza
   size by the user.
   
   @return 2 if the user cancels the 
             order
           1 if the user inputs any 
		   other value
*/

int
choosetop (int *pcheese, 
           int *pham,
           int *ppapple, 
           int *psausage, 
           int *polives,
           char csize)
{
  char ctop;
  int ncount = 1;
  int ncountham  = 0;
  int ncountpapple = 0; 
  int ncountsausage = 0;
  int ncountcheese = 0;
  int ncountolives = 0;
  
  displaytop (csize);
  printf("\n");
 
  do 
  {
	/* User input */
	
      printf("Choose toppings:");
      scanf(" %c", &ctop);
	  
	/* 
	   Ask user for a valid
	   topping input at least once
	   if user chooses stop choosing
	*/
	
	if ((checkTopping (ctop) == 3 
	     || checkTopping (ctop) == 0)
	    && ncount == 1)
	{
	  while (checkTopping (ctop) == 3
	        || checkTopping (ctop) == 0)
	  {
	    if (checkTopping (ctop) == 3)
		{
          printf("Please choose at ");
          printf ("least one topping"); 
		  printf("\nChoose toppings:");
          scanf(" %c", &ctop);
		}
		else if(checkTopping(ctop) == 0)
		{
	        printf("Invalid input!\n");
            printf("Choose toppings:");
            scanf(" %c", &ctop);
		}
	  }
       ncount = 1; 
	}
	
	else if (checkTopping (ctop) == 3 
	         && ncount != 1)
	{
	  /* 
	     decrement topping count 
	     to zero once user wants
		 to stop choosing 
	  */
	  ncount = 0;
	}

	/* 
	   Ask user for input
	   until the input is valid 
	*/
	
    while (checkTopping (ctop) == 0)
    {
	  printf("Invalid input!\n");
      ncount = 1; 
      printf("Choose toppings:");
      scanf(" %c", &ctop); 
    }
    
	/* Count how many times 
	each topping was chosen */
	
	if (ctop == 'H' || 
	    ctop == 'h')
	{
	  ncountham++;
	  *pham = ncountham;
	}
	
	else if (ctop == 'P' ||
	         ctop == 'p')
	{
	  ncountpapple++;
	  *ppapple = ncountpapple;
	}
	
	else if (ctop == 'S' ||
	         ctop == 's')
	{
	  ncountsausage++;
	  *psausage = ncountsausage;
	}
	
	else if (ctop == 'C' ||
	         ctop == 'c')
	{
	  ncountcheese++;
	  *pcheese = ncountcheese;
	}
	else if (ctop == 'O' ||
	         ctop == 'o')
	{
	  ncountolives++;
	  *polives = ncountolives;
	}
	
	 
	/* increment topping count
	   once user has chosen at 
	   least once 
	*/
	
    ncount++;
	
   } while(checkTopping(ctop) == 1
           && ncount > 0);
   
  /* 
     returns a value of 2
     if cancels order 
  */ 
	
  if (checkTopping (ctop) == 2)
	return 2;

  else
	return 1; 
}



/* This function allows the user to
   choose the preferred cheese type.
   
   Precondition: all values stored into
   the parameters are to be 
   non-negative integers only
   
   @param ncheese is the number 
   of times cheese was chosen 
   as a topping
   
   @param pMoz is the address in which
   the number of times Mozzarella is 
   chosen is stored
   
   @param pGorg is the address in which
   the number of times Gorgonzola is 
   chosen is stored
   
   @param pFon is the address in which
   the number of times Fontina is 
   chosen is stored
   
   @param pPar is the address in which
   the number of times Parmesan is 
   chosen is stored
   
   @return 2 if the user cancels
           the order
		   
		   1 if the user inputs
		   any other value
		   
		   3 if the amount of times
		   cheese was chosen is 0
		   
		   
*/

int  
getcheesetype (int ncheese, 
               int *pMoz,
               int *pGorg, 
               int *pFon,
               int *pPar)
{
  int i;
  char ccheese;
  int ncountMoz = 0;
  int ncountGorg = 0;
  int ncountFon = 0;
  int ncountPar = 0;
    	
  if (ncheese != 0)
  {
	/* display options */
	
    displaymenu (3);
	displayline ();
	printf ("\n");
	
	/* 
	  loops in the same number of times
      as the cheese topping count
	*/
	for (i = 1; i <= ncheese; i++)
	{
	  /* Get user input */
	  printf("Choose cheese type:");
      scanf(" %c", &ccheese);
	  
	  /* 
	    Ask for user input until 
		the input is valid
	  */
	  
	  while(checkCheese(ccheese) == 0)
	  {
		printf("Invalid Input!\n"); 
		printf("Choose cheese type:");
		scanf(" %c", &ccheese);
	  }
	  
	  /* 
	    Count number of times per type 
		of cheese was chosen 
	  */
		
	  if (ccheese == 'M' || 
	      ccheese == 'm')
	  {
		ncountMoz++;
		*pMoz = ncountMoz;
	  }
	  
	  else if (ccheese == 'G' || 
	           ccheese == 'g')
	  {
		ncountGorg++;
		*pGorg = ncountGorg;
	  }
	  
	  else if (ccheese == 'F' || 
	           ccheese == 'f')
	  {
		ncountFon++;
		*pFon = ncountFon;
	  }
	  
	  else if (ccheese == 'P' || 
	           ccheese == 'p')
	  {
		ncountPar++;
		*pPar = ncountPar;
	  }
	 
	}
	
    /* 
	  returns a value of 2 if the user 
	  cancels the order 
	*/
	  
	 if (checkCheese (ccheese) == 2)
		return 2; 
	 else
	    return 1; 		
  }
  
  /* 
     returns a value of 3
     if cheese topping count is 0
  */
  else 
	  return 3;
}

/* This function checks if
   the user input for topping
   is valid. 

   Precondition: topping is a
   character value.

   @param ctopping is the chosen 
   pizza topping by the user

   @return 1 if the user inputted
           a valid input
		   
           2 if the user inputted
           a value to cancel 
           the order
		   
           3 if the user is done 
           choosing his toppings
		   
           0 if the user inputted 
           an invalid input
*/

int 
checkTopping (char ctopping)
{
  if (ctopping == 'H' ||
      ctopping == 'h' ||
      ctopping == 'p' ||
      ctopping == 'P' ||
      ctopping == 'S' ||
      ctopping == 's' ||
      ctopping == 'C' ||
      ctopping == 'c' ||
      ctopping == 'O' ||
      ctopping == 'o')
	return 1;
	
  else if (ctopping == 'X' ||
           ctopping == 'x')
	return 2;
	
  else if (ctopping == 'N' ||
           ctopping == 'n')
	return 3; 
	
  else
	return 0;
}

/* This function checks if
   the user input for cheese
   type is valid. 

   Precondition: cheese type is a
   character value.

   @param ccheese is the chosen 
   cheese type by the user

   @return 1 if the user inputted
           a valid input
		    
           2 if the user inputted
           a value to cancel 
           the order
		   
           0 if the user inputted 
           an invalid input
*/

int 
checkCheese (char ccheese)
{
	if (ccheese == 'M' ||
        ccheese == 'm' ||
        ccheese == 'G' ||
        ccheese == 'g' ||
        ccheese == 'F' ||
        ccheese == 'f' ||
        ccheese == 'P' ||
        ccheese == 'p')
	  return 1;
	  
	else if (ccheese == 'X' ||
	         ccheese == 'x')
	  return 2;
	  
	else
	  return 0; 
}

/* The function gets the increased  
   topping price based on the size.
   
   Precondition: fprice is a 
   nonnegative float value; 
   csize is a character value
   
   @param fprice is the topping price
   regardless of pizza size
   
   @param csize is the pizza size 
   chosen by the user. 
   
   @return the modified amount
           based on the pizza size
*/

float 
gettopprice (float fprice, 
             char csize)
{ 
 /* an increase in topping 
    price based on pizza size
 */
  if (csize == 'M' 
      || csize == 'm')
	fprice *= 1.5; 
	
  else if (csize == 'L' 
           || csize == 'l')
    fprice *= 1.75; 

  else 
  	fprice *= 1.0; 
	
  return fprice; 
	
}

/* The function gets the total 
   topping price based on the size 
   and the number of times each
   topping was chosen. 
   
   Precondition: pAmount is the
   address of a float value 
   of the updated amount(>0).
   The topping count paramaters are 
   non-negative integer values.
   The csize is a character value. 
   
   @param pAmount is the address where 
   the current amount will be stored.
   
   @param nham is the number of times
   ham was chosen as a topping.
   
   @param npapple is the number of 
   times pineapple was chosen as
   a topping.
   
   @param nsausage is the number of 
   times sausage was chosen as 
   a topping.
   
   @param ncheese is the number of 
   times cheese was chosen as 
   a topping.
   
   @param nolives is the number of 
   times olives was chosen as 
   a topping.
   
   @param csize is the pizza size
   chosen by the user. 
   
   @return the current amount
*/

float 
gettotaltoppings (float *pAmount, 
                  int nham,
                  int npapple, 
                  int nsausage,
                  int ncheese, 
                  int nolives,
                  char csize)
{
  /* 
     multiply the modified topping 
     price with the number of times
     the corresponding topping was
     chosen	 
  */
  if (nham > 0)
    *pAmount += (gettopprice(10, csize) 
                 * nham);

  if (npapple > 0)
    *pAmount += (gettopprice(6, csize) 
                 * npapple);
 
  if (nsausage > 0)
    *pAmount += (gettopprice(15, csize) 
                 * nsausage);
 
  if (ncheese > 0)
	*pAmount += (gettopprice(12, csize) 
                 * ncheese);
  
  if (nolives > 0)
	*pAmount += (gettopprice(10, csize)
                 * nolives);
  
  return *pAmount; 
}

/* The function allows the user to 
   choose a stuffing type. 
 
   @return the character value of
           the chosen stuffing 
*/

char 
choosestuff ()
{
  char cstuffing; 
  
  /* Display options */
  
  displaymenu (4);
  displayline ();
  
  /* Get user input */
  
  printf("\nChoose type of stuffing: ");
  scanf(" %c", &cstuffing);
 
  /* 
     Ask for user input until
     the input is valid
  */
  
  while (checkStuff (cstuffing) == 0)
  {
	printf("Invalid Input!\n");
	printf("Choose stuffing type: ");
	scanf(" %c", &cstuffing);
  }
  
  return cstuffing;
}

/* This function checks if
   the user input for stuffing
   type is valid. 

   Precondition: stuffing type is a
   character value.

   @param cstuffingtype is the chosen 
   crust stuffing by the user

   @return 1 if the user inputted
           a valid input
		   
           2 if the user inputted
           a value to cancel 
           the order
		   
           0 if the user inputted 
           an invalid input
*/

int
checkStuff (char cstuffingtype)
{
  if (cstuffingtype == 'C' ||
      cstuffingtype == 'c' ||
      cstuffingtype == 'S' ||
      cstuffingtype == 's' ||
      cstuffingtype == 'B' ||
      cstuffingtype == 'b' ||
      cstuffingtype == 'N' ||
      cstuffingtype == 'n')
	return 1;
	  
  else if (cstuffingtype == 'X' ||
           cstuffingtype == 'x')
	return 2;
	  
  else
	return 0; 		
}

/* The function updates the
   current amount based on the
   chosen stuffing type. 
   
   Precondition: pAmount is a float 
   value of the updated amount(>0).
   cstuffingtype is a character value.
   
   @param pAmount is the address where 
   the current amount will be stored.
   
   @param cstuffingtype is the type of 
   stuffing chosen by the user. 
   
   @return the current amount
*/

float
getstuffingprice (float *pAmount, 
                  char cstuffingtype)
{
 /* 
    add to the current amount 
    the price for the stuffing
 */	
  if (cstuffingtype == 'C' ||
      cstuffingtype == 'c')
	*pAmount += 30;
	
  else if (cstuffingtype == 'S' ||
           cstuffingtype == 's')
	*pAmount += 25; 
	
  else if (cstuffingtype == 'B' ||
           cstuffingtype == 'b')
	*pAmount += 35;
	
  return *pAmount; 
}

/* This function allows the user
   to insert his payment through
   numbers corresponding to a 
   certain bill/amount.
   
   Precondition: the total payable
   amount of the order is a float
   value in 2 decimal places.
   
   @param fAmount is the total 
   payable amount of the user. 
   
   @return the amount of money 
           inputted by the user
*/

float
getbills (float fAmount)
{
  int nPay;
  float fValue = 0;
  
  /* print selection of money */
  
  displaymenu (5);
  displayline ();
  printf("\n");
  
  /* 
    keep asking for payment input until 
	payment inserted is greater than
	or equal to current amount
  */
  do
  {
	printf("Insert payment:");
	scanf("%d", &nPay);
	
	/* 
	  Ask user for input until
	  the input becomes valid
	*/
	
	while (checkPay (nPay) == 0)
	{
	  printf("Invalid Input!\n");
	  printf("Insert your payment:");
	  scanf("%d", &nPay);
	}
	
	/* 
	  switch statement for the 
	  selection of money 
	*/
	switch (nPay)
	{
	  case 1: fValue += 1000;
              break;  
				
	  case 2: fValue += 500;
              break;
			  
	  case 3: fValue += 100;
              break;
			  
	  case 4: fValue += 50;
              break;
			  
	  case 5: fValue += 20;
              break;  
				
	  case 6: fValue += 10;
              break;
			  
	  case 7: fValue += 5;
              break;
			  
	  case 8: fValue += 1;
	          break;
			  
	  case 9: fValue += 0.25;
              break;  
				
	  case 10: fValue += 0.10;
               break;
			  
	  case 11: fValue += 0.05;
               break;
			  
	  case 12: fValue += 0.01;
               break;
	           
      case 0: fValue = 0;
              fAmount = 0; 
              break; 			  

	}
  } while (fValue < fAmount);
	 
    return fValue; 
}

/* This function checks if the payment
   input of the user is valid
   
   Precondition: nPay is a non-negative
                 integer value.
				 
   @param nPay is the user input for 
   payment inserted.
   
   @return 1 if the user inputted
           a valid input
		   
           2 if the user inputted a 
           zero input
		   
           0 if the user inputted 
           an invalid input
*/

int 
checkPay (int nPay)
{
  if (nPay == 1 ||
      nPay == 2 ||
      nPay == 3 ||
      nPay == 4 ||
      nPay == 5 ||
      nPay == 6 ||
      nPay == 7 ||
      nPay == 8 ||
      nPay == 9 ||
      nPay == 10 ||
      nPay == 11 ||
      nPay == 12)
	return 1;
	  
  else if (nPay == 0)
	return 2;
  
  else 
	return 0; 
		
}

/* The function outputs the minimum
   number of bills/coins for the 
   change. 
   
   Precondition: the change of 
   the user is a float value 
   in 2 decimal places.
   
   @param fchange is the change of the
   user based on the payment inserted
*/

void 
displaychange (float fchange,
               int *pbills)
{
  int n1000, n500, n100, n50, n20,
      n10, n5, n1, npoint25,
	  npoint10, npoint05, npoint01;
	  
  if (fchange > 0)
  {
 	/* 
	   Compute for the number 
	   of bills
	*/
	
	n1000 = fchange / 1000; 
    fchange -= n1000 * 1000;
	
    n500 = fchange / 500; 
    fchange -= n500 * 500;
    
 	n100 = fchange / 100;
 	fchange -= n100 * 100;

 	n50 = fchange / 50;
 	fchange -= n50 * 50;
 	
 	n20 = fchange / 20;
 	fchange -= n20 * 20;

 	n10  = fchange / 10;
 	fchange -=  n10 * 10;
 	
 	n5 = fchange/ 5;
 	fchange -= n5*5;
 	
 	n1 = fchange;
 	fchange -= n1; 
	
	/* for bills less than 1 */
	
 	if (fchange != 0)
 	{
	  npoint25 = fchange / 0.25; 
	  fchange -= npoint25 * 0.25;
	
	  npoint10 = fchange / 0.10;
	  fchange -= npoint10 * 0.10;
	
	  npoint05 = fchange / 0.05;
	  fchange -= npoint05 * 0.05;

	  npoint01 = (fchange + 0.005) 
	             / 0.01;
    }
    
    else 
    {
    	npoint25 = 0;
    	npoint10 = 0;
    	npoint05 = 0;
    	npoint01 = 0; 
	}
	
	/* Equating this to count 
	   pointer variables */
	   
	   pbills[0] += n1000;
	   pbills[1] += n500; 
	   pbills[2] += n100;
	   pbills[3] += n50;
	   pbills[4] += n20; 
	   pbills[5] += n10;
	   pbills[6] += n5;
	   pbills[7] += n1;
	   pbills[8] += npoint25;
	   pbills[9] += npoint10;
	   pbills[10] += npoint05;
	   pbills[11] += npoint01;
 	
	/*
	  Output the number of 
	  bills per type of bill
	  (1,  5, 10, 20,
	  50, 100, 500).
	*/
	
	printf ("Dispensing change:\n");
	
	displayif (n1000, 1000);
	displayif (n500, 500);
	displayif (n100, 100);
	displayif (n50, 50 );
	displayif (n20, 20);
	displayif (n10, 10);
	displayif (n5, 5);
	displayif (n1, 1);
	displayif (npoint25, 0.25);
	displayif (npoint10, 0.10);
	displayif (npoint05, 0.05);
	displayif (npoint01, 0.01);
	
  }
  
  else 
    printf ("Change : 0.00\n");
}

/* The function displays the 
   number of bills per type 
   of bill based on the change. 
   
   Precondition: nNum is a non-negative
   integer value and fValueBill is a
   floating point value in 2 decimal
   places. 
   
   @param nNum is the number of bills 
   per type of bill.
   
   @param fValueBill refers to the 
   value of the corresponding 
   bill type.
*/

void
displayif (int nNum, float fValueBill)
{
  if (nNum > 0)
  {
   printf("%d -", nNum);
   printf(" %.2f\n", fValueBill);
  }
}

/* This function displays the receipt
   for the entire order. 
   
   Precondition: all parameters based 
   on user input are non-negative or 
   character values. The payable
   amount, the user payment and 
   the change is a float value
   in 2 decimal places. 
   
   @param ncrust is the chosen crust 
   type by the user 
   
   @param csize is the chosen pizza
   size by the user
   
   @param ncheese is the number of 
   times cheese was chosen 
   
   @param nham is the number of
   times ham was chosen
   
   @param npapple is the number
   of times pineapple was chosen
   
   @param nsausage is the number
   of times sausage was chosen
   
   @param nolives is the number
   of times olives was chosen 
   
   @param nMoz is the number
   of times Mozzarella was chosen
   
   @param nFon is the number 
   of times Fontina was chosen
   
   @param nGorg is the number 
   of times Gorgonzola was chosen
   
   @param nPar is the number
   of times Parmesan was chosen
   
   @param ntransact is the 
   transaction number of 
   the vending machine
   
   @param cstuffing is the chosen
   stuffing type by the user
   
   @param fAmount is the total 
   payable amount
   
   @param fpayment is the payment
   inserted by the user
   
   @param fchange is the change given 
   to the user for excess payment
*/

void
displayreceipt (int ncrust, 
                char csize, 
                int ncheese, 
                int nham, 
                int npapple, 
                int nsausage, 
                int nolives, 
                int nMoz, 
                int nFon, 
                int nGorg, 
                int nPar, 
                int ntransact,
                char cstuffing, 
                float fAmount, 
                float fpayment, 
                float fchange)
{
  /* Declaring variables */
  float ftopping1 = 0;
  float ftopping2 = 0;
  float ftopping3 = 0;
  float ftopping4 = 0;
  
  int ntopping1, ntopping2, 
      ntopping3, ntopping4;
	  
  int ncount1, ncount2,
      ncount3, ncount4;  
  
  float fcheese1 = 0;
  float fcheese2 = 0;
  float fcheese3 = 0;
  float fcheese4 = 0;
  
  int ncheese1, ncheese2, 
      ncheese3, ncheese4;
	  
  int ncount5, ncount6, 
      ncount7, ncount8;
	  
  int nTotal, nchange, npay; 
  char cname [50];
  
  /* Ask user to input name */
  
  printf("\nPlease input your name:");
  scanf("\n");
  scanf("%[^\n]s", cname);
       
  printf ("Printing receipt...\n");
  
  /* Displaying Receipt Header */
  
  printf("%27s\n", "Authentic Pizza");
  printf("%25s\n", "Philippines");
  printf("%25s\n", "Your Receipt");
  printf("Transaction No. ");
  printf("%d\n", ntransact);
  printf("Name: %s\n", cname); 
  
  
  /* Print time display */
  printf("\nTime of Order:");
  displaytime ();
  displayline(); 
  
  /* conditions to print crust type*/
  
  if (ncrust == 1)
  {
    printf("\nThin Crust");
    printf("(%c)", csize);
	
	if (csize == 'S' 
	    || csize == 's')
      printf("%27.2f\n", 100.00); 
	  
    else if (csize == 'M' 
	         || csize == 'm')
      printf("%27.2f\n", 175.00);
	  
    else 
	  printf("%27.2f\n", 225.00);
  }
  else 
  {	  
    printf("\nThick Crust");
    printf("(%c)", csize);
	if (csize == 'S' 
	    || csize == 's')
      printf("%26.2f\n", 100.00); 
    else if (csize == 'M' 
	         || csize == 'm')
      printf("%26.2f\n", 175.00);
    else 
	  printf("%26.2f\n", 225.00);
	
  }
  
 
 /*
   Conditions for 
   displaying toppings
 */
  
  if (nham > 0)
  {
	printf("Ham (%d)", nham);
	
	/* 
	  get price for topping
	  based on size 
	*/
	ftopping1 = gettopprice(10, csize);
	ftopping1 *= nham;
				
	/* 
	  convert ftopping1 into 
	  an integer value
	*/
	
	ntopping1 = ftopping1;
	
	/* 
	  count the number of digits
	  for the count of ham topping
      and integer price value of 
	  ham topping	  
	*/
	
	ncount1 = countnum (nham) +
	         (countnum (ntopping1)
			 + 3);
	
	/* display the space */
	
	displayspace(6, ncount1);
				 
    printf("%.2f\n", ftopping1);
  }
  
  if (npapple > 0)
  {
  	printf("Pineapple (%d)", npapple);
	
	/* 
	   get price for topping
	   based on size 
	*/
	
	ftopping2 = gettopprice(6, csize);
	ftopping2 *= npapple;
	
	/* 
	   convert ftopping2 into 
	   an integer value 
	*/
	ntopping2 = ftopping2;
	
	/*
	  count the number of digits for
      the count of pineapple topping 
	  and integer price value of 
	  pineapple topping
	*/
	
	ncount2 = countnum(npapple) +
	         (countnum (ntopping2)
			 +3);
	
	/* display the space */
	
	displayspace(12, ncount2);
				 
    printf("%.2f\n", ftopping2);
  }
  
  if (nsausage > 0)
  {
	printf("Sausage (%d)", nsausage);
	
	/* 
	   get price for topping
	   based on size 
	*/
	
	ftopping3 = gettopprice(15, csize);
	ftopping3 *= nsausage;
				
	/* 
	   convert ftopping3 into 
	   an integer value 
	*/
	
	ntopping3 = ftopping3;
	
	/* 
	   count the number of digits for
       the count of sausage topping
	   and integer price value of 
	   sausage topping
	*/
	
	ncount3 = countnum(nsausage) +
	         (countnum (ntopping3)
			  +3);
	
	/* display the space */
	
	displayspace(10, ncount3);
				 
    printf("%.2f\n", ftopping3);
  }
  
  if (ncheese > 0)
  {
	if (nMoz > 0)
	{	
	  printf("Mozzarella (%d)",nMoz);
	  
	  /* 
	     get price for topping
	     based on size 
	  */
	  
	  fcheese1 = gettopprice(12, csize);
	  fcheese1 *= nMoz;
				 
	  /* 
	    convert fcheese1 into
	    an integer value 
	  */
	  
	  ncheese1 = fcheese1;
	  
	  /* 
	    count the number of digits 
        for the count of  
	    Mozzarella topping and 
		the integer price value
		of cheese 
	  */
	  
	  ncount5 = countnum(nMoz)+
	           (countnum(ncheese1) 
			    + 3);
	  
	  /* display the space */
	  
	  displayspace(13, ncount5);
				   
	  printf("%.2f\n", fcheese1);
	} 
	
    if (nGorg > 0)
	{
      printf("Gorgonzola (%d)", nGorg);
	  
	  /* 
	     get price for topping
	     based on size 
	  */
	  
	  fcheese2 = gettopprice(12, csize);
	  fcheese2 *= nGorg;
	  
	  /* 
	     convert fcheese2 into
	     an integer value 
	  */
	  
	  ncheese2 = fcheese2;
	  
	  /* 
	    count the number of digits for
        the count of Gorgonzola 
	    topping and the integer 
		price value of cheese 
	  */
	  
	  ncount6 = countnum(nGorg) +
	           (countnum (ncheese2)
			    + 3);
	  
	  /* display the space */
	  
	  displayspace(13, ncount6);
				   
	  printf("%.2f\n", fcheese2);
	}
	
    if (nFon > 0)
	{	
	  printf("Fontina (%d)",nFon);
	  
	  /* 
	    get price for topping
	    based on size 
	  */
	
	  fcheese3 = gettopprice(12, csize);
	  fcheese3 *= nFon;
	  
	  /* 
	    convert fcheese3 into
	    an integer value 
	  */
	  
	  ncheese3 = fcheese3;
	  
	  /* 
	    count the number of digits 
	    for the count of Fontina 
	    topping and the integer 
		price value of cheese 
	  */
	  
	  ncount7 = countnum(nFon) +
	           (countnum (ncheese3)
			    + 3);
	  
	  /* display the space */
	  
	  displayspace(10, ncount7);
	  printf("%.2f\n", fcheese3);
	} 
	
    if (nPar > 0)
	{
      printf("Parmesan (%d)", nPar);
	  
	  /* 
	    get price for topping
	    based on size 
	  */
	  
	  fcheese4 = gettopprice(12, csize);
	  fcheese4 *= nPar;
	  
	  /* 
	    convert fcheese4 into
	    an integer value 
	  */
	  
	  ncheese4 = fcheese4;
	  
	  /* 
	    count the number of digits 
	    for the count of Parmesan 
	    topping  and the integer 
		price value of cheese 
	  */
	  
	  ncount8 = countnum(nPar) +
	            (countnum (ncheese4)
				+ 3);
	  
	  /* display the space */
	  
	  displayspace(11, ncount8);
	  printf("%.2f\n", fcheese4);
	}		
  }
  
  if (nolives > 0)
  {
	printf("Olives (%d)", nolives);
	
	/* 
	  get price for topping
	  based on size 
	*/
	
	ftopping4 = gettopprice(10, csize);
	ftopping4 *= nolives;
				
	/* 
	  convert ftopping4 into
	  an integer value 
	*/
	
	ntopping4 = ftopping4;
	
	/* 
      count the number of digits 
	  for the count of Olives 
	  topping and the integer 
	  price value of olives 
	*/
	
	ncount4 = countnum(nolives) +
	          (countnum (ntopping4) 
			  + 3);
	
	/* display the space */
	
	displayspace(9, ncount4);
				 
    printf("%.2f\n", ftopping4);
  }
  
  /* 
    conditions to display
    crust stuffing 
  */
  
  if (ncrust == 2)
  {
    if (cstuffing == 'c' 
	    || cstuffing == 'C')
	{
	  printf("Cheese Stuffing");
	  printf("%25.2f\n", 30.00);
	}
	
	else if (cstuffing == 'S' 
	         || cstuffing == 's')
	{
	  printf("Spam Stuffing");
	  printf("%27.2f\n", 25.00);
	}
	
	else if (cstuffing == 'B' 
	         || cstuffing == 'b')
	{
	  printf("Cheese & Spam Stuffing");
	  printf("%18.2f\n", 35.00);
	}
	
	else 
	  printf ("No Stuff Crust\n");
  }
  
  displayline ();
  
  /* display payable amount */
  
  printf("\nTotal");
  nTotal = fAmount;
  displayspace(5, 
              countnum(nTotal) + 3);
			  
  printf("%.2f\n", fAmount);
  
  /* display cash received */
  
  printf("Cash Received");
  npay = fpayment;
  displayspace(13, 
              countnum(npay) + 3);
			  
  printf("%.2f\n", fpayment);
  
  /* display dispensed change */
  
  printf("Change");
  nchange = fchange;
  displayspace(6, 
               countnum(nchange) + 3);
  printf("%.2f\n", fchange);
}

/* This function counts the 
   number of digits.
   
   Precondition: nNum is a 
   non-negative integer value
   (>0).
   
   @param nNum is the given number 
   to be counted.
   
   @return number of digits
*/

int 
countnum(int nNum)
{
  int nCount = 0;
  if (nNum == 0)
  {
  	nCount = 1;
  }
  while (nNum!= 0)
  {
	 nNum /= 10;
     nCount++;
  }
  return nCount; 
}

/* This function displays spaces
   based on the number of characters.
   Precondition: all parameters are 
   non-negative integer values. 
   
   @param nNum1 is the number of 
   characters in the string part
   of the receipt.
   
   @param nNum2 is the sum of 
   the number of  digits in the 
   count of topping, crust, 
   cheese, or stuffing    
   parameter and the number of
   digits of the integer price 
   value of each item
*/

void 
displayspace(int nNum1, int nNum2)
{
  int nspaces;
  int i;  
  
  /* 
    40 - (number of characters 
    + (number of orders + 
	number of placevalue)) 
  */
	 
  nspaces = 40 - (nNum1 + nNum2);
  
  for (i = 1; i <= nspaces; i++)
	  printf(" ");
  
}

/* The function calculates the
   time in seconds.
   
   Precondition: all parameters are
   character and non-negative integer
   values. 
   
   @param nham is the number of times
   ham was chosen as a topping.
   
   @param npapple is the number of
   times pineapple was chosen as a 
   topping. 
   
   @param ncheese is the number of 
   times cheese was chosen as 
   a topping.
   
   @param nsausage is the number of 
   times sausage was chosen as a 
   topping.
   
   @param nolives is the number of
   times olives was chosen as a 
   topping.
   
   @param cstuffing is the chosen 
   stuffing type by the user. 
   
   @return time in seconds
*/
int
calculatetime (int nham,
               int npapple,
               int ncheese,
               int nsausage,
               int nolives,
               char cstuffing)
{
  int nTotal;
  
  /* 
    calculate time in seconds
    based on toppings 
  */
	 
  nTotal= (nham + npapple + ncheese 
           + nsausage + nolives) * 2; 
		   
  /* 
    calculate time in seconds
    based on stuffing 
  */
  
  if (cstuffing == 'b' 
      || cstuffing == 'B')
	  nTotal += 10;
  
  else if (cstuffing == 'c' 
           || cstuffing == 'C' 
           || cstuffing == 'S' 
           || cstuffing == 's')
	  nTotal += 5;
	  
  return nTotal; 
}

/* This function displays a simple
   countdown timer using a loop. 
   
   Precondition: all parameters are
   character and non-negative integer
   values. 
   
   @param nham is the number of times
   ham was chosen as a topping.
   
   @param npapple is the number of
   times pineapple was chosen as a 
   topping. 
   
   @param ncheese is the number of 
   times cheese was chosen as 
   a topping.
   
   @param nsausage is the number of 
   times sausage was chosen as a 
   topping.
   
   @param nolives is the number of
   times olives was chosen as a 
   topping.
   
   @param cstuffing is the chosen 
   stuffing type by the user. 
*/

void
displaytimer (int nham,
              int npapple,
			  int ncheese,
			  int nsausage,
			  int nolives,
			  char cstuffing)
{
  
  int i, nMin, nSec, nTime;
  nTime = calculatetime (nham, 
                         npapple, 
                         ncheese,
                         nsausage,
                         nolives,
                         cstuffing);
  nTime += 180; 
  
  for (i = nTime; i >= 0; i--)
  {
  	nMin = i / 60; 
    nSec = i % 60;
    printf ("%d:", nMin);
    printf("%02d  ", nSec); 
  }
	  
}

/* This functions displays
   the current time using 
   the system's time and date
   information.
*/

void
displaytime ()
{
  time_t currenttime;
  struct tm *info;
  
  /* 
    returns the time value
	in seconds
  */
  
  time (&currenttime);
  
  /* 
    Fills in the info time structure 
	with the corresponding value for 
	seconds, hours, minutes, etc. 
	according to the local time zone
  */
  
  info = localtime (&currenttime);
  
  /* 
    Interpreting the structure 
    contents as calendar time and 
    converting it to string.
  */
  printf("%s", asctime (info)); 
}

/* This function updates the count
   of every ingredient in the pizza 
   for every transaction.
   
   @param ncrust is the type of
   crust chosen by the user. 
   
   @param nham is the number of 
   times ham was chosen as a topping. 
   
   @param npapple is the number of
   times pineapple was chosen 
   as a topping. 
   
   @param nsausage is the number of
   times sausage was chosen as 
   a topping. 
   
   @param nolives is the number of 
   times sausage was chosen as 
   a topping. 
   
   @param nMoz is the number of 
   times Mozzarella was chosen
   
   @param nGorg is the number 
   of times Gorgonzola was chosen
   
   @param nFon is the number 
   of times Fontina was chosen
   
   @param nPar is the number 
   of times Parmesan was chosen. 
   
   @param cstuff is the stuffing
   type chosen by the user
   
   @param pcrust is a pointer 
   that points to the array 
   holding the values for
   total count of crust type
   from previous transactions
   
   @param ptop is a pointer 
   that points to the array 
   holding the values for
   total count of toppings
   from previous transactions
   
   @param pcheese is a pointer 
   that points to the array 
   holding the values for
   total count of cheese type
   from previous transactions
   
   @param pstuff is a pointer 
   that points to the array 
   holding the values for
   total count of stuffing type
   from previous transactions
   
*/
void
updatevariables (int ncrust,
                 int nham,
                 int npapple,
                 int nsausage,
                 int nolives,
                 int nMoz,
                 int nGorg,
                 int nFon,
                 int nPar,
                 char cstuff,
                 int *pcrust,
                 int *ptop,
                 int *pcheese,
                 int *pstuff)
{ 
  
  /* Crust Type */
  if (ncrust == 1)
  {
	pcrust[0]++;
  } 
  else if (ncrust == 2)
  {
	pcrust[1]++;
  }
	   
  /* toppings*/
  ptop[0] += nham; 
  ptop[1]+= npapple;
  ptop[2] += nsausage;
  ptop[3] += nolives; 
	  
  pcheese[0] += nMoz; 
  pcheese[1] += nFon;
  pcheese[2] += nGorg; 
  pcheese[3] += nPar; 
	  
  /* Stuffing type */
  if (ncrust == 1)
  {
	pstuff[0] += 0;
	pstuff[1] += 0; 
  }
  
  else 
  {	  
    if (cstuff == 'C' 
	    || cstuff == 'c')
	  pstuff[0] += 1;
	
    else if (cstuff == 'S'
	         || cstuff == 's')
	  pstuff[1] += 1; 
	
    else if (cstuff == 'B'
	         || cstuff == 'b')
    {
	  pstuff[0] += 1;
	  pstuff[1] += 1; 
    }
    else 
    {
	  pstuff[0]+= 0;
	  pstuff[1]+= 0;   
    }
  }
}
/* This function generates
   a summary of transactions, 
   which include the ingredients
   used, and cash balance. 
   
   @param ncrusttotal is a pointer
   that points to an array holding 
   the updated values of crust type 
   for all previous transactions
   
   @param ntoptotal is a pointer
   that points to an array holding 
   the updated values of topping count
   for all previous transactions
   
   @param ncheesetotal is a pointer
   that points to an array holding 
   the updated values of cheese count
   for all previous transactions
   
   @param nstufftotal is a pointer
   that points to an array holding 
   the updated values of stuffing count
   for all previous transactions
   
   @param nbilltotal is a pointer
   that points to an array holding 
   the updated values of bill count
   for all previous transactions
   
   @param ntransact is a value for
   how many pizzas were made
   
   @param fbalance is the overall
   cash balance from previous 
   transactions
 */
void
generatereport (int *ncrusttotal, 
                int *ntoptotal,
                int *ncheesetotal,
                int *nstufftotal,
                int *nbilltotal,
                int ntransact,
                float fbalance)
{
  displayline();
  printf("\n%27s\n","Report Summary");
  displayline();
 
 
  /* Quantity per Crust type Used */
  printf("\nQuantity per Crust");
  printf(" Type Ordered\n"); 
  printf("Thin Crust: ");
  printf("%d", ncrusttotal[0]); 
  printf("\nThick Crust: ");
  printf("%d\n", ncrusttotal[1]);
  displayline();

  /* Quantity per Topping Used */
  printf("\nQuantity per ");
  printf("Topping Used");
  printf("\nHam: ");
  printf ("%d", ntoptotal[0]);
  printf("\nPineapple: ");
  printf ("%d", ntoptotal[1]);
  printf("\nSausage: "); 
  printf ("%d", ntoptotal[2]);
  printf("\nOlives: ");
  printf ("%d\n", ntoptotal[3]);
  displayline(); 
  
  /* Quantity per Type 
	 of Cheese Used 
  */
  printf("\nQuantity per Type");
  printf(" of Cheese Used");
  printf("\nMozzarella: ");
  printf("%d", ncheesetotal[0]);
  printf("\nFontina: ");
  printf("%d", ncheesetotal[1]);
  printf("\nGorgonzola: ");
  printf("%d", ncheesetotal[2]);
  printf("\nParmesan: "); 
  printf("%d\n", ncheesetotal[3]);
  displayline(); 
  
  /* Quantity per Stuffing 
	 Type Used
  */
  printf("\nQuantity per ");
  printf("Stuffing Type Used");
  printf("\nCheese Stuffing: ");
  printf ("%d", nstufftotal[0]);
  printf("\nSpam Stuffing: ");
  printf ("%d\n", nstufftotal[1]);
  displayline(); 		
		
  /* Quantity of bills and 
	 coins released 
  */
  printf("\nQuantity per Bill");
  printf(" Type Used\n");
  displayif(nbilltotal[0], 1000); 
  displayif(nbilltotal[1], 500);
  displayif(nbilltotal[2], 100);	
  displayif(nbilltotal[3], 50);
  displayif(nbilltotal[4], 20);
  displayif(nbilltotal[5], 10);
  displayif(nbilltotal[6], 5);
  displayif(nbilltotal[7], 1);
  displayif(nbilltotal[8], 0.25);	
  displayif(nbilltotal[9], 0.10);	
  displayif(nbilltotal[10], 0.05);
  displayif(nbilltotal[11], 0.01);	
  displayline(); 

  /* Quantity of Pizzas Ordered */
  printf("\nQuantity of");
  printf(" Pizzas Ordered: ");
  printf("%d\n", ntransact); 
  displayline(); 
		
  /* output cash balance */
  printf ("\nCash Balance: ");
  printf ("%.2f", fbalance);
  
  
}
