#include<stdio.h>
char board[]={'0','1','2','3','4','5','6','7','8','9'};

void printBoard(){//making a board
system("cls");

    printf("\n\n");
    printf("  ****** TIC TAC TOE *******   \n");
    printf("        |           |          \n");
    printf("    %c   |     %c     |    %c    \n",board[1],board[2],board[3]);
    printf("________|___________|__________\n");
    printf("        |           |          \n");
    printf("    %c   |     %c     |    %c    \n",board[4],board[5],board[6]);
    printf("________|___________|__________\n");
    printf("        |           |          \n");
    printf("    %c   |     %c     |    %c    \n",board[7],board[8],board[9]);
    printf("        |           |          \n");
    printf("\n\n");

}

int checkWin(){
        if(board[1]==board[2] && board[2]==board[3]){
            return 1;
        }else if(board[4]==board[5] && board[5]==board[6]){
            return 1;
        }else if(board[7]==board[8] && board[8]==board[9]){
            return 1;
        }else if(board[1]==board[4] && board[4]==board[7]){
            return 1;
        }else if(board[2]==board[5] && board[5]==board[8]){
            return 1;
        }else if(board[3]==board[6] && board[6]==board[9]){
            return 1;
        }else if(board[1]==board[5] && board[5]==board[9]){
            return 1;
        }else if(board[3]==board[5] && board[5]==board[7]){
            return 1;
        }else{
            int i,count=0;
            for(i=1;i<=9;i++){
                if(board[i]=='X' || board[i]=='O'){
                    count++;
                }
            }
            if(count==9){
                return 0;
            }
        return -1;
    }

}
int main(){
    int input=0,status=-1;
int player=1;                       //creating a player

printBoard();


while( status==-1){                 //until somone wins

player=(player%2==0)?2:1;           //either player 1 or 2

char mark=(player==1)?'X':'O';//player 1 mark is always X 

printf("Please Enter number for player %d: ",player);
scanf("%d",&input);
if(input<1 || input>9){
    printf("INVALID INPUT");
}else{
    board[input]=mark;
    int result=checkWin();
    if(result==1){
        printBoard();
        printf("CONGRATULATIONS!! Player %d is the WINNER!\n\n",player);
        return;
    }else if(result==0){
        printBoard();
        printf("THE MATCH IS DRAW~~\n\n");
        return ;
    }
}
player++;
printBoard();
}

    return 0;
}