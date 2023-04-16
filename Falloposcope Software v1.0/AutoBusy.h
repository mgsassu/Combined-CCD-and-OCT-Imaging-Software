#pragma once
#include <WinUser.h>
#include <windef.h>
#include <picam.h>
//////////////////////////////////////////////////////////////////////////////////
//// AutoBusy
//// - helper to control wait cursor through RAII (busy in ctor, not in dtor)
//// - properly handles nesting
//////////////////////////////////////////////////////////////////////////////////
class AutoBusy
{
	HCURSOR waitCursor_ = 0;                // - the wait cursor
	piint busy_ = 0;                        // - controls the wait cursor
public:
	//--------------------------------------------------------------------------
	AutoBusy() : previous_(GetCursor()), released_(false)
	{
		++busy_;
		if (busy_ == 1)
			previous_ = SetCursor(waitCursor_);
	}
	//--------------------------------------------------------------------------
	~AutoBusy()
	{
		Release();
	}
	//--------------------------------------------------------------------------
	void Release()
	{
		if (!released_)
		{
			--busy_;
			if (!busy_)
				SetCursor(previous_);
			released_ = true;
		}
	}
	//--------------------------------------------------------------------------
private:
	AutoBusy(const AutoBusy&);            // - not implemented
	AutoBusy& operator=(const AutoBusy&); // - not implemented
	HCURSOR previous_;
	pibool released_;
};