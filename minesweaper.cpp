#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector< vector<char> > BOARD(int row, int col, int x, int y){
	string s;
	vector< vector<char> > RealBoard(row);
	int n=0;
	
	while(1){
		getline(cin, s);
		
		if(n==0){
			getline(cin, s);
		}
		for(int i= 0; i<col; i++){
			RealBoard[n].push_back(s[i]);
		}
		
		n= n+1;
		
		if(n==row){
			
			break;
		}

	}
	return RealBoard;
}


void printBoard(vector< vector<char> >board,int row,int col){
	for(int i=0; i<row; i++){
		if(i!= 0){
			cout<<endl;
		}
		for(int j=0; j<col; j++){
			cout<<board[i][j];
		}
	} 
	cout<<endl;
	return;
	
}

// A Utility Function to check whether given cell (row, col) 
// is a valid cell or not 
int isValid(int x, int y, int row, int col) { 
    // Returns true if row number and column number 
    // is in range 
    return (x> 0) && (x <= col) && 
           (y> 0) && (y <= row); 
}

// A Utility Function to check whether given cell (row, col) 
// has a mine or not. 
int isMine (int x, int y, vector< vector<char> > board) 
{ 
    if (board[y-1][x-1] == 'M') 
        return 1; 
    else
        return 0; 
}  


// A Function to count the number of 
// mines in the adjacent cells 
int countAdjacentMines(int x, int y,int r, int c, vector< vector<char> > board){ 
  
    int i; 
    int count = 0; 
 
  
    //----------- 1st Neighbour (North) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x-1, y, r, c) == 1) 
        { 
               if (isMine (x-1, y, board) == 1) 
               count++; 
        } 
  
    //----------- 2nd Neighbour (South) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x+1, y, r, c) == 1) 
        { 
               if (isMine (x+1, y, board) == 1) 
               count++; 
        } 
  
    //----------- 3rd Neighbour (East) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x, y+1, r, c) == 1) 
        { 
            if (isMine (x, y+1, board) == 1) 
               count++; 
        } 
  
    //----------- 4th Neighbour (West) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x, y-1, r, c) == 1) 
        { 
               if (isMine (x, y-1, board) == 1) 
               count++; 
        } 
  
    //----------- 5th Neighbour (North-East) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x-1, y+1, r, c) == 1) 
        { 
            if (isMine (x-1, y+1, board) == 1) 
               count++; 
        } 
  
     //----------- 6th Neighbour (North-West) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x-1, y-1, r, c) == 1) 
        { 
             if (isMine (x-1, y-1, board) == 1) 
               count++; 
        } 
  
     //----------- 7th Neighbour (South-East) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x+1, y+1, r, c) == 1) 
        { 
               if (isMine (x+1, y+1, board) == 1) 
               count++; 
        } 
  
    //----------- 8th Neighbour (South-West) ------------ 
  
        // Only process this cell if this is a valid one 
        if (isValid (x+1, y-1, r, c) == 1) 
        { 
            if (isMine (x+1, y-1, board) == 1) 
               count++; 
        } 
  
    return count; 
} 





void MineSweep(int x, int y, int r, int c, vector< vector<char> >board, vector< vector<char> >&Output_Board){
	int MineSelected= 0;
	int count= 0;
	int ValidSelected= isValid(x, y, r, c);
		// Base Case of Recursion 
	if (Output_Board[y-1][x-1] != '*'){ 
		return;
	} 
	if(ValidSelected== 1){
		MineSelected= isMine(x, y, board);
		if(MineSelected== 0){
			count= countAdjacentMines(x, y, r, c, board);
		}	
	}
	if(ValidSelected== 0){

		return;
	}
	if(MineSelected== 1){
		for(int i=0; i<r; i++){
			for(int j= 0; j<c; j++){
				if(board[i][j]== 'M'){
					Output_Board[i][j]= 'M';
				}
			}
		}
	
		return;
	}
	
	if(count!=0){
		Output_Board[y-1][x-1]= count+'0';
		return;
	}
	else{
		Output_Board[y-1][x-1]= '0'+count;
		if(isValid(x-1, y, r, c)== 1){
			if(isMine(x-1, y, board)== 0){
				MineSweep(x-1, y, r, c, board, Output_Board);
			}
		}

		if(isValid(x, y-1, r, c)== 1){
			if(isMine(x, y-1, board)== 0){
				//Output_Board[y-2][x]= '0';
				MineSweep(x, y-1, r, c, board, Output_Board);
			}
		}
		if(isValid(x-1, y-1, r, c)== 1){
			if(isMine(x-1, y-1, board)== 0){
				MineSweep(x-1, y-1, r, c, board, Output_Board);
			}
		}
		if(isValid(x+1, y, r, c)== 1){
			if(isMine(x+1, y, board)== 0){
				
				MineSweep(x+1, y, r, c, board, Output_Board);

			}
		}
		if(isValid(x+1, y+1, r, c)== 1){
			if(isMine(x+1, y+1, board)== 0){
				MineSweep(x+1, y+1, r, c, board, Output_Board);
			}
		}
		if(isValid(x-1, y+1, r, c)== 1){
			
			if(isMine(x-1, y+1, board)== 0){
				
				MineSweep(x-1, y+1, r, c, board, Output_Board);
				
				
			}
		}
		if(isValid(x+1, y-1, r, c)== 1){
		
			if(isMine(x+1, y-1, board)== 0){
				//Output_Board[y-2][x]= '0';
				MineSweep(x+1, y-1, r, c, board, Output_Board);
				
				
			}
		}
		if(isValid(x, y+1, r, c)== 1){
			
			if(isMine(x, y+1, board)== 0){
				//Output_Board[y][x-1]= '0';
				MineSweep(x, y+1, r, c, board, Output_Board);

			
			}
		}
		return;



	}


}




	
int main(){
	int temp;
	string s;
	vector<int> Row_Col_X_Y;
	int i= 0;
	//Getting first line of input:row, coloumn, x, y:
	while(cin>> temp){
		i= i+1;
		Row_Col_X_Y.push_back(temp);
		if(Row_Col_X_Y.size()== 4){
			
			break;
		}
	}
	int r= Row_Col_X_Y[0];
	int c= Row_Col_X_Y[1];
	int x= Row_Col_X_Y[2];
	int y= Row_Col_X_Y[3];

	vector< vector<char> > Input_Board(r);
	Input_Board= BOARD(r, c, x, y);
	vector< vector<char> > Output_Board(r, vector<char>(c, '*'));
	
	MineSweep(x, y,  r, c, Input_Board,Output_Board);
	printBoard(Output_Board,r, c);
}