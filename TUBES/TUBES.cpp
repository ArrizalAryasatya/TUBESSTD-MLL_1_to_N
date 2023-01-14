#include "TUBES.h"

void addUser(ListUser &LU, adrUser U){ // Marcel
    adrUser Q;
    if(First(LU) == NULL){
        First(LU) = U;
        Last(LU) = U;
        next(U) = First(LU);
        prev(U) = Last(LU);
    } else {
        Q = First(LU);
        while (next(Q) != First(LU)){
            Q = next(Q);
        }
        next(Q) = U;
        prev(U) = Q;
        next(U) = First(LU);
        prev(First(LU)) = U;
        Last(LU) = U;
    }
}

void createListUser(ListUser &LU){
    First(LU) = NULL;
    Last(LU) = NULL;

}

void createListEmail(ListEmail &LE){
    First(LE) = NULL;

}

adrUser createUser(infoUser X){ //Marcel
    adrUser U;
    U = new elemenUser;
    info(U) = X;
    next(U) = NULL;
    prev(U) = NULL;

    return U;
}

adrEmail createEmail(infoEmail Y){
    adrEmail E;
    E = new elemenEmail;
    info(E) = Y;
    next(E) = NULL;

    return E;
}

void showUser(ListUser &LU, ListEmail &LE, string username ){
    adrUser U;
    U = findUser(LU, username);
    if(U != NULL){
        cout << "===== DATA USER =====" << endl;
        cout << "Nama : ";
        cout << info(U).name << endl;
        cout << "Username : ";
        cout << info(U).username << endl;
        cout << "TTL : ";
        cout << info(U).tanggalLahir << endl;
        cout << "Domisili : ";
        cout << info(U).domisili << endl;
    }
}

void deleteUser(ListUser &LU, ListEmail &LE, string username){ //marcel
    adrUser prec;
    adrUser U;
    adrEmail E;

    E = First(LE);
    while (E != NULL){
        if (info(email(E)).username == username){
            deleteEmail(LE,LU,E);
        }
        E = next(E);
    }
    cout << "User berhasil dihapus" << endl;

    U = findUser(LU,username);
    if (U != NULL){
        if (U == First(LU)){
            First(LU) = next(U);
            prev(First(LU)) = Last(LU);
            next(Last(LU)) = First(LU);
            next(U) = NULL;
            prev(U) = NULL;
        } else if (U == Last(LU)){
            Last(LU) = prev(U);
            next(Last(LU)) = First(LU);
            prev(First(LU)) = Last(LU);
            next(U) = NULL;
            prev(U) = NULL;
        } else {
            prec = prev(U);
            next(prec) = next(U);
            prev(next(U)) = prec;
            next(U) = NULL;
            prev(U) = NULL;
        }
    }
}

adrUser findUser(ListUser &LU, string username){
    adrUser U;
    U = First(LU);

    while(next(U) != First(LU) && info(U).username != username){
        U = next(U);
    }

    return U;
}

void addEmail(ListEmail &LE, ListUser &LU, adrUser U, adrEmail E){ // marcel
    adrEmail Q;
    if(U != NULL){          //Jika user dutemukan (U != NULL), maka email akan ditambahkan ke dalam list
        if(First(LE) == NULL){
            First(LE) = E;
        } else {
            Q = First(LE);
            while(next(Q) != NULL){
                Q = next(Q);
            }
            next(Q) = E;
        }
        connectUser(E,U);
    } else {
        cout << "User tidak ditemukan" << endl;
    }
}

void deleteEmail(ListEmail &LE, ListUser &LU, adrEmail E){
    adrEmail Q,prec;

    if (E != NULL){
        disconnectUser(E);
        if (E == First(LE)){
            First(LE) = next(E);
            next(E) == NULL;
        } else if (next(E) == NULL){
            Q = First(LE);
            while(next(next(Q)) != NULL){
                Q = next(Q);
            }
            next(Q) = NULL;
        } else {
            Q = First(LE);
            while(next(Q) != E){
                Q = next(Q);
            }
            prec = Q;
            next(prec) = next(E);
            next(E) = NULL;
        }
    }
}
void showEmail(ListUser &LU, ListEmail &LE, string username){
    adrEmail E;
    adrUser U;
    U = findUser(LU,username);
    E = First(LE);

    if (U != NULL){
    cout << "Daftar Email dari " << username << ":" << endl;
        while (E != NULL){
            if (info(email(E)).username == username){
                cout << info(E).email << endl;
            }
            E = next(E);
        }
    }

} // marcel

adrEmail findEmail(ListEmail &LE, string email){
    adrEmail E;

    E = First(LE);
    while(E != NULL &&  info(E).email != email){
        E = next(E);
    }

    return E;
}

void connectUser(adrEmail E, adrUser U){
    if(E != NULL){
        email(E) = U;
    } else {
        cout << "Email tidak ditemukan" << endl;
    }
}//marcel

void disconnectUser(adrEmail E){
    if(E != NULL){
        email(E) = NULL;
    } else {
        cout << "Email tidak ditemukan" << endl;
    }
}

void showMost(ListUser &LU, ListEmail &LE){
    adrUser U, maksUser;
    adrEmail E;
    int jumlah_email, maks;

    maks = 0;
    maksUser = First(LU);

    U = First(LU);
    while(next(U) != First(LU)){
        jumlah_email = 0;
        E = First(LE);
        while(E != NULL){
            if (info(email(E)).username == info(U).username){
                jumlah_email++;
            }
            E = next(E);
        }
        if (jumlah_email > maks){
            maksUser = U;
            maks = jumlah_email;
        }
        U = next(U);
    }
    E = First(LE);
    while(E != NULL){
        if (info(email(E)).username == info(U).username){
            jumlah_email++;
        }
    E = next(E);
    }
    if (jumlah_email > maks){
        maksUser = U;
        maks = jumlah_email;
    }
    cout << "User yang memiliki jumlah email terbanyak adalah : " << info(maksUser).username << endl;
    showEmail(LU, LE, info(maksUser).username);
} //  marcel

void searchUser(ListEmail &LE, string email){
    adrEmail E;
    E = findEmail(LE, email);
    if (E != NULL){
        cout << info(email(E)).name << " Adalah pemiliki alamat email " << email << endl;
    } else {
        cout << "Email Tidak Ditemukan" << endl;
    }
}

