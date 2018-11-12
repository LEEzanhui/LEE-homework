# 洗衣机算法设计

自顶向下是将一个大问题分解为若干个小问题，再将每个小问题继续分解，直到不能再分解或者可以轻易实现为止。应用在计算机领域的编程过程中，则是将主程序分为若干个模块，实现了这些模块，就可以实现整个程序，然后再用同样的方法对待每一个模块，这样，实现每一个小模块就意味着实现最终的大模块。

>A top-down approach is essentially the breaking down of a system to gain insight into its compositional sub-systems in a reverse engineering fashion. 
–Wikipedia

生活中常见的洗衣机的程序设计也可以通过这种方法来进行  

我们先观察洗衣机的主要的大步骤  
```
浸泡-洗涤-漂洗-甩干
```  
再细分它的功能为  
```
water_in()
soak()
wash()
water_out()
water_in()
rinse()
water_out()
dry()
```
进一步细分为具体的程序  
```
input volume, soak-time, wash-time
while get_water_volume() < volume
	water_in_switch(open)
water_in_switch(close)
while time_counter() < soak-time
	motor_run(stop)
while time_counter() < wash-time
	while  time_counter() < 5s
		motor_run(left)
	while  time_counter() < 5s
		motor_run(right)	
motor_run(stop)
while get_water_volume() > 0
	water_out_switch(open)
water_out_switch(close)
while get_water_volume() < volume
	water_in_switch(open)
water_in_switch(close)
while time_counter() < rinse-time
	while  time_counter() < 5s
		motor_run(left)
	while  time_counter() < 5s
		motor_run(right)	
motor_run(stop)
while get_water_volume() > 0
	water_out_switch(open)
while time_counter() < rinse-time
	while  time_counter() < 5s
		motor_run(left)
	while  time_counter() < 5s
		motor_run(right)	
motor_run(stop)
water_out_switch(close)
halt(returncode)
```
当然，其中有许多重复的步骤，可以模块化来进行优化  
```
motor_mod(time){
	while time_counter() < time
		while  time_counter() < 5s
			motor_run(left)
		while  time_counter() < 5s
			motor_run(right)	
	motor_run(stop)
}

water_mod(in/out, volume){
	if in do
		while get_water_volume() < volume
			water_in_switch(open)
		water_in_switch(close)
	else
		while get_water_volume() > 0
			water_out_switch(open)
		water_out_switch(close)
}

input volume, soak-time, wash-time
water_mod(in, volume)
while time_counter() < soak-time
	motor_run(stop)
motor_mod(time)
water_mod(out, volume)
water_mod(in, volume)
motor_mod(time)
water_mod(out, volume)
motor_mod(time)
water_mod(out, volume)
halt(returncode)
```

在上面，我通过不断分解问题，将复杂的洗衣机程序分割成小程序，即是自顶向下、逐步求精的编程方法。这种方法给我们的学习提供思考的方向与方法  