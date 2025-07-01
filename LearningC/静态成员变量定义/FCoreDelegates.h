#pragma once
#include "FSimpleMulticastDelegate.h"

class FCoreDelegates
{
	static FSimpleMulticastDelegate OnPostEngineInit;
};

FSimpleMulticastDelegate FCoreDelegates::OnPostEngineInit;