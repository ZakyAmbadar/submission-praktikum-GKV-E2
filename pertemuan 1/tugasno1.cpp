#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 
    
    // *** 1. Panah kiri menggunakan GL_LINE_LOOP ***
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.8, 0.2);
    glVertex2f(-0.8, 0.5);
    glVertex2f(-1.0, 0.5);
    glVertex2f(-0.6, 0.9);
    glVertex2f(-0.2, 0.5);
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.4, 0.2);
    glEnd();

    // *** 2. Panah kanan menggunakan GL_LINE_LOOP ***
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.6, 0.9);
    glVertex2f(1.0, 0.5);
    glVertex2f(0.8, 0.5);
    glVertex2f(0.8, 0.2);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(0.4, 0.50);  
    glVertex2f(0.8, 0.50); 
    glEnd();

    // *** 3. GL_TRIANGLE_FAN 
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.8, -0.3);  
    glColor3f(0.0, 1.0, 0.0); glVertex2f(-1.0, -0.6);
    glColor3f(0.0, 0.0, 1.0); glVertex2f(-0.8, -0.7);
    glColor3f(1.0, 1.0, 0.0); glVertex2f(-0.6, -0.6);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.8, -0.3);
    glEnd();

    // *** 4. GL_TRIANGLE_STRIP 
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.4, -0.3);
    glColor3f(0.0, 1.0, 1.0); glVertex2f(-0.6, -0.6);
    glColor3f(1.0, 1.0, 0.0); glVertex2f(-0.2, -0.6);
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.0, -0.3);
    glEnd();
    
    // *** 5. GL_QUADS - Trapesium dengan ukuran seragam ***
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); glVertex2f(0.2, -0.2); 
    glColor3f(1.0, 0.0, 0.0); glVertex2f(0.4, -0.2);  
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5, -0.4);  
    glColor3f(1.0, 1.0, 0.0); glVertex2f(0.1, -0.4);  
    glEnd();

    // *** 6. GL_QUAD_STRIP*
    glBegin(GL_QUAD_STRIP);
glColor3f(1.0, 0.0, 0.0); glVertex2f(0.55, -0.6);  
glColor3f(0.0, 1.0, 0.0); glVertex2f(0.95, -0.6);  
glColor3f(0.0, 0.0, 1.0); glVertex2f(0.6, -0.3);   
glColor3f(1.0, 1.0, 0.0); glVertex2f(1.0, -0.3);   
glEnd();


    glFlush();
}

// Fungsi inisialisasi
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.0, 1.0); 
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

