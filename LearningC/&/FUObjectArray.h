#pragma once
#include "TUObjectArray.h"
class FUObjectArray {
public:

	/** Array of all live objects.											*/
	TUObjectArray ObjObjects;

	/** INTERNAL USE ONLY: gets the internal FUObjectItem array */
	TUObjectArray& GetObjectItemArrayUnsafe()
	{
		return ObjObjects;
	}
};
