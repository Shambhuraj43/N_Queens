//Shambhuraj Wadghule
//N Queens Assignment


#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

//defining N for the square matrix (chess board)
#define N 16

using namespace std;

//Prototype
bool nQueens(stack<int> rowS, stack<int> colS, bool chessBoard[N][N], int row, int col, int filled);
bool checkPlace(bool chessBoard[N][N], int row, int col);
void printPos(bool chessBoard[N][N], stack<int>, stack<int>);


int main() {


	//Decalaration
	int n, row,col,filled;

	stack <int> rowStack;
	stack <int> colStack;

	bool chessBoard[N][N] = {0}; 
	row = 0;
	col = 0;
	filled = 0;

	bool call;

	call = nQueens(rowStack,colStack,chessBoard,row,col,filled);


	//checking the value of the function nQueens and outputting accordingly
	if (call == true) {
		
		cout << "The positions for n Queens" << endl;

		printPos(chessBoard, rowStack, colStack);
	}
	else {
		
		cout << "The solution does not exists" << endl;
	}


	return 0;
}


//Function: Prints the chess board with specific positions of the n Queens
void printPos(bool chessBoard[N][N],stack<int> rowS, stack<int> colS) {

	/*int temp1 = rowS.top();
	int temp2 = colS.top();

		if (rowS.empty() && colS.empty())
			return;

	//poping temporarily
	rowS.pop();
	colS.pop();


	//calling recursively to print other elements
	printPos(chessBoard,rowS,colS);

	//printing 
	cout << temp1 << " " << temp2 <<" ";

	 //pushing that is adding elements again in the stacks
	rowS.push(temp1);
	colS.push(temp2);*/


	int row = 0;
	int col = 0;

	//prints the chess board using the boolean matrix 
	
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++)
			
			if (chessBoard[row][col] == true) {
				
				cout << "Q";
			}
			else {
				cout << "[]";
			}
			
		cout << endl;
	}


}


//Validates the position to put the queen and retuens false if the position can be attacked by the other queens
bool checkPlace(bool chessBoard[N][N], int row, int col)
{
	
	//Tried to extract the pushed position values in the stacks and store in an array for validation of the place
	//Couldn't extract. Getting the same error when tried printing the positions through stacks






	//checking the next possible position at which the other queen cannot attack the queen, starting with column
	int i, j;
	for ( i = row, j = col; j >= 0 && i < N; i++, j--) {
		if (chessBoard[i][j])
			return false;
	}

	for(i = row,  j = col; (i >= 0 && j >= 0); (i--, j--)){
	if (chessBoard[i][j])
		return false; }

	//for fixed row going across the chess board
	for (i = 0; i < col; i++) {
		if (chessBoard[row][i])
			return false;
	}

	return true;		//if found the next possible position
}


//Function: nQueens
//Ends the program if all the queens are properly positioned
//Calls itself recursively to move across columns to put the next queen at a proper position
//Backtracks and pops the position of queens until other possible scenario found
//This algorithm backtracks till the very first element in the stack to ensure that all the succeeding queens will be at validated position

bool nQueens(stack<int> rowS, stack<int> colS, bool chessBoard[N][N], int row, int col, int filled) {

	//if filled variable is more than N, it means the position for all the queens is already in the stacks 
	if (filled >= N) {
		
		cout << "The algorithm is complete!" << endl;
			//printPos(rowS,colS);
			return true;
	}

	//For every row on the chess board
	for (int i = 0; i < N; i++) {
		
		
		if (checkPlace(chessBoard, i, col)) {
			
			//Basically assign this positionto the queen
			chessBoard[i][col] = true;
			rowS.push(i); 
			colS.push(col);
			filled++;;

			//Calling recursively 
			if (nQueens(rowS, colS, chessBoard, row, col + 1, filled)) {
				return true;
			}

			
			//If the assigned position does not produce a solution, backtrack and change the position of previous queens
			chessBoard[i][col] = false; 
			rowS.pop();
			colS.pop();
			filled--;
		}
	}

	//If the loop ends here, that means there is no possible solution
	return false;
}








