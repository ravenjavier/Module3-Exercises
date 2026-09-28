// Exercise Q15 — 30-Second Countdown Timer [Hard] 
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

int secondsRemaining = 30;
bool timeUp = false;

char message[50];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.3f, 0.0f);

    if (timeUp)
    {
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"Time's up!");
    }
    else
    {
        snprintf(message, sizeof(message), "Time remaining: %d", secondsRemaining);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)message);
    }

    glFlush();
}

void timer(int value)
{
    if (secondsRemaining > 0)
    {
        secondsRemaining--;

        if (secondsRemaining == 0)
        {
            timeUp = true;
        }

        glutPostRedisplay();

        if (secondsRemaining > 0)
        {
            glutTimerFunc(1000, timer, 0);
        }
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q15 - 30-Second Countdown Timer");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
    return 0;
}