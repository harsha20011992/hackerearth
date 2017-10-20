#include <iostream>
using namespace std;
int n;
void printSolution(int **board)
{
    //static  int k = 1;
    //printf("%d-\n",k++);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
bool isAttackingPosition(int **board,int n,int i,int j){
    int row;
    int col;
    /* Check this column on top side */
    for (row = 0; row < i; row++){
        if (board[row][j]){
            return true;
        }
    }
    /* Check upper diagonal on left side */
    for (row=i, col=j; row>=0 && col>=0; row--, col--){
        if (board[row][col]){
            return true;
        }
            
    }
    /* Check upper diagonal on right  side */
    for (row=i, col=j; row>=0 && col<n; row--, col++){
        if (board[row][col]){
            return true;
        }
    }
    return false;
}

bool NQueenGen(int **board,int n,int row){
    if(row == n){
        return true;
    }else{
            int i=row;
            for(int j=0;j<n;j++){
                if(!isAttackingPosition(board,n,i,j)){
                    board[i][j] = 1;
                    if(NQueenGen(board,n,row+1)){
                        return true;
                    }else{
                        board[i][j] = 0; 
                    }            
                }
                
            }
        
        return false;
    }
}

int main()
{
    cin >> n;
    //int board = new int[n][n];
    //int **board;
     int r = n, c = n;
    int **board = (int **)malloc(r * sizeof(int *));
    for (int i=0; i<r; i++)
         board[i] = (int *)malloc(c * sizeof(int));
         
         
     for (int i = 0; i <  r; i++)
      for (int j = 0; j < c; j++)
         board[i][j] = 0;
         
    if(NQueenGen(board,n,0)){
        cout<< "YES" << "\n";
        printSolution(board);
    }else{
        cout<<"NO"<<"\n";
    }
}
/**
N Queens sum
**/
