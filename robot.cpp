#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "robot.hpp"

#define DECALAGE 400
#define WINDOW_WIDTH VideoMode::getDesktopMode().width //Largeur de l'écran
#define WINDOW_HEIGHT (VideoMode::getDesktopMode().height - DECALAGE) //Hauteur de l'écran


void Robot::deplacement(bool upFlag, bool downFlag, bool leftFlag, bool rightFlag, IntRect* rectSourceSprite)
{
  float leftside, topside, rightside, bottomside;
  leftside=x;
  topside=y;
  rightside = x + sprite->getGlobalBounds().height;
  bottomside = y + sprite->getGlobalBounds().width;
  float cx = WINDOW_WIDTH/2;
  float cy = WINDOW_HEIGHT/2;


  // Update coordinates
  if (leftFlag)
  {
    x-=vitesse;
    if(((leftside-cx)*(leftside-cx)+ (topside-cy)*(topside-cy)) > (cy*cy)
    || ((leftside-cx)*(leftside-cx)+ (bottomside-cy)*(bottomside-cy)) > (cy*cy))

    {
      x+=vitesse;
    }
    rectSourceSprite->left=0;
    rectSourceSprite->top=0;

  }
  if (rightFlag)
  {
    x+=vitesse;
    if(((rightside-cx)*(rightside-cx)+ (topside-cy)*(topside-cy)) > (cy*cy)
    || ((rightside-cx)*(rightside-cx)+ (bottomside-cy)*(bottomside-cy)) > (cy*cy))
    {
      x-=vitesse;
    }
    rectSourceSprite->left=128;
    rectSourceSprite->top=98;
  }
  if (upFlag)
  {
    y-=vitesse;
    if(((leftside-cx)*(leftside-cx)+ (topside-cy)*(topside-cy)) > (cy*cy)
    || ((rightside-cx)*(rightside-cx)+ (topside-cy)*(topside-cy)) > (cy*cy))
    {
      y+=vitesse;
    }
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;
  }

  if (downFlag)
  {
    y+=vitesse;
    if(((leftside-cx)*(leftside-cx)+ (bottomside-cy)*(bottomside-cy)) > (cy*cy)
    || ((rightside-cx)*(rightside-cx)+ (bottomside-cy)*(bottomside-cy)) > (cy*cy))
    {
      y-=vitesse;
    }
    rectSourceSprite->left=0;
    rectSourceSprite->top=98;

  }

}

void Robot::settings() const
{
  sprite->setPosition(x,y);
}




bool Robot::onSegment(Point p, Point q, Point r)
{
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
      q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
      return true;

    return false;
}

int Robot::orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // collineaire

    return (val > 0)? 1: 2; // Sens horaire ou anti horaire
}

bool Robot::doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

void Robot::collision( FloatRect* R1 , RectangleShape* R2, IntRect* rectSourceSprite)
    {
      Vector2f TL2,BR2;
      struct Point line_corner_1,line_corner_4;
      struct Point sprite_corner_1,sprite_corner_2,sprite_corner_3,sprite_corner_4;

      sprite_corner_1.x=R1->left; sprite_corner_1.y=R1->top;
      sprite_corner_2.x=R1->left+ R1->height; sprite_corner_2.y=R1->top;
      sprite_corner_3.x=R1->left; sprite_corner_3.y=R1->top + R1->width;
      sprite_corner_4.x=R1->left + R1->height;  sprite_corner_4.y=R1->top + R1->width;

      TL2=R2->getTransform().transformPoint(R2->getPoint(0));
      BR2=R2->getTransform().transformPoint(R2->getPoint(2));

      line_corner_1.x= TL2.x;
      line_corner_1.y= TL2.y;
      line_corner_4.x=BR2.x;
      line_corner_4.y=BR2.y;


     if (doIntersect(sprite_corner_1, sprite_corner_4, line_corner_1, line_corner_4)
     || doIntersect(sprite_corner_2, sprite_corner_3, line_corner_1, line_corner_4) )
        {
          rectSourceSprite->left=403;
          rectSourceSprite->top=250;
          rectSourceSprite->width=75;
          rectSourceSprite->height=75;
          life=false;
        }

      }
