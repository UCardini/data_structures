#include <iostream>
#include <string>
//Used geeksforgeeks.org/rand-and-srand-in-ccpp/

class basketballPlayer
{
  private:
    std::string Name;
    int ShotsTaken;
    int ShotsMade;
    int PassesAttempted;
    int PassesMade;
  public:
    basketballPlayer(std::string Name, int ShotsTaken, int ShotsMade, int PassesAttempted, int PassesMade)
    {
      this->Name = Name;
      this->ShotsTaken = ShotsTaken;
      this->ShotsMade = ShotsMade;
      this->PassesAttempted = PassesAttempted;
      this->PassesMade = PassesMade;

    }; 

    std::string playerNames()
    {
      return Name;
    };
    void playerStats()
    {
      std::cout<<std::endl<<Name<<"'s Stats: "<<std::endl;
      std::cout<<"Shots Taken:\t  "<<ShotsTaken<<std::endl;
      std::cout<<"Shots Made:\t  "<<ShotsMade<<std::endl;
      std::cout<<"Passes Attempted: "<<PassesAttempted<<std::endl;
      std::cout<<"Passes Made:\t  "<<PassesMade<<std::endl;
    };
    bool PassBall()
    {
      int passChance = rand()%100 + 1;
      double passingPercentage = 100*static_cast<double>(PassesMade)/PassesAttempted;

      PassesAttempted++;
      if(PassesMade==0)
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
    int TakeShot(int points)
    {
      double shootingPercentage = 100*static_cast<double>(ShotsMade)/ShotsTaken; 

      int onePointerChance = rand()%70 + 1;
      int twoPointerChance = rand()%100 + 1;
      int threePointerChance = rand()%125 + 1;

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
};

int options(basketballPlayer player[5])
{
  int choice=0;
  std::cout<<std::endl<<"[1] shoot";
  std::cout<<", [2] pass";
  std::cout<<", [3] see current score and remaining possessions";
  std::cout<<", [4] see all Player's Stats"<<std::endl;
  std::cout<<"Type a number between 1 and 4 to make your selection: ";

  std::cin>>choice;
  if(choice==4)
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
  return -1;
}

void opponentCalculator(int& oppsPossessions,int& oppsPoints)
{
  bool possession=true;
  oppsPossessions++;
  std::cout<<std::endl;

  while(possession)
  {
    int typeShot = rand()%60+1;
    int shotMade = rand()%100+1;
    int possessionRetained = rand()%100+1;

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

int main()
{
  srand(time(0));
  basketballPlayer player[5] = {
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
  while(true) //posession is selected again
  {
    if(oppsPossessions==30 || myPossessions==30)
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
    int currentPlayer = rand()%5;
    player[currentPlayer].playerStats();
    myPossessions++;
    possession = true;
    

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
          points = player[currentPlayer].TakeShot(points);
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
      else if(userDecision == 2)
      {
        int playerPass = 0;
        std::string passSelection[4];
        bool flag{false};
        for(int f=0;f<5;f++)
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
        if(player[currentPlayer].PassBall())
        {
          std::cout<<std::endl<<"Ball was successfully passed from "<<player[currentPlayer].playerNames()<<" to "<< passSelection[playerPass-1]<<"!"<<std::endl;
          for(int i=0;i<playerPass+1;i++)
          {
            if(passSelection[playerPass-1] == player[i].playerNames())
            {
              currentPlayer = i;
              player[currentPlayer].playerStats();
              break;
            }
          }
        }
        else 
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
