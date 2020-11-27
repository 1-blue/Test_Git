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
* Core... ������ �Ŵ������� ����
* SceneManager.. Scene���� ����
* Scene... Scene�� ��ӹ޴� ���� ������ ����.. (��Ʈ��, �ΰ���, �ƿ�Ʈ��)
* Layer���� ���ļ� �ϳ��� Scene�� ����
* 
*/

