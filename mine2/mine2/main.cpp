#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "TextureManager.h"
#include <fstream>
#include <sstream>
using namespace std;

vector<int> ReadingConfig() {
    ifstream configFile("config.cfg");
    vector<int> configNum;

    if (configFile.is_open()) {
        int value;
        for (int i = 0; i < 3; i++) {
            configFile >> value;
            configNum.push_back(value);
        }
    }
    return configNum;
}

int main()
{
    //variables
    int totalMines = 0;
    bool won = false;
    bool lose = false; //should be true because this project is an L
    bool debugB = false;

    //board variables
    vector<int> current = ReadingConfig();
    int col = current[0];
    int row = current[1];
    int mineCount = current[2];

    int** topBoard = new int* [col];
    int** bottomBoard = new int* [col];
    int** tempTop = new int* [col];
    int** tempBottom = new int* [col];

    //main boards
    for (int i = 0; i < col; i++) {
        topBoard[i] = new int[row];
        bottomBoard[i] = new int[row];
        tempTop[i] = new int[row];
        tempBottom[i] = new int[row];
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            topBoard[i][j];
            bottomBoard[i][j];
            tempTop[i][j];
            tempBottom[i][j];
        }
    }

    //mines
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            bottomBoard[i][j] = 10;
            //  tempTop[i][j] = 10;
            if (rand() % 7 == 0 && mineCount > 0) {
                topBoard[i][j] = 50;
                //tempTop[i][j] = 50;
                mineCount--;
                totalMines++;
            }
            else {
                topBoard[i][j] = 0;
            }
        }
    }
      // do shit for testing win
      //  cout << **tempTop;
      // for (int i = 1; i < col - 1; i++) {
      //    for (int j = 0; j < row; j++) {
      //        bottomBoard[i][j] = 10;
      //        //tempTop[i][j] = 10;
      //        if (totalMines < 384) {
      //            topBoard[i][j] = 50;
      //            //tempBottom[i][j] = 50;
      //            totalMines++;
      //            mineCount--;
      //        }
      //        else {
      //            topBoard[i][j] = 0;
      //          //  tempTop[i][j] = 0;
      //        }
      //      
      //    }
      //}

    int tileCount = current[0] * current[1];
    int totalTiles = col * row;
    
    //INITIAL BOARD//

    //top left
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i + 1][j + 1] == 50) adjTiles++;
            if (topBoard[i + 1][j] == 50) adjTiles++;
            if (topBoard[i][j + 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //top right
    for (int i = col - 1; i < col; i++) {
        for (int j = 0; j < 1; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i - 1][j] == 50) adjTiles++;
            if (topBoard[i - 1][j + 1] == 50) adjTiles++;
            if (topBoard[i][j + 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //bottom left
    for (int i = 0; i < 1; i++) {
        for (int j = row - 1; j < row; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i][j - 1] == 50) adjTiles++;
            if (topBoard[i + 1][j - 1] == 50) adjTiles++;
            if (topBoard[i + 1][j] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //bottom right
    for (int i = col - 1; i < col; i++) {
        for (int j = row - 1; j < row; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i - 1][j] == 50) adjTiles++;
            if (topBoard[i - 1][j - 1] == 50) adjTiles++;
            if (topBoard[i][j - 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //border top
    for (int i = 1; i < col - 1; i++) {
        for (int j = 0; j < 1; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i - 1][j] == 50) adjTiles++;
            if (topBoard[i - 1][j + 1] == 50) adjTiles++;
            if (topBoard[i][j + 1] == 50) adjTiles++;
            if (topBoard[i + 1][j] == 50) adjTiles++;
            if (topBoard[i + 1][j + 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //border left
    for (int i = 0; i < 1; i++) {
        for (int j = 1; j < row - 1; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i][j - 1] == 50) adjTiles++;
            if (topBoard[i + 1][j - 1] == 50) adjTiles++;
            if (topBoard[i + 1][j] == 50) adjTiles++;
            if (topBoard[i + 1][j + 1] == 50) adjTiles++;
            if (topBoard[i][j + 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //border right
    for (int i = col - 1; i < col; i++) {
        for (int j = 1; j < row - 1; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i][j - 1] == 50) adjTiles++;
            if (topBoard[i - 1][j - 1] == 50) adjTiles++;
            if (topBoard[i - 1][j] == 50) adjTiles++;
            if (topBoard[i - 1][j + 1] == 50) adjTiles++;
            if (topBoard[i][j + 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //border bottom
    for (int i = 1; i < col - 1; i++) {
        for (int j = row - 1; j < row; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i - 1][j] == 50) adjTiles++;
            if (topBoard[i - 1][j - 1] == 50) adjTiles++;
            if (topBoard[i][j - 1] == 50) adjTiles++;
            if (topBoard[i + 1][j] == 50) adjTiles++;
            if (topBoard[i + 1][j - 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }
    //all inside
    for (int i = 1; i < col - 1; i++) {
        for (int j = 1; j < row - 1; j++) {
            int adjTiles = 0;
            if (topBoard[i][j] == 50) continue;
            if (topBoard[i + 1][j] == 50) adjTiles++;
            if (topBoard[i + 1][j + 1] == 50) adjTiles++;
            if (topBoard[i][j + 1] == 50) adjTiles++;
            if (topBoard[i - 1][j] == 50) adjTiles++;
            if (topBoard[i - 1][j - 1] == 50) adjTiles++;
            if (topBoard[i][j - 1] == 50) adjTiles++;
            if (topBoard[i + 1][j - 1] == 50) adjTiles++;
            if (topBoard[i - 1][j + 1] == 50) adjTiles++;
            topBoard[i][j] = adjTiles;
        }
    }

    //TEMP//

    //top left
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i + 1][j + 1] == 50) adjTiles++;
            if (tempTop[i + 1][j] == 50) adjTiles++;
            if (tempTop[i][j + 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //top right
    for (int i = col - 1; i < col; i++) {
        for (int j = 0; j < 1; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i - 1][j] == 50) adjTiles++;
            if (tempTop[i - 1][j + 1] == 50) adjTiles++;
            if (tempTop[i][j + 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //bottom left
    for (int i = 0; i < 1; i++) {
        for (int j = row - 1; j < row; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i][j - 1] == 50) adjTiles++;
            if (tempTop[i + 1][j - 1] == 50) adjTiles++;
            if (tempTop[i + 1][j] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //bottom right
    for (int i = col - 1; i < col; i++) {
        for (int j = row - 1; j < row; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i - 1][j] == 50) adjTiles++;
            if (tempTop[i - 1][j - 1] == 50) adjTiles++;
            if (tempTop[i][j - 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //border top
    for (int i = 1; i < col - 1; i++) {
        for (int j = 0; j < 1; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i - 1][j] == 50) adjTiles++;
            if (tempTop[i - 1][j + 1] == 50) adjTiles++;
            if (tempTop[i][j + 1] == 50) adjTiles++;
            if (tempTop[i + 1][j] == 50) adjTiles++;
            if (tempTop[i + 1][j + 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //border left
    for (int i = 0; i < 1; i++) {
        for (int j = 1; j < row - 1; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i][j - 1] == 50) adjTiles++;
            if (tempTop[i + 1][j - 1] == 50) adjTiles++;
            if (tempTop[i + 1][j] == 50) adjTiles++;
            if (tempTop[i + 1][j + 1] == 50) adjTiles++;
            if (tempTop[i][j + 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //border right
    for (int i = col - 1; i < col; i++) {
        for (int j = 1; j < row - 1; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i][j - 1] == 50) adjTiles++;
            if (tempTop[i - 1][j - 1] == 50) adjTiles++;
            if (tempTop[i - 1][j] == 50) adjTiles++;
            if (tempTop[i - 1][j + 1] == 50) adjTiles++;
            if (tempTop[i][j + 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //border bottom
    for (int i = 1; i < col - 1; i++) {
        for (int j = row - 1; j < row; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i - 1][j] == 50) adjTiles++;
            if (tempTop[i - 1][j - 1] == 50) adjTiles++;
            if (tempTop[i][j - 1] == 50) adjTiles++;
            if (tempTop[i + 1][j] == 50) adjTiles++;
            if (tempTop[i + 1][j - 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //all inside
    for (int i = 1; i < col - 1; i++) {
        for (int j = 1; j < row - 1; j++) {
            int adjTiles = 0;
            if (tempTop[i][j] == 50) continue;
            if (tempTop[i + 1][j] == 50) adjTiles++;
            if (tempTop[i + 1][j + 1] == 50) adjTiles++;
            if (tempTop[i][j + 1] == 50) adjTiles++;
            if (tempTop[i - 1][j] == 50) adjTiles++;
            if (tempTop[i - 1][j - 1] == 50) adjTiles++;
            if (tempTop[i][j - 1] == 50) adjTiles++;
            if (tempTop[i + 1][j - 1] == 50) adjTiles++;
            if (tempTop[i - 1][j + 1] == 50) adjTiles++;
            tempTop[i][j] = adjTiles;
        }
    }
    //for when you lose it doesnt show the entire bottom board just the mines and what you have selected thus far
    for (int i = 1; i < col; i++) {
        for (int j = 1; j < row; j++) {
            if (topBoard[i][j] == 50) {
                tempTop[i][j] = 1000;
            }
        }
    }

    totalTiles = tileCount - totalMines;

    //getting all the adjacent tiles 
    //actually thats a lie i couldnt figure it out LOL

    //Getting the board size//
    int column1 = current[0] * 32.0f;
    int row1 = (current[1] * 32.0f) + 88.0f;
    //int tileCount = current[0] * current[1];


    sf::RenderWindow window(sf::VideoMode(column1, row1), "Minesweeper-ish!");

    sf::Sprite tileh(TextureManager::GetTexture("tile_hidden"));
    sf::Sprite tiler(TextureManager::GetTexture("tile_revealed"));
    sf::Sprite happyface(TextureManager::GetTexture("face_happy"));
    sf::Sprite loseface(TextureManager::GetTexture("face_lose"));
    sf::Sprite winface(TextureManager::GetTexture("face_win"));
    sf::Sprite digits1(TextureManager::GetTexture("digits"));
    sf::Sprite digits10(TextureManager::GetTexture("digits"));
    sf::Sprite digits10N(TextureManager::GetTexture("digits"));
    sf::Sprite digits100(TextureManager::GetTexture("digits"));
    sf::Sprite digitsN(TextureManager::GetTexture("digits"));
    sf::Sprite one(TextureManager::GetTexture("number_1"));
    sf::Sprite two(TextureManager::GetTexture("number_2"));
    sf::Sprite three(TextureManager::GetTexture("number_3"));
    sf::Sprite four(TextureManager::GetTexture("number_4"));
    sf::Sprite five(TextureManager::GetTexture("number_5"));
    sf::Sprite six(TextureManager::GetTexture("number_6"));
    sf::Sprite seven(TextureManager::GetTexture("number_7"));
    sf::Sprite eight(TextureManager::GetTexture("number_8"));
    sf::Sprite mines(TextureManager::GetTexture("mine"));
    sf::Sprite flag(TextureManager::GetTexture("flag"));
    sf::Sprite debug(TextureManager::GetTexture("debug"));
    sf::Sprite t1(TextureManager::GetTexture("test_1"));
    sf::Sprite t2(TextureManager::GetTexture("test_2"));
    sf::Sprite t3(TextureManager::GetTexture("test_3"));

    int flaggy = current[2];
    bool flaggythere = false;
    //int totalTiles = col * row;
    totalTiles = tileCount - totalMines;

    while (window.isOpen()) {

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        int x = localPosition.x / 32.0f;
        int y = localPosition.y / 32.0f;


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Right) {
                    if (lose == false && won == false) {
                        int temp2 = bottomBoard[x][y];
                        if (bottomBoard[x][y] == 10) {
                            bottomBoard[x][y] = 11;
                            tempBottom[x][y] = 11;
                            flaggy--;
                        }
                        else if (bottomBoard[x][y] == 11) {
                            bottomBoard[x][y] = 10;
                            tempBottom[x][y] = 10;
                            flaggy++;
                        }
                        else if (temp2 == 1 || temp2 == 2 || temp2 == 3 || temp2 == 4 || temp2 == 5 || temp2 == 6 || temp2 == 7 || temp2 == 8 || temp2 == 0) {
                            break;
                        }
                        else {
                            bottomBoard[x][y] = 10;
                        }
                    }
                    //testing counter
                    //for (int i = 0; i < 15; i++) {
                    //    for (int j = 0; j < 10; j++) {
                    //        bottomBoard[i][j] = 11;
                    //        flaggy--;
                    //    }
                    //}
                }

                if (event.key.code == sf::Mouse::Left) {

                    int temp = topBoard[x][y];
                    int temp2 = bottomBoard[x][y];
                    won = false;
                    //cout << **topBoard;
                    // tempTop[x][y] = topBoard[x][y];

                    bottomBoard[x][y] = topBoard[x][y];

                    
                 
                    if (tempBottom[x][y] == 11) {
                        bottomBoard[x][y] = 11;
                    }
                    else if (bottomBoard[x][y] == 50) {
                        bottomBoard[x][y] = tempTop[x][y];
                        lose = true;    
                       /* for (int i = 0; i < col; i++) {
                            for (int j = 0; j < row; j++) {
                                if (bottomBoard[i][j] == 10) {
                                    bottomBoard[i][j] = 10;
                                }
                            }
                        }*/
                    }
                    else if (temp2 == 1 || temp2 == 2 || temp2 == 3 || temp2 == 4 || temp2 == 5 || temp2 == 6 || temp2 == 7 || temp2 == 8) {
                        bottomBoard[x][y] = bottomBoard[x][y];
                    }
                    else if (temp == 1 || temp == 2 || temp == 3 || temp == 4 || temp == 5 || temp == 6 || temp == 7 || temp == 8) {
                        bottomBoard[x][y] = topBoard[x][y];
                        tempTop[x][y] = topBoard[x][y];
                        //tempTop[x][y] = topBoard[x][y];
                        totalTiles--;
                    }
                    else {
                        bottomBoard[x][y] = 0;
                        totalTiles--;
                    }
                    if (totalTiles == 0) {
                        for (int i = 0; i < col; i++) {
                            for (int j = 0; j < row; j++) {
                                //int temp = topBoard[i][j];
                                if (topBoard[i][j] != 50 && bottomBoard[i][j] != 10) {
                                    won = false;
                                }
                                if (totalTiles == 0) {
                                    won = true;
                                }
                            }
                        }
                    }
                    

                    //debugger button
                    if (debug.getGlobalBounds().contains(x * 32.0f, y * 32.0f) && debugB == false) {
                        debugB = true;
                        flaggythere = false;
                        for (int i = 0; i < col; i++) {
                            for (int j = 0; j < row; j++) {
                                if (bottomBoard[i][j] == 11) {
                                    flaggythere = true;
                                }
                                if (topBoard[i][j] == 50 && bottomBoard[i][j] == 11) {
                                    bottomBoard[i][j] = 900;
                                }
                                else if (topBoard[i][j] == 50) {
                                    bottomBoard[i][j] = 1000;
                                }

                                if (bottomBoard[i][j] == 11) {
                                    bottomBoard[i][j] = 11;
                                    flaggythere = true;
                                }
                            }
                        }
                    }
                    else if (debug.getGlobalBounds().contains(x * 32.0f, y * 32.0f) && debugB == true) {
                        debugB = false;
                        for (int i = 0; i < col; i++) {
                            for (int j = 0; j < row; j++) {
                                if (bottomBoard[i][j] == 900) {
                                    bottomBoard[i][j] = 11;
                                }
                                else if (topBoard[i][j] == 50) {
                                    bottomBoard[i][j] = 10;
                                }
                            }
                        }
                    }

                    ///test one
                    if (t1.getGlobalBounds().contains(x * 32.0f, y * 32.0f)) {
                        // testOne = true;
                        totalTiles = col * row;
                        totalMines = 0;
                        flaggy = 0;
                        ifstream file("testboard1.brd");

                        if (file.is_open()) {

                            string rowz;
                            int j = 0;
                            // bottomBoard[i][j] = 10;
                            while (getline(file, rowz)) {
                                for (int i = 0; i < col; i++) {
                                    bottomBoard[i][j] = 10;
                                    int number = int(rowz[i]) - 48;

                                    if (number == 1) {
                                        topBoard[i][j] = 50;
                                        totalMines++;
                                        flaggy++;
                                    }
                                    if (number == 0) {
                                        topBoard[i][j] = 0;
                                    }
                                    //because doing a double for loop didnt work needed to manually increment the rows
                                    if (i == col - 1) {
                                        j++;
                                    }
                                }
                            }
                        }
                        totalTiles = tileCount - totalMines;
                        //top left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //top right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom left
                        for (int i = 0; i < 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border top
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border bottom
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //all inside
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                    }

                    //test two
                    if (t2.getGlobalBounds().contains(x * 32.0f, y * 32.0f)) {
                        // testOne = true;
                        totalTiles = col * row;
                        totalMines = 0;
                        flaggy = 0;
                        ifstream file("testboard2.brd");

                        if (file.is_open()) {

                            string rowz;
                            int j = 0;

                            while (getline(file, rowz)) {
                                for (int i = 0; i < col; i++) {
                                    bottomBoard[i][j] = 10;
                                    int number = int(rowz[i]) - 48;
                                    if (number == 1) {
                                        topBoard[i][j] = 50;
                                        totalMines++;
                                        flaggy++;
                                    }
                                    if (number == 0) {
                                        topBoard[i][j] = 0;
                                    }
                                    //because doing a double for loop didnt work needed to manually increment the rows
                                    if (i == col - 1) {
                                        j++;
                                    }
                                }
                            }
                        }
                        totalTiles = tileCount - totalMines;
                        //top left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //top right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom left
                        for (int i = 0; i < 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border top
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border bottom
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //all inside
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                    }

                    //test three
                    if (t3.getGlobalBounds().contains(x * 32.0f, y * 32.0f)) {
                        // testOne = true;
                        totalTiles = col * row;
                        flaggy = 0;
                        totalMines = 0;
                        ifstream file("testboard3.brd");

                        if (file.is_open()) {

                            string rowz;
                            int j = 0;

                            while (getline(file, rowz)) {
                                for (int i = 0; i < col; i++) {
                                    bottomBoard[i][j] = 10;
                                    int number = int(rowz[i]) - 48;
                                    if (number == 1) {
                                        topBoard[i][j] = 50;
                                        totalMines++;
                                        flaggy++;
                                    }
                                    if (number == 0) {
                                        topBoard[i][j] = 0;
                                    }
                                    //because doing a double for loop didnt work needed to manually increment the rows
                                    if (i == col - 1) {
                                        j++;
                                    }
                                }
                            }
                        }
                        totalTiles = tileCount - totalMines;
                        //top left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //top right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom left
                        for (int i = 0; i < 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border top
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border bottom
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //all inside
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                    }

                    //resetting the board
                    if (happyface.getGlobalBounds().contains(x * 32.0f, y * 32.0f)) {
                        mineCount = current[2];
                        totalMines = 0;
                        lose = false;
                        won = false;
                        flaggy = current[2];
                        totalTiles = col * row;

                        window.draw(happyface);
                       

                        //mines
                        for (int i = 0; i < col; i++) {
                            for (int j = 0; j < row; j++) {
                                bottomBoard[i][j] = 10;
                                if (rand() % 7 == 0 && mineCount > 0) {
                                    topBoard[i][j] = 50;
                                    mineCount--;
                                    totalMines++;
                                }
                                else {
                                    topBoard[i][j] = 0;
                                }
                            }
                        }
                        totalTiles = tileCount - totalMines;
                        //top left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //top right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom left
                        for (int i = 0; i < 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //bottom right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border top
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 0; j < 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border left
                        for (int i = 0; i < 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border right
                        for (int i = col - 1; i < col; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //border bottom
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = row - 1; j < row; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        //all inside
                        for (int i = 1; i < col - 1; i++) {
                            for (int j = 1; j < row - 1; j++) {
                                int adjTiles = 0;
                                if (topBoard[i][j] == 50) continue;
                                if (topBoard[i + 1][j] == 50) adjTiles++;
                                if (topBoard[i + 1][j + 1] == 50) adjTiles++;
                                if (topBoard[i][j + 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j] == 50) adjTiles++;
                                if (topBoard[i - 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i][j - 1] == 50) adjTiles++;
                                if (topBoard[i + 1][j - 1] == 50) adjTiles++;
                                if (topBoard[i - 1][j + 1] == 50) adjTiles++;
                                topBoard[i][j] = adjTiles;
                            }
                        }
                        if (debugB == true) {
                            for (int i = 0; i < col; i++) {
                                for (int j = 0; j < row; j++) {
                                    if (bottomBoard[i][j] == 11) {
                                        flaggythere = true;
                                    }
                                    if (topBoard[i][j] == 50 && bottomBoard[i][j] == 11) {
                                        bottomBoard[i][j] = 900;
                                    }
                                    else if (topBoard[i][j] == 50) {
                                        bottomBoard[i][j] = 1000;
                                    }

                                    if (bottomBoard[i][j] == 11) {
                                        bottomBoard[i][j] = 11;
                                        flaggythere = true;
                                    }
                                }
                            }
                        }
                        else if (debugB == false) {
                            for (int i = 0; i < col; i++) {
                                for (int j = 0; j < row; j++) {
                                    if (bottomBoard[i][j] == 900) {
                                        bottomBoard[i][j] = 11;
                                    }
                                    else if (topBoard[i][j] == 50) {
                                        bottomBoard[i][j] = 10;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }


        window.clear(sf::Color::Blue);


        //inital printing of a blank board
        for (int i = 0; i < current[0]; i++) {
            for (int j = 0; j < current[1]; j++) {
                tileh.setPosition(sf::Vector2f(i * 32.0f, j * 32.0f));
                window.draw(tileh);
            }
        }


        //positioning
        happyface.setPosition(sf::Vector2f(((current[0] / 2.0f) * 32.0f), (current[1] * 32.0f)));
        window.draw(happyface);
        t1.setPosition(sf::Vector2f(((current[0] - 6.0f) * 32.0f), (current[1] * 32.0f)));
        window.draw(t1);
        t2.setPosition(sf::Vector2f(((current[0] - 4.0f) * 32.0f), (current[1] * 32.0f)));
        window.draw(t2);
        t3.setPosition(sf::Vector2f((((current[0] - 2.0f) * 32.0f)), (current[1] * 32.0f)));
        window.draw(t3);
        debug.setPosition(sf::Vector2f(((current[0] - 8.0f) * 32.0f), (current[1] * 32.0f)));
        window.draw(debug);


        if (won == true && lose == false) {
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < row; j++) {
                    if (topBoard[i][j] == 50) {
                        bottomBoard[i][j] = 11;
                    }
                    winface.setPosition(sf::Vector2f(((current[0] / 2.0f) * 32.0f), (current[1] * 32.0f)));
                    window.draw(winface);
                }
            }
        }
        if (lose == false) {
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < row; j++) {
                    if (bottomBoard[i][j] == 50) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                    }
                    else if (bottomBoard[i][j] == 11) {
                        flag.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(flag);
                    }
                    else if (bottomBoard[i][j] == 900) {
                        flag.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(flag);
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                    }
                    else if (topBoard[i][j] == 10) {
                        tileh.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tileh);
                    }
                    else if (bottomBoard[i][j] == 50) {
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                    }
                    else if (bottomBoard[i][j] == 10) {
                        tileh.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tileh);
                    }
                    else if (bottomBoard[i][j] == 1) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        one.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(one);
                        //  totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 2) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        two.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(two);
                        // totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 3) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        three.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(three);
                        // totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 4) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        four.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(four);
                        //totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 5) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        five.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(five);
                        // totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 6) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        six.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(six);
                        //  totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 7) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        seven.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(seven);
                        // totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 8) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        eight.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(eight);
                        //   totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 0) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        //    totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 100) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        //  totalTiles--;
                    }
                    else if (bottomBoard[i][j] == 1000) {
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                        //  totalTiles--;
                    }
                }
            }
        }
        // lose = true;
        if (lose == true) {
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < row; j++) {
                    int temp = bottomBoard[i][j];
                    if (topBoard[i][j] == 50) {
                        //topBoard[i][j] = tempTop[i][j];
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                        loseface.setPosition(sf::Vector2f(((current[0] / 2.0f) * 32.0f), (current[1] * 32.0f)));
                        window.draw(loseface);
                       // tempTop[i][j] = tempTop[i][j];

                    }
                    else if (bottomBoard[i][j] == 11) {
                        flag.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(flag);
                    }
                    else if (bottomBoard[i][j] == 900) {
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                    }
                    else if (topBoard[i][j] == 10) {
                        tileh.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tileh);
                    }
                    else if (bottomBoard[i][j] == 50) {
                        mines.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(mines);
                    }
                    else if (bottomBoard[i][j] == 10) {
                        tileh.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tileh);
                    }
                    else if (bottomBoard[i][j] == 1) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        one.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(one);
                    }
                    else if (bottomBoard[i][j] == 2) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        two.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(two);
                    }
                    else if (bottomBoard[i][j] == 3) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        three.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(three);
                    }
                    else if (bottomBoard[i][j] == 4) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        four.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(four);
                    }
                    else if (bottomBoard[i][j] == 5) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        five.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(five);
                    }
                    else if (bottomBoard[i][j] == 6) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        six.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(six);
                    }
                    else if (bottomBoard[i][j] == 7) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        seven.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(seven);
                    }
                    else if (bottomBoard[i][j] == 8) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                        eight.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(eight);
                    }
                    else if (bottomBoard[i][j] == 0) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                    }
                    else if (bottomBoard[i][j] == 100) {
                        tiler.setPosition(i * 32.0f, j * 32.0f);
                        window.draw(tiler);
                    }
                }
            }
        }

        int negativeInt = 0;
        //flaggy == 150

        //FLAG COUNTER//

        if (flaggy < 0) {
            digitsN.setTextureRect(sf::IntRect(210, 0, 21, 32));
            digitsN.setPosition(sf::Vector2f(0, (current[1] * 32.0f)));
            window.draw(digitsN);
        }

        if (flaggy / 100 == 0) {
            digits100.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digits100.setPosition(sf::Vector2f(21, (current[1] * 32.0f)));
            window.draw(digits100);
        }
        else if (flaggy < 0) {
            negativeInt++;
            digits100.setTextureRect(sf::IntRect(21 * (-flaggy / 100), 0, 21, 32));
            digits100.setPosition(sf::Vector2f(21, (current[1] * 32.0f)));
            window.draw(digits100);
        }
        else {
            digits100.setTextureRect(sf::IntRect(21 * (flaggy / 100), 0, 21, 32));
            digits100.setPosition(sf::Vector2f(21, (current[1] * 32.0f)));
            window.draw(digits100);
        }

        if (flaggy / 10 == 10) {
            digits10.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digits10.setPosition(sf::Vector2f(42, (current[1] * 32.0f)));
            window.draw(digits10);
        }
        else if (flaggy < 0 && flaggy / 10 == -10) {
            digits10.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digits10.setPosition(sf::Vector2f(42, (current[1] * 32.0f)));
            window.draw(digits10);
        }
        else if (flaggy < 0) {
            digits10.setTextureRect(sf::IntRect(21 * (-flaggy / 10), 0, 21, 32));
            digits10.setPosition(sf::Vector2f(42, (current[1] * 32.0f)));
            window.draw(digits10);
        }
        else {
            digits10.setTextureRect(sf::IntRect(21 * (flaggy / 10), 0, 21, 32));
            digits10.setPosition(sf::Vector2f(42, (current[1] * 32.0f)));
            window.draw(digits10);
        }

        if (flaggy % 10 == 0) {
            digits1.setTextureRect(sf::IntRect(0, 0, 21, 32));
            digits1.setPosition(sf::Vector2f(63, (current[1] * 32.0f)));
            window.draw(digits1);
        }
        else if (flaggy < 0) {
            negativeInt++;
            digits1.setTextureRect(sf::IntRect(21 * (-flaggy % 10), 0, 21, 32));
            digits1.setPosition(sf::Vector2f(63, (current[1] * 32.0f)));
            window.draw(digits1);
        }
        else {
            digits1.setTextureRect(sf::IntRect(21 * (flaggy % 10), 0, 21, 32));
            digits1.setPosition(sf::Vector2f(63, (current[1] * 32.0f)));
            window.draw(digits1);
        }

        window.display();
    }

    TextureManager::Clear();
    delete[] topBoard;
    delete[] bottomBoard;
    delete[] tempBottom;
    delete[] tempTop;
    return 0;
}