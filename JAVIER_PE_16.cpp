// Exercise Q16 — Click-and-Drag Square [Hard] 
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
float squareY = 0.0f;

bool dragging = false;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(squareX - 0.1f, squareY - 0.1f);
        glVertex2f(squareX + 0.1f, squareY - 0.1f);
        glVertex2f(squareX + 0.1f, squareY + 0.1f);
        glVertex2f(squareX - 0.1f, squareY + 0.1f);
    glEnd();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            dragging = true;
        }
        else if (state == GLUT_UP)
        {
            dragging = false;
        }
    }
}

void motion(int x, int y)
{
    if (dragging)
    {
        int width = glutGet(GLUT_WINDOW_WIDTH);
        int height = glutGet(GLUT_WINDOW_HEIGHT);
        squareX = (2.0f * x / width) - 1.0f;
        squareY = 1.0f - (2.0f * y / height);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q16 - Click-and-Drag Square");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}