#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.1415926535

FILE *arqEntrada;
int sizex, sizey;
int n, i;
// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
     float angle, raio_x, raio_y;
     int i=1, circle_points = 1;
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();             
     // Limpa a janela de visualiza��o com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);
     // Especifica que a cor corrente � branca
     //         R     G     B
     glColor3f(1.0f, 1.0f, 1.0f);
     // Especifica o tamanho do pixel
     glPointSize(15.0);
     // Desenha um c�rculo (elipse) preenchido com a cor corrente
     //glBegin(GL_LINE_LOOP);
     //glBegin(GL_CIRCLE);
	 raio_x = 20.0;
     raio_y = 20.0;
     
        angle = (2*PI*i)/circle_points;
        glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
    
     glEnd();
     // Executa os comandos OpenGL
     glFlush();
}

void point(void){
	
		arqEntrada = fopen ("caminho.txt", "r");
		glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de visualiza��o
     	glColor3f(1.0f, 1.0f, 0.0f);
		// Desenha um quadrado preenchido com a cor corrente
 		glPointSize(10.0);
		arqEntrada = fopen ("Cidades.txt", "r");
		
		fscanf (arqEntrada, "%d\n", &n);
		for (int x = 1; x <= n; x++) {
			glPointSize(10.0*x);
			glColor3f(1.0f, 1.0f, 0.0f+x);
			glBegin(GL_POINTS);
			glVertex2f(70+(x*5), 70+(x*5));
	};
 //glBegin(GL_POINTS);
//glVertex2f(70, 70);

 glEnd();
 
glFlush();
}
// Inicializa par�metros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimens�es da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de sele��o (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(int argc, char ** argv) {


 sizex = 500;
 sizey = 500;
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("C�rculo");
 glutDisplayFunc(point);
 glutReshapeFunc(AlteraTamanhoJanela);
 Inicializa();
 glutMainLoop();

 return 0;
}

