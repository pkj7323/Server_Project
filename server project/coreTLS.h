#pragma once
#include <stack>

extern thread_local uint32_t LThreadID;
extern thread_local std::stack<int32_t> LLockStack;

