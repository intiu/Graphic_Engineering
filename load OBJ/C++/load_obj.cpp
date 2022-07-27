#include<GL/glut.h>
#include<stdio.h>
GLuint jmodel;
float jmodelrot;
char ch='1';

void loadObj(char *fname)
{
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    jmodel=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(jmodel, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read==4&&ch=='v')
            {
                glVertex3f(x,y,z);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
    //glOrtho(-25,25,-2,2,0.1,100);
    glMatrixMode(GL_MODELVIEW);
}
void drawjmodel()
{
    glPushMatrix();
    glTranslatef(0,-10.00,-105);
    glColor3f(5.0,0.23,0.27);
    glScalef(10,10,10);
    glRotatef(jmodelrot,0,1,0);
    glCallList(jmodel);
    glPopMatrix();
    jmodelrot=jmodelrot+0.1;
    if(jmodelrot>360)jmodelrot=jmodelrot-360;
}
void display(void)
{
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    drawjmodel();
    glutSwapBuffers(); //swap the buffers
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1380,830);
    glutInitWindowPosition(10,10);
    glutCreateWindow("ObjLoader");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    //render file obj, chon file tuy y, trong do co 3 file
  //loadObj("2srp1fi1oigw-CHARACTER-ANIME_HIGH/anime character(high).obj");
 //loadObj("Dragon/Dragon.obj"); 
 //loadObj("Tennis/tennis.obj");
  loadObj("Bird_v1_L2.123c62214d41-2432-4b73-8f56-ed312b43c2aa/12212_Bird_v1_l2.obj");
  //loadObj("Soldier_on_one_knee_firing_a_rifle_v1_L127252b93-3b98-4583-bddd-90ccc5c44d17/18825_Soldier_on_one_knee_firing_a_rifle_v1_NEW.obj");
    glutMainLoop();
    return 0;
}

