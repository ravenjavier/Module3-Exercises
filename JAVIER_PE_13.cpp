// Exercise Q13 — Timer-Driven Counter [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
#include <cstdio>
using namespace std;

int counter = 0;
char counterText[50];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.25f, 0.0f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)counterText);
    glFlush();
}

void timer(int value)
{
    counter++;
    snprintf(counterText, sizeof(counterText), "Counter: %d", counter);
    glutPostRedisplay();
    glutTimerFunc(1000, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q13 - Timer-Driven Counter");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    snprintf(counterText, sizeof(counterText), "Counter: 0");
    glutDisplayFunc(display);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
    return 0;
}