#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

#define MAX_Z_POS 10.0

float z_pos = 0.0;
int dir=1;

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
			if(z_pos < -5)
				z_pos += 0.15;
			else
			{
				dir=-1;
			}
			break;

		case -1:
			if(z_pos > -15)
				z_pos -= 0.15;
			else
			{
				dir=1;
			}
			break;
	}

}

void reshape(int width,int height)
{
	glViewport(0,0,(GLsizei)width,(GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1,2.0,50.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	/* Clear frame buffer */
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0,0.0,z_pos);

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(5.0,5.0,0.0);
	glVertex3f(-5.0,5.0,0.0);
	glVertex3f(-5.0,-5.0,0.0);
	glVertex3f(5.0,-5.0,0.0);
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
