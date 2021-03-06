/**
 *      Author: Eliyahu Many
 *      ID: 308249150
 *      Author: Orian Edri
 *      ID: 308335454
 */

#include "../include/LocalPlayer.h"

LocalPlayer::LocalPlayer(char symbol, Client &client, Print &printer) : Players(symbol, printer), client(client),
                                                                        cell(Cell()) {
    string s = "";
    string sym;
    sym.push_back(symbol);
    s.append("You are: ");
    s.append(sym);
    char c[11];
    strcpy(c, s.c_str());
    printer.string(c);
}

Cell &LocalPlayer::play(Board &b, int &myScore, int &otherScore) {
    if (this->moves.empty()) {
        string s = "NoMove";
        try {
            this->client.sendMove(s);
        } catch(const char* msg) {
            cout<<msg<<endl;
        }
        return this->cell;
    } else {
        string choose;
        this->printer.playerTurn(this->symbol, this->moves);
        while (true) {
            this->printer.string((char *) "Please enter your move row,col: ");
            cin >> choose;
            for (int i = 0; i < this->moves.size(); ++i) {
                if ((int) choose[0] - 48 == this->moves[i].getX()
                    && (int) choose[2] - 48 == this->moves[i].getY()) {
                    while (!this->moves.empty()) {
                        this->moves.pop_back();
                    }

                    try {
                        this->client.sendMove(choose);
                    } catch(const char* msg) {
                        cout<<msg<<endl;
                    }
                    return this->moves[i];
                }
            }
            this->printer.string((char *) "Wrong entry!");
        }
    }
}