#include "SoundManager.h"

SoundManager::SoundManager()
{
	effectSoundPath = "effectSound.wav";
	selectSoundPath = "selectSound.wav";
}

void SoundManager::PlaySelectSound()
{
	PlaySound(NULL, NULL, SND_PURGE | SND_NOWAIT | SND_ASYNC);
	PlaySoundA(selectSoundPath.c_str(), NULL, SND_ASYNC);
}

void SoundManager::PlayEffectSound()
{
	PlaySound(NULL, NULL, SND_PURGE | SND_NOWAIT | SND_ASYNC);
	PlaySoundA(effectSoundPath.c_str(), NULL, SND_ASYNC);
}

void SoundManager::PlayGameBGM()
{
    mciOpen.lpstrElementName = "title.mp3"; // 파일 경로 입력
    mciOpen.lpstrDeviceType = "mpegvideo";

    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
        (DWORD)(LPVOID)&mciOpen);

    dwID = mciOpen.wDeviceID;

    mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
        (DWORD)(LPVOID)&m_mciPlayParms);
}

void SoundManager::PlayMenuBGM()
{
    mciOpen.lpstrElementName = "menu.mp3"; // 파일 경로 입력
    mciOpen.lpstrDeviceType = "mpegvideo";

    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
        (DWORD)(LPVOID)&mciOpen);

    dwID = mciOpen.wDeviceID;

    mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
        (DWORD)(LPVOID)&m_mciPlayParms);    
}

void SoundManager::StopBGM()
{
    mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);        // stop
}
