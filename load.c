/*This Loads in the board from "Text.txt" and returns it as a 2-d array
 Description of loadgrid:
 Each line read from the source text file corresponds to
 one board of the Easy as ABC game. This method reads in one line, or grid,
 and returns it as an array.
 Reading in the Grid:
 The loadgrid method reads in one line from the text.txt file using
 fgets until  a null charactor is found and stores the remaining grids in the Text.txt file in rest.txt.
 Then the algorithm stores the remaining grids in rest.txt into the grid source file: "Text.txt", effectively
 preventing the previously solved grid from being solved again.
 The algorithm constructs the grid by converting the positions on the board in the "position" array and the letters
 found at those positions in the  "letters" array. While storing the positions and the letters in their respective array,
 the algorithm checks if the board is valid (i.e. only the letters 'A','B',and 'C', digits 0-9, and a comma to separate the values)
 Constructing the 6x6 Board:
 The algorithm reads in the first 4 values in position which indicate where the 'X's are in the 6x6 board, and place them in the 2d array "board".
 N.B. The algorithm will goto wrongInput if the position of the letter falls in inner grid, the positions 1,6,31, and 36, or
 if the user accidentally stored a number where the letter should be stored in the text file.
 the wrongInput goto will set set onegrid =NULL, thereby initiating a break in the main.
 Constructing the 4x4 grid:
 The algorithm first reads in the 'X's from the 6x6 board and places them in their correct position on the 4x4 grid.
 Then the algorithm stores the letter in its corresponding position on the 4x4 grid.
 Passing the 4x4 grid as onegrid:
 The algorithm stores the 4x4 grid, with all letters in the correct position, in the 1d array "onegrid".
 Lastly, the index of the output, or the solution, which is the last element in the 'position' array is added to 97 and stored in the int "output"
 If output is greater than 122, the  the last index of onegrid
 onegrid is then returned to the main.
 
 
 
 
 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

///robustness what if they fuck up the input .
//assumes that the program opens up a speciifc file.
//how do we build the program in the terminal

//1.Assume that they enter into text.txt

char* loadgrid(){
    FILE *infile;
    infile = fopen("Text.txt", "r");
    char buffer[256];
    FILE *outfile;
    outfile = fopen("rest.txt", "w");
    char *indices=NULL;
    char board[6][6];
    char letters[5];
    char bufferrest[256];
    int indexofoutput=0;
    char newbufferrest[256];
    char *ptr;
    int i=0;
    int position[256];
    int x,y,j,k=0; //x is the column, y is the row
    int f=0;
    char grid[4][4];
    char* onegrid;
    char newline='\n';
    //Initializes all of the boards (board[][] and grid[][]), and buffer to NULL
    for(int i=0;i<=6; i++){
        for (int j=0;j<=6;j++){
            board[i][j]=NULL;
        }
    }
    
    for(int i =0; i<256;i++)
    {
        buffer[i]= NULL;
    }
    for(int i=0;i<=6; i++){
        for (int j=0;j<=6;j++){
            grid[i][j]=NULL;
        }
    }
    //attempt to read infile, return error if there is no source file with all of the boards
    if(infile==NULL) perror ("Error opening file");
    else{
        
        
        int z=0;
        //use fgets to store one line of the board into the buffer array
        while (fgets(buffer, 256, infile)!=NULL){
            //  printf("This is the buffer %s\n", buffer);
            //check if the elements passed through buffer are "A","B","C", a comma, or digits 0-9
            //goto wrongInput which will return an error message in the main if anything other than the specified parameters are passed through
            if((buffer[z]>=65&&buffer[z]<=67)||buffer[z]==44||(buffer[z]>=48 && buffer[z]<=57)){
                
                //tokenize the first line of the text file by splitting it by commas and store it in array "indices"
                indices=strtok(buffer,",");
                while(indices!=NULL){
                    //Stores any letters found in "letters" array, keeping track of the number of letters
                    if(*indices=='A'){
                        letters[f]='A';
                        f++;
                    } else if(*indices=='B'){
                        letters[f]='B';
                        f++;
                    } else if(*indices=='C'){
                        letters[f]='C';
                        f++;
                    }
                    //convert the positions of the letters into long integers, store in "position array"
                    *(position+i)=strtol(indices, &ptr, 10);
                    //  printf("The ret integers are %d\n , ", position[i]);
                    indices=strtok(NULL,",");
                    i++;
                    indexofoutput++;
                    
                }
                
                //scan the remaining lines of boards in the "Text.txt" file into the  "rest.txt" file.
                while(fscanf(infile, "%s[^\n] ",&bufferrest)!=EOF){
                    
                    fprintf(outfile, "%s \n",bufferrest);
                }
                
                z++;
                
            }
            else{
                //goto wrongInput if there are invalid characters/positions
                goto wrongInput;
            }
        }
        fclose(infile);
        fclose(outfile);
        
    }
    //checks if there are no more boards in the text file, returns error message
    if (buffer[0]==NULL){
        printf("Error: There are no more boards in the text file");
        goto wrongInput;
    }
    //reopen the "Text.txt" and "rest.txt" files to store the remaining boards in the "Text.txt" file for the next method call
    infile = fopen("Text.txt", "w");
    outfile = fopen("rest.txt", "r");
    while(fscanf(outfile, "%s [^\n] ",&newbufferrest)!=EOF){
        
        fprintf(infile, "%s \n",newbufferrest);
    }
    fclose(infile);
    fclose(outfile);
    //places the X's in the correct position on the 6x6 board
    for(i=0; i<=3; i++){
        //Checks if the X's are not in the inner grid
        if((position[i]<=6&&position[i]>31)||position[i]%6==0||position[i]%6==1){
            goto wrongInput;
        }else if(position[i]>=6){
            //x's are columns and y's are rows
            x=position[i]%6;
            y=position[i]/6;
            if(x==0){
                y-=1;
                x=5;
            }else{
                x-=1;
            }
            board[x][y]='X';
        }else{
            x=position[i]-1;
            board[x][0]='X';
        }
    }
    
    int z=1;
    if(position[4]!=f){
        goto wrongInput;
    }
    //number of letters is given by the fourth element in position
    //The code will add the letters "A", "B", and "C" in their correct position on the 6x6 board
    for(k=0;k<position[4];k++){
        //checks if the letters are in the positions 1,6,31, and 36, and if they lie inside the inner grid.
        if(position[4+2*z]==1||position[4+2*z]==6||position[4+2*z]==31||position[4+2*z]==36){
            goto wrongInput;
        }else if((position[4+2*z]>7 &&position[4+2*z]<12)||(position[4+2*z]>13 &&position[4+2*z]<18)||(position[4+2*z]>19 &&position[4+2*z]<24)||(position[4+2*z]>25 &&position[4+2*z]<30)){
            goto wrongInput;
            
        } else if(position[3+2*z]!=0){ // returns 0 if the user accidentally placed a number where the letters are supposed to be
            goto wrongInput;
        } else{
            //x's are columns and y's are rows.
            x=(position[6+(2*k)]%6);
            y=(position[6+(2*k)]/6);
            if(x==0){
                y-=1;
                x=5;
            }else{
                x-=1;
            }
            board[x][y]=letters[k];
        }
        z++;
        
    }
    
    
    //stores all of the 'X's in the board in their correct position in the 4x4 grid
    for(int i =0;i<=5;i++)//row
    {
        for(int j=0;j<=5;j++){
            if(board[i][j]=='X'){
                grid[i-1][j-1]=board[i][j];
            }
        }
        
    }
    
    for(int i=0;i<5;i++){
        //move letters in outer, top layer into the 4x4 grid
        //if the grid already has an X next to the letter, the code will skip over the X and place the letter in the correct position
        if(board[i+1][0]!=NULL && grid[i][0]=='X'){
            grid[i][1]=board[i+1][0];
        } else if(board[i+1][0]!=NULL && grid[i][0]==NULL){
            grid[i][0]=board[i+1][0];
        }
        //move letters in outer,left layer into the 4x4 grid
        //if the grid already has an X next to the letter, the code will skip over the X and place the letter in the correct position
        if(board[0][i+1]!=NULL && grid[0][i]=='X'){
            grid[1][i]=board[0][i+1];
        } else if(board[i][1]!=NULL && grid[i][0]==NULL){
            grid[0][i]=board[0][i+1];
        }
        //move letters in outer, bottom layer into the 4x4 grid
        //if the grid already has an X next to the letter, the code will skip over the X and place the letter in the correct position
        if(board[i+1][5]!=NULL && grid[i][3]=='X'){
            grid[i][2]=board[i+1][5];
        } else if(board[i+1][5]!=NULL && grid[i][3]==NULL){
            grid[i][3]=board[i+1][5];
        }
        //move letters in outer,right layer into the 4x4 grid
        //if the grid already has an X next to the letter, the code will skip over the X and place the letter in the correct position
        if(board[5][i+1]!=NULL && grid[3][i]=='X'){
            grid[2][i]=board[5][i+1];
        } else if(board[5][i+1]!=NULL && grid[3][i]==NULL){
            grid[3][i]=board[5][i+1];
        }
        
        
    }
    
    //allocate memory to onegrid
    onegrid=(char*) malloc(sizeof(char)*36);
    //assert(onegrid != NULL);
    //store the 4x4 grid into onegrid
    for(y=0; y<4;y++){
        for(x=0;x<4;x++){
            onegrid[4*y+x]=grid[x][y];
        }
    }
    //add 97 to the output index to convert it to a char (a-z),
    //then store the output index in the array "onegrid"
    //if the output index ascii value is greater than 122, then
    // convert the char to "X","Y", "Z", and "W", respectively
    int output =position[indexofoutput-1]+97;
    if(output>122)
    {
        if(output==123)
        {
            output = 88;  //26
        }
        else if (output==123)//27
        {
            output = 89;
        }
        else if (output==124)//28
        {
            output = 90;
        }
        else if(output==125)
        {
            output = 87;    //29
        }
        else{
        }
        onegrid[16]=output;
    } else{
        onegrid[16]=output;
    }
    
    
    //assert( 0 );
    
    return onegrid;
wrongInput: onegrid = NULL;
    return onegrid;
    
}
