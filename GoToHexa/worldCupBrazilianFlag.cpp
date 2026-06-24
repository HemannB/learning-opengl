//
// Created by bruno on 23/06/2026.
//
//
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Desenha um círculo preenchido
void DrawCircle(float cx, float cy, float r)
{
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= numSegments; i++) {
            float angle = 2.0f * M_PI * i / numSegments;
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();
}

void Draw(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Retângulo verde (fundo da bandeira)
    glColor3f(0.0f, 0.51f, 0.24f); // verde Brasil
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.7f);
        glVertex2f( 1.0f, -0.7f);
        glVertex2f( 1.0f,  0.7f);
        glVertex2f(-1.0f,  0.7f);
    glEnd();

    // Losango amarelo
    glColor3f(1.0f, 0.84f, 0.0f); // amarelo ouro
    glBegin(GL_QUADS);
        glVertex2f( 0.0f,  0.55f);
        glVertex2f( 0.85f, 0.0f);
        glVertex2f( 0.0f, -0.55f);
        glVertex2f(-0.85f, 0.0f);
    glEnd();

    // Círculo azul
    glColor3f(0.06f, 0.22f, 0.55f); // azul Brasil
    DrawCircle(0.0f, 0.0f, 0.32f);

    // Faixa branca (ordem e progresso - simplificada)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.32f, -0.045f);
        glVertex2f( 0.32f, -0.045f);
        glVertex2f( 0.32f,  0.045f);
        glVertex2f(-0.32f,  0.045f);
    glEnd();

    // Texto na faixa (simplificado)
    glColor3f(0.06f, 0.22f, 0.55f);
    glRasterPos2f(-0.18f, -0.018f);
    const char* texto = "ORDEM E PROGRESSO";
    for (const char* c = texto; *c != '\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);

    glFlush();
}

void KeyboardHandler(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

void Initialize(void)
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Brasil Rumo ao HEXA 2026!!!");

    glutDisplayFunc(Draw);
    glutKeyboardFunc(KeyboardHandler);

    Initialize();
    glutMainLoop();

    return 0;
}