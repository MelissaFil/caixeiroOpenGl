#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.1415926535


FILE *arqEntrada;
FILE * arqSaida;
int sizex, sizey;
int n;
int matrizCidade[10][10];
int ponteiroDeViagem=0;


void Caminhao(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(0,0,1);

	glVertex3f(x+3.0,y+1.0,0);
	glVertex3f(x+2, y+1.0,0);
	glVertex3f(x+2,y+6.0,0);
	glVertex3f(x+3,y+6.0,0);
	glVertex3f(x-3.0,y-1.0,0);
	glVertex3f(x-2, y-1.0,0);
	glVertex3f(x-2,y-6.0,0);
	glVertex3f(x-3,y-6.0,0);
	
	glVertex3f(x+3.0,y-1.0,0);
	glVertex3f(x+2, y-1.0,0);
	glVertex3f(x+2,y-6.0,0);
	glVertex3f(x+3,y-6.0,0);
	
	glVertex3f(x-3.0,y+1.0,0);
	glVertex3f(x-2, y+1.0,0);
	glVertex3f(x-2,y+6.0,0);
	glVertex3f(x-3,y+6.0,0);

}


void Cidades (){
	arqEntrada = fopen ("Cidades.txt", "r");
	fscanf(arqEntrada, "%d\n", &n);
	matrizCidade[n][2];
	
	int x,y;
	
	for (int i = 1; i <= n; i++) {
		glPointSize(10.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_POINTS);
		fscanf (arqEntrada, "%d %d\n", &x, &y);
		printf("%d %d \n",x, y);
		glVertex2f(x, y);
		matrizCidade[i-1][0] = x;
		matrizCidade[i-1][1] = y;
		
	};
}

// Fun��o callback chamada para gerenciar eventos de teclado
void ProximaParada(unsigned char key, int x, int y)
{	

if(key == 13){

		fscanf (arqSaida, "%d\n", &ponteiroDeViagem);
		printf("ponteiro %d \n",ponteiroDeViagem);

		x=matrizCidade[ponteiroDeViagem-1][0];
		y=matrizCidade[ponteiroDeViagem-1][1];
		
		Caminhao(x, y);
		
		printf("Coordenadas atual x: %d y: %d \n",x, y);


}
		glEnd();
		glFlush();		
}



void Desenhar(void){
	glClear(GL_COLOR_BUFFER_BIT); // Limpa a janela de visualiza��o
    glColor3f(1.0f, 1.0f, 0.0f);
    arqSaida = fopen ("caminho.txt", "r");
    
    //Iniciando pontos(cidades)
	Cidades();
	
	int x,y;
	arqEntrada = fopen ("Cidades.txt", "r");
	glPointSize(15.0);
	glColor3f(1.0f, 0.0f, 0.0f);
	fscanf (arqEntrada, "%d\n\n%d %d\n",&n, &x, &y);
	
	//Iniciando quadradro do caminh�o	
	Caminhao(x, y);

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
 

 sizex =500;
 sizey = 500;
 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(sizex,sizey);
 glutInitWindowPosition(10,10);
 glutCreateWindow("C�rculo");
 glutDisplayFunc(Desenhar);
 glutReshapeFunc(AlteraTamanhoJanela);
 glutKeyboardFunc(ProximaParada);
 Inicializa();
 glutMainLoop();

 return 0;
}

