/*
 Main file is responsible for executing the program. The file first asks
 the player how many boards he/she intends toplay. This number is
 important because it lets the program know how many Lines of Text the
 program should read.One line of text represents one board that is
 needed to be solved. As long as there are more board to be read, the
 main method call the methods that are responsible for load the  36 X 36
 game board, setting the 4X4 grid, solving the 4X4 grid, and finally
 returning the letter that was filled in at the specified location
 written at the end of each line in the text file. The main file
 should continually ouputthe Letter at the specified location so
 long as there are boards to be solved in teh following format:
 "Character at specified location is: Letter".
 The main method does not take any paramters.
 
 
 
 
 
 
 */






#include "load.h"
#include "solver.h"

#include <stdio.h>
int main()
{
    char *test;
    
    int boards=0;
    printf("How many boards do you intend to play?(This Number Should be equal to the number of lines you entered in your text file)");                                   //prompt to the to user
    scanf("%d",&boards);                                        //response will be used to let program to
    //continue reading boards
    int i =0;
    int a= 1;
    while(i<boards)                                             //If there are more boards to be read, continue
        // program
    {
        test = loadgrid();
        if(test==NULL)
        {
            printf("%s","\nproblem in board\n");
            
            break;
        }
        
        setGrid(test);                                          //Using the ptr of 4X4 board, set the Grid to
        //be solved
        findSol();                                              //Solve the Grid
        printf("%s","Character at specified location is:");
        if(returnFinal()==NULL)
        {
            printf("%s", " you requested an x this is not how you play the game!!!!!!");
        }
        else{
            printf("%c\n",returnFinal());                       //Finally return the final letter at specified
        }                                                       //locaiton.
        i++;
        a++;
        
        
    }
    
    
    
}