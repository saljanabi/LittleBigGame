/*
** TimeManager.cpp for Baignoire in /group-687056
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#include "TimeManager.h"

TimeManager TimeManager::instance;

TimeManager::TimeManager() {}
TimeManager::~TimeManager() {}

TimeManager &TimeManager::GetInstance() {
    return TimeManager::instance;
}

void TimeManager::Start() {
    this->tp_starting = std::chrono::system_clock::now();
}

void TimeManager::Update() {
    this->tp_update_start = this->tp_update_end;
    this->tp_update_end = std::chrono::system_clock::now();
}

unsigned int TimeManager::GetElapsedTime() const {
    TimeManager &t = TimeManager::GetInstance();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        t.tp_update_end - t.tp_update_start
    ).count();
}

unsigned int TimeManager::GetStartedTime() const {
    TimeManager &t = TimeManager::GetInstance();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        t.tp_update_end - t.tp_starting
    ).count();
}
