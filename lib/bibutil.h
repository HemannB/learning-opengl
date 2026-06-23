#ifndef __BIBUTIL_H
#define __BIBUTIL_H

//*****************************************************
//
// bibutil.h
// Cont�m as estruturas e rotinas implementadas na 
// biblioteca de rotinas auxiliares (bibutil.cpp).
//
// Isabel H. Manssour e Marcelo Cohen
//
// Este c�digo acompanha o livro
// "OpenGL - Uma Abordagem Pr�tica e Objetiva" 
// 
//*****************************************************

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

extern "C" {
	#include <jpeglib.h>
}

#ifndef M_PI
#define M_PI 3.1415926
#endif

// Define a estrutura de uma imagem
typedef struct
{
	char nome[50];			// nome do arquivo carregado
	int ncomp;				// n�mero de componentes na textura (1-intensidade, 3-RGB)
	GLint dimx;				// largura 
	GLint dimy;				// altura
	GLuint texid;			// identifi��o da textura em OpenGL
	unsigned char *data;	// apontador para a imagem em si
} TEX;

// Define a estrutura de um v�rtice
typedef struct {
	GLfloat x,y,z;
} VERT;

// Define a estrutura de uma face
typedef struct {
	GLint nv;		// n�mero de v�rtices na face
	GLint *vert;	// �ndices dos v�rtices
	GLint *norm;	// �ndices das normais
	GLint *tex;		// �ndices das texcoords
	GLint mat;		// �ndice para o material (se houver)
	GLint texid;	// �ndice para a textura (se houver)
} FACE;

// Define a estrutura de uma coordenada
// de textura (s,t,r) - r n�o � usado
typedef struct {
	GLfloat s,t,r;
} TEXCOORD;

// Define a estrutura de um objeto 3D
typedef struct {
	GLint numVertices;
	GLint numFaces;
	GLint numNormais;
	GLint numTexcoords;
	bool normais_por_vertice;	// true se houver normais por v�rtice
	bool tem_materiais;			// true se houver materiais
	GLint textura;				// cont�m a id da textura a utilizar, caso o objeto n�o tenha textura associada
	GLint dlist;				// display list, se houver
	VERT *vertices;
	VERT *normais;
	FACE *faces;
	TEXCOORD *texcoords;
} OBJ;

// Define um material
typedef struct {
	char nome[20];	// Identifica��o do material
	GLfloat ka[4];	// Ambiente
	GLfloat kd[4];	// Difuso
	GLfloat ks[4];	// Especular
	GLfloat ke[4];	// Emiss�o
	GLfloat spec;	// Fator de especularidade
} MAT;

// Prot�tipos das fun��es
// Fun��es para c�lculos diversos
void Normaliza(VERT &norm);
void ProdutoVetorial (VERT &v1, VERT &v2, VERT &vresult);
void VetorNormal(VERT vert1, VERT vert2, VERT vert3, VERT &n);
void RotaZ(VERT &in, VERT &out, float ang);
void RotaY(VERT &in, VERT &out, float ang);
void RotaX(VERT &in, VERT &out, float ang);

// Fun��es para carga e desenho de objetos
OBJ *CarregaObjeto(char *nomeArquivo, bool mipmap);
void CriaDisplayList(OBJ *obj);
void DesabilitaDisplayList(OBJ *ptr);
void DesenhaObjeto(OBJ *obj);
void SetaModoDesenho(char modo);

// Fun��es para libera��o de mem�ria
void LiberaObjeto(OBJ *obj);
void LiberaMateriais();

// Fun��es para c�lculo e exibi��o da taxa de quadros por segundo
float CalculaQPS(void);
void Escreve2D(float x, float y, char *str);

// Fun��es para c�lculo de normais
void CalculaNormaisPorFace(OBJ *obj);

// Fun��es para manipula��o de texturas e materiais
TEX *CarregaTextura(char *arquivo, bool mipmap);
TEX *CarregaTexturasCubo(char *arquivo, bool mipmap);
void SetaFiltroTextura(GLint tex, GLint filtromin, GLint filtromag);
MAT *ProcuraMaterial(char *nome);
TEX *CarregaJPG(const char *filename, bool inverte=true);

// Constantes utilizadas caso n�o existam em GL/gl.h
#ifndef GL_ARB_texture_cube_map
# define GL_NORMAL_MAP					0x8511
# define GL_REFLECTION_MAP				0x8512
# define GL_TEXTURE_CUBE_MAP			0x8513
# define GL_TEXTURE_BINDING_CUBE_MAP	0x8514
# define GL_TEXTURE_CUBE_MAP_POSITIVE_X	0x8515
# define GL_TEXTURE_CUBE_MAP_NEGATIVE_X	0x8516
# define GL_TEXTURE_CUBE_MAP_POSITIVE_Y	0x8517
# define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y	0x8518
# define GL_TEXTURE_CUBE_MAP_POSITIVE_Z	0x8519
# define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z	0x851A
# define GL_PROXY_TEXTURE_CUBE_MAP		0x851B
# define GL_MAX_CUBE_MAP_TEXTURE_SIZE	0x851C
#endif

#endif
