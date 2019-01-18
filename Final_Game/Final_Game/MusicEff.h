#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#define MUSIC_BR "resources/GameLoop.wav"
#define SOUND_PLAY "resources/SpeedBoost.wav"
#define SOUND_EXIT "resources/SlowDown.wav"

#define SOUND_DESTROY "resources/Explosion.wav"
#define SOUND_GEM "resources/Powerup2.wav"
#define MUSIC_PREBR "resources/pre_br.wav"
#define MUSIC_OVER "resources/gameover.wav"
using namespace sf;
class MusicEff
{
private:
	static MusicEff* s_instace;
	Music br_music,pre_br_music,br_over;
	Sound Play, Exit,  Destroy,Eated;
	SoundBuffer play, exit, destroy,eated;
	
public:
	static MusicEff* getInstance();
	void Init();
	//void startBrMusic();
	void startPlay();
	void startExit();

	void startDestroy();
	void startEated();

	void startBrMusic();
	void pauseBrMusic();
	void stopBrMusic();

	void startPreBrMusic();
	void pausePreBrMusic();
	void stopPreBrMusic();

	void startOverMusic();
	void pauseOverMusic();
	void stopOverMusic();

	bool statusPauseMusic();
	bool statusStartMusic();

	MusicEff();
	~MusicEff();
};

