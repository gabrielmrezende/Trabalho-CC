#include <GL/glut.h>
#include <cmath>

// Função para desenhar um círculo com centro em (x, y), raio r e cor RGB
void drawCircle(float x, float y, float r, float red, float green, float blue) {
    glColor3f(red, green, blue);  // Define a cor do círculo
    glBegin(GL_TRIANGLE_FAN);     // Inicia o modo de desenho com triângulos em forma de leque
    glVertex2f(x, y);             // Define o centro do círculo
    int numSegments = 100;        // Define a quantidade de segmentos para suavidade do círculo
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.14 * i / numSegments;  // Calcula o ângulo
        float dx = r * cosf(angle);                   // Coordenada x do ponto
        float dy = r * sinf(angle);                   // Coordenada y do ponto
        glVertex2f(x + dx, y + dy);                   // Define o ponto no círculo
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Parâmetros para os círculos
    float centerX = 0.0f, centerY = 0.0f;
    float radius1 = 0.8f;  // Raio do círculo maior
    float radius2 = 0.6f;  // Raio do círculo intermediário
    float radius3 = 0.4f;  // Raio do círculo menor
    float radius4 = 0.2f;  // Raio do círculo menor

    // Desenha os círculos do maior para o menor
    drawCircle(centerX, centerY, radius1, 0.0f, 0.0f, 0.3f); // Azul escuro para o círculo maior
    drawCircle(centerX, centerY, radius2, 0.0f, 0.0f, 0.5f); // Azul mais claro para o círculo intermediário
    drawCircle(centerX, centerY, radius3, 0.0f, 0.0f, 0.3f); // Azul escuro para o círculo maior
    drawCircle(centerX, centerY, radius4, 1.0f, 1.0f, 1.0f); // Branco para o círculo menor (interior)

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fundo branco
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // Configura a visão ortogonal
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Desenho de Círculos Concêntricos");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
