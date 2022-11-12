#include"iostream"
#include"first-header.h"

using namespace std;
using namespace N;

int mybank::mainpage(){
    cout<<"Welcome to our Bank!"<<endl;
    int option=0;
    cout<<"Press 1 to register!"<<endl;
    cout<<"Press 2 to log in"<<endl;
    cout<<"Press 3 to exit"<<endl;
    cin>>option;
    if(option == 1){
        Register();
    }else if(option == 2){
        int status=login();
        if(status == 100){
            cout<<"Try Again!";
        }
        }else if (option == 3){
        cout<<"bye bye";
        return 0;}
    }

int mybank::Register(){
    cout<<"THIS IS FROM REGISTRATION!"<<endl;
    string username1;
    string password1;
    string confirmpass;
    int amount=0;
    cout<<"Enter your name :";
    cin>>username1;
    cout<<"Enter your password :";
    cin>>password1;
    cout<<"Enter your confirm password :";
    cin>>confirmpass;
    if(password1 == confirmpass){
        username[locate]= username1;
        userpassword[locate] =password1;
        cout<<"Registration success!"<<endl;
        cout<<"how much money do u want to save in our bank :";
        cin>>amount;
        useramount[locate] = amount;
        locate++;
        mainpage();
    }
}

int mybank::login(){
    cout<<"THIS IS FROM LOG-IN!\n";
    string lusername;
    string lpassword;
    cout<<"Enter your name to log in:";
    cin>>lusername;
    cout<<"Enter your password to login:";
    cin>>lpassword;
    for (int i=0; i<locate ; i++){
        if(lusername == username[i] && lpassword == userpassword[i]){
            cout<<"LOG IN SUCCESS!\n";
            currentID = i;
            exchange();
        }
    }if(state){
    return 100;}
}

int mybank::exchange(){
    int exoption=0;
    cout<<"Press 1 to transfer\n";
    cout<<"Press 2 to withdraw\n";
    cout<<"Press 3 to update\n";
    cout<<"Press 4 to exit\n";
    cout<<"Press 5 to see all info";
    cin>>exoption;
    if(exoption == 1){
        cout<<"THIS IS FROM TRANSFER!\n";
        string transname;
        int transamount;
        cout<<"Enter the name that u want to transfer:";
        cin>>transname;
        cout<<"Enter the amount that u want to transfer:";
        cin>>transamount;
        receiverID = checkingname(transname);
        if(receiverID >= 0){
            while(receiverID >= 0){
                if(transamount <= useramount[receiverID]){
                    transfer(currentID,receiverID,transamount);
                    exchange();
                    }else {
                    cout<<"INVALID AMOUNT";
                    break;
                    }
            }
        }
    }else if(exoption ==2){
        cout<<"THIS IS FROM WITHDRAW!"<<endl;
        withdraw();
        }else if(exoption ==3){
            cout<<"THIS IS FROM UPDATE";
            updatemoney();
        }else if(exoption == 4){
            return state=false;
        }else if(exoption == 5){
            allinfo();
            return state=false;}
}

int mybank::checkingname(string name){
        for (int i=0; i<locate ; i++){
            if(name == username[i]){
                return i;
            }else{
            cout<<"Doesn't exist!";
            return -1;}
        }
}

int mybank::transfer(int current,int receiver,int tranmoney){
    useramount[receiver]+=tranmoney;
    useramount[current]-=tranmoney;
    cout<<"TRANSFER IS DONE!"<<endl;
    cout<<username[current]<<" transfer to "<<username[receiver]<<tranmoney<<endl;
    cout<<"This is your money now :"<<useramount[current]<<endl;
}

int mybank::withdraw(){
    int withdrawmoney=0;
    cout<<"How much money do u want to withdraw:";
    cin>>withdrawmoney;
    if(withdrawmoney<=useramount[currentID]){
        useramount[currentID]-=withdrawmoney;
        cout<<"This is your money now:"<<useramount[currentID]<<endl;
    }else{
    cout<<"Invalid amount";}
    exchange();
}

int mybank::updatemoney(){
    int update=0;
    cout<<"How much money do u want to update:";
    cin>>update;
    useramount[currentID]+=update;
    cout<<"This is your money now :"<<useramount[currentID]<<endl;
    exchange();
}

int mybank::allinfo(){
for (int i=0; i<locate; i++){
    cout<<username[i]<<endl;
    cout<<userpassword[i]<<endl;
    cout<<useramount[i]<<endl;
}
}
