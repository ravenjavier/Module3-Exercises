// Exercise Q12 — Idle-Driven Bouncing Label [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

float textX = -0.9f;
float speed = 0.0008f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(textX, 0.0f);
    const unsigned char* text = (const unsigned char*)"Bouncing Label";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
    glFlush();
}

void idle()
{
    textX += speed;

    if (textX >= 0.55f)
    {
        textX = 0.55f;
        speed = -speed;
    }

    if (textX <= -0.9f)
    {
        textX = -0.9f;
        speed = -speed;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q12 - Idle-Driven Bouncing Label");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}