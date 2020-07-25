#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

#define MAX_Z_POS 10.0

float angle = 0.0;
int dir=1;

void init(void)
{
	/* Set BG to black */
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
}

void timer(int arg)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);

	if(angle>360.0)
		angle -= 360;
	else
		angle += 1.0;

}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25,1,2.0,50.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	/* Clear frame buffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0,0.0,-8.0);
//	glRotatef(angle,1.0,0.0,0.0);
	glRotatef(angle,0.0,1.0,0.0);
//	glRotatef(angle,0.0,0.0,1.0);

	glColor3f(1,0,0);
	glutWireSphere(1,50,16);
/*
	glBegin(GL_QUADS);
	//front
	glColor3f(1.0,0.0,0.0);
	glVertex3f(-1.0,1.0,1.0);
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,1.0,1.0);
	//back
	glColor3f(0.0,1.0,0.0);
	glVertex3f(1.0,1.0,-1.0);
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,1.0,-1.0);
	//right
	glColor3f(0.0,0.0,1.0);
	glVertex3f(1.0,1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,-1.0);
	glVertex3f(1.0,1.0,-1.0);
	//left
	glColor3f(1.0,1.0,0.0);
	glVertex3f(-1.0,1.0,-1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(-1.0,1.0,1.0);
	//top
	glColor3f(0.0,1.0,1.0);
	glVertex3f(-1.0,1.0,-1.0);
	glVertex3f(-1.0,1.0,1.0);
	glVertex3f(1.0,1.0,1.0);
	glVertex3f(1.0,1.0,-1.0);
	//bottom
	glColor3f(1.0,0.0,1.0);
	glVertex3f(-1.0,-1.0,-1.0);
	glVertex3f(-1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,1.0);
	glVertex3f(1.0,-1.0,-1.0);
	glEnd();
*/
	/* Displays frame buffer on screen */
	glFlush();
	glutSwapBuffers();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

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
