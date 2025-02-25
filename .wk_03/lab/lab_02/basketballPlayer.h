#include <string>

// class definition file

class basketballPlayer
{
private:
    std::string Name;
    int ShotsTaken;
    int ShotsMade;
    int PassesAttempted;
    int PassesMade;

public:
    basketballPlayer( std::string, int, int, int, int );
    void playerStats();
    bool PassBall();
    int TakeShot( int points );
    std::string playerNames()
    {
        return Name;
    }; // This is used to return the player names
};
