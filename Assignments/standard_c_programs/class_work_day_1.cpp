#include <iostream>
using namespace std;

class robotMotion {
    private:
        int speed = 0;
    public:
        void moveForward(){
            cout << "Moving forward";
        }
        void moveBackward(){
            cout << "Moving backward";
        }
        void moveRight(){
            cout << "Moving Right";
        }
        void moveLeft(){
            cout << "Moving Left";
        }
        int velocity(){
            return speed;
        }
        void setSpeed(float vel){
            speed = vel;
        }
};


char dir;
bool breakFlag = false;
float speed;
int main(){
    robotMotion r;
    while(true){
        cout << "Enter the direction you want to go(F,B,R,L):";
        cin >> dir;
        cout << "Enter the speed at which it should travele in:";
        cin >> speed;
        r.setSpeed(speed);
        switch(dir){
            case 'F':
                r.moveForward();
                break;
            case 'B':
                r.moveBackward();
                break;
            case 'R':
                r.moveRight();
                break;
            case 'L':
                r.moveLeft();
                break;
            case 'E':
                breakFlag = true;
                break;
            default:
                cout << "Enter valid direction";
        }
        cout << ".The velocity is "<< r.velocity()<<endl;
        if(breakFlag == true){
            break;
        }
    }
    return 0;
}