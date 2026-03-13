#include "TalkyClient.h"
#include <QMessageBox>
#include <utility>

inline QString ToQString(const std::string& str)
{
    return QString::fromStdString(str);
}

TalkyClient::TalkyClient(QObject* parent)
    : QObject(parent)
{
    NetWorker::Callbacks cbs;

    cbs.onConnectedChanged = [this](bool connected) {
        QMetaObject::invokeMethod(this, [this, connected]() {
            emit connectedChanged(connected);
        }, Qt::QueuedConnection);
    };

    cbs.onNetworkError = [this](const std::string& msg) {
        QMetaObject::invokeMethod(this, [this, msg]() {
            emit networkError(ToQString(msg));
        }, Qt::QueuedConnection);
    };

    cbs.onRegisterFinished = [this](int code, const std::string& msg) {
        QMetaObject::invokeMethod(this, [this, code, msg]() {
            emit registerFinished(code, ToQString(msg));
        }, Qt::QueuedConnection);
    };

    cbs.onLoginFinished = [this](int code, const std::string& msg, const UserInfo& user) {
        QMetaObject::invokeMethod(this, [this, code, msg, user]() {
            emit loginFinished(
                code,
                ToQString(msg),
                user.userId,
                ToQString(user.username),
                ToQString(user.nickname));
        }, Qt::QueuedConnection);
    };

    cbs.onAddFriendFinished = [this](int code, const std::string& msg, int targetUserId) {
        QMetaObject::invokeMethod(this, [this, code, msg, targetUserId]() {
            emit addFriendFinished(code, ToQString(msg), targetUserId);
        }, Qt::QueuedConnection);
    };

    cbs.onMessageReceived = [this](const ChatMsg& m) {
        QMetaObject::invokeMethod(this, [this, m]() {
            emit messageReceived(m.fromUserId, m.toUserId, ToQString(m.text), m.timestamp);
        }, Qt::QueuedConnection);
    };

    _worker.SetCallbacks(std::move(cbs));


    connect(this, &TalkyClient::networkError, this, [this](const QString& msg) {
        QMessageBox::warning(_signin.get(), QStringLiteral("网络错误"), msg);
        if (_login)
        {
            _login->setSubmitting(false);
        }
        if (_signin)
        {
            _signin->setSubmitting(false);
        }
        });
}

TalkyClient::~TalkyClient()
{
    _worker.Stop();
}

void TalkyClient::start(const QString& host, quint16 port) 
{
    _worker.SetServer(host.toUtf8().toStdString(), static_cast<uint16_t>(port));
    _worker.Start();
}

void TalkyClient::stop()
{
    _worker.Stop();
}

void TalkyClient::registerUser(const QString& username, const QString& nickname, const QString& password) 
{
    // todo  worker
    

}

void TalkyClient::login(const QString& username, const QString& password, int status) 
{
    
}

void TalkyClient::addFriend(int targetUserId) 
{

}

void TalkyClient::sendTextMessage(int toUserId, const QString& text) 
{
    
}

void TalkyClient::launch()
{
    showLogin();
}

void TalkyClient::showLogin()
{
    if (!_login)
    {
        _login = std::make_unique<Login>();
        connect(_login.get(), &Login::registerRequested, this, &TalkyClient::showSignin); // 点击注册，切换到注册界面
        //connect(_login.get(), &Login::loginRequested, this, &TalkyClient::showMainWindow); // 
    }

    _login->show();
    _login->raise();
    _login->activateWindow();
}

void TalkyClient::showSignin()
{

    if (!_signin)
    {
        _signin = std::make_unique<Signin>();
        //connect(_signin.get(), &Signin::closeRequested, this, &TalkyClient::showLogin);
        connect(_signin.get(), &Signin::registerSubmitted,
            this,
            [this](const QString& username, const QString& nickname, const QString& password) {
                _signin->setSubmitting(true);
                registerUser(username, nickname, password);
            });
    }

    //if (_login)
    //{
    //    _login->hide();
    //}

    _signin->show();
    _signin->raise();
    _signin->activateWindow();
}

void TalkyClient::showMainWindow()
{
    if (!_mainWindow)
    {
        _mainWindow = std::make_unique<MainWindow>();
    }

    if (_login)
    {
        _login->hide();
    }

    _mainWindow->show();
    _mainWindow->raise();
    _mainWindow->activateWindow();
}
