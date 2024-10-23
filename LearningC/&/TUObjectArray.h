#pragma once
#include "FUObjectItem.h"
/*ͬ��Ҳ��FChunkedFixedUObjectArray
*
* Simple array type that can be expanded without invalidating existing entries.
* This is critical to thread safe FNames.
�����ڲ�ʹ��������Ч�������չ���ļ��������͡�
������̰߳�ȫ��FNames��������Ҫ�ġ�
*/
class TUObjectArray  //FChunkedFixedUObjectArray
{
private:
	/** Primary table to chunks of pointers **/
	//����ָ��ָ���
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

