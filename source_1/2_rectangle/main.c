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
	/* Clearing screen buffer by creating new buffer */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Set foreground colour to white */
	glColor3f(1.0f,1.0f,1.0f);

	/* Drawing rectangle */
	glRectf(-0.2f,0.2f,0.2f,-0.2f);

	/* Assigning newly created buffer to our window */
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
