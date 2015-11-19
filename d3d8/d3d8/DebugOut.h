#pragma once

template<typename R>
void OutToLog(R result, const char *functionName);
template <typename R, typename ...Args>
void OutToLog(R result, const char *functionName, Args...args);

// TRACEFUNC macro for tracing function
#ifdef TRACEFUNC
#undef TRACEFUNC
#endif

#ifdef _DEBUG
#define TRACEFUNC(res, ...) OutToLog(res, __FUNCTION__, __VA_ARGS__)
#else
#define TRACEFUNC(...)
#endif
#define TRACE_NORETURN(...) TRACEFUNC(nullptr, __VA_ARGS__)
#define TRACE_RETURN(...) TRACEFUNC(__VA_ARGS__)
