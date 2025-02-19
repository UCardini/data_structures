#include "basketballPlayer.h"
#include <iostream>
// sets the initial values for each member when used 
basketballPlayer::basketballPlayer(std::string Name, int ShotsTaken, int ShotsMade, int PassesAttempted, int PassesMade)
{
    this->Name = Name;
    this->ShotsTaken = ShotsTaken;
    this->ShotsMade = ShotsMade;
    this->PassesAttempted = PassesAttempted;
    this->PassesMade = PassesMade;

} 
// Displays a players stats 
void basketballPlayer::playerStats()
{
  std::cout<<std::endl<<Name<<"'s Stats: "<<std::endl;
  std::cout<<"Shots Taken:\t  "<<ShotsTaken<<std::endl;
  std::cout<<"Shots Made:\t  "<<ShotsMade<<std::endl;
  std::cout<<"Passes Attempted: "<<PassesAttempted<<std::endl;
  std::cout<<"Passes Made:\t  "<<PassesMade<<std::endl;
}

/* Function: PassBall()
 *   Inputs: None
 *  Outputs: true/false
 *
 *  This function determines if a 
 *  pass is made. If there hasn't 
 *  been any passes made yet it uses
 *  a 1/2 chance of landing on pass
 *  in order to initialize PassesMade.
 *  If there has been passes made it 
 *  will calculate the passing 
 *  percentage and if it's higher
 *  than the random number you 
 *  make the pass and it returns true. 
 */
bool basketballPlayer::PassBall()
{
  int passChance = rand()%100 + 1;
  double passingPercentage = 100*static_cast<double>(PassesMade)/PassesAttempted;

  PassesAttempted++;
  if(PassesMade==0) // This is used once to initialize PassesMade otherwise it always is 0
  {
    if(passChance>100/2) 
    {
      PassesMade++;
      return true;
    }
    else 
    {
      return false;
    }
  }
  if(passChance<passingPercentage)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

/* Function: TakeShot
 *   Inputs: int points
 *  Outputs: points scored
 *
 *  This function determines if a 
 *  shot is made. If there hasn't 
 *  been any shots made yet it uses
 *  a 1/2 chance of landing on throw
 *  in order to initialize ShotsMade.
 *  If there has been shots made it 
 *  will calculate the shooting 
 *  percentage and if it's higher
 *  than the random number you 
 *  make the shot. If you miss 
 *  the shot it returns 0, and if 
 *  an input thats invalid it 
 *  returns -1.
 */
int basketballPlayer::TakeShot(int points)
{
  double shootingPercentage = 100*static_cast<double>(ShotsMade)/ShotsTaken; 

  int onePointerChance = rand()%70 + 1; // random number 1-70
  int twoPointerChance = rand()%100 + 1; // random number 1-100
  int threePointerChance = rand()%125 + 1;// random number 1-125

  ShotsTaken++;
  if(ShotsMade == 0) // value will always be zero if there isn't a special case checking 
  {
    if(points==3)
    {
      if(threePointerChance>125/2)
      {
        ShotsMade++;
        return 3;
      }
      else return 0;
    }
    else if(points == 2)
    {
      if(twoPointerChance>100/2)
      {
        ShotsMade++;
        return 2;
      }
      else return 0;
    }
    else if(points == 1)
    {
      if(onePointerChance>70/2)
      {
        ShotsMade++;
        return 1;
      }
      else return 0;
    }
    else return -1; //for error handling
  }

  if(points == 3)
  {
    if(threePointerChance < shootingPercentage)
    {
      ShotsMade++;
      return 3;
    }
    else return 0;
  }
  else if(points == 2) 
  {
    if(twoPointerChance < shootingPercentage)
    {
      ShotsMade++;
      return 2;
    }
    else return 0; 
  }
  else if(points == 1)
  {
    if(onePointerChance < shootingPercentage)
    {
      ShotsMade++;
      return 1;
    }
    else return 0;
  }
  else return -1; //for error handling
}
