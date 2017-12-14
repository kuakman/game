//
// Created by Patricio Ferreira on 12/12/17.
//

#ifndef GAME_WELCOME_H
#define GAME_WELCOME_H

#include <QObject>
#include <QString>

class Welcome : public QObject {

    Q_OBJECT
    Q_PROPERTY(QString greeting READ greeting WRITE setGreeting NOTIFY greetingChanged)

    public:
        explicit Welcome(QObject *parent = nullptr);
        QString greeting();
        void setGreeting(const QString &greeting);

    signals:
        void greetingChanged();

    private:
        QString m_greeting;

};


#endif //GAME_WELCOME_H
