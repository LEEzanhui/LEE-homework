# 游戏设计
## 游戏策划
游戏致敬Pacman，融合了迷宫的玩法。  
Pacman陷入了迷宫当中，而迷宫中还潜伏着它的对手ghosts，它能否逃出生天呢？  
其中，当然有Pacman的经典形象。  
![](https://www.scirra.com/images/articles/ChomperSprites.png)  
玩家的目标是在ghosts的追捕下，穿过迷宫到达终点。 
玩家通过八字方向键移动，尽力躲开ghosts、避免碰到墙壁。  
当碰到ghosts时,生命值减少，并受到一定时间的眩晕影响，而且碰到墙壁时也会受到眩晕影响。  
![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/%E6%8D%95%E8%8E%B7.PNG?raw=true)  
上图为游戏背景  
![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/3.gif?raw=true)  
上图为效果图  
## 游戏设计
```
Object:Pacman
Attribute:图片,位置
Collaborator：wall(solid) Events & Actions：碰撞 & 玩家操作反向 & 在Pacman处显示字体“晕”  

Object:Pacman
Attribute:图片,位置
Collaborator：ghosts Events & Actions：碰撞 & 暂停操作输入1s & Pacman血量减少1

Object:Pacman
Attribute:图片,位置
Collaborator：ending(solid) Events & Actions：Pacman消失 & 显示字体“恭喜通关”

Object:血量
Attribute:字体,左上
Collaborator：NULL Events & Actions：显示当前Pacman血量
```