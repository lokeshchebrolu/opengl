#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

#define MAX_X_POS 8.0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define X 1.0
#define Y 1.0

float x_pos = -50.0;
float y_pos = 0.0;
float x_speed = 0.2;
float y_speed = 0.2;
int dir=0;


void init(void)
{
	/* Set BG to black */
	glClearColor(0,0,0,1);
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
			break;

		case DOWN:
			y_pos -= y_speed;
			break;

		case LEFT:
			x_pos -= x_speed;
			break;

		case RIGHT:
			x_pos += x_speed;
			break;
	}

}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	/* Clear frame buffer */
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(x_pos,y_pos,0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(X,Y);
	glVertex2f(-X,Y);
	glVertex2f(-X,-Y);
	glVertex2f(X,-Y);
	glEnd();

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
	glutCreateWindow("Box movement");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	glutSpecialFunc(specialInput);

	glutMainLoop();
	return 0;
}
