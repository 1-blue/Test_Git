#include "Core.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    if (!Core::GetInst()->Init(hInstance))
    {
        Core::ReleaseInst();
        return 0;
    }

    int returnValue = Core::GetInst()->Run();

    Core::ReleaseInst();

    return returnValue;
}

/*
* Core... 각각의 매니저들을 관리
* SceneManager.. Scene들을 관리
* Scene... Scene을 상속받는 여러 장면들을 만듦.. (인트로, 인게임, 아웃트로)
* Layer들을 겹쳐서 하나의 Scene을 만듦
* 
*/

