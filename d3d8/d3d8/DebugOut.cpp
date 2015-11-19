#include "main.h"
#include <sstream>

std::ostream &operator<<(std::ostream &out, const IID&riid) {
	return out << "guid{" << riid.Data1 << ", " << riid.Data2 << ", " << riid.Data3 << ", " << riid.Data4 << "}";
}

template <typename Arg>
std::ostream &Write(std::ostream &out, Arg &arg) {
	return out << arg;
}

template <typename Arg, typename ...Args>
std::ostream &Write(std::ostream &out, Arg arg, Args...args) {
	out << arg;
	return Write(out, args...);
}

template<typename R>
void WriteBeginFunction(std::ostringstream &out, R result, const char *functionName) {
//	out << result << " = ";
	if (functionName)
		out << functionName << "( ";
}

void WriteEndFunctionAndFlush(std::ostringstream &out, const char *functionName) {
	if (functionName)
		out << " );";
	out << std::endl;
	::OutputDebugStringA(out.str().c_str());
}

template<typename R>
void OutToLog(R result, const char *functionName) {
	if (!functionName)
		return;
	std::ostringstream out;
	::WriteBeginFunction(out, result, functionName);
	::WriteEndFunctionAndFlush(out, functionName);
}

template <typename R, typename ...Args>
void OutToLog(R result, const char *functionName, Args...args) {
	if (!functionName)
		return;
	std::ostringstream out;
	::WriteBeginFunction(out, result, functionName);
	::Write(out, args...);
	::WriteEndFunctionAndFlush(out, functionName);
}
