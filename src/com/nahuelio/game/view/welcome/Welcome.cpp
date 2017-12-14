//
// Created by Patricio Ferreira on 12/12/17.
//

#include <QMainWindow>
#include <QtGui>
#include <QQuickWindow>
#include "headers/Welcome.h"

Welcome::Welcome(QObject *parent) : QObject(parent) {};

QString Welcome::greeting() {
    return m_greeting;
}

void Welcome::setGreeting(const QString &greeting) {
    if(greeting == m_greeting) {
        return;
    }
    m_greeting = greeting;
    emit greetingChanged();
}