#include <GL/glut.h>
#include <cmath>

float angle = 0.0f; // Ângulo de rotação inicial

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Cor de fundo branca
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define o sistema de coordenadas
}

void drawCircle() {
    int numSegments = 100; // Número de segmentos para formar o círculo
    float radius = 0.5f;   // Raio do círculo

    // Desenha o círculo multicolorido
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro do círculo
    for (int i = 0; i <= numSegments; i++) {
        // Alteração de cor a cada segmento
        glColor3f((i % 3 == 0) ? 1.0f : 0.0f, (i % 3 == 1) ? 1.0f : 0.0f, (i % 3 == 2) ? 1.0f : 0.0f);

        // Calcula a posição de cada ponto do círculo com o ângulo aplicado
        float theta = 2.0f * 3.14 * float(i) / float(numSegments) + angle;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotação no eixo Z para criar o efeito de rotação do círculo
    drawCircle();
    glPopMatrix();

    glFlush();
}

void update(int value) {
    angle -= 1.0f; // Decrementa o ângulo para rotacionar no sentido horário
    if (angle <= -360.0f) {
        angle += 360.0f; // Reinicia o ângulo após uma rotação completa
    }

    glutPostRedisplay(); // Redesenha a tela
    glutTimerFunc(16, update, 0); // Chama a função novamente em 16 ms (~60 fps)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Rotating Multicolor Circle");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); // Inicia o timer para atualizar o ângulo
    glutMainLoop();
    return 0;
}
