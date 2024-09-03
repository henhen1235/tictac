/*
Henry Xu
8/29/2024
Palindrome code.
*/
#include <iostream>
#include <string.h>
#include <cctype>


using namespace std;


int main() {//init varriables
    char input[81];
    char newinput[81];
    char flipped[81];
    int position = 0;


    cout << "Enter what you want to check (max 80 characters): " << endl;//prompt user for the word they want to check and put it into inputs
    cin.get(input, 81);


    for (int x = 0; x < strlen(input); x++) {//get rid of everything that isn't a letter or number
        if (isalnum(input[x])) {
            newinput[position] = tolower(input[x]);//lower case everything
            position++;
        }
    }
    newinput[position] = '\0';//add the weird thing to the end of the cstring so the code knows when the string stops


    for (int x = 0; x < strlen(newinput); x++) { // take the word they want to check and flip it
        flipped[strlen(newinput) - 1 - x] = newinput[x];
    }
    flipped[position] = '\0';


    // Output the result
    if (strcmp(newinput, flipped) == 0) {//compare the two words
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }


    return 0;
}


