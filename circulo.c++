#include <GL/glut.h>
#include <cmath>

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Cor de fundo branca
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Definir o sistema de coordenadas
}

void drawCircle(float radius, float red, float green, float blue) {
    glColor3f(red, green, blue); // Define a cor
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro do círculo
    int numSegments = 100; // Define a precisão do círculo
    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * 2.0f * M_PI / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha os círculos concêntricos, do maior para o menor
    drawCircle(0.6f, 0.0f, 0.0f, 0.3f); // Círculo externo (azul escuro)
    drawCircle(0.4f, 0.0f, 0.0f, 0.5f); // Círculo do meio (azul médio)
    drawCircle(0.2f, 1.0f, 1.0f, 1.0f); // Círculo central (branco)

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Target Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
