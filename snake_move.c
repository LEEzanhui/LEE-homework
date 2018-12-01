#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

void printMap(int snakeHeadX, int snakeHeadY);	//打印地图 
void Body(int *snakeBodyX, int *snakeBodyY);	//在地图中描绘蛇身 

char map[12][13] = {	//编辑地图 
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

int main(){
	char control;
	int	snakeHeadX = 1, snakeHeadY = 6, snakeBodyLength = 5;
	int snakeBodyX[snakeBodyLength], snakeBodyY[snakeBodyLength];
	int i, selfEat;
	int midX, midY;
	
	for(i = 0; i<snakeBodyLength; i++){		//确定初始蛇身位置 
		snakeBodyX[i] = 1;
		snakeBodyY[i] = i+1;
	}
		
	Body(snakeBodyX, snakeBodyY);		//初始化蛇身 
	printMap(snakeHeadX, snakeHeadY);	//初始化地图 
	
	for(; ; ){
		map[snakeHeadX][snakeHeadY] = ' ';		//清除原有蛇头 
		for(i = 0; i<snakeBodyLength; i++){		//清除原有蛇身 
			map[snakeBodyX[i]][snakeBodyY[i]] = ' ';
		}
		midX = snakeHeadX;
		midY = snakeHeadY;

		scanf(" %c", &control);
		
		switch(control){	//操作 
			case 'a':snakeHeadY--;
				break;
			case 's':snakeHeadX++;
				break;
			case 'w':snakeHeadX--;
				break;
			case 'd':snakeHeadY++;
				break;
		}
		
		
		if(snakeHeadX == 0 || snakeHeadX == 11 || snakeHeadY == 0 || snakeHeadY == 11){	//检查是否撞到围栏 
			system("cls");
			printf("你头这么铁?\nGame over!!!");
			return 0;
		} 
		else{
			
			for(i = 0; i<snakeBodyLength-1; ++i){	//使蛇身随蛇头移动 

				snakeBodyX[i] = snakeBodyX[i+1];
				snakeBodyY[i] = snakeBodyY[i+1];
			}
			
			snakeBodyX[i] = midX;
			snakeBodyY[i] = midY;
			
			Body(snakeBodyX, snakeBodyY);
	
			printMap(snakeHeadX, snakeHeadY);
					
		}
		
		for(selfEat = 0, i = 0; i<snakeBodyLength; i++){					//检查是否撞到自己 
			if(snakeHeadX == snakeBodyX[i] && snakeHeadY == snakeBodyY[i]){
				selfEat = 1;
			}
		}
		
		if(selfEat == 1){		//撞到自己游戏结束 

			printf("你虽然肉多，但也不能吃自己啊\nGame over!!!");
			return 0;
		}
	}
	
	return 0;
}

void printMap(int snakeHeadX, int snakeHeadY){
	int i;
	
	system("cls");	//清屏 
	map[snakeHeadX][snakeHeadY] = 'H';	//蛇头 
	
	
	for(i = 0; i<12 ; ++i){		//打印地图 
		printf("%s\n", map[i]);
	}
}

void Body(int *snakeBodyX, int *snakeBodyY){
	
	int i;
	
	for(i = 0; i<snakeBodyLength; i++){
		map[ snakeBodyX[i] ][ snakeBodyY[i] ] = 'X';	//描绘蛇身位置 
	}
}