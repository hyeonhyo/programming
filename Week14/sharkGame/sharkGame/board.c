//
//  board.c
//  sharkGame
//

#include "board.h"

// ----- EX. 3 : board ------------
#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    //coin assign
     for (i = 0; i < N_COINPOS; i++)
    {
        
        while (board_coin[i] == 0)  
        {
            int coin_pos = rand() % N_BOARD; // random coin position 
            {
                // 동전을 놓을 칸을 랜덤으로 지정; 
                if (board_coin[coin_pos]==0) // 칸에 동전이 이미 있지 않으면
				//i번째 coin 할당 
                board_coin[coin_pos] = rand() % MAX_COIN + 1;  
                
            }
        }
    }
    
// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation
   
    
    return N_COINPOS;
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void)
{
	int board_step = rand() % MAX_SHARKSTEP +1;
	int i; 
	//1~MAX_SHARKSTEP 칸 랜덤 이동 
	
	for (i =SHARK_INITPOS+1; i<= shark_position + board_step;i++)
	{
		if (i>=0 && i<N_BOARD)
		board_status[i] = BOARDSTATUS_NOK;
	}// 이동 경로 칸=BOARDSTATUS_NOK 
	
	shark_position += board_step; //값 갱신 
	
	
}
// ----- EX. 5 : shark ------------


// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------

