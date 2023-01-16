#include "Cli.h"
#include "UploadCommand.h"
#include "CheckFuncs.h"
#include "Data.h"
using namespace std;


Cli::Cli(DefaultIO* dio) : dio(dio) {
    data = new Data();

    commands = {new UploadCommand(dio, data), new UploadCommand(dio, data),
                  new UploadCommand(dio, data), new UploadCommand(dio, data),
                  new UploadCommand(dio, data), new UploadCommand(dio, data)};
}

void Cli::start() {
    // Print the menu
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int size = commands.size();

    for (int i = 0; i < size; ++i) {
        menu += commands[i]->getDescription() + "\n";
    }
    menu += "8. exit\n";


    bool flag = false;
    while(true) {
        //show the menu
        if (!flag) {
            dio->write(menu);
        }

        // Execute the chosen command
        int index = -1;

        try {
            index = stoi(dio->read());
            //if a not number input
        } catch (const std::exception& e) {
            dio->write("Please enter a option that is a number\n");
            flag = true;
            continue;
        }
        flag = false;

        //exit option
        if (index == size + 1) {
            dio->write("exit\n");
            break;
        }

        //invalid option
        if (index <= 0 || index > size) {
            dio->write("Invalid command, try to type again a valid one:\n");
            flag = true;
            continue;
        }

        //run option
        commands[index - 1]->execute();
    }

    // try {
    //     SocketIO* socketIo = (SocketIO*) m_dio;
    //     socketIo->stopRunning();
    // } catch (const std::exception& e) {}
}

Cli::~Cli() {
    delete data;
    delete dio;

    for (int i = 0; i < commands.size(); ++i) {
        delete commands[i];
    }
}

