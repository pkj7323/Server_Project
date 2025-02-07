#include "pch.h"
#include "coreTLS.h"
#include "ThreadManager.h"
#include "coreGlobal.h"

thread_local uint32_t LThreadID;

void ThreadMain()
{
	while (true)
	{
		std::cout << "I'm" << LThreadID << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}


int main()
{
	for (size_t i = 0; i < 5; i++)
	{
		GThreadManager->Launch(ThreadMain);
	}

	GThreadManager->Join();
}