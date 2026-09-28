// Exercise Q14 — Keyboard + Mouse Combo [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

float shapeX = 0.0f;
float shapeY = 0.0f;

float moveAmount = 0.1f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(shapeX - 0.1f, shapeY - 0.1f);
        glVertex2f(shapeX + 0.1f, shapeY - 0.1f);
        glVertex2f(shapeX + 0.1f, shapeY + 0.1f);
        glVertex2f(shapeX - 0.1f, shapeY + 0.1f);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'w')
    {
        shapeY += moveAmount;
    }
    else if (key == 's')
    {
        shapeY -= moveAmount;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        shapeX = 0.0f;
        shapeY = 0.0f;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q14 - Keyboard + Mouse Combo");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}