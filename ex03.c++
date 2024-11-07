#include <GL/glut.h>

float yPosition = 0.0f; // Posição inicial do quadrado no eixo Y

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Cor de fundo branca
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Definindo o sistema de coordenadas
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Movendo o quadrado para a posição atual no eixo Y
    glPushMatrix();
    glTranslatef(0.0f, yPosition, 0.0f); // Aplica translação no eixo Y

    // Desenha o quadrado vermelho
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();

    glPopMatrix();
    glFlush();
}

// Função chamada quando uma tecla é pressionada
void keyboard(unsigned char key, int x, int y) {
    if (key == 32) { // Código ASCII para a barra de espaço
        yPosition += 0.1f; // Incrementa a posição Y para mover o quadrado para cima
        glutPostRedisplay(); // Atualiza a tela para aplicar a mudança
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Moving Square");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Define o callback para eventos de teclado
    glutMainLoop();
    return 0;
}
