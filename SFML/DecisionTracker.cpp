#include "DecisionTracker.h"

void DecisionTracker::evaluate(bool infected, bool reported)
{
    if ((infected && reported) || (!infected && !reported))
    {
        correctDecisions++;
    }
    else
    {
        wrongDecisions++;
    }
}

int DecisionTracker::getCorrect() const
{
    return correctDecisions;
}

int DecisionTracker::getWrong() const
{
    return wrongDecisions;
}
