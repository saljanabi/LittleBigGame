/*
** TimeManager.hh for Baignoire in /group-687056
**
** Made by BOURDALE Jules
** Login   <bourda_j@etna-alternance.net>
**
*/

#ifndef TIME_MANAGER_HH
#define TIME_MANAGER_HH

#include <chrono>
#include <vector>

class TimeManager
{
    static TimeManager instance;

private:
    std::chrono::system_clock::time_point tp_starting;
    std::chrono::system_clock::time_point tp_update_start, tp_update_end;

    TimeManager();

    TimeManager(const TimeManager&); // non construction-copyable
    TimeManager& operator=(const TimeManager&); // non copyable

public:
    ~TimeManager();

    static TimeManager &GetInstance();

    void Start();
    void Update();

    unsigned int GetElapsedTime() const;
    unsigned int GetStartedTime() const;
};

#endif /* TIME_MANAGER_HH */
