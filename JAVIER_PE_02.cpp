// Exercise Q02 — Font Size Comparison [Easy] 
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

    const unsigned char* text = (const unsigned char*)"Hello OpenGL";

    // line 1 - helvetica 10
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.20f, 0.40f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_10, text);

    // line 2 - helvetica 18
    glRasterPos2f(-0.25f, 0.10f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);

    // line 3 - times roman 24
    glRasterPos2f(-0.30f, -0.30f);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, text);

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercise Q02 - Font Size Comparison");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}