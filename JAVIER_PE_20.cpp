// Exercise Q20 — Interactive Text Placer (Capstone) [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

float markerX = 0.0f;
float markerY = 0.0f;

float mouseX = 0.0f;
float mouseY = 0.0f;

char coordinateText[100];

float pulseAngle = 0.0f;

const float baseSize = 0.12f;
const float amplitude = 0.03f;

void toGL(int x, int y, float* ox, float* oy)
{
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    *ox = (2.0f * x / width) - 1.0f;
    *oy = 1.0f - (2.0f * y / height);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float size = baseSize + amplitude * sin(pulseAngle);

    glColor3f(0.2f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(markerX - size, markerY - size);
        glVertex2f(markerX + size, markerY - size);
        glVertex2f(markerX + size, markerY + size);
        glVertex2f(markerX - size, markerY + size);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(markerX - 0.08f, markerY + size + 0.05f);
    const unsigned char* label = (const unsigned char*)"Marker";
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, label);
    glRasterPos2f(-0.9f, 0.85f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)coordinateText);

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        toGL(x, y, &markerX, &markerY);
        glutPostRedisplay();
    }
}

void passiveMotion(int x, int y)
{
    toGL(x, y, &mouseX, &mouseY);
    snprintf(coordinateText, sizeof(coordinateText), "Mouse: (%.2f, %.2f)", mouseX, mouseY);
    glutPostRedisplay();
}

void idle()
{
    pulseAngle += 0.003f;
    if (pulseAngle > 6.28318f)
    {
        pulseAngle = 0.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q20 - Interactive Text Placer");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    snprintf(coordinateText, sizeof(coordinateText), "Mouse: (0.00, 0.00)");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
