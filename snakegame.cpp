#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

const int height=20;
const int width=20;
int x,y,fruitsX,fruitsY;
bool gameover;
enum eDirection{stop=0,left1,right1,up1,down1};
eDirection dir;
int score=0;
int tailX[20],tailY[20];
int nTail=0;

void setup(){
    gameover=false;
    x= width/2;
    y= height/2;
    fruitsX= rand()%width;
    fruitsY= rand()%height;
}
void draw(){
    system("cls");
    for (int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
         if(j == 0)
            {cout <<"#";}
        if(i== x && j==y)
            {cout<<"0";}
         else if(i==fruitsX && j==fruitsY)
            {cout <<"f";}
         else
            {bool print=false;
            for(int k=0;k<nTail;k++)
                {
                    if(tailX[k] == i && tailY[k] == j)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                cout<<" ";
            }
         if(j == height-1)
            {cout << "#";}
        }
        cout<<endl;
    }
    for (int i=0;i<width+2;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<< "Score"<<score;
}

void logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for (int i=1;i<nTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;

    }
    switch (dir){
    case left1: y--;
            break;
    case right1: y++;
            break;
    case up1: x--;
            break;
    case down1: x++;
            break;
    default: break;}
    if(x>width || x<0 || y>height || y<0){
        gameover=true;
    }
    if(x == fruitsX && y == fruitsY){
        score+=10;
        fruitsX= rand()%2;
        fruitsY= rand()%2;
        nTail++;
    }
}
void input(){
    if(_kbhit()){
    switch(_getch()){
        case 'a': dir = left1;
                break;
        case 'd': dir = right1;
                break;
        case 'w': dir = up1;
                break;
        case 's': dir =down1;
                break;
        case 'x': gameover=true;
                break;}
    }
}

int main(){
    setup();
    while(!gameover){
        draw();
        logic();
        Sleep(150);
        input();

    }
return 0;}
