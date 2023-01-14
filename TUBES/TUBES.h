#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define email(P) (P)->email

typedef struct elemenUser *adrUser;
typedef struct User infoUser;

typedef struct elemenEmail *adrEmail;
typedef struct Email infoEmail;

struct User{
    string name;
    string username;
    string tanggalLahir;
    string domisili;
};

struct Email{
    string email;
};

struct elemenUser{
    infoUser info;
    adrUser next;
    adrUser prev;
};

struct elemenEmail{
    infoEmail info;
    adrEmail next;
    adrUser email;

};


//L1 Single Linked List
struct ListEmail{
    adrEmail First;
};

//L2 Double Cirular Linked List
struct ListUser{
    adrUser First;
    adrUser Last;
};


void addUser(ListUser &LU, adrUser U);
void createListUser(ListUser &LU);
void createListEmail(ListEmail &LE);
adrUser createUser(infoUser X);
adrEmail createEmail(infoEmail Y);
void showUser(ListUser &LU, ListEmail &LE, string user );
void deleteUser(ListUser &LU, ListEmail &LE, string username);
adrUser findUser(ListUser &LU, string username);
void addEmail(ListEmail &LE, ListUser &LU, adrUser U, adrEmail E);
void deleteEmail(ListEmail &LE, ListUser &LU,adrEmail E);
void showEmail(ListUser &LU, ListEmail &LE, string username);
adrEmail findEmail(ListEmail &LE, string email);
void connectUser(adrEmail E, adrUser U);
void disconnectUser(adrEmail E); // email tetap ada, rrlasinya saja yang dihapus
void showMost(ListUser &LU, ListEmail &LE);
void searchUser(ListEmail &LE, string email);

#endif // FLIGHT_H_INCLUDED
