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
	glTranslatef(0.5,0.5f,0.5f);
	glutSolidTeapot(0.25);
	glutSwapBuffers();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("Hello World");

	setup();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
