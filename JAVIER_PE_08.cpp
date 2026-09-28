// Exercise Q08 — Clamped Keyboard Movement [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

float squareX = 0.0f;

const float squareHalfWidth = 0.1f;
const float moveAmount = 0.1f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(squareX - squareHalfWidth, -0.1f);
        glVertex2f(squareX + squareHalfWidth, -0.1f);
        glVertex2f(squareX + squareHalfWidth,  0.1f);
        glVertex2f(squareX - squareHalfWidth,  0.1f);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a')
    {
        squareX -= moveAmount;
    }
    else if (key == 'd')
    {
        squareX += moveAmount;
    }

    if (squareX - squareHalfWidth < -0.9f)
    {
        squareX = -0.9f + squareHalfWidth;
    }

    if (squareX + squareHalfWidth > 0.9f)
    {
        squareX = 0.9f - squareHalfWidth;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q08 - Clamped Keyboard Movement");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}