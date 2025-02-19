#include "basketballPlayer.h"
#include <iostream>
// compiled using "g++ -o main *.cpp *.h"

// function declairations
int options(basketballPlayer player[]);
void opponentCalculator(int& oppsPossessions,int& oppsPoints);

int main()
{
  basketballPlayer player[5] = { // Calls out constructor and sets the values for out players
    basketballPlayer("Grace Harper", 0, 0, 0, 0), 
    basketballPlayer("Thomas Edison", 0, 0, 0, 0), 
    basketballPlayer("Sean William Scott", 0, 0, 0, 0),
    basketballPlayer("Tyler Perry", 0, 0, 0, 0),
    basketballPlayer("Eddie Murphy", 0, 0, 0, 0)};

  int myPossessions = 0; 
  int oppsPossessions = 0;
  int myPoints = 0;
  int oppsPoints = 0;
  bool possession={true};

  std::cout<<"Welcome to Carter's BasketBall Bananza:"<<std::endl;
  while(true) // main loop  
  {
    srand(time(0)); //seeding time for random
    if(oppsPossessions==30 || myPossessions==30) //Determining if number of possessions has been reached
    {
      std::cout<<std::endl<<"------GAME HAS FINISHED------"<<std::endl;
      if(oppsPoints<myPoints)
      {
        std::cout<<"YOU WIN!!!"<<std::endl;
      }
      else 
      {
        std::cout<<"YOU LOST!!!"<<std::endl;
      }
      std::cout<<"Your final score is: "<< myPoints;
      std::cout<<"\t Your oppenents final score is: " << oppsPoints << std::endl;
      break;
    }
    std::cout<<std::endl<<"Player with possession...";
    int currentPlayer = rand()%5; // Determines 0-4 which player has possession of the ball
    player[currentPlayer].playerStats(); // Display stats
    myPossessions++;
    possession = true; // If the same player keeps possession of the ball then possession is true
                       // due to how I wrote it theres no way of starting from certain points 
                       // if I wrote a function for some of the loops it could've solve this.
    while(possession)//Possession is retained by current player
    {
      int userDecision = options(player);
      if(userDecision == 1)
      {
        while(true)
        {
          int points = 0;
          std::cout<<"Enter the amount of points you want to shoot for (1-3): ";
          std::cin>>points;
          points = player[currentPlayer].TakeShot(points); // checks to see whats returned we know if 0 is returned we missed and -1 something is wrong
          if(points==0)
          {
            if(50<rand()%100+1)
            {
              std::cout<<"You shoot and miss but retain possession of the ball!"<<std::endl;
              possession=false; //possession is retained but no way of knowing who got the ball back, thats why we break to reinitialize the player who got the ball
              break;
            }
            else 
            {
              std::cout<<"You shoot and miss losing possession of the ball!"<<std::endl;
              opponentCalculator(oppsPossessions, oppsPoints);
              possession=false;
              break;
            }
          }
          else if(points == 1)
          {
            myPoints++;
            std::cout<<"You shoot and score 1 point!"<<std::endl;
            opponentCalculator(oppsPossessions, oppsPoints);
            possession=false;
            break;
          }
          else if(points == 2)
          {
            myPoints+=2;
            std::cout<<"You shoot and score 2 points!"<<std::endl;
            opponentCalculator(oppsPossessions, oppsPoints);
            possession=false;
            break;
          }
          else if(points == 3)
          {
            myPoints+=3;
            std::cout<<"You shoot and score 3 points!"<<std::endl;
            opponentCalculator(oppsPossessions, oppsPoints);
            possession=false;
            break;
          }
          else 
          {
            std::cout<<std::endl<<"Your selection was invalid";
            break;
          }
        }

      }
      else if(userDecision == 2) // should write into function 
      {
        int playerPass = 0;
        std::string passSelection[4];
        bool flag{false};
        for(int f=0;f<5;f++) // Used to make an array of every player except the one with possession
        {
          if(f==currentPlayer)
          {
            if(f==4)
            {
              break;
            }
            flag=true;
          }
          else
          {
            if(flag) 
            {
              passSelection[f-1] = player[f].playerNames();
            }
            else 
            {
              passSelection[f] = player[f].playerNames();
            }
          }
        }
        for(int k=0;k<4;k++)
        {
          std::cout<<"["<<k+1<<"] "<<passSelection[k];
          if(k<4)
          {
            std::cout<<", ";
          }
        }
        std::cout<<std::endl<<"Choose a player to pass the ball to (enter 1-4): ";
        std::cin>>playerPass;
        if(player[currentPlayer].PassBall()) // If the pass was successful
        {
          std::cout<<std::endl<<"Ball was successfully passed from "<<player[currentPlayer].playerNames()<<" to "<< passSelection[playerPass-1]<<"!"<<std::endl;
          for(int i=0;i<playerPass+1;i++) // Itterating though all values and setting the player with the ball to the selection
          {
            if(passSelection[playerPass-1] == player[i].playerNames())
            {
              currentPlayer = i;
              player[currentPlayer].playerStats();
              break; // possesion remains as true and when it breaks it will keep the player the ball was passed to 
            }
          }
        }
        else //failed the pass
        {
          std::cout<<std::endl<<"Pass was unsuccessful opponents now have possession!"<<std::endl;

          opponentCalculator(oppsPossessions, oppsPoints);
          possession=false;
        }

      }
      else if(userDecision == 3)
      {
        std::cout<<"You have scored "<<myPoints<<" points and have "<<30 - myPossessions<<" remaining possessions!"<<std::endl;
        std::cout<<"Your opponents have scored "<<oppsPoints<<" points and have "<<30 - oppsPossessions<<" remaining possessions!"<<std::endl;
        possession=true;
      }
    }
  }
  return 0;
}

/* Function: options
 *   Inputs: basketballPlayer player[5]
 *  Outputs: choice
 *
 *  This function prints 4 choices for 
 *  the user to select. Their choice is 
 *  then returned or prints the stats for 
 *  all players in the case of [4].
 */
int options(basketballPlayer player[5])
{
  int choice=0;
  std::cout<<std::endl<<"[1] shoot";
  std::cout<<", [2] pass";
  std::cout<<", [3] see current score and remaining possessions";
  std::cout<<", [4] see all Player's Stats"<<std::endl;
  std::cout<<"Type a number between 1 and 4 to make your selection: ";

  std::cin>>choice;
  if(choice==4) // printing all players stats
  {
    for(int i=0;i<5;i++)
    {
      player[i].playerStats();
    }
  }
  if(0 < choice && choice < 5)
  {
    return choice;
  }
  return -1; // error handling if we get like 7 obviously we cant handle 7, this is more neccissary when getting inputs used for arithmetic
}

/* Function: opponentCalculator
 *   Inputs: oppsPossessions, oppsPoints
 *  Outputs: void
 *
 *  This function itterates the possessions
 *  and the points for the opponents. It 
 *  also prints the values of the points 
 *  opponents have earned and their 
 *  current possession.
 */
void opponentCalculator(int& oppsPossessions,int& oppsPoints)
{
  bool possession=true;
  oppsPossessions++;
  std::cout<<std::endl;

  while(possession)
  {
    int typeShot = rand()%60+1; // 1/3 chance
    int shotMade = rand()%100+1; // 3/5 chance
    int possessionRetained = rand()%100+1; // 1/2 chance

    if(typeShot<20)
    {
      if(shotMade>40) //one point shot
      {
        oppsPoints+=1;
        std::cout<<"Your opponent shoots and scores 1 point!"<<std::endl;
        possession = false;
      }
      else 
      {
        if(possessionRetained<50)
        {
          std::cout<<"Your opponent misses and loses possession!"<<std::endl;
          possession = false;
        }
        else 
        {
          std::cout<<"Your opponent misses and retains possession!"<<std::endl;
          possession = true;
        }
      }
    }
    else if (typeShot<40)//two point shot
    {
      if(shotMade>40)
      {
        oppsPoints+=2;
        std::cout<<"Your opponent shoots and scores 2 points!"<<std::endl;
        possession = false;
      }
      else 
      {
        if(possessionRetained<50)
        {
          std::cout<<"Your opponent misses and loses possession!"<<std::endl;
          possession = false;
        }
        else 
        {
          std::cout<<"Your opponent misses and retains possession!"<<std::endl;
          possession = true;
        }
      }
    }
    else //three point shot
    {

      if(shotMade>40)
      {
        oppsPoints+=3;
        std::cout<<"Your opponent shoots and scores 3 points!"<<std::endl;
        possession=false;
      }
      else 
      {
        if(possessionRetained<50)
        {
          std::cout<<"Your opponent misses and loses possession!"<<std::endl;
          possession=false;
        }
        else 
        {
          std::cout<<"Your opponent misses and retains possession!"<<std::endl;
          possession=true;
        }
      }
    }
  }
}
