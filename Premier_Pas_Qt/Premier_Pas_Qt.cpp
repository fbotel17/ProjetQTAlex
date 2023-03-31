
/// PROVIDENCE ///

#include "Premier_Pas_Qt.h"
#include <QtSql/qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>

Premier_Pas_Qt::Premier_Pas_Qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	socket = new QTcpSocket(this);
	
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));

	server = new QTcpServer(this);
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnecion()));
	server->listen(QHostAddress::AnyIPv4, 5678);


	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	db = QSqlDatabase::addDatabase("QMYSQL");

	db.setHostName("192.168.64.240");    // local 192.168.1.79 Providence 192.168.64.240
	db.setUserName("ChatTCP");			// local rootWP Providence ChatTCP
	db.setPassword("ChatTCP");			// local rootWP Providence ChatTCP
	db.setDatabaseName("ChatTCP");		// Always ChatTCP

	if (db.open())   //Test connexion a la BDD
	{
		qDebug() << "Connexion reussie a oui";  // si réussi printf Debug 
		/*
		QString queryStr = "SELECT * FROM User";    //  requete

		QSqlQuery query(queryStr);

		//tu pars du rang -1
		//premier résultat rang 0

		while (query.next())	//  tant que il y a des résultat
		{
			this->ID = query.value(0).toString(); // passage  de l'ID du sender en string
													// possibilité de modifier pour faire la meme avec le nom du User

			qDebug() << "ID : " << ID;
		}*/
	}
	else
	{
		qDebug() << "Ceci est un échec";  //sinon printf echec
	}
}

void Premier_Pas_Qt::onDisplayMessageButtonClicked()   // tuto bouton 
{
	ui.label->setText("C'est de la merde !!");
}

void Premier_Pas_Qt::onSendMessageButtonClicked()
{
	if (socket->state() == QTcpSocket::ConnectedState)       // Vérification de la connexion du socket / Vérifie si il existe
	{
		QString MSG = ui.MSGEdit->text();
		socket->write(MSG.toStdString().c_str());          //envoye socket récupérer du champ text MSGEdit
		//socket->write("Steven on a un problème !!!\n");    //écriture en dur

	}
}

void Premier_Pas_Qt::onDisplayConnexionClicked()
{
	QString pseudo = ui.NameLineEdit->text();
	QString password = ui.PassLineEdit->text();

	QString ip = "localhost";
	QString port = "5678";
	bool ok;
	int portAsInt = port.toInt(&ok);
	if (ok) {
		socket->connectToHost(ip, portAsInt);
	}
	
	
	QString queryStr = "SELECT * FROM User WHERE Nom = '"+pseudo+"' AND MDP = '"+password+"'";


	QSqlQuery query(queryStr);
	bool existe = false;
	while (query.next())
	{
		this-> ID = query.value(0).toString();
		qDebug() << "ID : " << ID;
		existe = true;
	}
	if (existe = true) {
		//QString recupMSG = "SELECT * FROM Messages ORDER BY ID ASC LIMIT 100";
		QString recupMSG = "SELECT Messages.ID, User.Nom, Messages.Contenue FROM Messages, User WHERE User.ID = Messages.Proprietaire ORDER BY Messages.ID ASC LIMIT 100";
		QSqlQuery reponce(recupMSG);

		QString messages = "";

		while (reponce.next())
		{

			messages += reponce.value(2).toString();
			messages += "\n";
		}
		ui.DialBox->setText(messages);
	}
	else {
		
	}
}

void Premier_Pas_Qt::onSocketConnected()
{
	ui.label_2->setText("Status Connexion : Connecter");
}

void Premier_Pas_Qt::onSocketDisconnected()
{
	ui.label_2->setText("Status Connexion : Déconnecter");
}

void Premier_Pas_Qt::onSocketReadyRead()
{
	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);
	ui.label_2->setText("Status Connexion : message reçu = " + str);

}

void Premier_Pas_Qt::onServerNewConnecion()
{
	ui.label_6->setText("un client s'est connecté");
	QTcpSocket * client = server->nextPendingConnection();
	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));

	clients[client] = new ClientState();
}

void Premier_Pas_Qt::onClientDisconnected()
{
	ui.label_6->setText("un client s'est Déconnecté");
	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());
	QObject::connect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
	delete clients[obj];
	clients.remove(obj);
	obj->deleteLater();
}

void Premier_Pas_Qt::onClientReadyRead()
{
	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());

	QByteArray data = obj->read(obj->bytesAvailable());
	QString str(data);
	ui.label_6->setText("Status Connexion : message reçu = " + str);

	QSqlQuery query;
	int idd = ID.toInt();

	query.prepare("INSERT INTO Messages (Proprietaire, Contenue) VALUES (?, ?)");
	query.addBindValue(this->ID);
	qDebug() << this->ID;
	query.addBindValue(str);
	qDebug() << str;
	if (query.exec())
	{
		//std::cout << "Insertion réussie" << std::endl;
		qDebug() << "YES ";
	}
	else
	{
		//std::cout << "Echec insertion !" << std::endl;
		qDebug() << query.lastError().text();
		qDebug() << "NO ";
	}
		//query.exec("INSERT INTO Messages (Propriétaire, Contenue) VALUES ('" + this->ID + "','" + str + "')");



	//obj->write(data);


	//QString recupMSG = "SELECT * FROM Messages ORDER BY ID ASC LIMIT 100";
	QString recupMSG = "SELECT Messages.ID, User.Nom, Messages.Contenue FROM Messages, User WHERE User.ID = Messages.Proprietaire ORDER BY Messages.ID ASC LIMIT 100";
	QSqlQuery reponce(recupMSG);

	QString messages = "";

	while (reponce.next())
	{
		messages += reponce.value(1).toString()+" : " + reponce.value(2).toString();
		messages += "\n";
	}
	ui.DialBox->setText(messages);

	ClientState * clientState = clients[obj];

	if (!clientState->Authentificated)
	{
		QRegExp separator("(;)");
		if (str.startsWith("AU"))
		{
			//str.section(separator, )
			QStringList splited = str.mid(2).split(separator);
			if (splited.size() >= 2)
			{
				QString pseudo = splited[0];
				QString password = splited[1];
				qDebug() << "Login = " << pseudo;
				qDebug() << "Password = " << password;

				password[0] = 'T';

				QString sentence = "Bonjour " + pseudo + " " + password;

				obj->write(sentence.toStdString().c_str());
			}
		}

	}
	else
	{

	}

	//clientState->Authentificated = true;

	
}