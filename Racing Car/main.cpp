#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
#include<windows.h>
#include<mmsystem.h>
#include <string>
#include <sstream>
#include<cstdio>
#include <fstream>
#include<string>
#include <windows.h>
#include<math.h>
#include <vector>
#include <cstdlib>
# define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>
#include<MMSystem.h>
using namespace std;
void update(int);
float transFactor = 0.0f;
float transFactor1 = 0.0f;
float transFactor2 = 0.0f;
float transFactor3 = 0.0f;
float transFactor4 = 0.0f;
float transFactor5 = 0.0f;
float transFactor6 = 0.0f;
float transFactor7 = 0.0f;
float transFactor8 = 0.0f;
float transFactor9 = 0.0f;
int count1 = 0;
int stage = 0;
string s1 = "Stage: ";
string s = "Count: ";
float xr=0,yr=0;
float w=65,h=110;
int dir=0;
    float getX(int val)
    {
        int width = glutGet(GLUT_WINDOW_WIDTH);
        float frac = (float)val/((float)width/2);
        return frac;
    }
    float getY(int val)
    {
        int height = glutGet(GLUT_WINDOW_HEIGHT);
        float frac = (float)val/((float)height/2);
        return frac;
    }
    void Sprint( float x, float y, char *st)
    {
        int l,i;
        l=strlen( st ); // see how many characters are in text string.
        glColor3f(0.0,1.0,0.7);
        //glDisable(GL_LIGHTING);
        glRasterPos2f( x, y); // location to start printing text
        for( i=0; i < l; i++) // loop until i is greater then l
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
        }
    }

    void Sprint1( float x, float y, char *st)
    {
        int l,i;
        l=strlen( st ); // see how many characters are in text string.
        glColor3f(1.0,0.0,0.0);
        //glDisable(GL_LIGHTING);
        glRasterPos2f( x, y); // location to start printing text
        for( i=0; i < l; i++) // loop until i is greater then l
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
        }
    }

    void Sprint5( float x, float y)
    {
    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2f(x,y);
    glVertex2f(x+0.1,y);
    glVertex2f(x+0.1,y+0.2);
    glVertex2f(x,y+0.2);

    //glVertex2f(-0.7f,-0.25f);
    glEnd();
    }

    void specialKeys(int key, int x, int y)
    {
        switch (key)
        {
            case GLUT_KEY_RIGHT:
            if(xr<0)
            {
                if (dir==0)
                {
                    dir=1;
                }
                else

                     dir=0;


                xr=xr+0.32;

                break;
            }
            else
            {
                dir=1;
                xr=0.32;
                break;
            }
            case GLUT_KEY_LEFT:
            if(xr>-0.1)
            {
                if (dir==1)
                {
                    dir=0;
                }
                else
                dir=2;
                xr=xr-0.32;
                break;
            }
            else
            {
                dir=dir;
                xr=-0.32;
                break;
            }
        }
    }

    void randomobj(int x, int y)
    {

        glBegin(GL_QUADS);
        ///starting
        glColor3f (1.0, 0.0, 0.0);
        glVertex2f(getX(x+15),getY(y));
        glVertex2f(getX(x+w-15),getY(y));
        glVertex2f(getX(x+w),getY(y+h-100));
        glVertex2f(getX(x),getY(y+h-100));
        /// body
         glColor3f (1.0, 0.0, 0.0);
         glVertex2f(getX(x),getY(y+h-100));
         glVertex2f(getX(x+w),getY(y+h-100));
         glVertex2f(getX(x+w),getY(y+h-5));
         glVertex2f(getX(x),getY(y+h-5));

         /// back side glass
         glColor3f (0.0, 0.0, 0.0);
         glVertex2f(getX(x+20),getY(y+h-20));
         glVertex2f(getX(x+w-20),getY(y+h-20));
         glVertex2f(getX(x+w-10),getY(y+h-10));
         glVertex2f(getX(x+10),getY(y+h-10));
         /// front side glass
         glColor3f (0.0, 0.0, 0.0);
        glVertex2f(getX(x+10),getY(y+h-80));
         glVertex2f(getX(x+20),getY(y+h-70));
         glVertex2f(getX(x+w-20),getY(y+h-70));
         glVertex2f(getX(x+w-10),getY(y+h-80));
         /// left side glass
          glColor3f (0.0, 0.0, 0.0);
          glVertex2f(getX(x+5),getY(y+h-78));
          glVertex2f(getX(x+15),getY(y+h-68));
          glVertex2f(getX(x+15),getY(y+h-22));
          glVertex2f(getX(x+5),getY(y+h-12));
          /// right side glass
          glColor3f (0.0, 0.0, 0.0);
          glVertex2f(getX(x+w-5),getY(y+h-78));
          glVertex2f(getX(x+w-15),getY(y+h-68));
          glVertex2f(getX(x+w-15),getY(y+h-22));
          glVertex2f(getX(x+w-5),getY(y+h-12));
        /// ending
        glColor3f (1.0, 0.0, 0.0);
        glVertex2f(getX(x),getY(y+h-5));
        glVertex2f(getX(x+w),getY(y+h-5));
        glVertex2f(getX(x+w-15),getY(y+h));
        glVertex2f(getX(x+15),getY(y+h));

        glEnd();

    }
        void car()
    {
        glBegin(GL_QUADS);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2f(getX(-35)+xr,getY(-280)+yr);
        glVertex2f(getX(0)+xr,getY(-280)+yr);
        glVertex2f(getX(15)+xr,getY(-290)+yr);
        glVertex2f(getX(-50)+xr,getY(-290)+yr);
        glColor3f (0.0, 0.0, 1.0);
        glVertex2f(getX(-50)+xr,getY(-290)+yr);
        glVertex2f(getX(15)+xr,getY(-290)+yr);
        glVertex2f(getX(15)+xr,getY(-390)+yr);
        glVertex2f(getX(-50)+xr,getY(-390)+yr);
        /// top glass
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(getX(-40)+xr,getY(-320)+yr);
        glVertex2f(getX(5)+xr,getY(-320)+yr);
        glVertex2f(getX(-10)+xr,getY(-330)+yr);
        glVertex2f(getX(-25)+xr,getY(-330)+yr);
        /// left side glass
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(getX(-30)+xr,getY(-330)+yr);
        glVertex2f(getX(-40)+xr,getY(-322)+yr);
        glVertex2f(getX(-40)+xr,getY(-375)+yr);
        glVertex2f(getX(-30)+xr,getY(-367)+yr);
        ///right side glass
         glColor3f (0.0, 0.0, 0.0);
        glVertex2f(getX(5)+xr,getY(-322)+yr);
        glVertex2f(getX(-5)+xr,getY(-330)+yr);
        glVertex2f(getX(-5)+xr,getY(-367)+yr);
        glVertex2f(getX(5)+xr,getY(-375)+yr);
        ///back side glass
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(getX(-40)+xr,getY(-380)+yr);
        glVertex2f(getX(5)+xr,getY(-380)+yr);
        glVertex2f(getX(-10)+xr,getY(-370)+yr);
        glVertex2f(getX(-25)+xr,getY(-370)+yr);
        glEnd();
    }
    void StartingText()
    {
    char text[120];
    sprintf(text, "Car racing Game.......",5.00,8.00);
    //sprintf(text, "Press Space to start the game",5.00,7.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( -8 , 30 );

    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

    void StartingText1()
    {
    char text[120];
    //sprintf(text, "Press",5.00,8.00);
    sprintf(text, "Press Space to start the game",2.00,3.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( -28 , 50 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

    void StartingText2()
    {
    char text[120];
    //sprintf(text, "Press",5.00,8.00);
    sprintf(text, "Created By :",2.00,3.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( 40 , 10 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

    void StartingText3()
    {
    char text[120];
    //sprintf(text, "Press",5.00,8.00);
    sprintf(text, "Hasan,Md.Asif",2.00,3.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( 50 , -10 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

    void StartingText4()
    {
    char text[120];
    //sprintf(text, "Press",5.00,8.00);
    sprintf(text, "Farheen Shuchi",2.00,3.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( 50 , -30 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

    void StartingText5()
    {
    char text[120];
    //sprintf(text, "Press",5.00,8.00);
    sprintf(text, "Ahmed,Rejwan",2.00,3.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( 50 , -55 );
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

    void StartingText6()
    {
    char text[120];
    //sprintf(text, "Press",5.00,8.00);
    sprintf(text, "Ahmed,Abdullah Shams",2.00,3.00);
    glColor3f(0, 0, 0);
    glRasterPos2f( 50 , -80);
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]==' ' && text[i+1]==' ')
        {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
            glRasterPos2f( -42 , 02 );
        }
        else glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

void DrawText(const char *text,int length,int xx,int yy)
    {
        glMatrixMode(GL_PROJECTION);
        double *matrix=new double[16];
        glGetDoublev(GL_PROJECTION_MATRIX,matrix);
        glLoadIdentity();
        glOrtho(0,800,0,600,-5,5);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2i(xx,yy);
        for(int i=0;i<length;i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);


        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);

    }
void reshape(int w, int h)
{
//    std::cout<<"Reshape is called"<<std::endl;
    float aspectRatio = (float)w/(float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(145, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

}

    void drawScene()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glColor3ub(255,0,0);
        glPushMatrix();
        glTranslatef(0,transFactor,0);
        //Road
        glBegin(GL_QUADS);
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(getX(-320),getY(-5070));
        glVertex2f(getX(320),getY(-5070));
        glVertex2f(getX(320),getY(5070));
        glVertex2f(getX(-320),getY(5070));


        //1
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(-270));
        glVertex2f(getX(-90),getY(-270));
        glVertex2f(getX(-90),getY(-370));
        glVertex2f(getX(-110),getY(-370));
        //2
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(-70));
        glVertex2f(getX(-90),getY(-70));
        glVertex2f(getX(-90),getY(-170));
        glVertex2f(getX(-110),getY(-170));
        //3
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(70));
        glVertex2f(getX(-90),getY(70));
        glVertex2f(getX(-90),getY(170));
        glVertex2f(getX(-110),getY(170));
        //4
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(270));
        glVertex2f(getX(-90),getY(270));
        glVertex2f(getX(-90),getY(370));
        glVertex2f(getX(-110),getY(370));
        //5
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(470));
        glVertex2f(getX(-90),getY(470));
        glVertex2f(getX(-90),getY(570));
        glVertex2f(getX(-110),getY(570));
        //6
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(670));
        glVertex2f(getX(-90),getY(670));
        glVertex2f(getX(-90),getY(770));
        glVertex2f(getX(-110),getY(770));
        //7
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(870));
        glVertex2f(getX(-90),getY(870));
        glVertex2f(getX(-90),getY(970));
        glVertex2f(getX(-110),getY(970));

        //8
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(1070));
        glVertex2f(getX(-90),getY(1070));
        glVertex2f(getX(-90),getY(1170));
        glVertex2f(getX(-110),getY(1170));
        //9th
        glBegin(GL_QUADS);
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(1270));
        glVertex2f(getX(-90),getY(1270));
        glVertex2f(getX(-90),getY(1370));
        glVertex2f(getX(-110),getY(1370));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(1470));
        glVertex2f(getX(-90),getY(1470));
        glVertex2f(getX(-90),getY(1570));
        glVertex2f(getX(-110),getY(1570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(1670));
        glVertex2f(getX(-90),getY(1670));
        glVertex2f(getX(-90),getY(1770));
        glVertex2f(getX(-110),getY(1770));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(1870));
        glVertex2f(getX(-90),getY(1870));
        glVertex2f(getX(-90),getY(1970));
        glVertex2f(getX(-110),getY(1970));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(2070));
        glVertex2f(getX(-90),getY(2070));
        glVertex2f(getX(-90),getY(2170));
        glVertex2f(getX(-110),getY(2170));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(2270));
        glVertex2f(getX(-90),getY(2270));
        glVertex2f(getX(-90),getY(2370));
        glVertex2f(getX(-110),getY(2370));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(2470));
        glVertex2f(getX(-90),getY(2470));
        glVertex2f(getX(-90),getY(2570));
        glVertex2f(getX(-110),getY(2570));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(2670));
        glVertex2f(getX(-90),getY(2670));
        glVertex2f(getX(-90),getY(2770));
        glVertex2f(getX(-110),getY(2770));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(2870));
        glVertex2f(getX(-90),getY(2870));
        glVertex2f(getX(-90),getY(2970));
        glVertex2f(getX(-110),getY(2970));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(3070));
        glVertex2f(getX(-90),getY(3070));
        glVertex2f(getX(-90),getY(3170));
        glVertex2f(getX(-110),getY(3170));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(3270));
        glVertex2f(getX(-90),getY(3270));
        glVertex2f(getX(-90),getY(3370));
        glVertex2f(getX(-110),getY(3370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(3470));
        glVertex2f(getX(-90),getY(3470));
        glVertex2f(getX(-90),getY(3570));
        glVertex2f(getX(-110),getY(3570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(3670));
        glVertex2f(getX(-90),getY(3670));
        glVertex2f(getX(-90),getY(3770));
        glVertex2f(getX(-110),getY(3770));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(3870));
        glVertex2f(getX(-90),getY(3870));
        glVertex2f(getX(-90),getY(3970));
        glVertex2f(getX(-110),getY(3970));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(4070));
        glVertex2f(getX(-90),getY(4070));
        glVertex2f(getX(-90),getY(4170));
        glVertex2f(getX(-110),getY(4170));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(4270));
        glVertex2f(getX(-90),getY(4270));
        glVertex2f(getX(-90),getY(4370));
        glVertex2f(getX(-110),getY(4370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(4470));
        glVertex2f(getX(-90),getY(4470));
        glVertex2f(getX(-90),getY(4570));
        glVertex2f(getX(-110),getY(4570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(4670));
        glVertex2f(getX(-90),getY(4670));
        glVertex2f(getX(-90),getY(4770));
        glVertex2f(getX(-110),getY(4770));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(4870));
        glVertex2f(getX(-90),getY(4870));
        glVertex2f(getX(-90),getY(4970));
        glVertex2f(getX(-110),getY(4970));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(5070));
        glVertex2f(getX(-90),getY(5070));
        glVertex2f(getX(-90),getY(5170));
        glVertex2f(getX(-110),getY(5170));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(5270));
        glVertex2f(getX(-90),getY(5270));
        glVertex2f(getX(-90),getY(5370));
        glVertex2f(getX(-110),getY(5370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(5470));
        glVertex2f(getX(-90),getY(5470));
        glVertex2f(getX(-90),getY(5570));
        glVertex2f(getX(-110),getY(5570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(5670));
        glVertex2f(getX(-90),getY(5670));
        glVertex2f(getX(-90),getY(5770));
        glVertex2f(getX(-110),getY(5770));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(5870));
        glVertex2f(getX(-90),getY(5870));
        glVertex2f(getX(-90),getY(5970));
        glVertex2f(getX(-110),getY(5970));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(6070));
        glVertex2f(getX(-90),getY(6070));
        glVertex2f(getX(-90),getY(6170));
        glVertex2f(getX(-110),getY(6170));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(6270));
        glVertex2f(getX(-90),getY(6270));
        glVertex2f(getX(-90),getY(6370));
        glVertex2f(getX(-110),getY(6370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(-110),getY(6470));
        glVertex2f(getX(-90),getY(6470));
        glVertex2f(getX(-90),getY(6570));
        glVertex2f(getX(-110),getY(6570));


        //right bar
        //1
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(-270));
        glVertex2f(getX(90),getY(-270));
        glVertex2f(getX(90),getY(-370));
        glVertex2f(getX(110),getY(-370));
        //2
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(-70));
        glVertex2f(getX(90),getY(-70));
        glVertex2f(getX(90),getY(-170));
        glVertex2f(getX(110),getY(-170));
        //3
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(70));
        glVertex2f(getX(90),getY(70));
        glVertex2f(getX(90),getY(170));
        glVertex2f(getX(110),getY(170));
        //4
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(270));
        glVertex2f(getX(90),getY(270));
        glVertex2f(getX(90),getY(370));
        glVertex2f(getX(110),getY(370));
        //5
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(470));
        glVertex2f(getX(90),getY(470));
        glVertex2f(getX(90),getY(570));
        glVertex2f(getX(110),getY(570));
        //6
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(670));
        glVertex2f(getX(90),getY(670));
        glVertex2f(getX(90),getY(770));
        glVertex2f(getX(110),getY(770));
        //7
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(870));
        glVertex2f(getX(90),getY(870));
        glVertex2f(getX(90),getY(970));
        glVertex2f(getX(110),getY(970));

        //8
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(1070));
        glVertex2f(getX(90),getY(1070));
        glVertex2f(getX(90),getY(1170));
        glVertex2f(getX(110),getY(1170));
        //9th
        glBegin(GL_QUADS);
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(1270));
        glVertex2f(getX(90),getY(1270));
        glVertex2f(getX(90),getY(1370));
        glVertex2f(getX(110),getY(1370));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(1470));
        glVertex2f(getX(90),getY(1470));
        glVertex2f(getX(90),getY(1570));
        glVertex2f(getX(110),getY(1570));

                        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(1670));
        glVertex2f(getX(90),getY(1670));
        glVertex2f(getX(90),getY(1770));
        glVertex2f(getX(110),getY(1770));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(1870));
        glVertex2f(getX(90),getY(1870));
        glVertex2f(getX(90),getY(1970));
        glVertex2f(getX(110),getY(1970));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(2070));
        glVertex2f(getX(90),getY(2070));
        glVertex2f(getX(90),getY(2170));
        glVertex2f(getX(110),getY(2170));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(2270));
        glVertex2f(getX(90),getY(2270));
        glVertex2f(getX(90),getY(2370));
        glVertex2f(getX(110),getY(2370));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(2470));
        glVertex2f(getX(90),getY(2470));
        glVertex2f(getX(90),getY(2570));
        glVertex2f(getX(110),getY(2570));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(2670));
        glVertex2f(getX(90),getY(2670));
        glVertex2f(getX(90),getY(2770));
        glVertex2f(getX(110),getY(2770));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(2870));
        glVertex2f(getX(90),getY(2870));
        glVertex2f(getX(90),getY(2970));
        glVertex2f(getX(110),getY(2970));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(3070));
        glVertex2f(getX(90),getY(3070));
        glVertex2f(getX(90),getY(3170));
        glVertex2f(getX(110),getY(3170));
        //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(3270));
        glVertex2f(getX(90),getY(3270));
        glVertex2f(getX(90),getY(3370));
        glVertex2f(getX(110),getY(3370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(3470));
        glVertex2f(getX(90),getY(3470));
        glVertex2f(getX(90),getY(3570));
        glVertex2f(getX(110),getY(3570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(3670));
        glVertex2f(getX(90),getY(3670));
        glVertex2f(getX(90),getY(3770));
        glVertex2f(getX(110),getY(3770));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(3870));
        glVertex2f(getX(90),getY(3870));
        glVertex2f(getX(90),getY(3970));
        glVertex2f(getX(110),getY(3970));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(4070));
        glVertex2f(getX(90),getY(4070));
        glVertex2f(getX(90),getY(4170));
        glVertex2f(getX(110),getY(4170));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(4270));
        glVertex2f(getX(90),getY(4270));
        glVertex2f(getX(90),getY(4370));
        glVertex2f(getX(110),getY(4370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(4470));
        glVertex2f(getX(90),getY(4470));
        glVertex2f(getX(90),getY(4570));
        glVertex2f(getX(110),getY(4570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(4670));
        glVertex2f(getX(90),getY(4670));
        glVertex2f(getX(90),getY(4770));
        glVertex2f(getX(110),getY(4770));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(4870));
        glVertex2f(getX(90),getY(4870));
        glVertex2f(getX(90),getY(4970));
        glVertex2f(getX(110),getY(4970));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(5070));
        glVertex2f(getX(90),getY(5070));
        glVertex2f(getX(90),getY(5170));
        glVertex2f(getX(110),getY(5170));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(5270));
        glVertex2f(getX(90),getY(5270));
        glVertex2f(getX(90),getY(5370));
        glVertex2f(getX(110),getY(5370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(5470));
        glVertex2f(getX(90),getY(5470));
        glVertex2f(getX(90),getY(5570));
        glVertex2f(getX(110),getY(5570));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(5670));
        glVertex2f(getX(90),getY(5670));
        glVertex2f(getX(90),getY(5770));
        glVertex2f(getX(110),getY(5770));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(5870));
        glVertex2f(getX(90),getY(5870));
        glVertex2f(getX(90),getY(5970));
        glVertex2f(getX(110),getY(5970));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(6070));
        glVertex2f(getX(90),getY(6070));
        glVertex2f(getX(90),getY(6170));
        glVertex2f(getX(110),getY(6170));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(6270));
        glVertex2f(getX(90),getY(6270));
        glVertex2f(getX(90),getY(6370));
        glVertex2f(getX(110),getY(6370));
                //10rd
        glBegin(GL_QUADS);
        glColor3f (1.0, 1.0, 1.0);
        glVertex2f(getX(110),getY(6470));
        glVertex2f(getX(90),getY(6470));
        glVertex2f(getX(90),getY(6570));
        glVertex2f(getX(110),getY(6570));

        glEnd();
        glPopMatrix();
 // if (transFactor1<-2.05&&dir==2|| transFactor4<-5.3&&dir==2|| transFactor2<-3.32&&dir==1||transFactor3<-4.63&&dir==0||transFactor5<-7.26&&dir==1)
           if (transFactor1<-2.05&&dir==2|| transFactor4<-5.42&&dir==2|| transFactor2<-3.32&&dir==1||transFactor3<-4.63&&dir==0||transFactor5<-6.47&&dir==1)

            {
            PlaySound("crash.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
            glutDisplayFunc(car);
            ifstream infile;
            infile.open("file.txt");
            int xf,xff;
            infile>>xf;
            infile.close();
            string text,text2,text3,text4,text5,text6,text7;
            text="GAME OVER...";
            text2="your score :";
            stringstream oo,hss;
            oo<<count1<<endl;
            int hs;
            hs=xf;
            if (hs<count1)
            {
                hs=count1;
            }
            ofstream out1;
            out1.open("file.txt");
            out1<<hs;
            out1.close();
            infile.open("file.txt");
            infile>>xff;
            infile.close();

            hss<<xff<<endl;
            text3=oo.str();
            text4="press SPACE to CONTINUE play";
            text5="press ESC to Exit";
            text6="Height score:";
            text7=hss.str();

            glColor3f(0,1,0);
            DrawText(text.data(),text.size(),350,380);
            DrawText(text2.data(),text2.size(),350,350);
            DrawText(text3.data(),text3.size()-1,420,350);
            DrawText(text6.data(),text6.size(),350,320);
            DrawText(text7.data(),text7.size()-1,420,320);
            DrawText(text4.data(),text4.size(),350,290);
            DrawText(text5.data(),text5.size(),350,205);


        }
         if (transFactor5<-7.8)
        {
            transFactor5=0;
            count1++;
            ostringstream str1;
            str1<<count1;
            s="Count: "+str1.str();
        }
        if (transFactor4<-5.99)
       {
           transFactor4=0;
           count1++;
           ostringstream str1;
            str1<<count1;
            s="Count: "+str1.str();
       }
        if (transFactor3<-5.17)
       {
           transFactor3=0;
           count1++;
            ostringstream str1;
            str1<<count1;
            s="Count: "+str1.str();
       }
       if (transFactor2<-3.9)
       {
           transFactor2=0;
           count1++;
            ostringstream str1;
            str1<<count1;
            s="Count: "+str1.str();
       }
        if (transFactor1<-2.6)
        {
            transFactor1=9;
            count1++;
            ostringstream str1;
            str1<<count1;
            s="Count: "+str1.str();
        }


        glPushMatrix();
        glTranslatef(0,transFactor1,0);
        randomobj(-269,500);//Left car
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,transFactor4,0);
        randomobj(-269,1800);//Left car
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,transFactor2,0);
        randomobj(169,1000);//right car
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,transFactor5,0);
        randomobj(169,2200);//right car
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,transFactor3,0);
        randomobj(-50,1500);//Middle car
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,transFactor6,0);
        randomobj(-50,3200);//Middle car
        glPopMatrix();
        car();

        char *cstr = new char[s.length() + 1];
        strcpy(cstr, s.c_str());
        ostringstream str1;
        str1<<count1;
        s="Count: "+str1.str();
        Sprint (-0.45,0.8,cstr);
        //Sprint5(0.55,0.5);

        char *cstr1 = new char[s1.length() + 1];
        strcpy(cstr1, s1.c_str());
        ostringstream str2;
        str2<<stage;
        s1="Stage: "+str2.str();
        Sprint1 (-0.45,0.7,cstr1);

        glTranslatef(0,0,-20);
        StartingText();
        glTranslatef(0,0,-30);
        StartingText1();
        glTranslatef(0,0,-10);
        StartingText2();
        glTranslatef(0,0,-10);
        StartingText3();
        glTranslatef(0,0,-10);
        StartingText4();
        glTranslatef(0,0,-10);
        StartingText5();
        glTranslatef(0,0,-10);
        StartingText6();
        glutPostRedisplay();
        glutSwapBuffers();

    }

    void update(int value)
    {
        transFactor-=0.01f;
        if(transFactor<getY(-4550))
        {
            stage++;
            transFactor = -1 * getY(950);
            if(stage<3)
            {
                glutPostRedisplay();
                glutTimerFunc(5,update,0);
            }
            glutPostRedisplay();
            //glutTimerFunc(5,update,0);
        }
        transFactor1-=0.01f;
        if(transFactor1<getY(-1150))
        {
            transFactor1 = 1 * getY(00);
            glutPostRedisplay();
       // glutTimerFunc(30,update,0);
        }
        transFactor2-=0.01f;
        if(transFactor2<getY(-1550))
        {
            transFactor2 = 1 * getY(00);
            glutPostRedisplay();
            // glutTimerFunc(30,update,0);
        }
        transFactor3-=0.01f;
        if(transFactor3<getY(-2050))
        {
            transFactor3 = 1 * getY(00);
            glutPostRedisplay();
            // glutTimerFunc(30,update,0);
        }
        transFactor4-=0.01f;
        if(transFactor4<getY(-2350))
        {
            transFactor4 = 1 * getY(00);
            glutPostRedisplay();
            // glutTimerFunc(30,update,0);
        }
        transFactor5-=0.01f;
        if(transFactor5<getY(-3050))
        {
            transFactor5 = 1 * getY(00);
            glutPostRedisplay();
            // glutTimerFunc(30,update,0);
        }
                glutPostRedisplay();
                glutTimerFunc(30,update,0);
    }
    void myInit(void)
    {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        //gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
    }
        void keyboard(unsigned char key, int x, int y)
    {
        switch (key)
        {
            case  32:
	        glutDestroyWindow(1);
	        glutInitWindowSize(800,800);
            glutCreateWindow("Car Race");
            glutFullScreen();
            glutDisplayFunc(drawScene);
            glutSpecialFunc(specialKeys); //Special Key Handler
            glutKeyboardFunc(keyboard);
            myInit ();
            //PlaySound(TEXT("bird-2.wav"), NULL, SND_ASYNC);
            break;
            case 27:     // ESC key
            exit(0);
            break;
           // case 32;
        }
    }
    int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(800,800);
        glutCreateWindow("Car Game");
        glutFullScreen();
        glutKeyboardFunc(keyboard);
        glutReshapeFunc(reshape);
        glutDisplayFunc(drawScene);
        glutSpecialFunc(specialKeys); //Special Key Handler
        //glutKeyboardFunc(keyboard);
        glutTimerFunc(20,update,0);
        PlaySound("NspRingtone.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        myInit ();
        glutMainLoop();
        return 0;
    }
