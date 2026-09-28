// Exercise Q17 — Mouse-Controlled Stopwatch [Hard] 
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

int elapsedSeconds = 0;
bool running = false;

char stopwatchText[50];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.3f, 0.0f);
    snprintf(stopwatchText, sizeof(stopwatchText), "Elapsed: %d seconds", elapsedSeconds);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)stopwatchText);
    glFlush();
}

void timer(int value)
{
    if (running)
    {
        elapsedSeconds++;
        glutPostRedisplay();
    }
    glutTimerFunc(1000, timer, 0);
}

void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            // Start or resume
            running = true;
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            // Pause
            running = false;
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q17 - Mouse-Controlled Stopwatch");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
    return 0;
}