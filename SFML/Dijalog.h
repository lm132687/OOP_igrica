#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>

using namespace std;

enum class DialogState
{
	Normal,
	Choice
};

class Dijalog
{
private:
	vector<string> dijalog;
	unsigned int dijalog_ind;
	bool active;
	DialogState state;
public:
	Dijalog();
	unsigned int br = 4;

	void start(const std::vector<std::string>& dijalogLines);
	void next();
	void stop();
	void enterChoice();
	void leaveChoice();
	bool isActive()const;
	bool isInChoice() const;
	const string& getCurrentDijalog() const;
	unsigned int getDijalog_Ind();
};

