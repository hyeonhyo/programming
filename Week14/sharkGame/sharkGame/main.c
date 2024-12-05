//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}
// ----- EX. 5 : shark ------------


// ----- EX. 6 : game end ------------


int getAlivePlayer(void)
{
   int i;
   int cnt = 0;
   for (i=0; i<N_PLAYER;i++)
   {
   	if (player_status[i] == PLAYERSTATUS_END)
   	cnt++;
	} 
	return cnt;
}

int getWinner(void)
{
    int i;
    int winner=0;
    int max_coin = -1;
    
    for (i=0; i<N_PLAYER; i++)
    {    // 살아있는 player를 찾고 그 중에서 코인이 가장 많은 사람  2024.12.4
    	if (player_status[i] == PLAYERSTATUS_LIVE && player_coin[i] >max_coin)
    	{
    		max_coin = player_coin[i];
    		winner = i;
		}
	}
}
// ----- EX. 6 : game end ------------


int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;
    int pos =0; // 위치 변수 선언 

// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER;
            continue;
        }
// ----- EX. 4 : player ------------
       
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
// ----- EX. 4 : player ------------
        dieResult = rolldie();
        
        
        //step 2-3. moving
        pos = player_position[turn] + dieResult;// 이동횟수만큼 pos 변경 
        if (pos >= N_BOARD) pos = N_BOARD - 1;//(N_BOARD 이상 갔을 떄 ) 
		 
        player_position[turn] = pos;
		printf("%s position: %d", player_name[turn], player_position[turn]);//이동 결과 출력  
        
        //step 2-4. coin
        int getcoin = board_getBoardCoin(pos);//이동한 위치에서 호출 
        player_coin[turn] += getcoin; // coin 습득 
		//coin이 존재하는 경우 coin 습득 정보를 출력 
		if (getcoin>0)
		printf("%s : + %d coin", player_name[turn], getcoin);
		else
		printf("%s : no coin", player_name[turn]);
	
       
        //step 2-5. end process
        if (player_position[turn] >= N_BOARD - 1)//보드 맨 끝까지 이동한 경우에 대한 처리
    	player_position[turn] = N_BOARD - 1;
    	player_status[turn] = PLAYERSTATUS_END;
    
        turn = (turn + 1) % N_PLAYER;
		if (turn == 0) { 
		int shark_pos = board_stepShark();   
		printf("Shark moved to %i\n", shark_pos);
		checkDie();         
    }
    
// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    
    //step 3. game end process
    printf("GAME END!!\n");
    printf("%i players are alive! winner is %s\n", getAlivePlayer(), player_name[getWinner()]);
// ----- EX. 6 : game end ------------

// ----- EX. 2 : structuring ------------

    return 0;
}
