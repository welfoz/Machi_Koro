//#ifndef MACHI_KORO_CARTECOULEUR_H
//#define MACHI_KORO_CARTECOULEUR_H
#include "cardColor.h"

class WheatField : public Blue {
public: 
	WheatField() : Blue(nullptr, 1, "WheatField", 9, "effet description wheatfield") {
		BaseCard::setIcon(new Icon("aaaa", "aaaai", Type::primaryIndustry));
		//BaseCard::setIcon(getIcon("wheat"));
		size_t* actNumber = new size_t[3];
		actNumber[0] = 1;
		actNumber[1] = 5;
		actNumber[2] = 9;
		EstablishmentCard::setActivationNumbers(actNumber);
	};
	void activation() override {};
};
//#endif // MACHI_KORO_CARTECOULEUR_H
