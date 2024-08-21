#include<stdio.h>
#include<GL/glut.h>
#include<string.h>

GLfloat a=0,b=0,c=0,d=0,e=0,y=350,x=350,i=0,j=0,flag=0;
//void building();
void building1();
void boom();
void outline();
void disp();
void disp1();
void bitmap_output();
void road();
void display2();
void display3();
void build_outline();
void update(int value)
{
a+=20.0; //Plane position takeoff on x axis
b-=10.0; //Road Strip backward movement
c+=15; //take off at certain angle on y axis
if(b<=-78.0)// moving of run way
b=0.0;
glutPostRedisplay();
glutTimerFunc(150,update,0);//delay
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,1.0,1.0);
road();
//blast();
glPushMatrix();
glTranslated(a,c,0);
glColor3f(0.2,1.0,1.0);
glBegin(GL_POLYGON);//rectangular body
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(0.2,1.0,1.0);
glBegin(GL_POLYGON);//upper triangle construction plane
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);//outline of upper triangle plane
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//lower triangle
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//back wing
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//left side wing
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//rightside wing
glVertex2f(70.0,40.0);
glVertex2f(100.0,40.0);
glVertex2f(80.0,15.0);
glVertex2f(50.0,15.0);
glEnd();
glPopMatrix();
if(c>360) //timer to jump to next display
{
display2();
d+=20;//plane takeoff on x in 2nd display
}
if(a>500.0)//window position during take off
{
a=0.0;
b=0.0;
}
if(c>750)//timer to jump to 3rd display
{
display3();
e+=20;//plane takeoff on x in 3rd display
if(e>200)//timer to call blast function
{
//e=200;
for(y=330;y>80;y-=0.1)
{
//for(i=0;i<1000;i++);for(i=0;i<1000;i++);for(i=0;i<1000;i++);for(i=0;i<1000;i++);for(i=0;i<1000;i++);
glColor3f(.0,0.8,0.0);
glBegin(GL_POLYGON);
glVertex2f(270.0,y);
glVertex2f(270.0,y-5.0);
glVertex2f(260.0,y-5.0);
glVertex2f(260.0,y);
glEnd();/*
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(270.0,y);
glVertex2f(270.0,y+.095);
glVertex2f(260.0,y+.095);
glVertex2f(260.0,y);
glEnd();*/
}
boom();
}

}glFlush();
}




void boom()
{
glColor3f(1,.2,0.20);
glBegin(GL_POLYGON);
glVertex2f(230.0,80.0);
glVertex2f(230.0,220.0);
glVertex2f(190.0,220.0);
glVertex2f(170.0,250.0);
glVertex2f(190.0,270.0);
glVertex2f(220.0,290.0);
glVertex2f(270.0,270.0);
glVertex2f(320.0,290.0);
glVertex2f(330.0,270.0);
glVertex2f(360.0,250.0);
glVertex2f(330.0,220.0);
glVertex2f(310.0,200.0);
glVertex2f(310.0,80.0);
glEnd();
glFlush();
}



void hiro()
{
glColor3f(0.3,1.00,0.50);
glBegin(GL_POLYGON);
glVertex2f(0.0,0.0);
glVertex2f(0.0,80.0);
glVertex2f(500.0,80.0);
glVertex2f(500.0,0.0);
glEnd();
glColor3f(0.6,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,80.0);
glVertex2f(100.0,150.0);
glVertex2f(200.0,80.0);
glVertex2f(300.0,150.0);
glVertex2f(400.0,80.0);
glVertex2f(500.0,150.0);
glVertex2f(500.0,80.0);
glEnd();
glFlush();
}



void road()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,100);
glVertex2f(0.0,101);
glVertex2f(500,101);
glVertex2f(500,100);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);//black road
glVertex2f(0.0,0.0);
glVertex2f(0.0,100.0);
glVertex2f(500.0,100.0);
glVertex2f(500.0,0.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//white strips on roadglVertex2f(0.0,40.0);
glVertex2f(8.0,60.0);
glVertex2f(58.0,60.0);
glVertex2f(50.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(100.0,40.0);
glVertex2f(108.0,60.0);
glVertex2f(158.0,60.0);
glVertex2f(150.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(200.0,40.0);
glVertex2f(208.0,60.0);
glVertex2f(258.0,60.0);
glVertex2f(250.0,40.0);glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(300.0,40.0);
glVertex2f(308.0,60.0);
glVertex2f(358.0,60.0);
glVertex2f(350.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(400.0,40.0);
glVertex2f(408.0,60.0);
glVertex2f(458.0,60.0);
glVertex2f(450.0,40.0);
glEnd();
glPopMatrix();
}




void display2()
{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(0.2,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(0.2,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
//glVertex2f(165.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);glBegin(GL_POLYGON);
glVertex2f(70.0,40.0);
glVertex2f(100.0,40.0);
glVertex2f(80.0,15.0);
glVertex2f(50.0,15.0);
glEnd();
glPopMatrix();

}






void display3()
{

glClear(GL_COLOR_BUFFER_BIT);
hiro();
//building();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(0.2,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(0.2,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
//glVertex2f(165.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
//glVertex2f(165.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(70.0,40.0);
glVertex2f(100.0,40.0);
glVertex2f(80.0,15.0);
glVertex2f(50.0,15.0);
glEnd();
glPopMatrix();



}



void myinit()
{
//glClearColor(0.2f,0.99f,0.99f,0.0f);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
}


void bitmap_output(int x,int y,char *string,void * font)
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(string);
	for(i=0;i<len;i++)
	{
		glutBitmapCharacter(font,string[i]);
	}
}




void disp1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	glVertex2f(10,10);
	glVertex2f(10,490);
	glVertex2f(490,490);
	glVertex2f(490,10);
	glEnd();
	glColor3f(1,1,1);
	bitmap_output(200,430,"DSCE",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,1,1);
	bitmap_output(170,380,"DEPT of CSE",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,1);
	bitmap_output(150,350,"A Mini Project On",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.5,0.8,0);
	bitmap_output(120,310,"Nuclear attack on Hiroshima",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,1);
	bitmap_output(240,270,"By",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	bitmap_output(70,220,"Name: Lingesh 		USN: 1DS15CS720",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	bitmap_output(70,190,"Name: Akshatha G V 	USN: 1DS15CS703",GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	bitmap_output(70,160,"Name: Mamatha U 		USN: 1DS15CS722",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(220,80);
	glVertex2f(220,30);
	glVertex2f(290,30);
	glVertex2f(290,80);
	glEnd();
	glFlush();
	glColor3f(0,0,0);
	bitmap_output(230,50,"Next",GLUT_BITMAP_TIMES_ROMAN_24);
	glEnd();
	glFlush();
	glutSwapBuffers();

}


void myMouse1(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)

		flag=1;
		glutPostRedisplay();
glutTimerFunc(100,update,0);
}




void myKeyboardFunc( unsigned char key, int x, int y )
{
	if(key==13)
		flag=1;
		//break;
		disp();
}


void disp()
{
	glClear(GL_COLOR_BUFFER_BIT);
     if(flag==0)
      disp1();
	 
	else if(flag==1)
		display();
}


int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500.0,500.0);
glutInitWindowPosition(0,0);
glutCreateWindow("Hiroshima Nuclear Attack");
glutDisplayFunc(disp);
glutMouseFunc(myMouse1);
glutKeyboardFunc(myKeyboardFunc);
myinit();
//glClearColor(0.2f,0.99f,0.99f,0.0f);

glutMainLoop();
return 0;
}


