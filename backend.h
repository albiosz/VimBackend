#pragma once
#include <string>

class Backend
{
public:
	virtual void runBackend() = 0;
	virtual void bind(std::string,void (*func)(void ),std::string) = 0;
};