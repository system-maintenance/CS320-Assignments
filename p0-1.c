#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){

    //makes structure to count letters
    struct letter{
        char c;
        int amount;
    };

    //initializes an array and fills it with character each struct represents and times occurred
    struct letter alpha_array[26];
    char start = 'A';
    for (int i=0; i<26; i++){ //makes everything 0
        alpha_array[i].c = start + i;
        alpha_array[i].amount = 0;
    }

    char filename [20];
    //gets file name
    printf("Please input name of .txt file in folder to count characters:\n"); //only works if file in folder and file extension added
    scanf("%s", &filename);


    //opens file and makes sure it exists
    FILE * text = fopen(filename, "r");
    if (text == NULL){
        printf("That file does not exist.\n");
        exit(-1);
    }
            
    
    //goes character by character to get what value it is
    while (!feof(text))
    {
        char ch;
        fscanf(text, "%c",&ch); 
        if (!isupper(ch)){ //makes sure this works for bother upper and lowercase
            ch = toupper(ch);
        }
        int asciiVal = (int) ch;
        if (asciiVal >= 'A' && asciiVal <='Z'){
            alpha_array[ch-'A'].amount += 1; //increments amount
        }
    }

    //prints out each character
    for (int i = 0; i <26; i++){
        printf("The variable %c occurred %d times.\n", alpha_array[i].c, alpha_array[i].amount);
    }
}