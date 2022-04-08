#include<iostream>
#include <Windows.h>
#include <GL/glut.h>
#include<math.h>
# define PI        3.14159265358979323846
#include<stdio.h>

using namespace std;


float _move6=0.0f;
float _move = 0.0f;
float _move2 = 0.0f;

GLfloat speed = 0.1f;



void DrawCircle(float cx, float cy, float r, int num_segments)
		{
		 glBegin(GL_TRIANGLE_FAN);
		 for (int i = 0; i < num_segments; i++)
            {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

            float x = r * cosf(theta);//calculate the x component
            float y = r * sinf(theta);//calculate the y component

            glVertex2f(x + cx, y + cy);//output vertex

            }
		 glEnd();
	}


	//=========================Ridwan==================================//

int upperCarStatus = 1;
float upperCarX = 0;
float upperCarY = 0;
float upperCarSpeed = 8;

int upperTruckStatus = 1;
float upperTruckX = 0;
float upperTruckY = 0;
float upperTruckSpeed = 3;

int lowerCarStatus = 1;
float lowerCarX = -128;
float lowerCarY = 0;
float lowerCarSpeed = 15;

int lowerBusStatus = 1;
float lowerBusX = 0;
float lowerBusY = 0;
float lowerBusSpeed = 5;



void CarUpper()  //201
{
    //car body
    glBegin(GL_POLYGON);
    glColor3ub(135,206,235);

	glVertex2f(-120.0f,9.0f);
	glVertex2f(-120.0f, 6.0f);
	glVertex2f(-107.0f,6.0f);
    glVertex2f(-107.0f,9.0f);
    glVertex2f(-110.0f,9.0f);
    glVertex2f(-112.0f,12.0f);
    glVertex2f(-117.0f,12.0f);
    glVertex2f(-118.0f,9.0f);
    glEnd();
    //car window
    glBegin(GL_POLYGON);
    glColor3ub(100,20,235);

	glVertex2f(-118.4f,9.5f);
	glVertex2f(-114.0f, 9.5f);
	glVertex2f(-114.9f,11.5f);
    glVertex2f(-116.4f,11.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100,20,235);

    glVertex2f(-114.5f,11.5f);
    glVertex2f(-113.6f, 9.5f);
    glVertex2f(-111.5f, 9.5f);
    glVertex2f(-112.8f, 11.5f);

    glEnd();

    //tyre
    glColor3ub(0,0,0);
    DrawCircle(-118,5.9,1.1,100000);

    glColor3ub(255,255,255);
    DrawCircle(-118,5.9,.5,100000);

    glColor3ub(0,0,0);
    DrawCircle(-110,5.9,1.1,100000);

    glColor3ub(255,255,255);
    DrawCircle(-110,5.9,.5,100000);


}


void updateUpperCar() //202
	{
		if (upperCarStatus == 1)
		{
			upperCarX +=upperCarSpeed;
		}
        if (upperCarX>250)
		{
			upperCarX =-128 ;
		}
		glPushMatrix();
		glTranslatef(upperCarX, upperCarY, 0);
		CarUpper();
		glPopMatrix();
		glutPostRedisplay();

	}



void TruckUpper()    //203
{
    //base
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

	glVertex2f(-100.0f,4.0f);
	glVertex2f(-100.0f, 3.0f);
	glVertex2f(-80.0f,3.0f);
    glVertex2f(-80.0f,4.0f);
    glEnd();

    //box
    glBegin(GL_POLYGON);
    glColor3ub(12,159,60);

	glVertex2f(-100.0f,9.0f);
	glVertex2f(-100.0f, 4.0f);
	glVertex2f(-86.0f,4.0f);
    glVertex2f(-86.0f,9.0f);
    glEnd();

    //engine
    glBegin(GL_POLYGON);
    glColor3ub(255,159,60);

	glVertex2f(-85.0f,8.0f);
	glVertex2f(-85.0f, 4.0f);
	glVertex2f(-81.0f,4.0f);
    glVertex2f(-81.0f,7.0f);
    glVertex2f(-82.0f,8.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(0, 0, 25 );
	glVertex2f(-86.0f, 3.0f);
	glVertex2f(-88.0f, 1.5f);
    glEnd();


    glBegin(GL_LINES);
	glColor3ub(0, 0, 25 );
	glVertex2f(-80.0f, 1.5f);
	glVertex2f(-82.0f, 3.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(0, 0, 25 );
	glVertex2f(-90.0f, 1.5f);
	glVertex2f(-92.0f, 3.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(0, 0, 25 );
	glVertex2f(-96.0f, 3.0f);
	glVertex2f(-98.0f, 1.5f);
    glEnd();

    //wheel
    glColor3ub(0,0,0);
    DrawCircle(-94,1.5,1.5,100000);

    glColor3ub(0,0,0);
    DrawCircle(-84,1.5,1.5,100000);

    glColor3ub(255,255,255);
    DrawCircle(-94,1.5,0.7,100000);

    glColor3ub(255,255,255);
    DrawCircle(-84,1.5,0.7,100000);

    //door

    glBegin(GL_POLYGON);
    glColor3ub(100,120,14);

	glVertex2f(-84.4f,7.5f);
	glVertex2f(-84.4f, 5.0f);
	glVertex2f(-82.0f,5.0f);
    glVertex2f(-82.0f,6.7f);
    glVertex2f(-82.5f,7.5f);
    glEnd();


}

void updateUpperTruck() //204
	{
		if (upperTruckStatus == 1)
		{
			upperTruckX +=upperTruckSpeed;
		}
        if (upperTruckX>250)
		{
			upperTruckX =-128 ;
		}
		glPushMatrix();
		glTranslatef(upperTruckX, upperTruckY, 0);
		TruckUpper();
		glPopMatrix();
		glutPostRedisplay();
	}

void LowerCar() //205
{
    //body

     glBegin(GL_POLYGON);
    glColor3ub(255,0,50);


	glVertex2f(15.0f, -3.0f);
	glVertex2f(10.0f,-3.0f);
    glVertex2f(7.0f,-6.0f);
    glVertex2f(35.0f,-6.0f);
    glVertex2f(35.0f,-3.0f);
    glVertex2f(32.0f,-3.0f);
    glVertex2f(27.0f,-1.0f);
    glVertex2f(20.0f,-1.0f);


    glEnd();

    //glass
     glBegin(GL_POLYGON);
    glColor3ub(0,200,255);


	glVertex2f(21.8f, -1.5f);
	glVertex2f(17.8f,-3.0f);
    glVertex2f(24.8f,-3.0f);
    glVertex2f(24.8f,-1.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,200,255);


	glVertex2f(25.0f, -1.5f);
	glVertex2f(25.0f,-3.0f);
    glVertex2f(30.0f,-3.0f);
    glVertex2f(26.5f,-1.5f);
    glEnd();

    //wheel
    glColor3ub(0,0,0);
    DrawCircle(15,-6.5,1.7,100000);

    glColor3ub(0,0,255);
    DrawCircle(15,-6.5,1.2,100000);


     glColor3ub(0,0,0);
    DrawCircle(30,-6.5,1.7,100000);

    glColor3ub(0,0,255);
    DrawCircle(30,-6.5,1.2,100000);




}

void updateLowerCar()  //206
{
    if (lowerCarStatus == 1)
		{
			lowerCarX -=lowerCarSpeed;
		}
        if (lowerCarX<-250)
		{
			lowerCarX =130 ;
		}
		glPushMatrix();
		glTranslatef(lowerCarX, lowerCarY, 0);
		LowerCar();
		glPopMatrix();
		glutPostRedisplay();
}

void LowerBus()  //207
{

    //body

     glBegin(GL_POLYGON);
    glColor3ub(0,0,255);


	glVertex2f(60.0f, -7.0f);
	glVertex2f(55.0f,-7.0f);
    glVertex2f(55.0f,-11.0f);
    glVertex2f(80.0f,-11.0f);
    glVertex2f(80.0f,-3.0f);
    glVertex2f(60.0f, -3.0f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(150,150,150);


	glVertex2f(61.0f, -3.5f);
	glVertex2f(61.0f,-6.0f);
    glVertex2f(66.0f,-6.0f);
    glVertex2f(66.0f,-3.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(150,150,150);
    glVertex2f(66.5f,-9.5f);
    glVertex2f(70.5f,-9.5f);
    glVertex2f(70.5f,-3.5f);
    glVertex2f(66.5f,-3.5f);
    glEnd();


     glBegin(GL_POLYGON);
    glColor3ub(150,150,150);
    glVertex2f(71.0f,-3.5f);
    glVertex2f(71.0f,-6.0f);
    glVertex2f(79.8f,-6.0f);
    glVertex2f(79.8f,-3.5f);
    glEnd();

    //wheel
    glColor3ub(0,0,0);
    DrawCircle(60,-11.0,1.7,100000);

    glColor3ub(10,150,150);
    DrawCircle(60,-11.0,1.2,100000);


     glColor3ub(0,0,0);
    DrawCircle(75,-11.0,1.7,100000);

    glColor3ub(10,150,150);
    DrawCircle(75,-11.0,1.2,100000);





}

void updateLowerBus() //208
{
    if (lowerBusStatus == 1)
		{
			lowerBusX -=lowerBusSpeed;
		}
        if (lowerBusX<-250)
		{
			lowerBusX =130 ;
		}
		glPushMatrix();
		glTranslatef(lowerBusX, lowerBusY, 0);
		LowerBus();
		glPopMatrix();
		glutPostRedisplay();
}


void Road() //209
{

    //whole road border
    glBegin(GL_POLYGON);
    glColor3ub(70,70,70);
	glVertex2f(-128.0f,10.0f);
	glVertex2f(-128.0f, -13.0f);
	glVertex2f(128.0f,-13.0f);
    glVertex2f(128.0f,10.0f);
    glEnd();
    // Road dividers //
    glLineWidth(4);
    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-128.0f, 0.0f);
	glVertex2f(-107.1f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-102.1f, 0.0f);
	glVertex2f(-81.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-128.0f, 0.0f);
	glVertex2f(-107.1f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-76.0f, 0.0f);
	glVertex2f(-54.9f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-49.9f, 0.0f);
	glVertex2f(-28.8f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(-23.8f, 0.0f);
	glVertex2f(-2.7f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(2.3f, 0.0f);
	glVertex2f(23.4f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(28.4f, 0.0f);
	glVertex2f(49.5f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(54.5f, 0.0f);
	glVertex2f(75.6f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(80.6f, 0.0f);
	glVertex2f(101.7f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255 );
	glVertex2f(106.7f, 0.0f);
	glVertex2f(127.8f, 0.0f);
    glEnd();


    updateUpperCar();
    updateUpperTruck();
    updateLowerCar();
    updateLowerBus();

}

/////////////////////////////Ridwan part ends\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\




		void clock1(){//101
glColor3ub(57,172,179); // clock background
DrawCircle(-26,59, 5, 10000);

glColor3ub(175,221,224); // clock front
DrawCircle(-26,59, 4.5, 10000);

glColor3ub(172,179,57); // clock inner
DrawCircle(-26,59, 0.5, 10000);
    glBegin(GL_TRIANGLES);
        glColor3ub(5,17,17);
        glVertex2f(-25,59);
        glVertex2f(-27,59);
        glVertex2f(-26,58);
      glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(5,17,17);
        glVertex2f(-25,59);
        glVertex2f(-27,59);
        glVertex2f(-26,63);

       glEnd();

}


	void clock2(){//102
glColor3ub(57,172,179); // clock background
DrawCircle(26,59, 5, 10000);

glColor3ub(175,221,224); // clock front
DrawCircle(26,59, 4.5, 10000);

glColor3ub(172,179,57); // clock inner
DrawCircle(26,59, 0.5, 10000);
    glBegin(GL_TRIANGLES);
        glColor3ub(5,17,17);
        glVertex2f(25,59);
        glVertex2f(27,59);
        glVertex2f(26,58);
      glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(5,17,17);
        glVertex2f(25,59);
        glVertex2f(27,59);
        glVertex2f(26,63);

       glEnd();

}


void left_side_1stBuilding()//103
{

//left side 1st buildring
glBegin(GL_POLYGON);    //
    glColor3ub(0,0,0);
	glVertex2f(-121.0f,14.0f);
	glVertex2f(-91.0f,14.0f);
	glVertex2f(-91.0f,13.0f);
    glVertex2f(-121.0f,13.0f);
glEnd();
glBegin(GL_POLYGON);    //
    glColor3ub(255,153,204);
	glVertex2f(-121.0f,14.0f);
	glVertex2f(-115.0f,14.0f);
	glVertex2f(-115.0f,26.0f);
    glVertex2f(-121.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //
    glColor3ub(255,153,204);
	glVertex2f(-97.0f,14.0f);
	glVertex2f(-91.0f,14.0f);
	glVertex2f(-91.0f,26.0f);
    glVertex2f(-97.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    // door glass
    glColor3ub(204,255,229);
	glVertex2f(-115.0f,14.0f);
	glVertex2f(-97.0f,14.0f);
	glVertex2f(-97.0f,19.0f);
    glVertex2f(-115.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //up
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,19.0f);
	glVertex2f(-97.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //1
    glColor3ub(0,0,0);
	glVertex2f(-111.0f,19.0f);
	glVertex2f(-111.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-106.0f,19.0f);
	glVertex2f(-106.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(0,0,0);
	glVertex2f(-101.0f,19.0f);
	glVertex2f(-101.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,19.0f);
	glVertex2f(-115.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //5
    glColor3ub(0,0,0);
	glVertex2f(-97.0f,19.0f);
	glVertex2f(-97.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);    //
    glColor3ub(255,153,204);
	glVertex2f(-119.0f,26.0f);
	glVertex2f(-93.0f,26.0f);
	glVertex2f(-93.0f,54.0f);
    glVertex2f(-119.0f,54.0f);
glEnd();
glBegin(GL_POLYGON);    // 2nd storage
   glColor3ub(255,153,204);
	glVertex2f(-115.0f,34.0f);
	glVertex2f(-97.0f,34.0f);
	glVertex2f(-97.0f,19.0f);
    glVertex2f(-115.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,19.0f);
	glVertex2f(-97.0f,19.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,42.0f);
	glVertex2f(-97.0f,42.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,42.0f);
	glVertex2f(-115.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-97.0f,42.0f);
	glVertex2f(-97.0f,19.0f);
glEnd();


glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,26.0f);
	glVertex2f(-121.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-121.0f,26.0f);
	glVertex2f(-121.0f,14.0f);
glEnd();

glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-97.0f,26.0f);
	glVertex2f(-91.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-91.0f,26.0f);
	glVertex2f(-91.0f,14.0f);
glEnd();


glBegin(GL_POLYGON);    // 2nd storage
   glColor3ub(255,153,204);
	glVertex2f(-115.0f,54.0f);
	glVertex2f(-97.0f,54.0f);
	glVertex2f(-97.0f,62.0f);
    glVertex2f(-115.0f,62.0f);
glEnd();

//line for top storage
glBegin(GL_LINES);    //1
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,54.0f);
	glVertex2f(-97.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,62.0f);
	glVertex2f(-115.0f,54.0f);
glEnd();

glBegin(GL_LINES);    //3
    glColor3ub(0,0,0);
	glVertex2f(-97.0f,62.0f);
	glVertex2f(-97.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(0,0,0);
	glVertex2f(-115.0f,62.0f);
	glVertex2f(-97.0f,62.0f);
glEnd();

//3rd storage border
glBegin(GL_LINES);    //1
    glColor3ub(0,0,0);
	glVertex2f(-119.0f,54.0f);
	glVertex2f(-93.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(-119.0f,26.0f);
	glVertex2f(-119.0f,54.0f);
glEnd();

glBegin(GL_LINES);    //3
    glColor3ub(0,0,0);
	glVertex2f(-93.0f,26.0f);
	glVertex2f(-93.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(0,0,0);
	glVertex2f(-119.0f,54.0f);
	glVertex2f(-93.0f,54.0f);
glEnd();

 glColor3ub(0,0,0);
DrawCircle(-110,58, 2, 10000);
glEnd();

 glColor3ub(255,255,255);
DrawCircle(-102,58, 2, 10000);
glEnd();

}


void left_side_2ndBuilding()//104

{


// left side 2nd building
glBegin(GL_POLYGON);    //body
   glColor3ub(204,204,0);
	glVertex2f(-84.0f,16.0f);
	glVertex2f(-68.0f,16.0f);
	glVertex2f(-68.0f,38.0f);
    glVertex2f(-84.0f,38.0f);
glEnd();

glBegin(GL_POLYGON);    //body
   glColor3ub(255,255,255);
	glVertex2f(-85.0f,39.0f);
	glVertex2f(-67.0f,39.0f);
	glVertex2f(-67.0f,38.0f);
    glVertex2f(-85.0f,38.0f);
glEnd();

glBegin(GL_POLYGON);    //window left 1
   glColor3ub(255,255,255);
	glVertex2f(-83.0f,36.0f);
	glVertex2f(-78.0f,36.0f);
	glVertex2f(-78.0f,31.0f);
    glVertex2f(-83.0f,31.0f);
glEnd();
glBegin(GL_POLYGON);    //window left 2
   glColor3ub(255,255,255);
	glVertex2f(-83.0f,29.0f);
	glVertex2f(-78.0f,29.0f);
	glVertex2f(-78.0f,24.0f);
    glVertex2f(-83.0f,24.0f);
glEnd();
glBegin(GL_POLYGON);    //window left 3
   glColor3ub(255,255,255);
	glVertex2f(-83.0f,22.0f);
	glVertex2f(-78.0f,22.0f);
	glVertex2f(-78.0f,17.0f);
    glVertex2f(-83.0f,17.0f);
glEnd();


glBegin(GL_POLYGON);    //window right 1
   glColor3ub(255,255,255);
	glVertex2f(-74.0f,36.0f);
	glVertex2f(-69.0f,36.0f);
	glVertex2f(-69.0f,31.0f);
    glVertex2f(-74.0f,31.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 2
   glColor3ub(255,255,255);
	glVertex2f(-74.0f,29.0f);
	glVertex2f(-69.0f,29.0f);
	glVertex2f(-69.0f,24.0f);
    glVertex2f(-74.0f,24.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 3
   glColor3ub(255,255,255);
	glVertex2f(-74.0f,22.0f);
	glVertex2f(-69.0f,22.0f);
	glVertex2f(-69.0f,17.0f);
    glVertex2f(-74.0f,17.0f);
glEnd();

//mid window
glBegin(GL_POLYGON);    //window right 1
   glColor3ub(255,255,255);
	glVertex2f(-77.0f,37.0f);
	glVertex2f(-75.0f,37.0f);
	glVertex2f(-75.0f,32.0f);
    glVertex2f(-77.0f,32.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 2
   glColor3ub(255,255,255);
	glVertex2f(-77.0f,30.0f);
	glVertex2f(-75.0f,30.0f);
	glVertex2f(-75.0f,26.0f);
    glVertex2f(-77.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 3
   glColor3ub(255,255,255);
	glVertex2f(-77.0f,24.0f);
	glVertex2f(-75.0f,24.0f);
	glVertex2f(-75.0f,20.0f);
    glVertex2f(-77.0f,20.0f);
glEnd();




}

void left_side_3rdBuilding()//105
{



//left side 3rd building
glBegin(GL_POLYGON);    //body
   glColor3ub(204,0,204);
	glVertex2f(-63.0f,16.0f);
	glVertex2f(-43.0f,16.0f);
	glVertex2f(-43.0f,32.0f);
    glVertex2f(-53.0f,35.0f);
    glVertex2f(-63.0f,32.0f);
glEnd();
glBegin(GL_POLYGON);    //roof top
   glColor3ub(255,255,255);
	glVertex2f(-63.0f,32.0f);
	glVertex2f(-64.0f,32.0f);
	glVertex2f(-53.0f,36.0f);
    glVertex2f(-53.0f,35.0f);
glEnd();
glBegin(GL_POLYGON);    //roof top
   glColor3ub(255,255,255);
	glVertex2f(-53.0f,35.0f);
	glVertex2f(-53.0f,36.0f);
	glVertex2f(-42.0f,32.0f);
    glVertex2f(-43.0f,32.0f);
glEnd();

glBegin(GL_POLYGON);    //window 1
   glColor3ub(255,255,255);
	glVertex2f(-61.0f,30.0f);
	glVertex2f(-57.0f,30.0f);
	glVertex2f(-57.0f,26.0f);
    glVertex2f(-61.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //window 2
   glColor3ub(255,255,255);
	glVertex2f(-61.0f,24.0f);
	glVertex2f(-57.0f,24.0f);
	glVertex2f(-57.0f,20.0f);
    glVertex2f(-61.0f,20.0f);
glEnd();
glBegin(GL_POLYGON);    //window 3
   glColor3ub(255,255,255);
	glVertex2f(-51.0f,30.0f);
	glVertex2f(-47.0f,30.0f);
	glVertex2f(-47.0f,26.0f);
    glVertex2f(-51.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //window 4
   glColor3ub(255,255,255);
	glVertex2f(-51.0f,24.0f);
	glVertex2f(-47.0f,24.0f);
	glVertex2f(-47.0f,20.0f);
    glVertex2f(-51.0f,20.0f);
glEnd();

}

void left_side_4thBuilding()//106
{



//left side 4th buildring
glBegin(GL_POLYGON);    //bottom
   glColor3ub(0,0,0);
	glVertex2f(-41.0f,13.0f);
	glVertex2f(-11.0f,13.0f);
	glVertex2f(-11.0f,14.0f);
    glVertex2f(-41.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);    //body
   glColor3ub(76,0,153);
	glVertex2f(-41.0f,26.0f);
	glVertex2f(-35.0f,26.0f);
	glVertex2f(-35.0f,14.0f);
    glVertex2f(-41.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);
   glColor3ub(76,0,153);
	glVertex2f(-17.0f,26.0f);
	glVertex2f(-11.0f,26.0f);
	glVertex2f(-11.0f,14.0f);
    glVertex2f(-17.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);
   glColor3ub(76,0,153);
	glVertex2f(-35.0f,66.0f);
	glVertex2f(-17.0f,66.0f);
	glVertex2f(-17.0f,14.0f);
    glVertex2f(-35.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3ub(76,0,153);
	glVertex2f(-39.0f,50.0f);
	glVertex2f(-13.0f,50.0f);
	glVertex2f(-13.0f,14.0f);
    glVertex2f(-39.0f,14.0f);
glEnd();
//left
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(-41.0f,26.0f);
	glVertex2f(-35.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(-41.0f,14.0f);
	glVertex2f(-35.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(-41.0f,26.0f);
	glVertex2f(-41.0f,14.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(255,255,255);
	glVertex2f(-35.0f,26.0f);
	glVertex2f(-35.0f,14.0f);
glEnd();
//right
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(-17.0f,26.0f);
	glVertex2f(-11.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(-17.0f,14.0f);
	glVertex2f(-11.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(-17.0f,26.0f);
	glVertex2f(-17.0f,14.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(255,255,255);
	glVertex2f(-11.0f,26.0f);
	glVertex2f(-11.0f,14.0f);
glEnd();

//mid
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(-35.0f,42.0f);
	glVertex2f(-17.0f,42.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(-35.0f,20.0f);
	glVertex2f(-17.0f,20.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(-35.0f,42.0f);
	glVertex2f(-35.0f,20.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(255,255,255);
	glVertex2f(-17.0f,42.0f);
	glVertex2f(-17.0f,20.0f);
glEnd();

glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(-31.0f,20.0f);
	glVertex2f(-31.0f,14.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(-26.0f,20.0f);
	glVertex2f(-26.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(-21.0f,14.0f);
	glVertex2f(-21.0f,20.0f);
	glEnd();

//2nd storage
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(-39.0f,50.0f);
	glVertex2f(-39.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(-13.0f,50.0f);
	glVertex2f(-13.0f,26.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(-39.0f,50.0f);
	glVertex2f(-13.0f,50.0f);
	glEnd();

//3nd storage
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(-35.0f,50.0f);
	glVertex2f(-35.0f,66.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(-17.0f,50.0f);
	glVertex2f(-17.0f,66.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(-35.0f,66.0f);
	glVertex2f(-17.0f,66.0f);
	glEnd();



}

void right_side_1stBuilding()//107
{


//right side 1st buildring
glBegin(GL_POLYGON);    //
    glColor3ub(0,0,0);
	glVertex2f(121.0f,14.0f);
	glVertex2f(91.0f,14.0f);
	glVertex2f(91.0f,13.0f);
    glVertex2f(121.0f,13.0f);
glEnd();
glBegin(GL_POLYGON);    //
    glColor3ub(255,225,153);
	glVertex2f(121.0f,14.0f);
	glVertex2f(115.0f,14.0f);
	glVertex2f(115.0f,26.0f);
    glVertex2f(121.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //
    glColor3ub(255,225,153);
	glVertex2f(97.0f,14.0f);
	glVertex2f(91.0f,14.0f);
	glVertex2f(91.0f,26.0f);
    glVertex2f(97.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    // door glass
    glColor3ub(255,225,153);
	glVertex2f(115.0f,14.0f);
	glVertex2f(97.0f,14.0f);
	glVertex2f(97.0f,19.0f);
    glVertex2f(115.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //up
    glColor3ub(0,0,0);
	glVertex2f(115.0f,19.0f);
	glVertex2f(97.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //1
    glColor3ub(0,0,0);
	glVertex2f(111.0f,19.0f);
	glVertex2f(111.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(106.0f,19.0f);
	glVertex2f(106.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(0,0,0);
	glVertex2f(101.0f,19.0f);
	glVertex2f(101.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(0,0,0);
	glVertex2f(115.0f,19.0f);
	glVertex2f(115.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //5
    glColor3ub(0,0,0);
	glVertex2f(97.0f,19.0f);
	glVertex2f(97.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);    //
    glColor3ub(255,225,153);
	glVertex2f(119.0f,26.0f);
	glVertex2f(93.0f,26.0f);
	glVertex2f(93.0f,54.0f);
    glVertex2f(119.0f,54.0f);
glEnd();
glBegin(GL_POLYGON);    // 2nd storage
   glColor3ub(255,225,153);
	glVertex2f(115.0f,34.0f);
	glVertex2f(97.0f,34.0f);
	glVertex2f(97.0f,19.0f);
    glVertex2f(115.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(115.0f,19.0f);
	glVertex2f(97.0f,19.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(115.0f,42.0f);
	glVertex2f(97.0f,42.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(115.0f,42.0f);
	glVertex2f(115.0f,19.0f);
glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(97.0f,42.0f);
	glVertex2f(97.0f,19.0f);
glEnd();


glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(115.0f,26.0f);
	glVertex2f(121.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(121.0f,26.0f);
	glVertex2f(121.0f,14.0f);
glEnd();

glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(97.0f,26.0f);
	glVertex2f(91.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(91.0f,26.0f);
	glVertex2f(91.0f,14.0f);
glEnd();


glBegin(GL_POLYGON);    // 2nd storage
   glColor3ub(255,225,153);
	glVertex2f(115.0f,54.0f);
	glVertex2f(97.0f,54.0f);
	glVertex2f(97.0f,62.0f);
    glVertex2f(115.0f,62.0f);
glEnd();

//line for top storage
glBegin(GL_LINES);    //1
    glColor3ub(0,0,0);
	glVertex2f(115.0f,54.0f);
	glVertex2f(97.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(115.0f,62.0f);
	glVertex2f(115.0f,54.0f);
glEnd();

glBegin(GL_LINES);    //3
    glColor3ub(0,0,0);
	glVertex2f(97.0f,62.0f);
	glVertex2f(97.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(0,0,0);
	glVertex2f(115.0f,62.0f);
	glVertex2f(97.0f,62.0f);
glEnd();

//3rd storage border
glBegin(GL_LINES);    //1
    glColor3ub(0,0,0);
	glVertex2f(119.0f,54.0f);
	glVertex2f(93.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(0,0,0);
	glVertex2f(119.0f,26.0f);
	glVertex2f(119.0f,54.0f);
glEnd();

glBegin(GL_LINES);    //3
    glColor3ub(0,0,0);
	glVertex2f(93.0f,26.0f);
	glVertex2f(93.0f,54.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(0,0,0);
	glVertex2f(119.0f,54.0f);
	glVertex2f(93.0f,54.0f);
glEnd();

 glColor3ub(0,0,0);
DrawCircle(110,58, 2, 10000);
glEnd();

 glColor3ub(255,255,255);
DrawCircle(102,58, 2, 10000);
glEnd();




}

void right_side_2ndBuilding()//108
{


// right side 2nd building
glBegin(GL_POLYGON);    //body
   glColor3ub(255,102,102);
	glVertex2f(84.0f,16.0f);
	glVertex2f(68.0f,16.0f);
	glVertex2f(68.0f,38.0f);
    glVertex2f(84.0f,38.0f);
glEnd();

glBegin(GL_POLYGON);    //body
   glColor3ub(255,255,255);
	glVertex2f(85.0f,39.0f);
	glVertex2f(67.0f,39.0f);
	glVertex2f(67.0f,38.0f);
    glVertex2f(85.0f,38.0f);
glEnd();

glBegin(GL_POLYGON);    //window left 1
   glColor3ub(255,255,255);
	glVertex2f(83.0f,36.0f);
	glVertex2f(78.0f,36.0f);
	glVertex2f(78.0f,31.0f);
    glVertex2f(83.0f,31.0f);
glEnd();
glBegin(GL_POLYGON);    //window left 2
   glColor3ub(255,255,255);
	glVertex2f(83.0f,29.0f);
	glVertex2f(78.0f,29.0f);
	glVertex2f(78.0f,24.0f);
    glVertex2f(83.0f,24.0f);
glEnd();
glBegin(GL_POLYGON);    //window left 3
   glColor3ub(255,255,255);
	glVertex2f(83.0f,22.0f);
	glVertex2f(78.0f,22.0f);
	glVertex2f(78.0f,17.0f);
    glVertex2f(83.0f,17.0f);
glEnd();


glBegin(GL_POLYGON);    //window right 1
   glColor3ub(255,255,255);
	glVertex2f(74.0f,36.0f);
	glVertex2f(69.0f,36.0f);
	glVertex2f(69.0f,31.0f);
    glVertex2f(74.0f,31.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 2
   glColor3ub(255,255,255);
	glVertex2f(74.0f,29.0f);
	glVertex2f(69.0f,29.0f);
	glVertex2f(69.0f,24.0f);
    glVertex2f(74.0f,24.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 3
   glColor3ub(255,255,255);
	glVertex2f(74.0f,22.0f);
	glVertex2f(69.0f,22.0f);
	glVertex2f(69.0f,17.0f);
    glVertex2f(74.0f,17.0f);
glEnd();

//mid window
glBegin(GL_POLYGON);    //window right 1
   glColor3ub(255,255,255);
	glVertex2f(77.0f,37.0f);
	glVertex2f(75.0f,37.0f);
	glVertex2f(75.0f,32.0f);
    glVertex2f(77.0f,32.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 2
   glColor3ub(255,255,255);
	glVertex2f(77.0f,30.0f);
	glVertex2f(75.0f,30.0f);
	glVertex2f(75.0f,26.0f);
    glVertex2f(77.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //window right 3
   glColor3ub(255,255,255);
	glVertex2f(77.0f,24.0f);
	glVertex2f(75.0f,24.0f);
	glVertex2f(75.0f,20.0f);
    glVertex2f(77.0f,20.0f);
glEnd();

}

void right_side_3rdBuilding()//109
{



//right side 3rd building
glBegin(GL_POLYGON);    //body
   glColor3ub(0,204,204);
	glVertex2f(63.0f,16.0f);
	glVertex2f(43.0f,16.0f);
	glVertex2f(43.0f,32.0f);
    glVertex2f(53.0f,35.0f);
    glVertex2f(63.0f,32.0f);
glEnd();
glBegin(GL_POLYGON);    //roof top
   glColor3ub(255,255,255);
	glVertex2f(63.0f,32.0f);
	glVertex2f(64.0f,32.0f);
	glVertex2f(53.0f,36.0f);
    glVertex2f(53.0f,35.0f);
glEnd();
glBegin(GL_POLYGON);    //roof top
   glColor3ub(255,255,255);
	glVertex2f(53.0f,35.0f);
	glVertex2f(53.0f,36.0f);
	glVertex2f(42.0f,32.0f);
    glVertex2f(43.0f,32.0f);
glEnd();

glBegin(GL_POLYGON);    //window 1
   glColor3ub(255,255,255);
	glVertex2f(61.0f,30.0f);
	glVertex2f(57.0f,30.0f);
	glVertex2f(57.0f,26.0f);
    glVertex2f(61.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //window 2
   glColor3ub(255,255,255);
	glVertex2f(61.0f,24.0f);
	glVertex2f(57.0f,24.0f);
	glVertex2f(57.0f,20.0f);
    glVertex2f(61.0f,20.0f);
glEnd();
glBegin(GL_POLYGON);    //window 3
   glColor3ub(255,255,255);
	glVertex2f(51.0f,30.0f);
	glVertex2f(47.0f,30.0f);
	glVertex2f(47.0f,26.0f);
    glVertex2f(51.0f,26.0f);
glEnd();
glBegin(GL_POLYGON);    //window 4
   glColor3ub(255,255,255);
	glVertex2f(51.0f,24.0f);
	glVertex2f(47.0f,24.0f);
	glVertex2f(47.0f,20.0f);
    glVertex2f(51.0f,20.0f);
glEnd();

}

void right_side_4thBuilding()//110
{




//right side 4th buildring
glBegin(GL_POLYGON);    //bottom black
   glColor3ub(0,0,0);
	glVertex2f(41.0f,13.0f);
	glVertex2f(11.0f,13.0f);
	glVertex2f(11.0f,14.0f);
    glVertex2f(41.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);    //body
   glColor3ub(51,25,0);
	glVertex2f(41.0f,26.0f);
	glVertex2f(35.0f,26.0f);
	glVertex2f(35.0f,14.0f);
    glVertex2f(41.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);
   glColor3ub(51,25,0);
	glVertex2f(17.0f,26.0f);
	glVertex2f(11.0f,26.0f);
	glVertex2f(11.0f,14.0f);
    glVertex2f(17.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);
   glColor3ub(51,25,0);
	glVertex2f(35.0f,66.0f);
	glVertex2f(17.0f,66.0f);
	glVertex2f(17.0f,14.0f);
    glVertex2f(35.0f,14.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3ub(51,25,0);
	glVertex2f(39.0f,50.0f);
	glVertex2f(13.0f,50.0f);
	glVertex2f(13.0f,14.0f);
    glVertex2f(39.0f,14.0f);
glEnd();
//left
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(41.0f,26.0f);
	glVertex2f(35.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(41.0f,14.0f);
	glVertex2f(35.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(41.0f,26.0f);
	glVertex2f(41.0f,14.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(255,255,255);
	glVertex2f(35.0f,26.0f);
	glVertex2f(35.0f,14.0f);
glEnd();
//right
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(17.0f,26.0f);
	glVertex2f(11.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(17.0f,14.0f);
	glVertex2f(11.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(17.0f,26.0f);
	glVertex2f(17.0f,14.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(255,255,255);
	glVertex2f(11.0f,26.0f);
	glVertex2f(11.0f,14.0f);
glEnd();

//mid
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(35.0f,42.0f);
	glVertex2f(17.0f,42.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(35.0f,20.0f);
	glVertex2f(17.0f,20.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(35.0f,42.0f);
	glVertex2f(35.0f,20.0f);
	glEnd();
glBegin(GL_LINES);    //4
    glColor3ub(255,255,255);
	glVertex2f(17.0f,42.0f);
	glVertex2f(17.0f,20.0f);
glEnd();

glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(31.0f,20.0f);
	glVertex2f(31.0f,14.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(26.0f,20.0f);
	glVertex2f(26.0f,14.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(21.0f,14.0f);
	glVertex2f(21.0f,20.0f);
	glEnd();

//2nd storage
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(39.0f,50.0f);
	glVertex2f(39.0f,26.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(13.0f,50.0f);
	glVertex2f(13.0f,26.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(39.0f,50.0f);
	glVertex2f(13.0f,50.0f);
	glEnd();

//3nd storage
glBegin(GL_LINES);    //1
    glColor3ub(255,255,255);
	glVertex2f(35.0f,50.0f);
	glVertex2f(35.0f,66.0f);
	glEnd();
glBegin(GL_LINES);    //2
    glColor3ub(255,255,255);
	glVertex2f(17.0f,50.0f);
	glVertex2f(17.0f,66.0f);
glEnd();
glBegin(GL_LINES);    //3
    glColor3ub(255,255,255);
	glVertex2f(35.0f,66.0f);
	glVertex2f(17.0f,66.0f);
	glEnd();

}

void middle_building()//111
{


//mid building
 glBegin(GL_POLYGON);
    glColor3ub(0,102,102);
	glVertex2f(-8.0f,13.0f);
	glVertex2f(7.0f,13.0f);
	glVertex2f(7.0f,45.0f);
    glVertex2f(-8.0f,45.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2f(-7.0f,42.0f);
	glVertex2f(6.0f,42.0f);
	glVertex2f(6.0f,44.0f);
    glVertex2f(-7.0f,44.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2f(-7.0f,32.0f);
	glVertex2f(6.0f,32.0f);
	glVertex2f(6.0f,41.0f);
    glVertex2f(-7.0f,41.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2f(-7.0f,30.0f);
	glVertex2f(6.0f,30.0f);
	glVertex2f(6.0f,28.0f);
    glVertex2f(-7.0f,28.0f);
glEnd();
glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
	glVertex2f(-7.0f,26.0f);
	glVertex2f(6.0f,26.0f);
	glVertex2f(6.0f,15.0f);
    glVertex2f(-7.0f,15.0f);
glEnd();
}

void BsS() //background sky  sun//112
{
  glBegin(GL_POLYGON);    //black border
    glColor3ub(96,96,96);
	glVertex2f(-128.0f,10.0f);
	glVertex2f(128.0f, 10.0f);
	glVertex2f(128.0f,12.0f);
    glVertex2f(-128.0f,12.0f);
glEnd();

  glBegin(GL_POLYGON);    //green borderd
    glColor3ub(0,255,0);
	glVertex2f(-128.0f,12.0f);
	glVertex2f(128.0f,12.0f);
	glVertex2f(128.0f,26.0f);
    glVertex2f(-128.0f,26.0f);
glEnd();
//sky making
glBegin(GL_POLYGON);
    glColor3ub(153,255,255);
	glVertex2f(-128.0f,26.0f);
	glVertex2f(128.0f,26.0f);
	glVertex2f(128.0f,70.0f);
    glVertex2f(-128.0f,70.0f);
glEnd();

//sun making
glColor3ub(255,255,0);
DrawCircle(72,62, 6, 10000);
glEnd();




}

void left_side_tree()//113
{
//left side 1st tree
    glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(-123.0f,14.0f);
	glVertex2f(-126.0f,14.0f);
	glVertex2f(-126.0f,28.0f);
    glVertex2f(-123.0f,28.0f);
    glEnd();
    glColor3ub(51,102,0);
    DrawCircle(-127,28, 3, 10000);
    glEnd();
    glColor3ub(51,102,0);
    DrawCircle(-122,28, 3, 10000);
    glEnd();
    glColor3ub(51,102,0);
DrawCircle(-125,30, 3, 10000);
glEnd();

//left side 2nd tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(-123+38.0f,14.0f);
	glVertex2f(-126+38.0f,14.0f);
	glVertex2f(-126+38.0f,28.0f);
    glVertex2f(-123+38.0f,28.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(-127+38,28, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-122+38,28, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-125+38,30, 3, 10000);
glEnd();


//left side 3rd tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(-123+38+21.0f,14.0f);
	glVertex2f(-126+38+21.0f,14.0f);
	glVertex2f(-126+38+21.0f,24.0f);
    glVertex2f(-123+38+21.0f,24.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(-127+38+21,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-122+38+21,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-125+38+21,26, 3, 10000);
glEnd();

//left side 4th tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(-44.0f,14.0f);
	glVertex2f(-42.0f,14.0f);
	glVertex2f(-42.0f,24.0f);
    glVertex2f(-44.0f,24.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(-127+38+21+22.5,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-122+38+21+22.5,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-125+38+21+23,26, 3, 10000);
glEnd();

//left side 5th tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(-8.5f,18.0f);
	glVertex2f(-10.0f,18.0f);
	glVertex2f(-10.0f,26.0f);
    glVertex2f(-8.5f,26.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(-127+38+21+22.5+35.5,24, 2, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-122+38+21+22.5+32.5,24, 2, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(-125+38+21+23+34,26, 2, 10000);
glEnd();

}
void right_side_tree()//114
{
    //left side 1st tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(123.0f,14.0f);
	glVertex2f(126.0f,14.0f);
	glVertex2f(126.0f,28.0f);
    glVertex2f(123.0f,28.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(127,28, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(122,28, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(125,30, 3, 10000);
glEnd();

//left side 2nd tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(123-38.0f,14.0f);
	glVertex2f(126-38.0f,14.0f);
	glVertex2f(126-38.0f,28.0f);
    glVertex2f(123-38.0f,28.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(127-38,28, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(122-38,28, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(125-38,30, 3, 10000);
glEnd();


//left side 3rd tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(123-38-21.0f,14.0f);
	glVertex2f(126-38-21.0f,14.0f);
	glVertex2f(126-38-21.0f,24.0f);
    glVertex2f(123-38-21.0f,24.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(127-38-21,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(122-38-21,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(125-38-21,26, 3, 10000);
glEnd();

//left side 4th tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(44.0f,14.0f);
	glVertex2f(42.0f,14.0f);
	glVertex2f(42.0f,24.0f);
    glVertex2f(44.0f,24.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(127-38-21-22.5,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(122-38-21-22.5,24, 3, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(125-38-21-23,26, 3, 10000);
glEnd();

//left side 5th tree
glBegin(GL_POLYGON);
    glColor3ub(153,76,0);
	glVertex2f(8.5f,18.0f);
	glVertex2f(10.0f,18.0f);
	glVertex2f(10.0f,26.0f);
    glVertex2f(8.5f,26.0f);
glEnd();
 glColor3ub(51,102,0);
DrawCircle(127-38-21-22.5-35.5,24, 2, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(122-38-21-22.5-32.5,24, 2, 10000);
glEnd();
glColor3ub(51,102,0);
DrawCircle(125-38-21-23-34,26, 2, 10000);
glEnd();

}





/////////////////////JEBA FAWJIA///////////

void water(){
glPushMatrix();

 /////////water//// 301

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(0, 211, 255  );
	glVertex2f(-128.0f, -13.0f);
	glVertex2f(128.0f, -13.0f);
	glVertex2f(128.0f, -128.0f);
    glVertex2f(-128.0f, -128.0f);
    glEnd();
glPopMatrix();

}

void waterlines(){
glPushMatrix();
///////waterlines/////// 302

    glLineWidth(3);
    glBegin(GL_LINES);            // These vertices form a closed polygon
	glColor3ub(255, 255, 255 );
	glVertex2f(-4.0f, -13.0f);
	glVertex2f(-10.0f, -13.0f);
    glVertex2f(-10.0f, -13.0f);
	glVertex2f(-4.0f, -13.0f);

	glVertex2f(100.0f, -20.0f);
	glVertex2f(110.0f, -20.0f);
    glVertex2f(110.0f, -20.0f);
	glVertex2f(100.0f, -20.0f);

	glVertex2f(-100.0f, -20.0f);
	glVertex2f(-110.0f, -20.0f);
    glVertex2f(-110.0f, -20.0f);
	glVertex2f(-100.0f, -20.0f);

	glVertex2f(-60.0f, -25.0f);
	glVertex2f(-70.0f, -25.0f);
    glVertex2f(-70.0f, -25.0f);
	glVertex2f(-60.0f, -25.0f);

	glVertex2f(60.0f, -25.0f);
	glVertex2f(70.0f, -25.0f);
    glVertex2f(70.0f, -25.0f);
	glVertex2f(60.0f, -25.0f);
    glEnd();

glPopMatrix();
}


void Boundery(){

///////Boundery//////////// 303

    glLineWidth(16);
    glBegin(GL_LINES);            // These vertices form a closed polygon
	glColor3ub(91, 34, 15 );
	glVertex2f(-128.0f, -13.0f);
	glVertex2f(128.0f, -13.0f);
    glEnd();

}

void relling(){
//Relling  304
glPushMatrix();
 glLineWidth(10); // These vertices form a closed polygon
 glBegin(GL_LINES);
	glColor3ub(207, 138, 39 );
	glVertex2f(-128.0f, -7.0f);
	glVertex2f(128.0f, -7.0f);
	glVertex2f(12.0f, -7.0f);
	glVertex2f(12.0f, -13.0f);

	glVertex2f(-4.0f, -7.0f);
	glVertex2f(-4.0f, -13.0f);

	glVertex2f(-20.0f, -7.0f);
	glVertex2f(-20.0f, -13.0f);

	glVertex2f(12.0f, -7.0f);
	glVertex2f(12.0f, -13.0f);

	glVertex2f(28.0f, -7.0f);
	glVertex2f(28.0f, -13.0f);
	glVertex2f(-36.0f, -7.0f);
	glVertex2f(-36.0f, -13.0f);


	glVertex2f(44.0f, -7.0f);
	glVertex2f(44.0f, -13.0f);
	glVertex2f(-52.0f, -7.0f);
	glVertex2f(-52.0f, -13.0f);

	glVertex2f(60.0f, -7.0f);
	glVertex2f(60.0f, -13.0f);

	glVertex2f(-68.0f, -7.0f);
	glVertex2f(-68.0f, -13.0f);
	glVertex2f(76.0f, -7.0f);
	glVertex2f(76.0f, -13.0f);


	glVertex2f(-85.0f, -7.0f);
	glVertex2f(-85.0f, -13.0f);
	glVertex2f(93.0f, -7.0f);
	glVertex2f(93.0f, -13.0f);

	glVertex2f(-101.0f, -7.0f);
	glVertex2f(-101.0f, -13.0f);


	glVertex2f(109.0f, -7.0f);
	glVertex2f(109.0f, -13.0f);
	glVertex2f(-117.0f, -7.0f);
	glVertex2f(-117.0f, -13.0f);

	glVertex2f(125.0f, -7.0f);
	glVertex2f(125.0f, -13.0f);

    glEnd();


glPopMatrix();
}
void smallship(){

////////////////////Ship1///////// 305
glPushMatrix();
glTranslatef(_move2, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(25, 18, 3 );
glVertex2f(4.0f, -10.0f);
glVertex2f(6.0f, -10.0f);
glVertex2f(6.0f, -1.0f);
glVertex2f(4.0f, -1.0f);
glVertex2f(2.0f, -10.0f);
glVertex2f(0.0f, -10.0f);
glVertex2f(0.0f, -1.0f);
glVertex2f(2.0f, -1.0f);

glColor3ub(7, 17, 118 );
glVertex2f(-6.0f, -10.0f);
glVertex2f(10.0f, -10.0f);
glVertex2f(12.0f, -15.0f);
glVertex2f(-10.0f, -15.0f);

glColor3ub(85, 64, 17   );
glVertex2f(-16.0f, -15.0f);
glVertex2f(15.0f, -15.0f);
glVertex2f(15.0f, -19.0f);
glVertex2f(-20.0f, -19.0f);

glColor3ub(2, 5, 15 );
glVertex2f(-32.0f, -19.0f);
glVertex2f(20.0f, -19.0f);
glVertex2f(20.0f, -24.0f);
glVertex2f(-20.0f, -24.0f);

glColor3ub(229, 255, 0);
glVertex2f(-15.0f, -16.0f);
glVertex2f(12.0f, -16.0f);
glVertex2f(12.0f, -18.0f);
glVertex2f(-17.0f, -18.0f);

glColor3ub(246, 133, 81 );
glVertex2f(9.0f, -11.0f);
glVertex2f(5.0f, -11.0f);
glVertex2f(5.0f, -14.0f);
glVertex2f(11.0f, -14.0f);
glVertex2f(-5.0f, -11.0f);
glVertex2f(4.0f, -11.0f);
glVertex2f(4.0f, -14.0f);
glVertex2f(-8.0f, -14.0f);
glEnd();
glPopMatrix();

}

void bigship(){


///////////////////ship2 306

glPushMatrix();
glTranslatef(_move6, 0.0f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(255, 255, 255  );
glVertex2f(-47.0f, -30.0f);
glVertex2f(-44.0f, -33.0f);
glVertex2f(3.0f, -33.0f);
glVertex2f(15.0f, -28.0f);

glColor3ub(15, 19, 112  );
glVertex2f(-40.0f, -38.0f);
glVertex2f(-44.0f, -33.0f);
glVertex2f(4.0f, -33.0f);
glVertex2f(-2.0f, -38.0f);
glEnd();


glLineWidth(4);
glBegin(GL_LINES);            // These vertices form a closed polygon
glColor3ub(12, 13, 43  );
glVertex2f(-47.0f, -30.0f);
glVertex2f(15.0f, -28.0f);
glVertex2f(-47.0f, -30.0f);
glEnd();



//glTranslatef(_move, 0.0f, 0.0f);
glBegin(GL_QUADS);
glColor3ub(67, 82, 82);
glVertex2f(-30.0f, -29.0f);
glVertex2f(-25.0f, -20.0f);
glVertex2f(-2.0f, -20.0f);
glVertex2f(4.0f, -28.4f);

glColor3ub(255, 254, 5 );
glVertex2f(-15.0f, -27.0f);
glVertex2f(-27.0f, -27.0f);
glVertex2f(-23.0f, -22.0f);
glVertex2f(-15.0f, -22.0f);
glVertex2f(-14.0f, -27.0f);
glVertex2f(-1.0f, -27.0f);
glVertex2f(-3.0f, -22.0f);
glVertex2f(-14.0f, -22.0f);

glColor3ub(23, 64, 114  );
glVertex2f(-22.0f, -18.0f);
glVertex2f(-30.0f, -29.0f);
glVertex2f(-44.0f, -30.0f);
glVertex2f(-51.0f, -18.0f);
glColor3ub(255, 191, 115 );
glVertex2f(-26.0f, -20.0f);
glVertex2f(-46.0f, -20.0f);
glVertex2f(-43.0f, -25.0f);
glVertex2f(-29.0f, -25.0f);

glColor3ub(66, 47, 16 );
glVertex2f(-40.0f, -18.0f);
glVertex2f(-43.0f, -18.0f);
glVertex2f(-43.0f, -5.0f);
glVertex2f(-40.0f, -5.0f);
glVertex2f(-36.0f, -18.0f);
glVertex2f(-33.0f, -18.0f);
glVertex2f(-33.0f, -5.0f);
glVertex2f(-36.0f, -5.0f);
glVertex2f(-28.0f, -18.0f);
glVertex2f(-25.0f, -18.0f);
glVertex2f(-25.0f, -5.0f);
glVertex2f(-28.0f, -5.0f);

glEnd();


glPopMatrix();
}


/////bigship animation///////// 307

void BigShipMove_update(int value) {

	_move6 +=1.0f;
    if(_move6-1.663 > 128.0)
    {
        _move6 = -128.0;
    }

    glutPostRedisplay();
glutTimerFunc(25, BigShipMove_update, 0);

}

/////smallship  animation///////// 308

void SmallShipMove_update1(int value) {


    _move2 -=2.0f;
    if(_move2+1.5 < -128.0)
    {
        _move2 = 128.0;
    }

	glutPostRedisplay();
	glutTimerFunc(100,SmallShipMove_update1,0);
}

void day()
{
    glClearColor(1.0,1.0,1.0,1.0);
glutPostRedisplay();

glFlush();


}
void night()
{
    glClearColor(0.0,0.0,0.0,0.4);
glutPostRedisplay();
}



void handleKeypress(unsigned char key, int x, int y) //210
{

	switch (key)
	{
/*
case 'd':

    glClearColor(1.0,1.0,1.0,1.0);
    glutPostRedisplay();
   // glutDisplayFunc(day);
    //day();
    break;
case 'n':
    glClearColor(0.0,0.0,0.0,1.0);
    //
    night();
    glutPostRedisplay();
    break;
*/

    case 'a':
    upperCarStatus=0;
    glutPostRedisplay();

    break;
case 'b':
    upperCarStatus=1;

    glutPostRedisplay();
    break;

case 'c':
    upperTruckStatus=0;
    glutPostRedisplay();

    break;
case 'd':
    upperTruckStatus=1;

    glutPostRedisplay();
    break;

case 'e':
    lowerCarStatus=0;
    glutPostRedisplay();
    break;

case 'f':
    lowerCarStatus=1;
    glutPostRedisplay();
    break;

case 'g':
    lowerBusStatus=0;
    glutPostRedisplay();
    break;

case 'h':
    lowerBusStatus=1;
    glutPostRedisplay();
    break;


	}
	glutPostRedisplay();
}


void display() {

	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color



BsS();

left_side_1stBuilding();
left_side_2ndBuilding();
left_side_3rdBuilding();
left_side_4thBuilding();

right_side_1stBuilding();
right_side_2ndBuilding();
right_side_3rdBuilding();
right_side_4thBuilding();
middle_building();
left_side_tree();
right_side_tree();

clock1();
clock2();

    water();
    waterlines();
    Boundery();
    Road();
    relling();
     smallship();
     bigship();


	glFlush();  // Render now
}



/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    cout<<"Press 'a' to stop the upper car" <<endl;
    cout<<"Press 'b' to move the upper car" <<endl;
    cout<<"Press 'c' to stop the upper truck" <<endl;
    cout<<"Press 'd' to move the upper truck" <<endl;
    cout<<"Press 'e' to stop the lower car" <<endl;
    cout<<"Press 'f' to move the lower car" <<endl;
    cout<<"Press 'g' to stop the lower bus" <<endl;
    cout<<"Press 'h' to move the lower bus" <<endl;

	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );               // Initialize GLUT
	glutCreateWindow("Final Project"); // Create a window with the given title
	glutInitWindowSize(1280, 720);
	//glutDisplayFunc(display);
    gluOrtho2D(-128,128,-60,70);   // Set the window's initial width & height
    glutTimerFunc(100, BigShipMove_update, 0); //Add a timer
    glutTimerFunc(100, SmallShipMove_update1, 0); //Add a timer
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutKeyboardFunc(handleKeypress);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}









