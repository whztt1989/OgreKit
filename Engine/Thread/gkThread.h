/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2013 Nestor Silveira.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _gkThread_h_
#define _gkThread_h_

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <semaphore.h>
#endif

#include "gkSyncObj.h"
#include "gkPtrRef.h"

class gkCall : public gkReferences
{
public:
	gkCall() {};

	virtual ~gkCall() {};

	virtual void run() = 0;
};

class gkThread
{
public:

	gkThread(gkCall* call);

	~gkThread();

	void join();

private:

#ifdef WIN32
	static unsigned __stdcall task(void* p);
#else
	static void* task(void* p);
#endif

	void run();

private:

	gkCall* m_call;
	gkSyncObj m_syncObj;

#ifdef WIN32
	HANDLE m_hChilThread;
	unsigned m_threadId;
#else
	pthread_t m_threadId;
#endif

};

#endif//_gkThread_h_
