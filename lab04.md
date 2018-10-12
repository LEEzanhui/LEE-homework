# 有关色彩的各种编码表示
## 物理本质
![](https://pic2.zhimg.com/80/v2-ffc7b8c0c6eb906a15ec46b4cb676fb2_hd.jpg)
不同波长、强度的电磁波，物理学通过频率似乎就可以表达出所有色光  
后来又出现色光的三原色，通过三色的调配，可以显示出各种颜色  
![](https://pic3.zhimg.com/80/v2-868c4332b317a6c1d83f13392af03c48_hd.jpg)  
三种原色的光聚集在一起就成了白光
## 如何编码
用名字来命名，如“淡紫”、“薰衣草紫”等既难以将颜色标准化，又不方便计算机储存，故颜色迫切需要一种编码方式

### RGB

三原色光模式（RGB color model)，是通过对红(R)、绿(G)、蓝(B)三个颜色通道的变化以及它们相互之间的叠加来得到各式各样的颜色的,这种模式被广泛使用，显示器也大多是采用三种发光极来产生各种色彩。值得注意的是，应用最多的是24字节存储的形式，也同时存在16字节和32字节的形式

![](http://blog.shuiguzi.com/images/Shader/5/rgb.png)
### HSL&HSV

HSL即色相、饱和度、亮度（英语：Hue, Saturation, Lightness）。HSV即色相、饱和度、明度（英语：Hue, Saturation, Value）  
>色相是色彩的基本属性，就是平常所说的颜色名称，如红色、黄色等。  
>饱和度是指色彩的纯度，越高色彩越纯，低则逐渐变灰.

太复杂，看不懂

![](http://www.canon.co.jp/imaging/picturestyle/editor/images/b1-e-img-1.jpg)
![](https://www.researchgate.net/profile/I_El-Feghi/publication/224299024/figure/fig1/AS:341224843169793@1458365750612/Figure-1-HSV-color-space-representation.png "hsv")
### 十六进制表示
