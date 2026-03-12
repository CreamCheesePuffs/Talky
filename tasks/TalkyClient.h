#pragma once
#include <QObject>
#include <QMetaObject>
#include <QString>
#include "NetWorker.h"

class TalkyClient : public QObject {
    Q_OBJECT
public:
    explicit TalkyClient(QObject* parent = nullptr);
    ~TalkyClient();

    Q_INVOKABLE void start(const QString& host, quint16 port);
    Q_INVOKABLE void stop();

    Q_INVOKABLE void registerUser(const QString& username, const QString& nickname, const QString& password);
    Q_INVOKABLE void login(const QString& username, const QString& password, int status);
    Q_INVOKABLE void addFriend(int targetUserId);
    Q_INVOKABLE void sendTextMessage(int toUserId, const QString& text);

signals:
    void connectedChanged(bool connected);
    void networkError(QString msg);
    void registerFinished(int code, QString msg);
    void loginFinished(int code, QString msg, int userId, QString username, QString nickname);
    void addFriendFinished(int code, QString msg, int targetUserId);
    void messageReceived(int fromUserId, int toUserId, QString text, qint64 ts);

private:
    NetWorker _worker;
};