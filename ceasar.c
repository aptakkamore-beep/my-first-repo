#include <stdio.h>


int main() 
{
    //To take input from user
    char ceasar_encrypt[100];
    printf("Enter the text to encrypt: ");
    scanf("%s", ceasar_encrypt);


    int k = 1; // Shift value for Caesar cipher
    
    //The output of the encrypted text is stored in the same variable ceasar_encrypt
    //The loop iterates through each character of the input string and applies the Caesar cipher encryption based on the shift value k.

    for (int i = 0; ceasar_encrypt[i] != '\0'; i++) 
    {
        char ch = ceasar_encrypt[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = (ch - 'A' + k) % 26 + 'A';
        } 
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') 
        {
            ch = (ch - 'a' + k) % 26 + 'a';
        }

        ceasar_encrypt[i] = ch;
    }
    printf("Encrypted text: %s\n", ceasar_encrypt);
}