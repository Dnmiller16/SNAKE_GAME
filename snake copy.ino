#include <MeggyJrSimple.h> 

int direction = 0;
int applex = random (8);
int appley = random (8);
int D = 200;
struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point snakeArray[64]= {p1, p2, p3};

int marker=3;

void setup()  
{
   MeggyJrSimpleSetup(); 
   Serial.begin (9600);
}

void loop ()

{
  Serial.print ("X is ");
  Serial.println (snakeArray[0].x);
  Serial.print ("Y is ");
  Serial.println (snakeArray[0].y);
  Serial.println (); 
  drawSnake();
  DrawPx(snakeArray[0].x, snakeArray[0].y,Red);
  DisplaySlate();
  delay(D);
  ClearSlate();
  updateSnake();
  DrawPx(applex,appley,Yellow);
  CheckButtonsPress();
   if (Button_Right)
    {
      direction=90;   
    }
  
   if (Button_Left)
    {
      direction=270;
    }

    if (Button_Down)
    {
       direction=180;
    }
 
   if (Button_Up) 
    {
      direction=0;
    }
    
      if (direction == 0) 
      {
      snakeArray[0].y ++;
      }
      if (direction == 90)
     { 
      snakeArray[0].x ++;
     }
      if (direction == 180) 
      
      {
     snakeArray[0].y --;
      }
      
      if (direction == 270) 
      
      {
     snakeArray[0].x --;
      }
      
      if (snakeArray[0].x > 7)
      
      {
      snakeArray[0].x=0;
      }
      
      if (snakeArray[0].y > 7)
      
      {
     snakeArray[0].y=0;
      }
      
      if (snakeArray[0].x < 0)
      
      {
      snakeArray[0].x=7;
      }
      
      if (snakeArray[0].y < 0)
      
      {
      snakeArray[0].y=7;
      }
      
    if (applex == snakeArray[0].x) 
    {
      if (appley == snakeArray[0].y) 
      {
        applex = random (8);
        appley = random (8);
        marker ++;
        D = D-2;
      }
    }    
}


void drawSnake()
{
  for (int i=0; i<marker; i++)
  {
   DrawPx (snakeArray[i].x, snakeArray[i].y,15);
  } 
}

void updateSnake()
{
  for (int i=marker-1; i>0; i--)
  {
    snakeArray[i] = snakeArray[i-1];
  }
}


