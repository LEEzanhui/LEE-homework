# 贪吃蛇实验报告

贪吃蛇主要由地图、蛇头、蛇身、食物组成。  
```
...
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

int foodX, foodY; 
int snakeBodyLength = 5;	//初始长度为5 
int noFood = 1;		//初始无食物 

int main(){
	char control;
	int	snakeHeadX = 1, snakeHeadY = 6;		//确定初始蛇头位置 
	int snakeBodyX[100], snakeBodyY[100];
...
```
先考虑地图，简单打印即可，每次循环均更新一次  
```
	Body(snakeBodyX, snakeBodyY);		//初始化蛇身 
	printMap(snakeHeadX, snakeHeadY);	//初始化地图 
...
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
```
蛇头，根据玩家的指令移动，并引导后续蛇身的移动，并检测是否吃到食物，如果吃到食物，蛇身增长，原始蛇身不动；否则蛇身移动    
蛇身，位置保存在数组中，每次打印地图前将蛇身保存在地图字符数组的相应位置，每次打印地图后清除地图中的蛇身，并根据蛇头的状态考虑移动或增长
  
详情可看[snake_eat.c](snake_eat.c)  

食物，通过随机数生成，每当被吃掉，生成新的食物（注意，食物位置要避开蛇身、蛇头）  
```
void spawnFood(void){	//rand()生成的数是很大的 
	foodX = rand() % 10 + 1;
	foodY = rand() % 10 + 1;
	
	while(map[foodX][foodY] != ' '){	//防止食物与各种东西重叠 
		foodX = rand() % 10 + 1;
		foodY = rand() % 10 + 1;
	}
	
	map[foodX][foodY] = '$';	//食物 
}
```  