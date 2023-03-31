#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Premier_Pas_Qt.h"
#include <qtcpsocket.h>
#include <qtcpserver.h>
#include "ClientState.h"
#include <qmap.h>

class Premier_Pas_Qt : public QMainWindow
{
	Q_OBJECT
		QString ID;
public:
    Premier_Pas_Qt(QWidget *parent = Q_NULLPTR);

private:
    Ui::Premier_Pas_QtClass ui;
	QTcpSocket * socket;
	QTcpServer * server;
	QMap<QTcpSocket*, ClientState*> clients;

public slots:
	void onDisplayMessageButtonClicked();
	void onDisplayConnexionClicked();
	void onSocketConnected();
	void onSocketDisconnected();
	void onSendMessageButtonClicked();
	void onSocketReadyRead();

	void onServerNewConnecion();
	void onClientDisconnected();
	void onClientReadyRead();
};
