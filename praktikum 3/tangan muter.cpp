// nama : Zaky Ambadar
// NIM  : 24060123140168

#include <GL/glut.h> 

// Variabel rotasi untuk bagian-bagian tubuh
static int shoulder = 0, elbow = 0, wrist = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0, finger4 = 0, finger5 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Gerakan bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // Lengan atas
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Gerakan siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // Lengan bawah
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Gerakan pergelangan tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    
    // Telapak tangan
    glPushMatrix();
    glScalef(1.0, 0.4, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari 1 (Paling kiri)
    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.3);
    glRotatef((GLfloat)finger1, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.6, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari 2
    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.15);
    glRotatef((GLfloat)finger2, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.6, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari 3 (Tengah)
    glPushMatrix();
    glTranslatef(0.5, 0.2, 0.0);
    glRotatef((GLfloat)finger3, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.6, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari 4
    glPushMatrix();
    glTranslatef(0.5, 0.2, -0.15);
    glRotatef((GLfloat)finger4, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.6, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    // Jari 5 (Paling kanan / jempol)
    glPushMatrix();
    glTranslatef(0.5, 0.0, -0.3);
    glRotatef((GLfloat)finger5, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.6, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Gerakan bahu
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;

        // Gerakan siku
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;

        // Gerakan pergelangan tangan
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;

        // Gerakan jari 1 (Paling kiri)
        case '1': finger1 = (finger1 + 5) % 90; break;
        case '!': finger1 = (finger1 - 5) % 90; break;

        // Gerakan jari 2
        case '2': finger2 = (finger2 + 5) % 90; break;
        case '@': finger2 = (finger2 - 5) % 90; break;

        // Gerakan jari 3 (Tengah)
        case '3': finger3 = (finger3 + 5) % 90; break;
        case '#': finger3 = (finger3 - 5) % 90; break;

        // Gerakan jari 4
        case '4': finger4 = (finger4 + 5) % 90; break;
        case '$': finger4 = (finger4 - 5) % 90; break;

        // Gerakan jari 5 (Jempol)
        case '5': finger5 = (finger5 + 5) % 90; break;
        case '%': finger5 = (finger5 - 5) % 90; break;

        // Keluar dari program
        case 27: exit(0); break;

        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan dengan 5 Jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

