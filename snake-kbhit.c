#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h> 

static struct termios ori_attr, cur_attr;

static __inline 
int tty_reset(void)
{
        if (tcsetattr(STDIN_FILENO, TCSANOW, &ori_attr) != 0)
                return -1;

        return 0;
}


static __inline
int tty_set(void)
{
        
        if ( tcgetattr(STDIN_FILENO, &ori_attr) )
                return -1;
        
        memcpy(&cur_attr, &ori_attr, sizeof(cur_attr) );
        cur_attr.c_lflag &= ~ICANON;

        cur_attr.c_lflag &= ~ECHO;
        cur_attr.c_cc[VMIN] = 1;
        cur_attr.c_cc[VTIME] = 0;

        if (tcsetattr(STDIN_FILENO, TCSANOW, &cur_attr) != 0)
                return -1;

        return 0;
}

static __inline
int kbhit(void) 
{
                   
        fd_set rfds;
        struct timeval tv;
        int retval;

        FD_ZERO(&rfds);
        FD_SET(0, &rfds);

        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        retval = select(1, &rfds, NULL, NULL, &tv);


        if (retval == -1) {
                perror("select()");
                return 0;
        } else if (retval)
                return 1;

        else
                return 0;
        return 0;
}

void printMap(int snakeHeadX, int snakeHeadY);
void Body(int *snakeBodyX, int *snakeBodyY);
void spawnFood(void);

char map[12][13] = {
	"************",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************", 
};

int foodX, foodY; 
int snakeBodyLength = 5;
int noFood = 1;		

int main()
{

        int tty_set_flag;
        tty_set_flag = tty_set();
		
	char control;
	int	snakeHeadX = 1, snakeHeadY = 6;	
	int snakeBodyX[100], snakeBodyY[100];
	int i, selfEat;
	int midX, midY;
	
	srand( time(NULL) );
	
	for(i = 0; i<snakeBodyLength; i++){
		snakeBodyX[i] = 1;
		snakeBodyY[i] = i+1;
	}
		
	Body(snakeBodyX, snakeBodyY);
	printMap(snakeHeadX, snakeHeadY);
	
	for(; ; ){
		map[snakeHeadX][snakeHeadY] = ' ';
		for(i = 0; i<snakeBodyLength; i++){
			map[snakeBodyX[i]][snakeBodyY[i]] = ' ';
		}
		midX = snakeHeadX;
		midY = snakeHeadY;

		scanf(" %c", &control);
		
		switch(control){
			case 'a':snakeHeadY--;
				break;
			case 's':snakeHeadX++;
				break;
			case 'w':snakeHeadX--;
				break;
			case 'd':snakeHeadY++;
				break;
		}
		
		
		if(snakeHeadX == 0 || snakeHeadX == 11 || snakeHeadY == 0 || snakeHeadY == 11){ 
			system("cls");
			printf("你头这么铁?\nGame over!!!");
			return 0;
		}
		else if(map[snakeHeadX][snakeHeadY] == '$'){
			snakeBodyX[snakeBodyLength] = midX;
			snakeBodyY[snakeBodyLength] = midY;
			snakeBodyLength++;
			
			noFood = 1;
			
			Body(snakeBodyX, snakeBodyY);
			
			printMap(snakeHeadX, snakeHeadY);
		}
		else{
			
			for(i = 0; i<snakeBodyLength-1; ++i){

				snakeBodyX[i] = snakeBodyX[i+1];
				snakeBodyY[i] = snakeBodyY[i+1];
			}
			
			snakeBodyX[i] = midX;
			snakeBodyY[i] = midY;
			
			Body(snakeBodyX, snakeBodyY);
	
			printMap(snakeHeadX, snakeHeadY);
					
		}
		
		for(selfEat = 0, i = 0; i<snakeBodyLength; i++){
			if(snakeHeadX == snakeBodyX[i] && snakeHeadY == snakeBodyY[i]){
				selfEat = 1;
			}
		}
		
		if(selfEat == 1){

			printf("你虽然肉多，但也不能吃自己啊\nGame over!!!");
			return 0;
		}
	}
		
        printf("pressed `q` to quit!\n");
        while(1) {

                if( kbhit() ) {
                        const int key = getchar();
                        printf("%c pressed\n", key);
                        if(key == 'q')
                                break;
                } else {
                       ;
                }
        }


        if(tty_set_flag == 0) 
                tty_reset();
        return 0;
}

void printMap(int snakeHeadX, int snakeHeadY){
	int i;
	
	printf("\033[2J");
	map[snakeHeadX][snakeHeadY] = 'H';
	
	if(noFood == 1){
		spawnFood();
		noFood = 0; 
	}

	for(i = 0; i<12 ; ++i){
		printf("%s\n", map[i]);
	}
}

void Body(int *snakeBodyX, int *snakeBodyY){
	
	int i;
	
	for(i = 0; i<snakeBodyLength; i++){
		map[ snakeBodyX[i] ][ snakeBodyY[i] ] = 'X';
	}
}

void spawnFood(void){
	foodX = rand() % 10 + 1;
	foodY = rand() % 10 + 1;
	
	while(map[foodX][foodY] != ' '){
		foodX = rand() % 10 + 1;
		foodY = rand() % 10 + 1;
	}
	
	map[foodX][foodY] = '$';
}