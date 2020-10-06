#pragma once
#include <windows.h>
#include <string>
#include <MMsystem.h>
#include "Digitalv.h"

#pragma comment(lib,"winmm.lib")

using namespace std;

class SoundManager
{
private:
	string effectSoundPath;
	string selectSoundPath;

	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;
	DWORD m_dwDeviceID;
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	int dwID;
public:
	SoundManager();
	void PlaySelectSound();
	void PlayEffectSound();

	void PlayGameBGM();
	void PlayMenuBGM();
	void StopBGM();
};

