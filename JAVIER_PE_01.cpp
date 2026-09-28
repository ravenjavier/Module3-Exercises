// Exercise Q01 — Display Your Name [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.25f, 0.0f);
    const unsigned char* text = (const unsigned char*)"Raven"; // display name
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q01 - Display Your Name");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}