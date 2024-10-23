#pragma once
#include "FUObjectItem.h"
/*同样也是FChunkedFixedUObjectArray
*
* Simple array type that can be expanded without invalidating existing entries.
* This is critical to thread safe FNames.
可以在不使现有项无效的情况下展开的简单数组类型。
这对于线程安全的FNames是至关重要的。
*/
class TUObjectArray  //FChunkedFixedUObjectArray
{
private:
	/** Primary table to chunks of pointers **/
	//主表指向指针块
	FUObjectItem** Objects;

	enum
	{
		NumElementsPerChunk = 64 * 1024,
	};

public:
	__forceinline FUObjectItem& operator[](signed int Index)
	{
		FUObjectItem* ItemPtr = GetObjectPtr(Index);
		return *ItemPtr;
	}

	__forceinline  FUObjectItem* GetObjectPtr(signed int Index)
	{
		const unsigned int ChunkIndex = (unsigned int)Index / NumElementsPerChunk;
		const unsigned int WithinChunkIndex = (unsigned int)Index % NumElementsPerChunk;
		FUObjectItem* Chunk = Objects[ChunkIndex];
		return  Chunk + WithinChunkIndex;
	}
};

