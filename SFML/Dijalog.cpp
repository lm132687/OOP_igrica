#include "Dijalog.h"

Dijalog::Dijalog()
{
    active = false;
    dijalog_ind = 0;
    state = DialogState::Normal;
}

void Dijalog::start(const std::vector<std::string>& dijalogLines)
{
    dijalog = dijalogLines;

    active = true;
    dijalog_ind = 0;

}

void Dijalog::next()
{
    if (!active) return;

    dijalog_ind++;

    if (dijalog_ind >= dijalog.size())
    {
        stop();
    }
}

void Dijalog::stop()
{
    active = false;
}

void Dijalog::enterChoice()
{
    state = DialogState::Choice;
}

void Dijalog::leaveChoice()
{
    state = DialogState::Normal;
}

bool Dijalog::isActive() const
{
    return active;
}

bool Dijalog::isInChoice() const
{
    return state == DialogState::Choice;
}

const string& Dijalog::getCurrentDijalog() const
{
    static std::string empty = "";

    if (!active || dijalog_ind >= dijalog.size())
        return empty;

    return dijalog[dijalog_ind];
}

unsigned int Dijalog::getDijalog_Ind()
{
    return dijalog_ind;
}


