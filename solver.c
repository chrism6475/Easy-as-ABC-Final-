//description of what file does
//descriptoin of method paramteers, what should do , and what it should reutrn.
//doccument line by line




/*
 
 Description of file: This file is responsible for recursively solving the 4X4
 grid that has been passed to setGrid(char *onegrid) in the form of a .
 1D array The file first constructs the 4X4 grid based on the specifications
 within the one dimensional array passed to it.
 Using this constructed 4X4 grid, the file recursively solves the 4X4 grid.
 The file then has a method responsible for returning the found letter.
 The main method is responsible for calling the following methods, and therefore
 ultimately responsible for solving the board. This file just provides the
 methods necessary for solving the board.
 
 
 Description of Algorithm :
 1. Check to see if the specified location's letter has been filled in,if so
 set char final to the letter found at the specified location, which will
 be later returned. Only if the letter has not been filled in at the specified
 location continue to step 2.
 
 2. Check Rows if there exists only one possible solution to
 replace an 'M'(case that there are 2 letters in the row). Upon the first
 case of this proving true replace 'M' with appropriate letter, and
 jump back to step 1. If there exists no such case continue to
 step 3.
 
 3. Check Cols if there exists only one possible solution to
 replace an 'M'(case that there are 2 letters in the col). Upon the first
 case of this proving true replace 'M' with appropriate letter, and
 jump back up to step 1. If there exists no such case continue to
 step 4.
 
 4. Find any place there exists an 'M', parse the 'M''s col and
 rows. Replace 'M' with the letter that was not found during
 the parsing of 'M''s rows and cols. Jump to Step 1.
 
 
 
 
 void setGrid(char *onegrid)
 {
 Parameter:ptr to a 1d board constructed in and passed by loadgrid() in load.c
 Responsibilities:1) Construct a 4x4 game board based on specifications 1d arr
 2)Convert 'number',which is disguised as a letter at end
 of onegrid, this is later used as the specified location to return
 letter.
 Returns:Returns nothing, fulfills  Responsibilities above.
 }
 
 
 bool checkOneRow()
 {
 Parameter: Nothing.
 Responsibilities: Responsible for checking Rows in 4x4 grid to find a row where
 there exists only one possible solution ('M' = blank space) Ex: BXMC ->
 only possible solution is 'A' so row becomes BXAC. The method creates a temp array
 letters so as to keep track of letters found within row, and keeps track of the
 number of letters found in the row. If it finds that there exists only one
 solution for the row, it will replace the 'M' with the proper letter, and
 return a boolean true. This is used for the method that is orchestrating the
 Algorithm  that solves the board
 
 Return: Return true if only one possible solution in a row is found,
 return false if no rows contain only one possible solution.
 
 }
 
 
 bool checkOneCol()
 {
 Parameter: Nothing.
 Responsibilities: Responsible for checking Cols in 4x4 grid to find a col where
 there exists only one possible solution ('M' = blank space)
 ex: B        B
     X   ->   X
     M        A
     C        C
 The method creates a temp array letters so as to keep track of letters found
 within col, and keeps track of the number of letters found in the col. If it
 finds that there exists only one solution for the col, it will replace  the 'M'
 with the proper letter, and return a boolean true. This is used for the method
 that is orchestrating the Algorithm that solves
 the board.
 Return: Return true if only one possible solution in a col is found,
 return false if no cols contain only one possible solution.
 
 }
 
 bool checkElse()
 
 {
 Parameter: Nothing
 Responsibilities: Responsible for parsing the 4X4 gird to find any 'M's
 that have not  otherwise been filled in by  checkOneCol() and checkOneRow().
 Upon finding an 'M' the method parses through the row in which the 'M' is
 found in and the col in which the 'M' is found in. The method keeps track of the
 letters found in a temp array of letters.Upon finding a letter,'A' for
 instance the method will set aFound to true, and continue parsing for
 letters upon finding another letter, 'C" for instance,  it will also set
 cFound to true. After the method has parsed the M's row and col, the
 method will reflect upon what letters it has found, and replace the letter
 that hasn't been found with the 'M'. In our current example it would replace
 'M' with 'B'. Upon replacing a letter the method will return true.
 This is used for the method  that is orchestrating the Algorithm that solves
 the board.
 
 Return true if replaced a letter, false if it did not.
 
 }
 
 
 
 
 void findSol()
 {
 parameters: none
 Responsibilities: orchestrate the component parts of the Algorithm:
 checkOneRow(),checkOneCol(),and checkElse() to correctly solve the board
 and return the letter at the specified location.Continually check
 if the letter at the specified location has been filled in. If so
 set char final to that letter, which will be later returned and outputed.
 return: nothing.
 
 }
 
 
 
 char returnFinal()
 {
 parameters:none
 Responsibilities: examine global variable: char final, and return this char.
 return: returns global variable char final.
 
 }
 
 
 */










#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char grid[4][4];                                       //4x4 grid used to find letter at specified location
int number;                                            //specified location
int row=0;
int col=0;
char final;                                            // letter at specified location,later returned

void setGrid(char *onegrid)
{
    char *ptr;
    char *p;
    p = (onegrid);
    for(int y=0;y<4;y++){                              //conversion process from 1D->2D 4X4 grid
        for(int x=0;x<4;x++){
            if(*(onegrid+4*x+y)==NULL)                 //replace blank spaces with letter 'M'
            {
                grid[x][y]='M';
            }
            else
            {
                grid[x][y]=(*(onegrid+4*x+y));         //grid[x][y] = 4*x*y in onegrid
            }
        }
    }
    
    switch(*(onegrid+16))                              //specified locaiton was embeded in one grid array
    {                                                  //as char, need to convert to number by adding
        case 'a': number = 0;//
            break;           //
        case 'b': number = 1;
            break;
        case 'c': number = 2;
            break;
        case 'd': number =3;
            break;
        case 'e': number =4;
            break;
        case 'f':number = 5;
            break;
        case 'g':number = 6;
            break;
        case 'h':number = 7;
            break;
        case 'i':number =8;
            break;
        case 'j':number =9;
            break;
        case 'k':number =10;
            break;
        case 'l':number =11;
            break;
        case 'm':number = 12;
            break;
        case 'n':number = 13;
            break;
        case 'o':number = 14;
            break;
        case 'p':number = 15;
            break;
        case 'q' :number = 16;
            break;
        case 'r':number = 17;
            break;
        case 's':number = 18;
            break;
        case 't':number = 19;
            break;
        case 'u' :number = 20;
            break;
        case 'v':number = 21;
            break;
        case 'w':number = 22;
            break;
        case 'x':number = 23;
            break;
        case 'y' :number = 24;
            break;
        case 'z' :number = 25;
            break;
        case 'X':number = 26;
            break;
        case 'Y':number = 27;
            break;
        case 'Z':number = 28;
            break;
        case 'W':number = 29;
            break;
    }
    
    
}



bool checkOneRow()
{
    char letters[10];
    bool aFound;
    bool bFound;
    bool cFound;
    bool oneInRow= false;
    int lettersFound =-1;
    
    
    
    for(int i =0; i<=3;i++)                             //i = rows,j = cols
    {
        for(int j=0;j<=3;j++)
        {
            if(grid[i][j]=='A')                         //Keep track of letters found in row,if at any point
            {                                           //you find a letter, place it in array of letters found
                letters[++lettersFound]='A';            //if A is found place in arrayy, set aFound to true
                aFound=true;
            }
            else  if(grid[i][j]=='B')                   //if B is found place in array,set bFound to true
            {
                letters[++lettersFound]='B';
                bFound=true;
            }
            else if(grid[i][j]=='C')                    // if C is found place in array, set cFound to true
            {
                letters[++lettersFound]='C';
                cFound=true;
            }
        }                                               //end of parsing the row at [i]
        if(lettersFound==1)                             //if lettersFound = 1, that means we have 2 element
        {                                               //in array,that means we found 2 letters in the row
            int k =0;                                   //and that we can replace the 'M' with the letter
            while(k<=3)                                 //not found
            {                                           //search for 'M'
                if(grid[i][k]=='M')
                {
                    if(aFound && bFound)                //if A and B found replace M with C
                    {
                        grid[i][k]='C';
                        oneInRow=true;
                        return oneInRow;                //return true, so that the findSol() can call itself again
                    }                                   //so as to be able to check if there are 2 letters in any row
                    else if(aFound&cFound)              //if A and C are found replace M with B
                    {
                        grid[i][k] ='B';
                        oneInRow = true;
                        return oneInRow;                //return true, so that the findSol() can call itself again
                    }
                    else{
                        grid[i][k]='A';                 //the only other case is b and c are foudn so replace 'M'
                        oneInRow = true;                //with 'C'
                        return oneInRow;
                    }
                }
                k++;
            }
            k=0;
        }
        letters[0]=NULL;                                //prior to parsing next row we must reset all conditions
        letters[1]=NULL;                                //so as to get accurate representation of new row
        letters[2]= NULL;
        
        aFound= false;
        bFound =false;
        cFound = false;
        oneInRow = false;
        
        lettersFound =-1;
    }
    return oneInRow;
}



bool checkOneCol()
{
    
    char letters[10];
    bool aFound;
    bool bFound;
    bool cFound;
    bool oneInCol= false;
    int lettersFound =-1;
    
    for(int j =0; j<=3;j++)                             //j = col, i = row,
    {
        for(int i=0;i<=3;i++)                           //begin parsing column, through incrementing row (i)
        {
            if(grid[i][j]=='A')                         //Keep track of letters found in row,if at any point
            {                                           //you find a letter, place it in array of letters at
                letters[++lettersFound]='A';            //updated index lettersFound
                aFound=true;                            //if a found set to true
            }
            else  if(grid[i][j]=='B')
            {
                letters[++lettersFound]='B';            //place in array of letters
                bFound=true;                            //b is found set it to true
            }
            else if(grid[i][j]=='C')
            {
                letters[++lettersFound]='C';            //place in array of letters
                cFound=true;                            //C is found so set it to true
            }
        }
        if(lettersFound==1)                             //end of parsing the col at [j]
        {                                               //if lettersFound = 1, that means we have 2 element
            int k =0;                                   //in array,that means we found 2 letters in the col
            while(k<=3)                                 //and that we can replace the 'M' with the letter
            {                                           //not found
                if(grid[k][j]=='M')                     //begin searching for 'M' in col
                {
                    if(aFound && bFound)                //if A and B found in col replace M with C
                    {
                        grid[k][j]='C';
                        oneInCol=true;                  //return true, so that the findSol() can call itself again
                        return oneInCol;                //so as to be able to begin algorithim over agaain(See algorithim)
                    }
                    else if(aFound&cFound)              //if A and C are found replace M with C
                    {
                        grid[k][j] ='B';
                        oneInCol=true;
                        return oneInCol;
                    }
                    else{                               //only other case is B and C are found so replace M with A
                        grid[k][j]='A';
                        oneInCol=true;
                        return oneInCol;
                    }
                }
                k++;
            }
            k=0;
        }
        letters[0]=NULL;                                //prior to parsing next row we must reset all conditions
        letters[1]=NULL;                                //so as to get accurate representation of new col.
        letters[2]= NULL;
        
        aFound= false;
        bFound =false;
        cFound = false;
        oneInCol=false;
        lettersFound =-1;
        
    }
    
    return oneInCol;
}


bool checkElse()                                        //method responsible for replacing 'M' where there exists
{                                                       //less than 2 letters in M's cols and Rows.
    
    char letters[10];
    bool aFound;
    bool bFound;
    bool cFound;
    bool checkFill = false;
    int lettersFound =-1;
    
    for(int i =0;i<=3;i++)                              //find any occurences of 'M',i = row, j = col
    {
        for(int j =0;j<=3;j++)
        {
            if(grid[i][j]=='M')
            {
                int k =0;                               //once you find a 'M',parss the row that M
                //is in, and track letters found.
                while(k<=3)
                {
                    if(grid[i][k]=='A')
                    {
                        letters[++lettersFound]='A';    //A is found in Row
                        aFound=true;
                    }
                    else if(grid[i][k]=='B')
                    {
                        letters[++lettersFound]='B';    //B is found in Row
                        bFound=true;
                    }
                    else if(grid[i][k]=='C')            //C is FOund in Row
                    {
                        letters[++lettersFound]='C';
                        cFound=true;
                    }
                    k++;
                    
                }
                
                k=0;                                    //once we are done parsing row for all letters
                while(k<=3)                             //we must begin parsing col for all letters
                {
                    if(grid[k][j]=='A')
                    {
                        letters[++lettersFound]='A';
                        aFound=true;                    //A is found in Col
                    }
                    else if(grid[k][j]=='B')
                    {
                        letters[++lettersFound]='B';
                        bFound=true;                    //B is found in col
                    }
                    else if(grid[k][j]=='C')
                    {
                        letters[++lettersFound]='C';
                        cFound=true;                    //C is found in col
                    }
                    k++;
                }
                
                //once we are done parsing rol,col
                if(aFound&&bFound)                      //lets test what we've found
                {
                    grid[i][j]='C';                     //if A and B have been found in both col and row
                    checkFill = true;                   //replace grid[i][j] which contains M with C
                    return checkFill;
                }
                else if(aFound&&cFound)
                {
                    grid[i][j]='B';                     //if A and C have been found in both col and row
                    checkFill = true;                   //replace grid[i][j] which contains M with B
                    return checkFill;
                }
                else if(bFound&&cFound)
                {
                    grid[i][j]='A';                     //if B and C are found in both col and row
                    checkFill = true;                   //replace grid[i][j] which contains M with A
                    return checkFill;
                }
            }
        }
        
        letters[0]=NULL;                                //prior to parsing next row we must reset all conditions
        letters[1]=NULL;                                //so as to get accurate representation of new row
        letters[2]= NULL;
        
        aFound= false;
        bFound =false;
        cFound = false;
        checkFill =false;
        lettersFound =-1;
        
        
    }
    return checkFill;                                   //return ture/false to findSol()
}







void findSol()                                          //method that orchestrates algorihtim(look at algorihtim)
{
    if(grid[(number/6)-1][(number%6)-2]!='M'&&(grid[(number/6)-1][(number%6)-2]!='X'))
    {                                                   //if grid at number != M or X it must be filled with number
        final = grid[(number/6)-1][(number%6)-2];       //set char to letter at the location asked for.
    }
    else{                                               //if grid at number isnt filled check checkOneRow()
        if(checkOneRow())                               //if checkOneRow() is true call findSol() (look at algorithim)
        {
            findSol();
        }
        else{
            
            if(checkOneCol())                           //if checkOneRow() is false, check checkOneCol()
            {
                findSol();                              //if checkOneCol() is true, begin algorithim over
            }                                           //by calling findSol()
            else{
                if(checkElse())                         //if checkOneCol() is false, fill in through
                {                                       //finding an 'M', and then looking at M's rows
                    findSol();                          //and cols.This will always return true unless
                }                                       //there are no more M's(i.e Board is solved),
                else{                                   //if true begin algorithim over again.
                }
            }
        }
        
    }
}


char returnFinal()
{
    return final;
}
