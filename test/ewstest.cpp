#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

#include "ewsclient/ewsclient.h"
#include "ewsclient/ewsgetfolderrequest.h"

class Test : public QObject
{
    Q_OBJECT
public:
    Test(QString url, QObject *parent);

public slots:
    void requestFinished(EwsRequest *req);

private:
    EwsClient cli;
    EwsGetFolderRequest *folderReq;
};

Test::Test(QString url, QObject *parent)
    : QObject(parent), cli(url)
{
    folderReq = new EwsGetFolderRequest(&cli);
    folderReq->setDistinguishedFolderId(EwsDistinguishedFolderIdItem::Inbox);
    folderReq->setFolderShape(EwsBaseShapeItem::Default);
    connect(folderReq, SIGNAL(finished(EwsRequest*)), SLOT(requestFinished(EwsRequest*)));
    folderReq->send();
}

void Test::requestFinished(EwsRequest *req)
{
    qDebug() << "Request done" << req->isError();
    if (req->isError()) {
        qDebug() << req->errorString();
    }
    else {
        EwsGetFolderRequest *folderReq = qobject_cast<EwsGetFolderRequest*>(req);
        if (!folderReq)
            return;

    }
}

int main(int argc, char ** argv)
{
    QCoreApplication app(argc, argv);

    Test test(argv[1], &app);

    app.exec();

    return 0;
}

#include "ewstest.moc"
