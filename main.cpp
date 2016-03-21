#include "krenameext.h"

#include <QCoreApplication>
#include <QDebug>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QStringList>
#include <QObject>

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("KRename");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("rename a filename's extension");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("RootDir",QObject::tr("\tthe root directory"));
    parser.addPositionalArgument("OldExtension",QObject::tr("\tthe old extension to be replaced"));
    parser.addPositionalArgument("NewExtension",QObject::tr("\tthe new extension"));

    QCommandLineOption beRecursively(QStringList()<<"r"<<"recursive",QObject::tr("be recursively"));
    parser.addOption(beRecursively);

    parser.process(app);

    const QStringList argslist = parser.positionalArguments();

    if(argslist.length()!=3)
    {
        std::cout<<"give right args please!"<<std::endl;
    }else{
        KRenameExt engine(argslist[0],argslist[1],argslist[2],parser.isSet(beRecursively));
        engine.run();
    }

    std::cout<<"press anykey to continue..."<<std::endl;
//    return app.exec();
    return 0;
}

