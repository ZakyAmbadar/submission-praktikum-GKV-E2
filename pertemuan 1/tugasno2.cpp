#include <GL/glut.h>

const float CUBE_SIZE = 0.2f;  
const float PADDING = 0.02f;   

void drawCube(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b); 
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + CUBE_SIZE, y);
    glVertex2f(x + CUBE_SIZE, y + CUBE_SIZE);
    glVertex2f(x, y + CUBE_SIZE);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float colors[5][5][3] = {
        {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {1, 0, 1}},
        {{0, 1, 1}, {1, 0.5, 0}, {0.5, 0, 0.5}, {0.5, 0.5, 0}, {0.2, 0.8, 0.5}},
        {{0.8, 0.3, 0.6}, {0.2, 0.6, 1}, {0.6, 0.2, 0.8}, {0.1, 0.9, 0.3}},
        {{0.5, 0.5, 1}, {1, 0.2, 0.5}, {0.3, 0.7, 0.2}},
        {{1, 1, 0}}
    };

    float startX = -0.5f; 
    float startY = -0.6f; 

    for (int row = 0; row < 5; row++) {
        float x = startX + row * (CUBE_SIZE / 2 + PADDING / 2);
        float y = startY + row * (CUBE_SIZE + PADDING);

        for (int col = 0; col < 5 - row; col++) {
            drawCube(x, y, colors[row][col][0], colors[row][col][1], colors[row][col][2]);
            x += CUBE_SIZE + PADDING;
        }
    }

    glFlush();
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Piramida Kubus Bertingkat");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

