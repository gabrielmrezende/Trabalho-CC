#include <GL/glut.h>

void init() {
    glClearColor(1.0f, 0.9f, 0.8f, 1.0f); // Cor de fundo (bege claro)
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Definir o sistema de coordenadas
}

void drawBoat() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Casco do barco (vermelho)
    glColor3f(1.0f, 0.0f, 0.0f); // Cor vermelha
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.3f);
    glVertex2f(0.5f, -0.3f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(-0.3f, -0.5f);
    glEnd();

    // Mastro (marrom)
    glColor3f(0.5f, 0.3f, 0.1f); // Cor marrom
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, -0.3f);
    glVertex2f(0.05f, -0.3f);
    glVertex2f(0.05f, 0.4f);
    glVertex2f(-0.05f, 0.4f);
    glEnd();

    // Vela (cinza)
    glColor3f(0.7f, 0.7f, 0.7f); // Cor cinza
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.0f, -0.3f);
    glEnd();

    // Bandeira (azul)
    glColor3f(0.2f, 0.2f, 0.8f); // Cor azul
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Boat Drawing");
    init();
    glutDisplayFunc(drawBoat);
    glutMainLoop();
    return 0;
}
