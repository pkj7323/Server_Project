#include "pch.h"
#include "coreGlobal.h"
#include "ThreadManager.h"
#include "Memory.h"


class ThreadManager*	GThreadManager = nullptr;
class Memory*			GMemory = nullptr;
class DeadLockProfiler* GLogManager = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
		//GMemory = new Memory();
		//GLogManager = new DeadLockProfiler();
	}

	~CoreGlobal()
	{
		delete GThreadManager;
		//delete GMemory;
		//delete GLogManager;
	}
} GCoreGlobal;