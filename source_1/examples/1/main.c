#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

void setup(void)
{
	/* Set background to black */
	glClearColor(0.0f,0.0f,0.0f,0.5f);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.5f, 0.0f, 1.0f); // (0.5, 0, 1) is half red and full blue, giving dark purple.
	glBegin(GL_QUADS);
		glVertex2f(-0.75, 0.75);
		glVertex2f(-0.75, -0.75);
		glVertex2f(0.75, -0.75);
		glVertex2f(0.75, 0.75);
	glEnd();
	glutSwapBuffers();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutCreateWindow("Hello World");

	setup();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
