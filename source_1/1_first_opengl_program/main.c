#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

void setup(void)
{
}

void display(void)
{
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
