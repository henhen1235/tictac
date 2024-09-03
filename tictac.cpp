#include <iostream>
/*
Henry Xu
9/2/24
Tictacttoe game!
*/


using namespace std;//init varriables
char spot[2];
char board[3][3];
void printb();
int player = 1;
bool valid = false;
void checkvalid(int row, int column, int player);
bool checkwin();
bool checktie();
bool tiecheck = false;
bool wincheck = false;
int player1 = 0;
int player2 = 0;


int main(){
  for (int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      board[x][y] = '_';
    }
  }
    while(true){
      printb();//call function to print board
    cout << "Player " << player <<" turn" << endl; // tell user whos turn it is
    cout << "Where would you like to move? Please put in the row(letters) first, the the column(numbers) second. Example:a1" << endl; //explain how to input
    while (valid == false){//while their input isn't valid
        cin >> spot;
        int row = int(spot[0] - 'a');//get position
        int column = int(spot[1] - '1');
        checkvalid(row, column, player);//call the check valid function
    }
    tiecheck = checktie();//call the check tie function
    wincheck = checkwin();//call the check win function
    if(player == 1) {player = 2;} //if it us player 1 turn make it player 2 and vice versa
    else {player = 1;}
    if (tiecheck == true){// if it was a tie
        cout <<"Player 1 points: " << player2 << endl << "Player 2 points: " << player1 << endl;//print out the points FYI the player points are swapped cause we just swapped the players in the code above
        for(int row = 0; row < 3; row++) {// clear board
            for(int column = 0; column < 3; column++) {
                board[row][column] = '_';}
        }
        player = 1;//set player to 1
	cout << "YOU TIE" << endl;
        wincheck = false;//set wincheck to false
    }
    if (wincheck == true){// if win is true
        if (player == 1){
            player1++;
	    cout << "Player 2 wins" << endl;
	}//add points for right player
        if (player == 2){
            player2++;
	    cout << "Player 1 wins" << endl;
	}
        cout <<"Player 1 points: " << player2 << endl << "Player 2 points: " << player1 << endl;// print out points
        for(int row = 0; row < 3; row++) {
             for(int column = 0; column < 3; column++) {
                board[row][column] = '_';}//clear board
        }
        player = 1;//set player to 1
    }
    valid = false;   //set valid to false to find new position
    }
    return 0;
}
    


void printb(){//function for printing board
    cout << "\t 1\t 2\t 3" << endl;//print colunbs
    for (int row = 0; row < 3; row++) {
        cout << static_cast<char>('a' + row);//print rows
        for (int col = 0; col < 3; col++) {
            if (board[col][row] == '_') {
                cout << " \t";//print a blank
            }
            else if (board[col][row] == '1') {
                cout << " \t X";//print a X
            }
            else if (board[col][row] == '2') {
                cout << " \t O";// print a O
            }
        }
        cout << endl;
    }
}


void checkvalid(int row, int column, int player){//check if spot is valid
    if (row == 2 || row == 0 || row == 1){//if row and column are within boundaries
        if (column == 2 || column == 0 || column ==1){
            if (board[column][row] == '_'){//if spot if empty
                if (player == 1){
                    board[column][row] = '1';//set spot as yours
                    valid = true;
                }
                if (player ==2) {
                    board[column][row] = '2';
                    valid = true;
                }
            }
            else{
                cout << "spot invalid" << endl;//else output spot invalid
            }
        }
        else{
            cout << "spot invalid" << endl;
        }  
    }
    else{
        cout << "spot invalid" << endl;
    }  
}


bool checkwin(){//go through all the options to win
    if(board[0][0] == '1' && board[0][1] == '1' && board[0][2] == '1' ||
    board[0][0] == '1' && board[1][1] == '1' && board[2][2] == '1' ||
    board[0][0] == '1' && board[1][0] == '1' && board[2][0] == '1' ||
    board[1][0] == '1' && board[1][1] == '1' && board[1][2] == '1' ||
    board[2][0] == '1' && board[2][1] == '1' && board[2][2] == '1' ||
    board[0][1] == '1' && board[1][1] == '1' && board[2][1] == '1' ||
    board[0][2] == '1' && board[1][2] == '1' && board[2][2] == '1' ||
    board[2][0] == '1' && board[1][1] == '1' && board[0][2] == '1' ||
    board[0][0] == '2' && board[0][1] == '2' && board[0][2] == '2' ||
    board[0][0] == '2' && board[1][1] == '2' && board[2][2] == '2' ||
    board[0][0] == '2' && board[1][0] == '2' && board[2][0] == '2' ||
    board[1][0] == '2' && board[1][1] == '2' && board[1][2] == '2' ||
    board[2][0] == '2' && board[2][1] == '2' && board[2][2] == '2' ||
    board[0][1] == '2' && board[1][1] == '2' && board[2][1] == '2' ||
    board[0][2] == '2' && board[1][2] == '2' && board[2][2] == '2' ||
    board[2][0] == '2' && board[1][1] == '2' && board[0][2] == '2') {
        return true;//you win!
    }
    return false;//you don't win.
}


bool checktie() {
    for(int row = 0; row < 3; row++) {
        for(int column = 0; column < 3; column++) {
            if(board[row][column] == '_') {//if all any spots are null then output false
                return false;
            }
        }
    }
    return true; //if all spots are filled output true.
}



