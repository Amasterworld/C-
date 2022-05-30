// for learning propose about OOP only

#include<iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
using namespace std;

enum eDir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};


class cBall{

private:
    int x, y;
    int originalX, originalY;
    eDir direction;
public:
    // constructor , you also can use initilizer list if you want  : originalX(posX), originalX(posY)
    cBall(int posX, int posY){

        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        direction = STOP;
    }

    void bReset(){

        x = originalX;
        y = originalY;
        direction = STOP;
    }

    void changeDirection(eDir d){
        direction = d;
    }
    void randomDirection(){

        direction = (eDir)((rand() %6) + 1); //  because rand() gives a random number that measn it can be 0 6 12% 6 = 0, 0 is STOP hence +1 to avoid this problem
    }

    inline int getX() {return x; } // useless inline here except for implicit, because function on a class always is inline
    inline int getY() {return y; }  // useless inline here except for implicit, because function on a class always is inline
    inline eDir getDirection(){return direction; }  // useless inline here except for implicit, because function on a class always is inline


    void Move(); // remember to declare the function: if the function needs argument, so most impotant thing is these type of data not var for example Move(int, int) insert operator, ostream& operator<< (ostream& os, char c); -> Inserts the character c into os.
    // ostream& operator<< (ostream& os, const char* s); ->Inserts the C-string s into os.
    // in this case we want to insert c to o
    friend ostream& operator<< (ostream & o, cBall c){ // friend to access private or protected  members
        o <<"Ball [" <<c.x<< "," <<c.y<<"][" <<c.direction <<"]";
        return o;


    }
};

void cBall::Move(){

    switch(direction){

        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UPLEFT:
            x--; y--;
            break;
        case DOWNLEFT:
            x--;y++;
            break;
        case DOWNRIGHT:
            x++;y++;
            break;
        case UPRIGHT:
            x++;y--;
            break;
        default:
            break;
        
    }
}

// to intilize the players
class cPaddle{

private:
    int x, y;
    int originalX, originalY;

public:
    //default constructor

    cPaddle(){

        x = y = 0;
    }

    // constructor with  parameters 
    cPaddle(int posX, int posY): cPaddle() { //delegating to the default constructor :

        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    }


    void Reset(){

        x = originalX;
        y = originalY;
       
    }

    int getX() {return x;}
    int getY() {return y;}
    // the players only can move up or down hecen
    void moveUp() {y--;}
    void moveDown() {y++;}
    
     friend ostream& operator<< (ostream & o, cPaddle c){ // friend to access private or protected  members
        o <<"Paddle [" <<c.x<< "," <<c.y<<"]";
        return o;


    }

};
//  to control ball and players
class eGameManager{

private:
    int width, height; // if const int width, height hence should use Initializer  list
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall* ball;
    cPaddle* player1;
    cPaddle* player2;
public:
//constructor, always in public.
    eGameManager(int w, int h): width(w), height(h){ // width  and height are not const so we can assign them in the body function,

        srand(time(NULL));
        quit = false;
        up1 = 'w'; up2 = 'i'; 
        down1 = 's'; down2 = 'k';
        score1 = 0;
        score2 = 0;
        // dynamic memory allocation, should delete them late in the destructor
        ball = new cBall (w/2, h/2);
        player1 = new cPaddle(1, (h/2 - 3));
        player2 = new cPaddle(w-2, (h/2 - 3));

    }
    // destructor
    ~eGameManager(){
       cout<<" destructor is called "<< endl;
        delete ball;
        delete player1;
        delete player2;

    }
    // pass by pointer
    void scoreUp(cPaddle *player){
        if (player == player1){
            score1++;
        }
        else if (player == player2){
            score2++;
        }
        //after getting the point, the both players need to be reseted to the 1st position
        ball->bReset();
        player1->Reset();
        player2->Reset();
    }

    void draw(){

        system("cls");
        //top
        for (int i = 0; i < width+1; ++i){
            cout<<"\xB2";
        }
        cout<<endl;

        //between top and bottom
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){

                if (j == 0){
                    cout<<"\xB2";
                }

                if (ball->getX() == j && ball->getY() == i){
                    cout<<"O"; // draw a ball 
                }
                else if (player1->getX() == j && player1->getY() == i){
                    cout<<"\xDB"; // player 1
                }
                // but we want to make player 1 a bit longer, that means   cout<<"\xDB" in the below cell hence,  player1->getY() + 1 == i 

                else if (player1->getX() == j && player1->getY() + 1 == i){
                    cout<<"\xDB"; // player 1
                }
                else if (player1->getX() == j && player1->getY() + 2 == i){
                    cout<<"\xDB"; // player 1
                }
                else if (player2->getX() == j && player2->getY() == i){
                    cout<<"\xDB"; // player 2
                }
                else if (player2->getX() == j && player2->getY() + 1 == i){
                    cout<<"\xDB"; // player 2
                }
                else if (player2->getX() == j && player2->getY() + 2 == i){
                    cout<<"\xDB"; // player 2
                }
                else{
                    cout<<" ";
                }
                if (j == width - 1){
                    cout<<"\xB2";
                }

            }
            cout<<endl;
        }

        //bottom
        for (int i = 0; i < width+2; ++i){
            cout<<"\xB2";
        }
        cout<<endl;
        cout<<"Score1: "<<score1<<endl;
        cout<<"Score2: "<<score2<<endl;
        cout<<"direction of the ball: "<<ball->getDirection()<<endl;
    }

    void input(){
        
        ball->Move();
        //if the keyboard is hit
        if (_kbhit()){

            char current_char = _getch(); // get the current char is pressed
            if (current_char == up1){ // press w then player1 should move up, it it is possible
                if (player1->getY() > 0){
                    player1->moveUp(); // the y of object, namely, player1, is --
                }  
            }
            if (current_char == down1){
                if (player1->getY() + 3 < height){
                    player1->moveDown(); // the y of object, namely, player1, is --
                }
            }
            if (current_char == down2){
                if (player2->getY() + 3 < height){
                    player2->moveDown(); // the y of object, namely, player1, is --
                }
            }

            if (current_char == up2){
                if (player2->getY() > 0){
                    player2->moveUp(); // the y of object, namely, player1, is --
                }
            }   

            // if the ball is STOP then if we press anykey BALL should move
            if(ball->getDirection() == STOP){
                ball->randomDirection();
                
            }
            // press q to quit the game
            
            if (current_char == 'q'){
                quit = true;
            }

        }

    }

    void logic(){

        // check whether the ball colide with the left paddle
        for (int i = 0; i < 3; ++i ){ // 3 because the length of the paddle is 3
            // check whether the ball collides with the paddler
            if (ball->getX() == player1->getX() + 1 ){
                if (ball->getY() == player1->getY() + i){
                    ball->changeDirection((eDir) ((rand()%3) + 4)); // we can easily se that the changeDirection is not really good, to be better we should calculate the angular when the ball collides with players
                }
            }

        }



        // check whether the ball colide with the right paddle
        for (int i = 0; i < 3; ++i ){ // 3 because the length of the paddle is 3
            // check whether the ball collides with the paddler
            if (ball->getX() == player2->getX() - 1){
                if (ball->getY() == player2->getY() + i){
                    ball->changeDirection((eDir) ((rand()%3) + 1)); // we can easily se that the changeDirection is not really good, to be better we should calculate the angular when the ball collides with players
                }
            }

        }
        
        // if the ball collides with the bottom hence if it moves from downright after colliding the ball will be upright and if moving from downleft, will be upleft

        if (ball->getY() == height - 1){
            ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT); 

        }

        // if the ball collides with the top 

        if (ball->getY() == 1){
            ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT); 

        }
        // check who get the score

        if (ball->getX() == width - 1){
            scoreUp(player1);
        }
        if (ball->getX() == 0){
            scoreUp(player2);
        }

    }
    void run(){ 
        
        while (!quit){

            draw();
            Sleep(60);
            input();
            logic();
        }
    }
};
int main(){
    eGameManager c(40,20);
   //c.draw();
    c.run();
    
    return 0;
}



