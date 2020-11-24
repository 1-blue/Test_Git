#include "Player.h"

Player::Player(HWND hWnd, RECT r, ULONGLONG speed)
{
    this->hWnd = hWnd;
	this->speed = speed;
    this->clientRect = r;
    startTime = GetTickCount64();
    playerRect.left = 100;
    playerRect.top = 500;
}

void Player::Move()
{
    if (startTime + speed < GetTickCount64())
        startTime = GetTickCount64();
    else
        return;

    hdc = GetDC(hWnd);
    mdc = CreateCompatibleDC(hdc);
    hbmp = CreateCompatibleBitmap(mdc, clientRect.right, clientRect.bottom);

    switch (++idx)
    {
    case 0:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 1:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 2:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 3:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 4:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 5:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 6:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;
    case 7:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\�����ȱ�\\8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        idx = -1;
        break;
    default:
        hbmp = (HBITMAP)LoadImage(NULL, "image\\11.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    }
    GetObject(hbmp, sizeof(BITMAP), &bmp);
    SelectObject(mdc, hbmp);

    playerRect.right = playerRect.left + bmp.bmWidth;
    playerRect.bottom = playerRect.top + bmp.bmHeight;

    BitBlt(hdc, playerRect.left, playerRect.top, bmp.bmWidth, bmp.bmHeight, mdc, 0, 0, SRCCOPY);
    DeleteObject(hbmp);
    DeleteDC(hdc);
    ReleaseDC(hWnd, hdc);
}

void Player::Jump()
{
    //��������� �𸣰ڳ�
    //�ѹ������� �����ѹ����� move���� ��������� ���ǿ� �����Ҷ����� �ݺ��ؾ��ϴµ�
    //��... Jump�� while���ȿ� ������ �����ϱ��ѵ�.. �װ����ƴϰ�
    //�����غ���
}
