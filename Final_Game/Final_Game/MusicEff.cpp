#include "MusicEff.h"
#include <iostream>


MusicEff * MusicEff::getInstance()
{
	if (s_instace == nullptr)
	{
		s_instace = new MusicEff();
	}
	return s_instace;
}

void MusicEff::Init()
{
	
		br_music.openFromFile(MUSIC_BR);
		pre_br_music.openFromFile(MUSIC_PREBR);
		br_over.openFromFile(MUSIC_OVER);
		br_music.setLoop(true);
		pre_br_music.setLoop(true);
		br_over.setLoop(true);

		play.loadFromFile(SOUND_PLAY);
		exit.loadFromFile(SOUND_EXIT);
		
		destroy.loadFromFile(SOUND_DESTROY);
		eated.loadFromFile(SOUND_GEM);
	
		Play.setBuffer(play);
		Exit.setBuffer(exit);
		
		Destroy.setBuffer(destroy);
		Eated.setBuffer(eated);
}

void MusicEff::startBrMusic()
{
	br_music.setVolume(30);
	br_music.play();
}

void MusicEff::startPlay()
{
	Play.play();
	Play.setVolume(100);
	//std::cout << "Play sound" << std::endl;
}

void MusicEff::startExit()
{
	Exit.setVolume(100);
	Exit.play();
}


void MusicEff::startDestroy()
{
	Destroy.setVolume(100);
	Destroy.play();
}

void MusicEff::startEated()
{
	Eated.setVolume(100);
	Eated.play();
}



void MusicEff::pauseBrMusic()
{
	br_music.setVolume(0);
	br_music.pause();
}

void MusicEff::stopBrMusic()
{
	br_music.stop();
}

void MusicEff::startPreBrMusic()
{
	pre_br_music.play();
}

void MusicEff::pausePreBrMusic()
{
	pre_br_music.pause();
}

void MusicEff::stopPreBrMusic()
{
	pre_br_music.stop();
}

void MusicEff::startOverMusic()
{
	br_over.setVolume(50);
	br_over.play();
}

void MusicEff::pauseOverMusic()
{
	br_over.pause();
}

void MusicEff::stopOverMusic()
{
	br_over.stop();
}

bool MusicEff::statusPauseMusic()
{
	return br_music.getStatus() == sf::SoundSource::Status::Paused;
}

bool MusicEff::statusStartMusic()
{
	return br_music.getStatus() == sf::SoundSource::Status::Playing;
}

MusicEff::MusicEff()
{
}


MusicEff::~MusicEff()
{
}
