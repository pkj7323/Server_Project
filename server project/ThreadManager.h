#pragma once



class ThreadManager
{
public:
	ThreadManager();
	~ThreadManager();

	void Launch(std::function<void()> callback);
	void Join();

	static void InitTLS();
	static void ReleaseTLS();
private:
	std::mutex m_lock;
	std::vector<std::thread> m_threads;
};
