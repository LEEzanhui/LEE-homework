#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<windows.h>		//用于Sleep（） 

void printMap(int snakeHeadX, int snakeHeadY);	//打印地图 
void Body(int *snakeBodyX, int *snakeBodyY);	//在地图中描绘蛇身 
void spawnFood(void);	//随机食物
char aiInput(int snakeHeadX, int snakeHeadY); 	//自己动
int isSelfEat(void);	//判断是否吃自己 

char map[12][13] = {	//编辑地图 （以*为墙，可有复杂地形） 
	"************",
	"*          *",
	"*          *",
	"*          *",
	"*         **",
	"*    *     *",
	"*    *     *",
	"*          *",
	"*          *",
	"*          *",
	"*   *      *",
	"************", 
};

int foodX, foodY; 
int snakeBodyLength = 2;	//初始长度 
int noFood = 1;		//初始无食物 
int	snakeHeadX = 1, snakeHeadY = 3;		//确定初始蛇头位置 
int snakeBodyX[100], snakeBodyY[100];

int main(){
	char control;
	int i, selfEat;
	int midX, midY;
	
	srand( time(NULL) );	//初始化随机数种子,利用计算机时间 
	
	for(i = 0; i<snakeBodyLength; i++){		//确定初始蛇身位置 
		snakeBodyX[i] = 1;
		snakeBodyY[i] = i+1;
	}
		
	Body(snakeBodyX, snakeBodyY);		//初始化蛇身 
	printMap(snakeHeadX, snakeHeadY);	//初始化地图 
	
	control = aiInput(snakeHeadX, snakeHeadY);	 //自动吃
	
	for(; ; ){
		map[snakeHeadX][snakeHeadY] = ' ';		//清除原有蛇头 
		for(i = 0; i<snakeBodyLength; i++){		//清除原有蛇身 
			map[snakeBodyX[i]][snakeBodyY[i]] = ' ';
		}
		midX = snakeHeadX;
		midY = snakeHeadY;

//		scanf(" %c", &control);		//人工操作蛇 （需要回车来输入指令） 
		 
		
		switch(control){	//操作 
			case 'a':snakeHeadY--;
				if(isSelfEat() == 1){	//玩家玩需注释掉 
					snakeHeadY++;
					control = 'w';
					continue;
				}						// 
				break;
			case 's':snakeHeadX++;
				if(isSelfEat() == 1){	// 
					snakeHeadX--;
					control = 'a';
					continue;
				}						// 
				break;
			case 'w':snakeHeadX--;
				if(isSelfEat() == 1){	// 
					snakeHeadX++;
					control = 'd';
					continue;
				}						// 
				break;
			case 'd':snakeHeadY++;
				if(isSelfEat() == 1){	// 
					snakeHeadY--;
					control = 's';
					continue;
				}						// 
				break;
		}
		
		control = aiInput(snakeHeadX, snakeHeadY);	 //自动吃
		
		if(map[snakeHeadX][snakeHeadY] == '*'){	//检查是否撞到围栏 
			system("cls");
			printf("你头这么铁?\nGame over!!!");
			return 0;
		}
		else if(map[snakeHeadX][snakeHeadY] == '$'){    //吃食物，蛇身增长
			snakeBodyX[snakeBodyLength] = midX;
			snakeBodyY[snakeBodyLength] = midY;
			snakeBodyLength++;
			
			noFood = 1;
			
			Body(snakeBodyX, snakeBodyY);
			
			printMap(snakeHeadX, snakeHeadY);
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
		
		selfEat = isSelfEat();
		
		if(selfEat == 1){		//撞到自己游戏结束 

			printf("你虽然肉多，但也不能吃自己啊\nGame over!!!");
			return 0;
		}
		
		Sleep(250); 	//运行停止  毫秒，方便观察 
	}
	
	return 0;
}

void printMap(int snakeHeadX, int snakeHeadY){
	int i;
	
	system("cls");	//清屏 
	map[snakeHeadX][snakeHeadY] = 'H';	//蛇头 
	
	if(noFood == 1){	//如果地图上无食物，则生成食物 
		spawnFood();
		noFood = 0; 
	}

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

void spawnFood(void){	//rand()生成的数是很大的 
	foodX = rand() % 10 + 1;
	foodY = rand() % 10 + 1;
	
	while(map[foodX][foodY] != ' '){	//防止食物与各种东西重叠 
		foodX = rand() % 10 + 1;
		foodY = rand() % 10 + 1;
	}
	
	map[foodX][foodY] = '$';	//食物 
}

char aiInput(int snakeHeadX, int snakeHeadY){
	if(abs(snakeHeadX-foodX) > abs(snakeHeadY-foodY)){
		if(snakeHeadX-foodX > 0){
			return 'w';
		}
		else{
			return 's';
		}
	}
	else{
		if(snakeHeadY-foodY > 0){
			return 'a';
		}
		else{
			return 'd';
		}
	}
}

int isSelfEat(void){
	int i, selfEat;
	
	for(selfEat = 0, i = 0; i<snakeBodyLength; i++){					//检查是否撞到自己 
		if(snakeHeadX == snakeBodyX[i] && snakeHeadY == snakeBodyY[i]){
				selfEat = 1;
		}
	}
	
	return selfEat;
}