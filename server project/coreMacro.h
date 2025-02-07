#pragma once

#define USE_MANY_LOCKS(count) Lock _locks[count];
#define USE_LOCK				USE_MANY_LOCKS(1)
#define	READ_LOCK_IDX(idx)		ReadLockGuard readLockGuard_##idx(_locks[idx], typeid(this).name());
#define READ_LOCK				READ_LOCK_IDX(0)
#define	WRITE_LOCK_IDX(idx)		WriteLockGuard writeLockGuard_##idx(_locks[idx], typeid(this).name());
#define WRITE_LOCK				WRITE_LOCK_IDX(0)

//TODO: read write Lock 만들어야함

//크래시를 nullptr로 가정하도록 요청, 컴파일러의 코드 재배치 방지
//crash에 강제로 값을 넣어서 크래시 발생
#define CRASH(cause)						\
{											\
	uint32_t* crash = nullptr;				\
	__analysis_assume(crash != nullpter);	\
	*crash = 0xDEADBEEF;					\
}

//
#define ASSERT_CRASH(expr)					\
{											\
	if (!(expr))							\
	{										\
		CRASH("ASSERT_CRASH");				\
		__analysis_assume(expr);			\
	}										\
}
