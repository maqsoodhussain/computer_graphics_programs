# computer_graphics_programs
graphic programs in cpp 


In computer graphics, we need to represent continuous graphics objects using discrete pixels. This process is known as scan conversion. Every graphics system must transform the primitives like lines, circles, and ellipses into a collection of pixels.

Line drawing algorithms are used to draw a line in discrete graphical media. There are three line drawing algorithms in computer graphics.

1. DDA algorithm (Digital Differential Analyzer)
2, Midpoint algorithm
3. Bresenham’s line algorithm



The Line Equation
![image](https://github.com/maqsoodhussain/computer_graphics_programs/assets/83625735/503c8323-05e1-4423-9469-c42f0eb7a20f)


Finding the next pixel to draw a line
We need two endpoints, P and Q, to draw a line on a raster screen. We are starting from the P coordinate and find the next pixels until we reach the endpoint Q.

There are three special scenarios when we draw lines.

Case 1: Draw a Horizontal Line: m = 0

The horizontal line has the same Y coordinate value. In this scenario, we only need to consider X coordinate value changes. We first draw pixel P and increment only the X coordinate value by 1 to get the next pixel.


Case 2: Draw a Vertical Line: m is undefined

Vertical lines have the same X coordinates values and different Y coordinate values. Similar to the horizontal line draw, we first draw the initial pixel (P), and this time we increment Y coordinate values by 1 to get the next pixel until we reach endpoint Q.


Case 3: Draw a Diagonal Line: m = 1

The final special scenario is to draw a diagonal line, where the slope equals 1. To get the next pixel in diagonal line we need to increment both X and Y coordinate values by 1.


The scenarios we discussed up to now are special cases. In general, we have to draw lines where the slope is greater than / less than 1. In that cases, we can use the DDA algorithm to draw lines.

DDA Algorithm
DDA stands for Digital Differential Analyzer. This is an incremental line algorithm, the calculation of each step is based on the results of the previous steps.

The algorithm has 2 cases based on slope value.

Let’s take (X1, Y1), and (X2, Y2) as our endpoints.

Case 1: When |m|<1
Assume and X1 < X2

Start with,

X = X1, Y = Y1

As we know, the slope of the line can be determined using,


In this case, we always keep the difference in X coordinate values to 1.


Now we can simply calculate the next Y coordinate value by adding slope to the current y coordinate.



Continue until X = X2

Case 2: When |m|>1
Similar to case 1, Start with,

X = X1, Y = Y1

But in this case, instead of X, we increment the Y value by one.


So, when we assign this to the slope equation, we can get the current X value.



Continue until Y = Y2

Note: Since we are dealing with pixels, we need integer values as coordinates. We need to round off fraction values.

Examples
Example 1

Draw a line from (2, 1) to (8, 5)

X1 = 2, X2 = 8, Y1 = 1 and Y2 = 5

First, we need to calculate the slope of the line.


The slope is less than 1 and we need to follow the steps in case 1. Increment X values by one, and add slope to get the corresponding Y value. Finally round off the Y values.



Example 2

Draw a line from (3, 2) to (7, 8)

X1 = 3, X2 = 7, Y1 = 2 and Y2 = 8

Slope of the line


The slope is greater than 1 and we need to follow steps in case 2.



DDA algorithm is simple and easier to calculate since each step has only two additions. One of the disadvantages of this algorithm is the involvement of round-off functionality. Round-off operation consumes a lot of time and accumulations of rounding off values cause accumulation error.

Note:

If X1 > X2, take (X2, Y2) as the starting point and (X1, Y1) as the end point, then continue the DDA algorithm as we learned today.





'''
// DDA (Digital Differential Analyzer)

#include<iostream>
#include<graphics.h>
#include<cmath>
main(){
	initwindow(500,500);
    
	
    // declearing varables 
    int x1=100,y2=50;
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
'''
