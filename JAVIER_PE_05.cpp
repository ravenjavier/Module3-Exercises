// Exercise Q05 — Mouse Button Text Color [Easy] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

int textChoice = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (textChoice == 1)
    {
        // left button text - green
        glColor3f(0.0f, 1.0f, 0.0f);
        glRasterPos2f(-0.3f, 0.0f);
        const unsigned char* text =(const unsigned char*)"Left button text";
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
    }
    else if (textChoice == 2)
    {
        // right button text - red
        glColor3f(1.0f, 0.0f, 0.0f);
        glRasterPos2f(-0.3f, 0.0f);
        const unsigned char* text = (const unsigned char*)"Right button text";
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, text);
    }

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    (void)x;
    (void)y;

    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            textChoice = 1;
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            textChoice = 2;
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Exercise Q05 - Mouse Button Text Color");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}