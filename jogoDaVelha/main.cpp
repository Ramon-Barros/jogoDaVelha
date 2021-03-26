#include <iostream>

using namespace std;

void init(int board[][3]);                      // inicializando o quaddro
char printBlock(int bloco);                    // coloca as linhas do jogo
void show(int board[][3]);                    // mostra o jogo da velha
void playMove(int board[][3], int);          // joga um movimento
int  checkContinue(int *board[][3]);        // checa se tem algum espaço em branco
int checkWin(int *board[][3]);             // checa se tem um vencedor
int game(int board[][3]);                 // jogo começa
void scoreboard(int, int &, int &);      //exibe o placar do jogo



int main()
{
    int board[3][3];

    int cont=0, player1=0, player2=0, result;
    do{
        int(board);
        result =  game(board);
        show(board);
        scoreboard(result, player1, player2);

        count<<"\n Outra partida?"<<endl;
        count<<"0. Sair" <<endl;
        count<<"1. Jogar de novo"<<endl;
        cin>> cont;

    }while(cont);

    return 0;

}

void init(int board[][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3;j++)
            board[i][j]=0;
}

char printBlock(int block)
{
    if(block == 0)
        return ' ';
    else if(block == 1)
        return 'X';
    else
        return 'O';
}

void show(int board[][3])
{
    count<<endl;
    for(int row=0; row<3, row++){
        count<<" "<<printBlock(board[row][0])<< "|";
        count<<" "<<printBlock(board[row][1])<< "|";
        count<<" "<<printBlock(board[row][2])<< endl;

        if(row!=2){
            cout<<"____ _____ _____\n"<<endl;
        }
    }
}

void playMove(int board[][3], int player)
{
    int row, col, check;
    do{
        count<<"Linha: ";
        cin >>row;
        count<<"Coluna: ";
        cin>>col;
        row--;
        col--;

        check = board[row][col] || row<0 || row>2 || col<0 || col>2;
        if(check)
            count<< "Essa casa não esta vazia o fora do interval o 3x3"<<endl;
    } while(check)
        if(player==0)
            board[row][col]=1;
        else
            board[row][col]=-1;
}
int checkContinue(int board[][3])
{
    for(int i=0; i<3; i++)
        for(j=0; j<3;j++)
            if(board[i][j]==0)
                return 1;
    return 0;
}

int checkWin(int board[][3])
{
    int row, col, sum;

    // vamos adicionar linhas

    for(row=0; row<3; row++)
        sum=0;

        for(col=0; col<3; col++)
            sum += board[row][col];

        if(sum==3)
            return 1;
        if(sum==-3)
            return -1;

}
    // adicionar coluna

    for(col=0; col<3; col++){
        sum=0;
        for(row=0; row<3; row++)
            sum += board[row][col];
        if(sum==3)
            return 1;
        if(sum==-3)
            return -1;
    }
