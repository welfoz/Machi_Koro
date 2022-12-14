#pragma once
#include "../game.h"

class Controller {
	// BUT: game.cpp ne doit jamais appeller l'interface
	// game.cpp: gère la logique, seulement la logique

	// relation Game <--> Controller ?
	// composition ? 
	// heritage ?

	// controleur est hérité selon cli ou gui ? 
	// controleur singleton ?

	//pour moi, y'a:
	//	- récupérer nom du joueur
	//	- ajouter le joueur(peut potentiellement throw)
	//	- demander si il faut un autre joueur
	//	et dans ajouter joueur :
	//  -checker nombre limite
	//	- checker homonyme
	//	- ajouter le joueur
	//	et donc ta logique est dans ajouter joueur²

};

class CliController : public Controller {

};

class GuiController : public Controller {

};
