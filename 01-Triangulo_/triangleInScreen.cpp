//
// Created by bruno on 23/06/2026.
//
#include <GL/glut.h>
#include <stdlib.h>

// função callback de redesenho da janela de visualizaçõa...
void Draw(void)
{
    //Limpa a janela de visualização com a cor branca
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);

    //Define a cor do desenho
    glColor3f(1,0,0);

    //Desenha um triangulo no centro da janela
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5,-0.5,0);
        glVertex3f(0,0.5,0);
        glVertex3f(0.5,-0.5,0);
    glEnd();

    //Executa os comandos OpenGL
    glFlush();
}

void KeyboardHandler(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

//função responsável por incizializar parametros e variaveis
void Initialize(void)
{
    //Define a janela de visualização 2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    //Inicializa o GLUT
    glutInit(&argc, argv);

    //Define o modo de operação GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);

    //Especifica o tamanho da janela em pixels
    glutInitWindowSize(400,400);

    //Cria a janela passando como argumento o titulo dela
    glutCreateWindow("Hello World in OpenGL, WTF this is a f*cking RED TRIANGLE IN MY SCREEN ");

    //Registra a função callback de redesenho da janela de visualização
    glutDisplayFunc(Draw);

    //Registra a função callback para tratmento de teclas ASCII
    glutKeyboardFunc(KeyboardHandler);

    //Chamada da função responsável por fazer a incialização
    Initialize();

    //Inicia o processamento e agurada intereção do usr
    glutMainLoop();

    return 0;
}