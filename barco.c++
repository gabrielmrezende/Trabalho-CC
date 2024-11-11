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
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(0.6f, -0.4f);
    glVertex2f(0.4f, -0.6f);
    glVertex2f(-0.4f, -0.6f);
    glEnd();

    // Vela esquerda (cinza)
    glColor3f(0.7f, 0.7f, 0.7f); // Cor cinza
    glBegin(GL_TRIANGLES);
    glVertex2f(0.02f, 0.3f);    // Topo da vela
    glVertex2f(-0.3f, -0.4f);   // Base esquerda
    glVertex2f(0.02f, -0.4f);   // Base direita
    glEnd();

    // Vela direita (cinza)
    glColor3f(0.7f, 0.7f, 0.7f); // Cor cinza
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.02f, 0.3f);   // Topo da vela
    glVertex2f(0.3f, -0.4f);    // Base direita
    glVertex2f(-0.02f, -0.4f);  // Base esquerda
    glEnd();

    // Mastro (marrom)
    glColor3f(0.5f, 0.3f, 0.1f); // Cor marrom
    glBegin(GL_QUADS);
    glVertex2f(-0.02f, -0.4f);
    glVertex2f(0.02f, -0.4f);
    glVertex2f(0.02f, 0.4f);
    glVertex2f(-0.02f, 0.4f);
    glEnd();

    // Bandeira (azul), alinhada com o mastro
    glColor3f(0.2f, 0.2f, 0.8f); // Cor azul
    glBegin(GL_QUADS);
    glVertex2f(0.02f, 0.4f);    // Ponto de início da bandeira alinhado ao topo do mastro
    glVertex2f(0.15f, 0.4f);    // Extensão da bandeira para a direita
    glVertex2f(0.15f, 0.5f);    // Altura da bandeira
    glVertex2f(0.02f, 0.5f);    // Fechando a bandeira
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
