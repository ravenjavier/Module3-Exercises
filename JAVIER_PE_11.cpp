// Exercise Q11 — Entry-Driven Background [Medium]
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

float bgColor = 0.2f;

void display()
{
    glClearColor(bgColor, bgColor, bgColor, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mouseEntry(int state)
{
    if (state == GLUT_ENTERED)
    {
        // light gray
        bgColor = 0.8f;
    }
    else if (state == GLUT_LEFT)
    {
        // dark gray
        bgColor = 0.2f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q11 - Entry-Driven Background");
    glutDisplayFunc(display);
    glutEntryFunc(mouseEntry);
    glutMainLoop();
    return 0;
}