#include "TUBES.h"

using namespace std;

int main()
{
    ListUser LU;
    ListEmail LE;
    infoUser X;
    infoEmail Y;
    adrUser U;
    adrEmail E;
    string username;
    string email;

    createListUser(LU);
    createListEmail(LE);

    cout << "=== MENAMBAHKAN DATA USER ===" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Nama: ";
        cin >> X.name;
        cout << "Username: ";
        cin >> X.username;
        cout << "Tanggal lahir: ";
        cin >> X.tanggalLahir;
        cout << "Domisili: ";
        cin >> X.domisili;

        U = createUser(X);
        addUser(LU, U);
        cout << endl;
    }
    cout << endl;

    cout << "=== MENAMBAHKAN EMAIL USER ===" << endl;

    for(int k = 0; k < 4; k++){
        cout << "Email :";
        cin >> Y.email;

        cout << "Username yang ingin menambahkan email : ";
        cin >> username;

        E = createEmail(Y);
        cout << "Create email berhasil" << endl;
        U = findUser(LU,username);
        addEmail(LE,LU,U,E);
        cout << endl;
    }

    /* showUser, deleteUser, deleteEmail, showEmail, showMost , searchUser */
    // Menampilkan data user tertentu
    cout << "=== MENCARI DAN MENAMPILKAN DATA USER ===" << endl;
    cout << "Username yang akan ditampilkan: ";
    cin >> username;

    showUser(LU,LE,username);
    cout << endl;

    // Menghapus user tertentu
    cout << "=== MENGHAPUS USER TERTENTU ===" << endl;
    cout << "Username yang akan dihapus: ";
    cin >> username;

    deleteUser(LU,LE,username);

    cout << endl;

   //Menghapus email tertentu
    cout << "=== MENGHAPUS EMAIL TERTENTU ===" << endl;
    cout << "Email yang akan dihapus: ";
    cin >> email;
    cout << "Username yang ingin menghapus email: ";
    cin >> username;
    E = findEmail(LE,email);
    deleteEmail(LE,LU,E); // SEMENTARA

    cout << endl;
    //Menampilkan semua email yang dimiliki user tertentu
    cout << "=== MENAMPILKAN SELURUH EMAIL DARI USER TERTENTU ===" << endl;
    cout << "Username yang ingin ditampilkan emailnya: ";
    cin >> username;

    showEmail(LU,LE,username);
    cout << endl;

    //Menampilkan user dengan jumlah email terbanyak dan daftar emailnya
    cout << "=== MENAMPILKAN USERNAME DENGAN EMAIL TERBANYAK ===" << endl;
    showMost(LU,LE);

    cout << endl;

    //Mencari pemilik dari suatu email
    cout << "=== MENCARI PEMILIK DARI SUATU EMAIL ===" << endl;
    cout << "Email :";
    cin >> email;

    searchUser(LE,email);



    return 0;
}
