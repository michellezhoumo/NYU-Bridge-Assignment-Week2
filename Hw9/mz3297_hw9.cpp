#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
const int SIZE = 20;
const int INITIALANT = 100;
const int INITIALDBUG = 5;
const int MAXSTARVECOUNT = 3;
const int MAXSURVIVALCOUNTDBUG = 8;
const int MAXSURVIVALCOUNTANT = 3;

//Class Ant and DoodleBug inherit from Organism
class Organism;
class Ant;
class DoodleBug;
class Game;

int generateRandInt();
char randDirGenerator();
//Predator-Prey Interface:

class Game{
public:
    Game();
    ~Game();
    void renderGame();
    void setOrgToBoard(int x, int y, Organism* critter);
    Organism* getOrgFromBoard(int x, int y);
    void initializeBoard();
    void killDeadBug();
    void eachTurnInGame();
    void resetMoved();
    Organism* gameBoard[SIZE][SIZE];
    //initialize the gameboard (2D array of organism pointers)
};
class Organism{
protected:
    Game* currGame;
    int x,y;
    bool moved = false;
private:
    char label = 'E';
    bool died = false;
    //Protected member specifying organism's
    // 1. The game this turn
    // 2. Coordinate in grid
    // 3. Organism label -> use set method to give derived class object label
    // 4. Organism moved -> use set method to track bool value of whether the derived class object has moved

public:
    Organism();
    //Default constructor
    virtual ~Organism();
    //Destructor -> Set to virtual because the compiler needs to know which derived class destructor to use
    //when deleting an Organism pointer.
    char getLabel() const {return label;};
    bool getMoved() const {return moved;};
    void setMoved(int movedNewTurn){moved = movedNewTurn;};
    void setLabel(char orgLabel);
    void setDied(bool hasDied);
    bool getDied() const;
    //Overridden in derived classes for specific label
    virtual void move() = 0;
    //pre-condition: current critter location (x1, y1) and dir of movement
    //post-condition: critter location changes to (x2,y2) adjacent to x1, y2 after moving in dir of motion
    //Overridden in derived classes for specific label
    virtual void breed() = 0;
    //pre-condition: current critter location (x1, y1) and dir of movement
    //post-condition: create new critter at location (x2,y2) adjacent to x1,y1 after moving in dir of motion
    //Overridden in derived classes for specific label
};

void Organism:: setLabel(char orgLabel){
    label = orgLabel;
}

Organism::Organism(){
    currGame = nullptr;
    x = 0;
    y = 0;
}

Organism::~Organism()= default;

//Initialize the empty gameBoard
Game::Game(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            gameBoard[i][j] = nullptr;
        }
    }
    cout << endl;
}
//Destory gameboard to release memory
Game::~Game(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(gameBoard[i][j] != nullptr) {
                delete gameBoard[i][j];
            }
        }
        cout << "Game Destructor Called" << endl;
    }
}

void Game::renderGame(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(gameBoard[i][j] == nullptr) {
                cout << "- ";
            }
            else{
                if(gameBoard[i][j] ->getLabel() == 'A')
                    cout << "o ";
                else if(gameBoard[i][j] ->getLabel() == 'D')
                    cout << "X ";
            }
        }
        cout << endl;
    }
}

//new_x and new_y are the specify the new location to move critter to;
void Game:: setOrgToBoard(int new_x, int new_y, Organism* critter){
    if((new_x >= 0 && new_x < SIZE) && (new_y >= 0 &&  new_y < SIZE))
        //shallow copy, need to create a copy of the object via copy constructor?
        gameBoard[new_x][new_y] = critter;
}
Organism* Game:: getOrgFromBoard(int x, int y){
    if((x >= 0 && x < SIZE) && (y >= 0 &&  y< SIZE))
        return gameBoard[x][y];
    else
        return nullptr;
}

void Game:: eachTurnInGame(){
    //DoodleBug moves
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameBoard[i][j] != nullptr && gameBoard[i][j]->getLabel() == 'D')
                gameBoard[i][j]->move();
        }
    }
    //Ant moves
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameBoard[i][j] != nullptr && gameBoard[i][j]->getLabel() == 'A')
                gameBoard[i][j]->move();
        }
    }
    //DoodleBug breed
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameBoard[i][j] != nullptr && gameBoard[i][j]->getLabel() == 'D')
                gameBoard[i][j]->breed();
        }
    }
    //Kill DoodleBugs that starved
    killDeadBug();
    //Ant breed

    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameBoard[i][j] != nullptr && gameBoard[i][j]->getLabel() == 'A')
                gameBoard[i][j]->breed();
        }
    }

    //Reset moved to false for all organism on board for the next round
    resetMoved();
}

void Game::resetMoved(){
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameBoard[i][j] != nullptr && gameBoard[i][j]->getMoved() == true)
                gameBoard[i][j]->setMoved(false);
        }
    }
}

class Ant : public Organism{
    int antSurvivalCount = 0;
public:
    Ant();
    Ant(Game* newGame, int x_ant, int y_ant);
    ~Ant();
    //char getLabel(){return orgLabel;};
    virtual void move();
    virtual void breed();
};

void Ant:: move(){
    char dir = randDirGenerator();
    if(moved == false) {
        //cout << dir << endl;
        if (dir == 'l' && y >= 1 && currGame->getOrgFromBoard(x, y - 1) == nullptr) {
            currGame->setOrgToBoard(x, y - 1, this);
            currGame->setOrgToBoard(x, y, nullptr);
            y--; //alter the current coordinate one to the left -> Update ant's curr coordinate
        } else if (dir == 'r' && y < SIZE - 1 && currGame->getOrgFromBoard(x, y + 1) == nullptr) {
            currGame->setOrgToBoard(x, y + 1, this);
            currGame->setOrgToBoard(x, y, nullptr);
            y++;//alter the current coordinate one to the right -> Update ant's curr coordinate
        } else if (dir == 'u' && x >= 1 && currGame->getOrgFromBoard(x - 1, y) == nullptr) {
            currGame->setOrgToBoard(x - 1, y, this);
            currGame->setOrgToBoard(x, y, nullptr);
            x--;//alter the current coordinate one up -> Update ant's curr coordinate
        } else if (dir == 'd' && x < SIZE - 1 && currGame->getOrgFromBoard(x + 1, y) == nullptr) {
            currGame->setOrgToBoard(x + 1, y, this);
            currGame->setOrgToBoard(x, y, nullptr);
            x++;//alter the current coordinate one down -> Update ant's curr coordinate
        }
        moved = true;
    }
}

void Ant:: breed(){
    antSurvivalCount++;
    if(antSurvivalCount == MAXSURVIVALCOUNTANT) {
        if (y >= 1 && currGame->getOrgFromBoard(x, y - 1) == nullptr) {
            Ant *ant = new Ant(currGame, x, y - 1);
            currGame->gameBoard[x][y - 1] = ant;
        } else if (y < SIZE - 1 && currGame->getOrgFromBoard(x, y + 1) == nullptr) {
            Ant *ant = new Ant(currGame, x, y + 1);
            currGame->gameBoard[x][y + 1] = ant;
        } else if (x >= 1 && currGame->getOrgFromBoard(x - 1, y) == nullptr) {
            Ant *ant = new Ant(currGame, x - 1, y);
            currGame->gameBoard[x - 1][y] = ant;
        } else if (x < SIZE - 1 && currGame->getOrgFromBoard(x + 1, y) == nullptr) {
            Ant *ant = new Ant(currGame, x + 1, y);
            currGame->gameBoard[x + 1][y] = ant;
        }
        antSurvivalCount = 0;
    }
}

class DoodleBug : public Organism{
    int dBugSurvivalCount = 0;
    int starveCount = 0;
public:
    DoodleBug();
    DoodleBug(Game* newGame, int x_dBug, int y_dBug);
    ~DoodleBug();
    //char getLabel(){return orgLabel;};
    virtual void move();
    virtual void breed();
};

Ant:: Ant(Game* newGame, int x_ant, int y_ant):Organism(){
    setLabel('A');
    currGame = newGame;
    x = x_ant;
    y = y_ant;
}//Organism default constructor automatically called
Ant:: ~Ant(){};
DoodleBug:: DoodleBug(Game* newGame, int x_dBug, int y_dBug):Organism(){
    setLabel('D');
    currGame = newGame;
    x= x_dBug;
    y= y_dBug;
}//Organism default constructor automatically called
DoodleBug:: ~DoodleBug(){cout << "DoodleBug Destructor Called" << endl;};

void DoodleBug:: move(){
    if(moved == false) {
        if (y >= 1 && currGame->getOrgFromBoard(x, y - 1) != nullptr &&
            currGame->getOrgFromBoard(x, y - 1)->getLabel() == 'A') {
            starveCount = 0;
            delete currGame->gameBoard[x][y - 1];  //Delete the pointer value: Ant object -> eaten
            currGame->gameBoard[x][y - 1] = this;
            currGame->setOrgToBoard(x, y, nullptr);
            moved = true;
            y--;
        } else if (y < SIZE - 1 && currGame->getOrgFromBoard(x, y + 1) != nullptr &&
                   currGame->getOrgFromBoard(x, y + 1)->getLabel() == 'A') {
            starveCount = 0;
            delete currGame->gameBoard[x][y + 1];  //Delete the pointer value: Ant object -> eaten
            currGame->setOrgToBoard(x, y + 1, this);
            currGame->setOrgToBoard(x, y, nullptr);
            moved = true;
            y++;
        } else if (x >= 1 && currGame->getOrgFromBoard(x - 1, y) != nullptr &&
                   currGame->getOrgFromBoard(x - 1, y)->getLabel() == 'A') {
            starveCount = 0;
            delete currGame->gameBoard[x - 1][y];  //Delete the pointer value: Ant object -> eaten
            currGame->setOrgToBoard(x - 1, y, this);
            currGame->setOrgToBoard(x, y, nullptr);
            moved = true;
            x--;
        } else if (x < SIZE - 1 && currGame->getOrgFromBoard(x + 1, y) != nullptr &&
                   currGame->getOrgFromBoard(x + 1, y)->getLabel() == 'A') {
            starveCount = 0;
            delete currGame->gameBoard[x + 1][y];  //Delete the pointer value: Ant object -> eaten
            currGame->setOrgToBoard(x + 1, y, this);
            currGame->setOrgToBoard(x, y, nullptr);
            moved = true;
            x++;
        } else {
            //calling the move function from Ant class? can I accomplish this by not copying the code?
            starveCount++;
            char dir = randDirGenerator();
            //cout << dir << endl;
            if (dir == 'l' && y >= 1 && currGame->getOrgFromBoard(x, y - 1) == nullptr) {
                currGame->setOrgToBoard(x, y - 1, this);
                currGame->setOrgToBoard(x, y, nullptr);
                y--; //alter the current coordinate one to the left -> Update ant's curr coordinate
            } else if (dir == 'r' && y < SIZE - 1 && currGame->getOrgFromBoard(x, y + 1) == nullptr) {
                currGame->setOrgToBoard(x, y + 1, this);
                currGame->setOrgToBoard(x, y, nullptr);
                y++;//alter the current coordinate one to the right -> Update ant's curr coordinate
            } else if (dir == 'u' && x >= 1 && currGame->getOrgFromBoard(x - 1, y) == nullptr) {
                currGame->setOrgToBoard(x - 1, y, this);
                currGame->setOrgToBoard(x, y, nullptr);
                x--;//alter the current coordinate one up -> Update ant's curr coordinate
            } else if (dir == 'd' && x < SIZE - 1 && currGame->getOrgFromBoard(x + 1, y) == nullptr) {
                currGame->setOrgToBoard(x + 1, y, this);
                currGame->setOrgToBoard(x, y, nullptr);
                x++;//alter the current coordinate one down -> Update ant's curr coordinate
            }
            moved = true;
        }
    }

}

void Organism:: setDied(bool hasDied){
    died = hasDied;
}
bool Organism:: getDied() const{
    return died;
}

void Game::killDeadBug() {
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gameBoard[i][j] != nullptr && gameBoard[i][j]->getLabel() == 'D' && gameBoard[i][j]->getDied() == true){
                    //DoodleBug dies delete the doodlebug and set the pointer to null;
                    //delete gameBoard[i][j];
                    gameBoard[i][j] = nullptr;
            }
        }
    }
}

void DoodleBug:: breed(){
    if(starveCount == MAXSTARVECOUNT) {
        //DoodleBug dies delete the doodlebug and set the pointer to null;
        setDied(true);
    }
        //if current Doodlebug didn't die this turn, it survived another turn
    dBugSurvivalCount++;
    if(dBugSurvivalCount == MAXSURVIVALCOUNTDBUG && getDied() == false) {
        if (y >= 1 && currGame->getOrgFromBoard(x, y - 1) == nullptr) {
            DoodleBug *dBug = new DoodleBug(currGame, x, y - 1);
            currGame->gameBoard[x][y - 1] = dBug;
        } else if (y < SIZE - 1 && currGame->getOrgFromBoard(x, y + 1) == nullptr) {
            DoodleBug *dBug = new DoodleBug(currGame, x, y + 1);
            currGame->gameBoard[x][y - 1] = dBug;
        } else if (x >= 1 && currGame->getOrgFromBoard(x - 1, y) == nullptr) {
            DoodleBug *dBug = new DoodleBug(currGame, x - 1, y);
            currGame->gameBoard[x][y - 1] = dBug;
        } else if (x < SIZE - 1 && currGame->getOrgFromBoard(x + 1, y) == nullptr) {
            DoodleBug *dBug = new DoodleBug(currGame, x + 1, y);
            currGame->gameBoard[x][y - 1] = dBug;
        }
        dBugSurvivalCount = 0;
    }
}

void Game:: initializeBoard(){
    int countAnt = 0;
    int countDbug = 0;

    //srand(time(NULL)); //why can't I seed in generateRandInt()?

    while(countAnt < INITIALANT){
        int x_loc, y_loc;
        x_loc = generateRandInt();
        y_loc = generateRandInt();
        if(gameBoard[x_loc][y_loc] == nullptr) {
            Ant* antPtr = new Ant(this,x_loc, y_loc);
            setOrgToBoard(x_loc, y_loc, antPtr);
            countAnt++;
        }
    }

    while(countDbug < INITIALDBUG){
        int x_loc, y_loc;
        x_loc = generateRandInt();
        y_loc = generateRandInt();
        if(gameBoard[x_loc][y_loc] == nullptr) {
            DoodleBug* dbugPtr = new DoodleBug(this, x_loc, y_loc);
            setOrgToBoard(x_loc, y_loc, dbugPtr);
            countDbug++;
        }
    }
}

int generateRandInt(){
    int m = rand() % SIZE;
    return m;
}

char randDirGenerator(){
    int m = rand()%4;
    char dir = "udlr"[m];
    return dir;
}

int main() {
    srand(time(NULL));

    char initialBoard;
    cout << endl << "Initial Game Board:" << endl;
    Game newGame;
    //Render the initial gameboard;
    newGame.initializeBoard();
    newGame.renderGame();
    //cout << newGame.getOrgFromBoard(3,9)->getLabel() << endl;

    cout << endl << "Press enter Key to see the the next turn, 's' to stop: ";

    while(cin.get() == '\n'){
        newGame.eachTurnInGame();
        cout << endl;
        newGame.renderGame();
    }

    cout << "You have reached the end state of ecosystem.";

    //newGame.getOrgFromBoard(3,9)->move();
    //test move function
    return 0;
}