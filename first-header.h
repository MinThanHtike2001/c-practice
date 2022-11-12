#ifndef FIRST-HEADER_H_INCLUDED
#define FIRST-HEADER_H_INCLUDED

namespace N{
    class mybank{
    public :
    bool state=true;
    int locate=0;
    int currentID=0;
    int receiverID=0;
    std::string username[100];
    std::string userpassword[100];
    int useramount[100];
    int Register();
    int login();
    int mainpage();
    int checkingname(std::string name);
    int allinfo();
    int exchange();
    int transfer(int current,int receiver,int tranmoney);
    int withdraw();
    int updatemoney();
    };
}


#endif // FIRST-HEADER_H_INCLUDED
