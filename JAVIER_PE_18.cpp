// Exercise Q18 — Entry + Idle Freeze Combo [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

float shapeX = -0.8f;
float speed = 0.0008f;

bool inside = false;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(shapeX - 0.1f, -0.1f);
        glVertex2f(shapeX + 0.1f, -0.1f);
        glVertex2f(shapeX + 0.1f,  0.1f);
        glVertex2f(shapeX - 0.1f,  0.1f);
    glEnd();

    glFlush();
}

void entry(int state)
{
    if (state == GLUT_ENTERED)
    {
        inside = true;
    }
    else if (state == GLUT_LEFT)
    {
        inside = false;
    }
}

void idle()
{
    if (inside)
    {
        shapeX += speed;

        if (shapeX >= 0.8f)
        {
            shapeX = 0.8f;
            speed = -speed;
        }

        if (shapeX <= -0.8f)
        {
            shapeX = -0.8f;
            speed = -speed;
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q18 - Entry + Idle Freeze Combo");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutEntryFunc(entry);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}