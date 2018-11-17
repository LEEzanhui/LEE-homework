# python 编程实验报告
太强大了，为为此付出心血的程序猿送出666  
### 1 选择2个高等数学上的作业，如泰勒分解、公式化简、解方程等。 （一般搜索不到有价值的答案）
求函数的极限：

$$ \lim_{n \to + 0} \frac{\sin5x - \tan3x}{2x} \quad $$  

```
import sympy
from sympy import *
x = symbols('x')    #之后才能用x

>>> limit( (sin(5*x)-tan(3*x))/(2*x), x, 0)
1
```

求不定积分：  

$$\int {\sec<sub>4</sub>x} \,{\rm d}x$$

```
>>> integrate((sec(x))**4,x)
2*sin(x)/(3*cos(x)) + sin(x)/(3*cos(x)**3)
```

### 2 选择2个线性代数上的作业，如求dot、逆矩阵等，最好会解方程。（建议阅读《用Python做科学计算》）
矩阵乘法  
```
>>> import numpy as np  #导入numpy模块，并用np指代它
>>> a = np.mat([[1,2,3],[4,5,6]])
>>> a
matrix([[1, 2, 3],
        [4, 5, 6]])
>>> b = np.mat([[7,8],[9,10],[11,12]])
>>> b
matrix([[ 7,  8],
        [ 9, 10],
        [11, 12]])
>>> a*b             #可用dot()函数做矩阵乘法
matrix([[ 58,  64],
        [139, 154]])
```

矩阵转置  
```
>>> c = a*b
>>> c.T
matrix([[ 58, 139],
        [ 64, 154]])
```

矩阵求逆  
```
>>> c_inverse = np.linalg.inv(c)
>>> c_inverse
matrix([[ 4.27777778, -1.77777778],
        [-3.86111111,  1.61111111]])
>>> np.dot(c,c_inverse)
matrix([[1., 0.],
        [0., 1.]])
```

 (๑ •̀ω•́)۶  