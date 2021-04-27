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
        init(board);
        result = game(board);
        show(board);
        scoreboard(result, player1, player2);

        cout<<"\n Outra partida?"<<endl;
        cout<<"0. Sair" <<endl;
        cout<<"1. Jogar de novo"<<endl;
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
    cout<<endl;
    for(int row=0; row<3; row++){
        cout<<"  "<<printBlock(board[row][0])<< " |";
        cout<<"  "<<printBlock(board[row][1])<< " |";
        cout<<"  "<<printBlock(board[row][2])<< endl;

        if(row!=2){
            cout<<" ___ ____ ___\n"<<endl;
        }
    }
}

void playMove(int board[][3], int player)
{
    int row, col, check;
    do{
        cout<<"Linha: ";
        cin >>row;
        cout<<"Coluna: ";
        cin>>col;
        row--;
        col--;

        check = board[row][col] || row<0 || row>2 || col<0 || col>2;
        if(check)
            cout<< "Essa casa não esta vazia o fora do interval o 3x3"<<endl;
    } while(check);
        if(player==0)
            board[row][col]=1;
        else
            board[row][col]=-1;
}
int checkContinue(int board[][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3;j++)
            if(board[i][j]==0)
                return 1;
    return 0;
}

int checkWin(int board[][3])
{
    int row, col, sum;

    // vamos adicionar linhas

    for(row=0; row<3; row++){
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
            sum+=board[row][col];
         if(sum==3)
            return 1;
         if(sum==-3)
            return -1;
    }
    // adicionando as diagonais

    sum=0;
    for(row=0; row<3; row++)
        sum+=board[row][row];
    if(sum==3)
        return 1;
    if(sum==-3)
        return -1;
    sum=board[0][2]+board[1][1]+board[2][0];
    if(sum==3)
        return 1;
    if(sum==-3)
        return -1;
    return 0;
}


int game(int board[][3])
{
    int turn=0, cont, win;

    do {

        show(board);
        cout<<"Jogador "<<1+turn%2<<endl;
        playMove(board,turn%2);
        turn++;

        cont=checkContinue(board);
        win=checkWin(board);
    } while(cont&&!win);

    if(win==1){
        cout<<"Jogador 1 ganhou!\n"<<endl;
        return 1;
    } else
        if(win==-1){
            cout<<"Jogador 2 ganhou!\n"<<endl;
            return 2;

        } else
        cout<<"Empate\n"<<endl;
        return 0;
}
void scoreboard(int result, int &player1, int &player2)
{
    if(result==1)
        player1++;
    if(result==2)
        player2++;

    cout<<"Placar: "<<endl;
    cout<<player1<<" X "<< player2<<endl;
}
