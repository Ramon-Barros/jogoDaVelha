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

