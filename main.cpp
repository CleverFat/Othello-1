/*
Othello For Term Task
Version 2.0
*/
#include "main.h"
#include <thread>


int main(int argc, char **argv)
{

#ifdef WINDOWS_
    system("title=JetOthello V2.0");
    system("mode con cols=50 lines=34");
    system("color 07");
#endif

    cPass = false;
    randomFlag = false;
    manualFlag = false;
    UIFlag = false;
    debugFlag = false;


    for (int i = 1; i < argc; i++)
    {
        if (argv[i][1] == 'u')
            UIFlag = true;
        if (argv[i][1] == 'd')
            debugFlag = true;
    }

    menu();

    gameThread(argc, argv);
}

void gameThread(int argc, char **argv)
{
    if (UIFlag)
    {
        thread UI(initUI, argc, argv);
        thread game(othelloMain);
        UI.join();
        game.join();
    }
    else
        othelloMain();
}

void othelloMain()
{
    gameBoard.print();
    while (!gameBoard.end())
    {
        if (UIFlag)
            while (drawable)
                SLP(1);

        //No-valid situation handle
        if (!gameBoard(Valid))
        {
            CLS;
            gameBoard.print();

            if (AIFlag == NON_AI_MODE || (AIFlag == AI_MODE &&~gameBoard == playerSide))
                cout << "      No Possible Move, Enter to Pass!";
            else
            {
                cout << "      Achilles Passed, Enter to Your Turn!";
                cPass = true;
            }

            PAUSE;

            gameBoard.move(passCoord);
            gameBoard.print();
            continue;
        }

        ////Get input
        if (AIFlag == NON_AI_MODE || ~gameBoard == playerSide)
        {
            getCoord(Human);
            while (!inputFlag || gameBoard[inputCoord.x][inputCoord.y].stat != Valid)
            {

                if (inputFlag)
                    cout << "       Invalid Position! Your input is " << inputCoord.x << char(inputCoord.y + '@') << endl;
                else if (!saveError&&!debugCalled)
                    cout << "                Invalid Input!" << endl;
                else
                    debugCalled = false;

                getCoord(Human);
            }
        }
        else 
            getCoord(AI);

        gameBoard.move(inputCoord);   //Move will auto flip side and refresh the board
        gameBoard.print();

        if (AIFlag == AI_MODE&&~gameBoard == !playerSide)
            cout << "            Achilles Thinking ...";

        if (debugFlag)
            cout << ABReturn << endl;

        cPass = false;

        if (UIFlag)
        {
            drawable = true;
            glutPostRedisplay();
        }
    }

    judge();
    menu();
}

void autoPlayThread(int argc, char **argv)
{
    if (UIFlag)
    {
        thread UI(initUI, argc, argv);
        thread game(autoPlay);
        UI.join();
        game.join();
    }
    else
        autoPlay();
}

void autoPlay()
{
    short delayDur = 0;

    CLS;
    inputFlag = true;

    short aDiff[2]{};
    cout << "Please Set Mode of Achilles Playing Black" << endl << endl;
    selectDiff();
    aDiff[Black] = diff;
    CLS;
    cout << "Please Set Mode of Achilles Playing White" << endl << endl;
    selectDiff();
    aDiff[White] = diff;

    gameBoard.print();
    SLP(0);
    while (!gameBoard.end())
    {
        if (UIFlag)
            while (drawable)
                SLP(1);

        SLP(delayDur);
        AchillesInit(aDiff[~gameBoard]);
        randomFlag = true;

        if (gameBoard(Valid))
            getCoord(AI);
        else
            inputCoord = passCoord;

        gameBoard.move(inputCoord);
        gameBoard.print();
        gameBoard.recordPrint();

        if (UIFlag)
        {
            drawable = true;
            glutPostRedisplay();
        }
    }

    autoFlag = false;
    randomFlag = false;

    judge();
    menu();
}

void judge()
{
    CLS;
    gameBoard.print();
    if (AIFlag == AI_MODE)
    {
        if (gameBoard(playerSide) > gameBoard(!playerSide))
            cout << "    You Defeated Achilles! Congratulations!" << endl << endl;
        else if (gameBoard(playerSide) < gameBoard(!playerSide))
            cout << "           Too Young too Simple!" << endl << endl;
        else
            cout << "   Tie! Achilles Want to Play Again With You." << endl << endl;
    }
    else
    {
        if (gameBoard(Black) > gameBoard(White))
            cout << "                Black Win!" << endl << endl;
        else if (gameBoard(Black) < gameBoard(White))
            cout << "                White Win!" << endl << endl;
        else
            cout << "           Tie!" << endl << endl;
    }
    gameBoard.recordPrint();

    cout << endl << "       Press Any Key to Main Menu...";

    PAUSE;
}