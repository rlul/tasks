#pragma once

#include <chrono>

class Timer
{
public:
    void start() {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }

    void stop() {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }

    int microseconds() {
        std::chrono::time_point<std::chrono::system_clock> endTime;
        if (m_bRunning)
            endTime = std::chrono::system_clock::now();
        else
            endTime = m_EndTime;
        return std::chrono::duration_cast<std::chrono::microseconds>(endTime - m_StartTime).count();
    }

    const char* start_time() {
        char buf[64];
        std::time_t start_c = std::chrono::system_clock::to_time_t(m_StartTime);
        std::tm start_tm = *std::localtime(&start_c);
        strftime(buf, 64, "%H:%M:%S", &start_tm);
        return buf;

    }

    const char* end_time() {
        char buf[64];
        std::time_t end_c = std::chrono::system_clock::to_time_t(m_EndTime);
        std::tm end_tm = *std::localtime(&end_c);
        strftime(buf, 64, "%H:%M:%S", &end_tm);
        return buf;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
};