#include "gameboard.hh"
#include "gamestate.hh"
#include "player.hh"
#include "gameengine.hh"
#include "QDebug"

#include <memory>
#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // GameBoard
    std::shared_ptr<Student::GameBoard> board =
            std::make_shared<Student::GameBoard>();
    board->initializeBoard();

    //GameState
    Student::GameState startingState;
    std::shared_ptr<Student::GameState> statePtr =
            std::make_shared<Student::GameState>(startingState);

    //Players
    Student::Player* player = new Student::Player(69);
    Common::IPlayer* castedPlayer = static_cast<Common::IPlayer*>(player);
    std::vector<Common::IPlayer*> playerVector = {castedPlayer};

    qDebug() << playerVector[0]->getPlayerId();

    Logic::GameEngine* backEngine = new Logic::GameEngine(
                board, statePtr, playerVector);

    qDebug() << backEngine->currentPlayer();

    //QQmlApplicationEngine* frontEngine = new QQmlApplicationEngine();
    //frontEngine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    return 0;
    return a.exec();
}
