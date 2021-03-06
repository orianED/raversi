/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "include/Server.h"
#include "include/CommandsManager.h"
#include <fstream>

using namespace std;

int main() {
    ifstream sFile;
    sFile.open("server_config.txt");
    string port;
    if (sFile.is_open())
        getline(sFile, port);
    else
        return 0;
    sFile.close();

    Server server(atoi(port.c_str()));
    try {
        server.start();
        cout << "Enter exit to stop server" << endl;
        string str;
        cin >> str;
        if (str == "exit")
            server.stop();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
