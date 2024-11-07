#include <GL/glut.h>

float xPosition = -0.9f; // Posição inicial no eixo X
float speed = 0.01f; // Velocidade de movimento

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Cor de fundo branca
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define o sistema de coordenadas
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Translada o quadrado para a posição atual no eixo X
    glPushMatrix();
    glTranslatef(xPosition, 0.0f, 0.0f);

    // Desenha o quadrado roxo
    glColor3f(0.5f, 0.0f, 0.5f); // Cor roxa
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();

    glPopMatrix();
    glFlush();
}

void update(int value) {
    // Atualiza a posição do quadrado
    xPosition += speed;

    // Inverte a direção ao alcançar os limites da tela
    if (xPosition > 0.9f || xPosition < -0.9f) {
        speed = -speed;
    }

    glutPostRedisplay(); // Redesenha a tela
    glutTimerFunc(16, update, 0); // Chama a função novamente em 16ms (~60fps)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Animated Purple Square");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0); // Inicia o timer para atualizar a posição
    glutMainLoop();
    return 0;
}
