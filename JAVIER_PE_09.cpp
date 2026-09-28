// Exercise Q09 — Active Motion Coordinate Display [Medium] 
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

float mouseX = 0.0f;
float mouseY = 0.0f;

char positionText[100];

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.8f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)positionText);

    glFlush();
}

void motion(int x, int y)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);
    mouseX = (2.0f * x / width) - 1.0f;
    mouseY = 1.0f - (2.0f * y / height);
    snprintf( positionText, sizeof(positionText), "OpenGL Position: (%.2f, %.2f)", mouseX, mouseY);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q09 - Active Motion Coordinate Display");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    // initial message
    snprintf( positionText, sizeof(positionText), "OpenGL Position: (0.00, 0.00)");
    glutMainLoop();
    return 0;
}