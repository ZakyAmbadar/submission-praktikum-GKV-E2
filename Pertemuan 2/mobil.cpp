// Nama : Zaky Ambadar
// NIM  : 24060123140168

#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.2);
    glVertex2f(0.5, -0.2);
    glVertex2f(0.5, 0.1);
    glVertex2f(-0.5, 0.1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.3, 0.1);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.2, 0.3);
    glVertex2f(-0.2, 0.3);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.18, 0.12);
    glVertex2f(-0.02, 0.12);
    glVertex2f(-0.02, 0.28);
    glVertex2f(-0.18, 0.28);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.02, 0.12);
    glVertex2f(0.18, 0.12);
    glVertex2f(0.18, 0.28);
    glVertex2f(0.02, 0.28);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    float angle;
    float radius = 0.1;
    float x_center = -0.3, y_center = -0.2; 

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        angle = i * 3.14159 / 180;
        glVertex2f(x_center + cos(angle) * radius, y_center + sin(angle) * radius);
    }
    glEnd();

    x_center = 0.3;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        angle = i * 3.14159 / 180;
        glVertex2f(x_center + cos(angle) * radius, y_center + sin(angle) * radius);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

