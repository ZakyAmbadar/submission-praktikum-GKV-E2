#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Bersihkan layar
    glLoadIdentity(); // Reset transformasi
    
    // *** 1. Panah kiri menggunakan GL_LINE_LOOP ***
    glColor3f(1.0, 1.0, 1.0); // Warna putih
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
    glColor3f(1.0, 1.0, 1.0); // Warna putih
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.4, 0.2);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.6, 0.9);
    glVertex2f(1.0, 0.5);
    glVertex2f(0.8, 0.5);
    glVertex2f(0.8, 0.2);
    glEnd();

    // *** Garis horizontal diturunkan sedikit ke bawah ***
    glBegin(GL_LINES);
    glVertex2f(0.4, 0.50);  // Titik kiri garis horizontal (diturunkan)
    glVertex2f(0.8, 0.50);  // Titik kanan garis horizontal
    glEnd();

    // *** 3. GL_TRIANGLE_FAN - Segitiga kipas dengan ukuran seragam ***
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.8, -0.3);  // Tengah
    glColor3f(0.0, 1.0, 0.0); glVertex2f(-1.0, -0.6);
    glColor3f(0.0, 0.0, 1.0); glVertex2f(-0.8, -0.7);
    glColor3f(1.0, 1.0, 0.0); glVertex2f(-0.6, -0.6);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.8, -0.3);
    glEnd();

    // *** 4. GL_TRIANGLE_STRIP - Strip segitiga dengan ukuran seragam ***
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(-0.4, -0.3);
    glColor3f(0.0, 1.0, 1.0); glVertex2f(-0.6, -0.6);
    glColor3f(1.0, 1.0, 0.0); glVertex2f(-0.2, -0.6);
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.0, -0.3);
    glEnd();
    
    // *** 5. GL_QUADS - Trapesium dengan ukuran seragam ***
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); glVertex2f(0.2, -0.2);  // Kiri atas
    glColor3f(1.0, 0.0, 0.0); glVertex2f(0.4, -0.2);  // Kanan atas
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5, -0.4);  // Kanan bawah (lebih lebar)
    glColor3f(1.0, 1.0, 0.0); glVertex2f(0.1, -0.4);  // Kiri bawah (lebih lebar)
    glEnd();

    // *** 6. GL_POLYGON - Persegi dengan satu titik di tengah (ukuran seragam) ***
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); glVertex2f(0.6, -0.2);  // Kiri atas
    glColor3f(0.0, 1.0, 0.0); glVertex2f(0.8, -0.2);  // Kanan atas
    glColor3f(0.0, 0.0, 1.0); glVertex2f(0.8, -0.4);  // Kanan bawah
    glColor3f(1.0, 1.1, 0.0); glVertex2f(0.6, -0.4);  // Kiri bawah
    glColor3f(1.0, 1.5, 0.0); glVertex2f(0.7, -0.3);  // Titik tengah dalam
    glEnd();

    glFlush();
}

// Fungsi inisialisasi
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Latar belakang hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.0, 1.0); // Area pandang 2D
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

