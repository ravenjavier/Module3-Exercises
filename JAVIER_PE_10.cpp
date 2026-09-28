// Exercise Q10 — Passive Motion Pixel Readout [Medium]
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

int mouseX = 0;
int mouseY = 0;

char positionText[100];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.8f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)positionText);
    glFlush();
}

void passiveMotion(int x, int y)
{
    mouseX = x;
    mouseY = y;
    snprintf( positionText, sizeof(positionText), "Mouse at (%d, %d)", mouseX, mouseY);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q10 - Passive Motion Pixel Readout");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutPassiveMotionFunc(passiveMotion);
    snprintf( positionText, sizeof(positionText), "Mouse at (0, 0)");
    glutMainLoop();
    return 0;
}