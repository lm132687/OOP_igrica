#pragma once
#include <SFML/Graphics.hpp>

class DecisionTracker
{
private:
    int correctDecisions = 0;
    int wrongDecisions = 0;

public:
    void evaluate(bool infected, bool reported);

    int getCorrect() const;
    int getWrong() const;
};

