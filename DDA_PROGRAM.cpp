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
