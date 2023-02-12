#include <iostream>

using namespace std;
class Game
{
public:
    explicit Game(int numberOfPlayer)
    : numberOfPlayer(numberOfPlayer) {}

    void run()//template method
    {
       start();
       while(!haveWinner())
           takeTurn();
       cout<<"player "<< getWinner() <<"wins\n";
    }
    virtual void start()=0;
    virtual void takeTurn() =0;
    virtual bool haveWinner() =0;
    virtual int getWinner()=0;

protected:
    int currentPlayer{0};
    int numberOfPlayer;
};

class Chess : public Game
{
public:
    explicit Chess() : Game(2) {}

protected:
    void start()
    {
        cout<< "start chess game with "<< numberOfPlayer <<"player's\n";
    }
    bool haveWinner()
    {
        return turns == maxTurns;
    }

    void takeTurn()
    {
        cout<< "Turn "<< turns<< "taken by player "<< currentPlayer<<endl;
        turns++;
        currentPlayer = (currentPlayer+1) % numberOfPlayer;
    }

    int getWinner() override
    {
        return currentPlayer;
    }
private:
    int turns{0},maxTurns{10};
};

int main() {

    Chess chess;
    chess.run();
    return 0;
}
