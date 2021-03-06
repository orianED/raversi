/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include <unistd.h>
#include <csignal>
#include "../include/Command.h"

void Command::commandNotify(int clientSocket, string msg) {
    signal(SIGPIPE, SIG_IGN);
    int size = msg.length() + 1;
    int n = write(clientSocket, &size, sizeof(int));
    if (n == -1) {
        throw "Error int writing to client";
    }
    n = write(clientSocket, msg.c_str(), size);
    if (n == -1) {
        throw "Error int writing to client";
    }
}