# 用construc2制作简易的迷宫游戏

## 1 安装并运行construct2

![](https://static3.scirra.net/images/newstore/products/32/construct2-screenshot1.png)

## 2 寻找模板

可以在网上找到许多模板作为游戏中的地图和人物形象

![](https://www.scirra.com/images/articles/ChomperSprites.png)

游戏形象

![](https://www.scirra.com/images/articles/Background.png)

游戏背景

## 3 制作背景与形象

要注意导入模板制作游戏人物时要切割图片，以便单独取出一个形象  
方法是在edit image的框下方animation frames处，右击，选择import frames from spirte...，选择合适的大小进行裁剪，再调节speed,游戏角色即可达到变身的效果。

![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/1.gif?raw=true)  

接着可以制作迷宫主体
制作时要注意图层关系，方便后续修改
在背景图层中可以加上effect，我用water background效果，适当调节XY轴的速度，在游戏中可以体现出柔和的水波的感觉

![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/%E6%8D%95%E8%8E%B7.PNG?raw=true)

## 4 移动、生命值与显示

主角采用八字方向移动，反派采用bullet 在地图边缘调整方向以面向主角
生命值在左上角显示，利用全局变量来保存，当生命结束时，游戏即结束

![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/%E6%8D%95%E8%8E%B72.PNG?raw=true)

## 5 制作碰撞

游戏角色添加behaviors中的solid,再在反派中设置bound off solids,完成角色间的碰撞
在event sheet中，设置on collision with...也可以模拟碰撞效果，搭配set angle和set text可以做出许多效果

![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/2.gif?raw=true)

## 6 设置一个结局，虽然没有下一关
## 7 成果展示

![](https://github.com/LEEzanhui/LEE-homework/blob/gh-pages/images/3.gif?raw=true)