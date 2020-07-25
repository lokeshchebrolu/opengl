#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

#define MAX_X_POS 8.0

float x_pos = -10.0;
int dir=1;
double trans_x=20.0;
double trans_y=20.0;

void init(void)
{
	/* Set BG to black */
	glClearColor(0,0,0,1);
}

void timer(int arg)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);

	switch(dir)
	{
		case	1:
			if(x_pos < MAX_X_POS)
				x_pos += 0.15;
			else
			{
				dir=-1;
				trans_x=-20.0;
				trans_y=-20.0;
			}
			break;

		case -1:
			if(x_pos > -10)
				x_pos -= 0.15;
			else
			{
				dir=1;
				trans_x=20.0;
				trans_y=20.0;
			}
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

	glTranslatef(trans_x,trans_y,0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x_pos,1.0);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(x_pos,-1.0);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(x_pos+2.0,-1.0);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(x_pos+2.0,1.0);
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
	glutCreateWindow("Hello World");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);

	glutMainLoop();
	return 0;
}
