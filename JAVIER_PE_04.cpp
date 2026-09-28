// Exercise Q04 — Keyboard Background Color Switch [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

float bgRed = 0.0f;
float bgGreen = 0.0f;
float bgBlue = 0.0f;

void display()
{
    // set the background color
    glClearColor(bgRed, bgGreen, bgBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r')
    {
        bgRed = 1.0f;
        bgGreen = 0.0f;
        bgBlue = 0.0f;
    }
    else if (key == 'g')
    {
        bgRed = 0.0f;
        bgGreen = 1.0f;
        bgBlue = 0.0f;
    }
    else if (key == 'b')
    {
        bgRed = 0.0f;
        bgGreen = 0.0f;
        bgBlue = 1.0f;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q04 - Keyboard Background Color Switch");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}