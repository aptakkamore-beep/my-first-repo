#include <stdio.h>

int main(void)
{
    //Declare a variable to store the height of the triangle
    int height;
    printf("Enter the height of the triangle: ");
    scanf("%d", &height);
// The bricks in the world of mario
// The outer loop iterates through each row of the triangle, starting from 0 up to the specified height. 
    for (int row = 0; row <= height; row++)
    {
        // The inner loops handle the printing of spaces and bricks for each row. 

        // The first inner loop prints spaces to create the left-aligned triangle shape. 
        for (int space = 0; space <= height - row - 1; space++)
        {
            printf(" ");
        }
        // The second inner loop prints the bricks (#) for each row. After printing the bricks for a row
        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }
        //  a newline character is printed to move to the next line.
        printf("\n");
    }

