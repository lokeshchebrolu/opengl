#include<stdio.h>
#include<string.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

#define MAX_X 50.0f
#define MAX_Y 50.0f

#define INITIAL_X_POS -MAX_X+5
#define INITIAL_Y_POS 0

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define END_GAME -1

#define X 1.0
#define Y 1.0

float x_pos = INITIAL_X_POS;
float y_pos = INITIAL_Y_POS;
float x_speed = 0.2;
float y_speed = 0.2;

float obstacle_x=0;
float obstacle_y=0;
float obstacle_size=1;
int obstacle_hit=0;

int dir=0;
int window_id=0;

int boundary_x=MAX_X-3;
int boundary_y=MAX_Y-3;

int dead=0;

void init(void)
{
	/* Set BG to black */
	glClearColor(0,0,0,1);
}

void output(char *string)
{
	int x=0,length=strlen(string);
	x=length/2;
	glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(-x*2,0);
	for(int i=0;i<length;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
	}
}

void dead_fun(void)
{
	char *msg="GAME OVER";
	int msg_len=strlen(msg);
	float rect_index=-msg_len*2;
	glColor3f(1.0f,1.0f,1.0f);	
	glRectf(-rect_index,5,rect_index,-5);
	output("GAME OVER");
}

void specialInput(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			dir=UP;
			break;

		case GLUT_KEY_DOWN:
			dir=DOWN;
			break;

		case GLUT_KEY_LEFT:
			dir=LEFT;
			break;

		case GLUT_KEY_RIGHT:
			dir=RIGHT;
			break;

		case GLUT_KEY_END:
			dir=END_GAME;
			break;
	}
}

void timer(int arg)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);

	switch(dir)
	{
		case	UP:
			y_pos += y_speed;
			if(y_pos>=(obstacle_y-obstacle_size))
				obstacle_hit=1;
			if(y_pos>=boundary_y)
				dead=1;
			break;

		case DOWN:
			y_pos -= y_speed;
			if(y_pos<=(obstacle_y+obstacle_size))
				obstacle_hit=1;
			if(y_pos<=boundary_y)
				dead=1;
			break;

		case LEFT:
			x_pos -= x_speed;
			if(x_pos<=(obstacle_x+obstacle_size))
				obstacle_hit=1;
			if(x_pos<=boundary_x)
				dead=1;
			break;

		case RIGHT:
			x_pos += x_speed;
			if(x_pos>=(obstacle_x-obstacle_size))
				obstacle_hit=1;
			if(x_pos>=boundary_x)
				dead=1;
			break;

		case END_GAME:
			glutDestroyWindow(window_id);
			break;
	}

}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-MAX_X,MAX_Y,-MAX_X,MAX_Y);
	glMatrixMode(GL_MODELVIEW);
}

void obstacle(float x,float y,float size)
{
	glTranslatef(x,y,0.0);
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(size,size);
	glVertex2f(-size,size);
	glVertex2f(-size,-size);
	glVertex2f(size,-size);
	glEnd();
}

void boundary(void)
{

	glBegin(GL_LINE_LOOP);
	glVertex2f(boundary_x,boundary_y);
	glVertex2f(-boundary_x,boundary_y);
	glVertex2f(-boundary_x,-boundary_y);
	glVertex2f(boundary_x,-boundary_y);
	glEnd();
}

void display(void)
{
	/* Clear frame buffer */
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	boundary();
	glPopMatrix();

	if(!dead)
	{
		if(!obstacle_hit)
		{
			glPushMatrix();
			obstacle(obstacle_x,obstacle_y,obstacle_size);
			glPopMatrix();
		}
		else
		{
		}

		glPushMatrix();
		glTranslatef(x_pos,y_pos,0.0);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(X,Y);
		glVertex2f(-X,Y);
		glVertex2f(-X,-Y);
		glVertex2f(X,-Y);
		glEnd();
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		dead_fun();
		glPopMatrix();
	}
	/* Displays frame buffer on screen */
	glFlush();
	glutSwapBuffers();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowPosition(0,0);
	glutInitWindowSize(400,400);
	window_id=glutCreateWindow("Box movement");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutSpecialFunc(specialInput);

	glutMainLoop();
	return 0;
}
