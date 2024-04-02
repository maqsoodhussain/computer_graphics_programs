# computer_graphics_programs
graphic programs in cpp 

<!--
In computer graphics, we need to represent continuous graphics objects using discrete pixels. This process is known as scan conversion. Every graphics system must transform the primitives like lines, circles, and ellipses into a collection of pixels.

Line drawing algorithms are used to draw a line in discrete graphical media. There are three line drawing algorithms in computer graphics.

1. DDA algorithm (Digital Differential Analyzer)
2, Midpoint algorithm
3. Bresenham’s line algorithm



## The Line Equation
<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/9765e70c-21dd-45af-b5b5-23b23f403649)

<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/503c8323-05e1-4423-9469-c42f0eb7a20f) <br>


### Finding the next pixel to draw a line
We need two endpoints, P and Q, to draw a line on a raster screen. We are starting from the P coordinate and find the next pixels until we reach the endpoint Q.

There are three special scenarios when we draw lines.

#### Case 1: Draw a Horizontal Line: m = 0

The horizontal line has the same Y coordinate value. In this scenario, we only need to consider X coordinate value changes. We first draw pixel P and increment only the X coordinate value by 1 to get the next pixel.
<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/97244a64-8449-46af-9a0c-8de472330c9c)
<br>

Case 2: Draw a Vertical Line: m is undefined

Vertical lines have the same X coordinates values and different Y coordinate values. Similar to the horizontal line draw, we first draw the initial pixel (P), and this time we increment Y coordinate values by 1 to get the next pixel until we reach endpoint Q.

<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/31d44cf8-0abc-45fb-9881-be22649d8523)

<br>
Case 3: Draw a Diagonal Line: m = 1
<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/17ce5982-16fe-4779-bb84-cdc11192907c)
<br>
The final special scenario is to draw a diagonal line, where the slope equals 1. To get the next pixel in diagonal line we need to increment both X and Y coordinate values by 1.


The scenarios we discussed up to now are special cases. In general, we have to draw lines where the slope is greater than / less than 1. In that cases, we can use the DDA algorithm to draw lines.

# DDA Algorithm
DDA stands for Digital Differential Analyzer. This is an incremental line algorithm, the calculation of each step is based on the results of the previous steps.

The algorithm has 2 cases based on slope value.

Let’s take (X1, Y1), and (X2, Y2) as our endpoints.

## Case 1: When |m|<1
Assume and X1 < X2

Start with,

X = X1, Y = Y1

As we know, the slope of the line can be determined using,

<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/0f5cd998-5cbe-42ed-b673-a68a16061c95)
<br>
In this case, we always keep the difference in X coordinate values to 1.
<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/a68ed3c0-7dee-4a6a-8575-fd6f633970f1)

<br>

Now we can simply calculate the next Y coordinate value by adding slope to the current y coordinate.



Continue until X = X2

Case 2: When |m|>1
Similar to case 1, Start with,

X = X1, Y = Y1

But in this case, instead of X, we increment the Y value by one.

<br>

[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/a37906f1-1211-48b2-9514-4d794a2bc443)
<br>
So, when we assign this to the slope equation, we can get the current X value.
<br>
[image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/365c96f3-8e1e-4c8a-b99c-8aaf7fca77de)
<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/fae46908-5ec0-458b-b66e-8ea8001fd4a4)
<br>


Continue until Y = Y2

Note: Since we are dealing with pixels, we need integer values as coordinates. We need to round off fraction values.

Examples
Example 1

Draw a line from (2, 1) to (8, 5)

X1 = 2, X2 = 8, Y1 = 1 and Y2 = 5

First, we need to calculate the slope of the line.

<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/c3e7c268-e851-45af-a65a-c1fcbac4d871)
<br>
The slope is less than 1 and we need to follow the steps in case 1. Increment X values by one, and add slope to get the corresponding Y value. Finally round off the Y values.

<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/551b1368-26d5-42d0-a586-2b4fb072b75d)
<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/2c5f03a0-f75d-499f-a833-3a6d96d98c4b)
<br>

Example 2

Draw a line from (3, 2) to (7, 8)

X1 = 3, X2 = 7, Y1 = 2 and Y2 = 8

Slope of the line

<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/afecb80b-b966-4603-88cb-7ef07ece6c76)
<br>
The slope is greater than 1 and we need to follow steps in case 2.

<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/8dc7c8ad-e228-4b5c-bbae-20f8c0a24b26)
<br>
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/b2b9fc30-b5fc-4d39-be0f-19475af7f4cb)
<br>


DDA algorithm is simple and easier to calculate since each step has only two additions. One of the disadvantages of this algorithm is the involvement of round-off functionality. Round-off operation consumes a lot of time and accumulations of rounding off values cause accumulation error.

Note:

If X1 > X2, take (X2, Y2) as the starting point and (X1, Y1) as the end point, then continue the DDA algorithm as we learned today.

"""


-->
# Line Drawing Using Line Equation y = mx + c
```

#include<iostream>
#include<graphics.h>
#include<cmath>

main(){
	initwindow(500,500);


     
    int x1=2, y1=3;
    int x2=8, y2=6;
    float dx, dy,xInc, yInc, m,c;
    int steps;
    
    dx = x2-x1;
    dy = y2-y1;
    
    m = dy/dx;
    c = y1 - m *x1;
    
    
    if(abs(dx)>abs(dy))
    	steps = dx;
    else
    	steps = dy;
	
    xInc = dx/steps;
    yInc = dy/steps;
    
    int x = x1;
    int y = y1;
    
    for( int i = 0; i < steps; i++){
    	putpixel(round(x), round(y), RED);
    	x = x+ xInc;
    	y = m*x +c;
	}
   
	getch();
}
```

# DDA (Digital Differential Analyzer)

```

#include<iostream>
#include<graphics.h>
#include<cmath>

main(){
	initwindow(500,500);


        // declearing varables

         int x1=100,y1=50;
         int x2=400,y2=300;
         float dx,dy,xInc, yInc;
         int steps;

          dx = x2-x1;
	  dy = y2-y1;

	if(abs(dx)>abs(dy))
		steps = dx;
	else
		steps = dy;

	xInc = dx/steps;
	yInc = dy/steps;

	for(int i=0; i<steps; i++){
		putpixel(x1,y1,WHITE);
		x1 = x1+xInc;
		y1 = y1+yInc;
	}

	getch();
}
```
