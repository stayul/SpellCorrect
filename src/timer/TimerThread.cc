#include "TimerThread.h"

namespace wd
{

TimerThread::TimerThread(TimerThreadCallback cb,
			int init_sec,
			int interval_sec)
: _timer(cb, init_sec, interval_sec)
, _thread(std::bind(&Timer::start, &_timer))
{

}

void TimerThread::start()
{
	_thread.start();//创建子线程,执行Timer的start方法　
}

void TimerThread::stop()
{
	_timer.stop();//停止定时器
}

}// end of namespace wd

