#include "pch.h"
#include "ThreadManager.h"


ThreadManager::ThreadManager()
{
	InitTLS();
}

ThreadManager::~ThreadManager()
{
	ReleaseTLS();
}

void ThreadManager::Launch(std::function<void()> callback)
{
	std::lock_guard<std::mutex> lock(m_lock);

	m_threads.emplace_back(std::thread([=]()
		{
			InitTLS();
			callback();
			ReleaseTLS();
		}));
}

void ThreadManager::Join()
{
	for (auto& t : m_threads)
	{
		if (t.joinable())
		{
			t.join();
		}
	}
	m_threads.clear();
}

void ThreadManager::InitTLS()
{
	static std::atomic<int32_t> s_threadId = 1;
	s_threadId = s_threadId.fetch_add(1);
}

void ThreadManager::ReleaseTLS()
{
}
