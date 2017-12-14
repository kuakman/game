/*
 * Class Main
 * @author Patricio Ferreira <3dimentionar@gmail.com>
 * Copyright (c) 2017 nahuelio. All rights reserved.
 */

#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQuickView>

#include "headers/Main.h"
#include "headers/Game.h"
#include "view/welcome/headers/Welcome.h"

using namespace game_main;
using namespace game_controller;

Main::Main(QGuiApplication* app) {
    this->app = app;
};

/*
 * Run
 */
int Main::run(int argc, char *argv[]) {
    //Game::instance()->get("Window")->run();
    //Game::instance()->get("Sound")->run();
    //Game::instance()->get("Game")->run()->terminate();

    qmlRegisterType<Welcome>("com.nahuelio.game.view.welcome", 1, 0, "Welcome");
    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile(":/view/welcome/welcome.qml"));

    return this->app->exec();
};

/*
 * Game Launch
 */
int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    return (*new Main(&app)).run(argc, argv);
};