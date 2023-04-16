#pragma once
#include <synchapi.h>
#include <picam.h>
//////////////////////////////////////////////////////////////////////////////////
//// AutoLock
//// - helper to control locking through RAII (acquires in ctor, releases in dtor)
//////////////////////////////////////////////////////////////////////////////////
class AutoLock
{
public:
	//--------------------------------------------------------------------------
	AutoLock(CRITICAL_SECTION& lock) : lock_(lock), released_(false)
	{
		EnterCriticalSection(&lock_);
	}
	//--------------------------------------------------------------------------
	~AutoLock()
	{
		Release();
	}
	//--------------------------------------------------------------------------
	void Release()
	{
		if (!released_)
		{
			LeaveCriticalSection(&lock_);
			released_ = true;
		}
	}
	//--------------------------------------------------------------------------
private:
	AutoLock(const AutoLock&);            // - not implemented
	AutoLock& operator=(const AutoLock&); // - not implemented
	CRITICAL_SECTION& lock_;
	pibool released_;
};