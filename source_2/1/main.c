#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

void init(void)
{
	/* Set BG to black */
	glClearColor(0,0,0,1);
}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	/* Clear frame buffer */
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_POLYGON);
	glVertex2f(0.0,5.0);
	glVertex2f(4.0,-3.0);
	glVertex2f(-4.0,-3.0);
	glVertex2f(5.0,2.0);
	glEnd();

	/* Displays frame buffer on screen */
	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	
	glutInitWindowPosition(0,0);
	glutInitWindowSize(400,400);
	glutCreateWindow("Hello World");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}
