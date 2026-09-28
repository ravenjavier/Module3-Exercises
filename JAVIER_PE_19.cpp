// Exercise Q19 — HUD Score with Color Milestones [Hard] 
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

int score = 0;
char scoreText[50];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int stage = score / 5;

    if (stage % 3 == 0)
    {
        // blue
        glColor3f(0.2f, 0.6f, 1.0f);
    }
    else if (stage % 3 == 1)
    {
        // green
        glColor3f(0.2f, 1.0f, 0.3f);
    }
    else
    {
        // red
        glColor3f(1.0f, 0.2f, 0.2f);
    }

    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f( 0.2f, -0.2f);
        glVertex2f( 0.2f,  0.2f);
        glVertex2f(-0.2f,  0.2f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.85f);
    snprintf(scoreText, sizeof(scoreText), "Score: %d", score);

    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)scoreText);

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        score++;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q19 - HUD Score with Color Milestones");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}