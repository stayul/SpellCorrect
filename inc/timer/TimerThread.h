#ifndef __MY_TIMERTHREAD_H_
#define __MY_TIMERTHREAD_H_

#include "Timer.h"
#include "Thread.h"
#include <functional>

namespace wd
{

class TimerThread
{
public:
	typedef std::function<void()> TimerThreadCallback;

	TimerThread(TimerThreadCallback cb, int init_sec, int interval_sec);

	void start();
	void stop();
private://组合的方式
	Timer _timer;
	Thread _thread;
};
}//end of namespace wd

#endif
