
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
