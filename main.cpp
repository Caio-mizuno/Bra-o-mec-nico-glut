#include <GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3,14
float andar=0,b1=0,b2=0,m=0,d=0;

GLfloat view_w,view_h,win;
/* GLUT callback Handlers */

///----------------------------------------------------------------
static void Quadrado(float r,float g,float b){

    glColor3f(r,g,b);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f,-1.0f);
        glVertex2f(1.0f,-1.0f);
        glVertex2f(1.0f,1.0f);
        glVertex2f(-1.0f,1.0f);
    glEnd();

    glFlush();

}
///----------------------------------------------------------------

static void linha(void)
{
     glColor3f(0.0,0.0,0.0);
     glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2f(win,0);
        glVertex2f(-win,0);
    glEnd();
   glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2f(0,win);
        glVertex2f(0,-win);
    glEnd();
    glFlush();

}

///----------------------------------------------------------------
   void retangulo2(float r, float g, float b){

       glPushMatrix();
            glScalef(25.0f,100.0f,0.0f);
            Quadrado(r,g,b);
        glPopMatrix();
    }
///----------------------------------------------------------------
    void retangulo1(float r, float g, float b){

       glPushMatrix();
            glScalef(100.0f,25.0f,0.0f);
            Quadrado(r,g,b);
        glPopMatrix();
    }

///----------------------------------------------------------------

  void retangulo3(float r, float g, float b){

       glPushMatrix();
            glScalef(30.0f,30.0f,0.0f);
            Quadrado(r,g,b);
        glPopMatrix();
    }

///----------------------------------------------------------------

void mao(float r, float g, float b){

       glPushMatrix();
            glScalef(20.0f,80.0f,0.0f);
            Quadrado(r,g,b);
        glPopMatrix();
    }
///----------------------------------------------------------------

void dedo(float r, float g, float b)
{
    glPushMatrix();
            glScalef(50.0f,15.0f,0.0f);
            Quadrado(r,g,b);
        glPopMatrix();
    }
///----------------------------------------------------------------
void circulo(){
    glPushMatrix();
    float angulo;
    glBegin(GL_POLYGON);
        for (int i = 0; i <360; i++) {

            angulo = i * PI * 2 / 360;
            glVertex2f((cos(angulo)),(sin(angulo)));

        }

    glEnd();
    glPopMatrix();
}
void C_maior(float r, float g, float b){
    glPushMatrix();
    glColor3f(r,g,b);
    glScalef(15.0f,15.0f,0.0f);
    circulo();
    glPopMatrix();
}
void C_menor(float r, float g, float b){
    glPushMatrix();
    glColor3f(r,g,b);
    glScalef(5.0f,5.0f,0.0f);
    circulo();
    glPopMatrix();
}
///----------------------------------------------------------------

 void desenho(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    ///BRAÇO - rosa
    //escalo o tamanho do quadrado
    glTranslatef(andar,-50.0f,0.0f);
    retangulo1(1,0,1);

    ///BRAÇO - azul
    glRotatef(b1,0.0f,0.0f,1.0f);
    glTranslatef(0.0f,100.0f,0.0f);
    retangulo2(0,0,1);
///---------------------------------------
///circulo 1
    glPushMatrix();
        glTranslatef(0.0f,-100.0f,0.0f);
        C_maior(0,0,0);
        C_menor(1,0,0);

    glPopMatrix();
///---------------------------------------

    ///BRAÇO - amarelo
    glTranslatef(0.0f,75.0f,0.0f);
    glRotatef(b2,0,0,1);
    glTranslatef(75.0f,0.0f,0.0f);
    retangulo1(1,1,0);
///---------------------------------------
///circulo 2
    glPushMatrix();
        glTranslatef(-75.0f,0.0f,0.0f);
        C_maior(0,0,0);
        C_menor(1,0,0);

    glPopMatrix();
///---------------------------------------

    ///MAO - quadrado
    glTranslatef(100.0f,0.0f,0.0f);
    glRotatef(m,0,0,1);
    glTranslatef(0.0f,0.0f,0.0f);
    retangulo3(1.0,0.5,0.5);
///---------------------------------------
///circulo 3
    glPushMatrix();
        glTranslatef(-10.0f,0.0f,0.0f);
        C_maior(0,0,0);
        C_menor(1,0,0);

    glPopMatrix();
///---------------------------------------
    ///MAO - RETANGULO
    glTranslatef(0.0f,2.5f,0.0f);
    glRotatef(0,0,0,1);
    glTranslatef(30.0f,0.0f,0.0f);
    mao(0.0,0.5,0.5);

    ///dedos ----------------------

    ///dedo-vermelho
    glPushMatrix();
         glTranslatef(0.0f,65.0f,0.0f);
         glRotatef(-d,0,0,1);
         glTranslatef(50.0f,0.0f,0.0f);
        dedo(1,0,0);
    glPopMatrix();
    ///dedo-cinza
    glPushMatrix();
            glTranslatef(0.0f,-65.0f,0.0f);
         glRotatef(d,0,0,1);
         glTranslatef(50.0f,0.0f,0.0f);
        dedo(0.2,0.2,0.2);
    glPopMatrix();




glFlush();

}




///----------------------------------------------------------------
/// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{   // Especifica as dimensões do viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;
    win=400.0f;
    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //tratamento da janela
    if (h==0){
        h=1;
    }
    if(w<=h){
        gluOrtho2D (-win, win, -win* h/w, win * h/w);
    }else{
        gluOrtho2D (-win * w/h, win * w/h, -win, win);
    }

}
///----------------------------------------------------------------
static void desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);

    desenho();

    glFlush();

}

///----------------------------------------------------------------
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        ///--------------------
        ///andar
        case 'c':
            andar++;

            break;

        case 'z':
            andar--;
        ///--------------------
        ///BRAÇO - 1
            break;
        case 'a':
            b1++;
            break;
        case 'd':
            b1--;
        ///--------------------
        ///BRACO  - 2
            break;
        case 'q':
            b2++;
            break;
        case 'e':
            b2--;
            break;
        ///--------------------
        ///MAO
        case 'j':
            m++;
            break;
        case 'l':
            m--;
            break;
        ///--------------------
        /// DEDO
        case 'k':
            if(d==30)
                d=0;
            else
                d++;
            break;
        case 'o':
            exit(0);
        break;

    }
    glFlush();
    glutPostRedisplay();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(10,10);
    ///cria janela
    glutCreateWindow("GLUT Shapes");

    ///chama função
    glutDisplayFunc(desenha);

    /// Atualiza - janela
    glutReshapeFunc(AlteraTamanhoJanela);

    ///movimentação
    glutKeyboardFunc(key);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//Cor de fundo
    glutMainLoop();

    return 0;

}
