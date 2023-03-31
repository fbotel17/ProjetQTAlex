#pragma once
#include <qstring.h>
struct ClientState
{
	bool Authentificated;
	QString pseudo;

	ClientState()
	{
		Authentificated = false;
		pseudo = "";
	}
};

