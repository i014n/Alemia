#include "CPlant_Sunflower.h"
bool CPlant_Sunflower::status_ = false;

CPlant_Sunflower::~CPlant_Sunflower()
{
	CLog::getInstance().printLog("S-a apelat destrucorul explicit al clasei CPlant_Sunflower.\n");
}

void CPlant_Sunflower::Draw(int x, int y)
{
	static UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	MY_UTILS::SetColor(5);
	conOut(y, x) << char(228);
	status_ = true;
	const char* PlantCoord = this->FilePlantationsCoord.c_str();
	FILE* fin = fopen(PlantCoord, "a");
	fprintf(fin, "%d %d\n", x, y);
	fclose(fin);
	char buff[10];
	string resistance = "ResistancePlant";
	resistance += _itoa(x, buff, 10);
	resistance += "_";
	resistance += _itoa(y, buff, 10);
	resistance += ".txt";
	const char* ResistanceChar = resistance.c_str();
	FILE* fRes = fopen(ResistanceChar, "w");
	fprintf(fRes, "%d", this->LifeResistance_);
	fclose(fRes);
}

bool CPlant_Sunflower::Attacker_or_not()
{
	return this->attacker_;
}
