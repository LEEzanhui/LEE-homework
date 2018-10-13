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

被誉为最流行、最常用的颜色表示方式，使用三个字符的十六进制码在范围 00-FF 的指定 RGB 值，其中 00 是没有颜色和 FF 是所有颜色聚集在一起形成的白色。本质上是RGB模式。

![](https://pic3.zhimg.com/80/v2-7b75d3cf46ca1a0f83c6ba26cc615d51_hd.jpg)

这种方法广泛用于相关领域，为此网上有许多总结，如：
>更高的数字 = 更多的光线 = 接近白色 = 明亮的颜色。 较低的数字 = 较少的光线 = 接近黑色 = 较暗的颜色。

### else
Pantone，一般是指由Pantone公司开发制定的色彩及色彩系统，它们有一套自己的编码系统。  
>PANTONE色卡是享誉世界的色彩权威，涵盖印刷、纺织、塑胶、绘图、数码科技等领域的色彩沟通系统，已经成为当今交流色彩信息的国际统一标准语言。潘通（Pantone Inc.）总部位于美国新泽西州卡尔士达特市（Carlstadt, NJ），是一家专门开发和研究色彩而闻名全球的权威机构，也是色彩系统的供应商，提供许多行业包括印刷及其他关于颜色如数码技术、纺织、塑胶、建筑以及室内设计等的专业色彩选择和精确的交流语言。

Pantone为油墨混色配方，在印刷行业通称为专色。遗憾的是，我并未找到相关的编码规则。

![](http://www.yyxx5.com/hdpic/option=aHR0cDovL2IuaGlwaG90b3MuYmFpZHUuY29tL3poaWRhby93aCUzRDQ1MCUyQzYwMC9zaWduPTRhZDhjNDE4ZjIxZmJlMDkxYzBiY2IxMDVlNTAyMDA1L2VhYzRiNzQ1NDNhOTgyMjZmZWVmZDA0OThhODJiOTAxNGE5MGViYjYuanBn.jpg)