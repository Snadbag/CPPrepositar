#pragma once
#include <crtdbg.h>

#define new new ( _NORMAL_BLOCK , FILE , LINE )

class MemLeak
{
public:
    MemLeak()
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    }
    ~MemLeak() { _CrtDumpMemoryLeaks(); }
};

const MemLeak ml;