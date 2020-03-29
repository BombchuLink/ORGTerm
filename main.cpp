#include <stdio.h>
#include <ncurses.h>
#include "Organya.h"
#include "Sound.h"

static const PIXTONEPARAMETER drum1[2] = {
	{1, 5000, {0, 16.0, 63, 0}, {3, 1.0, 32, 0}, {0, 0.0, 32, 0}, 63, 64, 63, 166, 35, 255, 0},
	{1, 1000, {5, 1.0, 16, 0}, {0, 1.0, 32, 0}, {0, 0.0, 32, 0}, 63, 64, 63, 91, 28, 255, 0},
};

static const PIXTONEPARAMETER drum2[2] = {
	{1, 5000, {0, 20.0, 30, 0}, {3, 1.0, 44, 0}, {0, 0.0, 32, 0}, 63, 64, 63, 111, 19, 255, 0},
	{1, 10000, {5, 14.0, 41, 0}, {5, 3.0, 32, 0}, {0, 0.0, 32, 0}, 63, 64, 18, 91, 12, 255, 0},
};

static const PIXTONEPARAMETER drum3[1] = {
	{1, 1000, {5, 48.0, 30, 0}, {5, 1.0, 32, 0}, {0, 0.0, 32, 0}, 63, 64, 63, 166, 27, 255, 0},
};

static const PIXTONEPARAMETER drum4[1] = {
	{1, 10000, {5, 48.0, 30, 0}, {5, 1.0, 32, 0}, {0, 0.0, 32, 0}, 63, 64, 43, 166, 41, 255, 7},
};

static const PIXTONEPARAMETER drum5[2] = {
	{1, 4000, {5, 35.0, 30, 0}, {3, 35.0, 32, 0}, {0, 0.0, 32, 0}, 63, 53, 21, 166, 13, 255, 0},
	{1, 10000, {1, 63.0, 32, 0}, {3, 1.0, 32, 0}, {0, 0.0, 32, 0}, 63, 64, 39, 91, 20, 255, 0},
};

static const PIXTONEPARAMETER drum6[2] = {
	{1, 4000, {5, 6.0, 32, 0}, {3, 2.0, 32, 0}, {3, 2.0, 32, 0}, 63, 26, 30, 66, 29, 255, 0},
	{1, 4000, {0, 150.0, 32, 0}, {0, 0.0, 32, 0}, {3, 2.0, 32, 0}, 63, 26, 30, 66, 29, 255, 0},
};


int main(int argc, char *argv[])
{
	// Init
	if (InitDirectSound())
	{

		// Load drums
		MakePixToneObject(drum1, 2, 150);
		MakePixToneObject(drum2, 2, 151);
		MakePixToneObject(drum3, 1, 152);
		MakePixToneObject(drum4, 1, 153);
		MakePixToneObject(drum5, 2, 154);
		MakePixToneObject(drum6, 2, 155);

		// Load song
		fflush(stdout);
		bool PlayOrg = LoadOrganya(argv[1]);
		if (PlayOrg == true) {

			// Start song
			ChangeOrganyaVolume(100);
			SetOrganyaPosition(0);
			PlayOrganyaMusic();



			//draw terminal stuff
			initscr();cbreak();noecho();refresh();
			int Wait;
			unsigned char Track[8];
			unsigned short Freq[8];
			int CurrentMeasure;
			long TotalMeasure;
			int Crotchet, Bar;
			GetORGinfo(&Wait, Track, Freq, &CurrentMeasure, &TotalMeasure, &Crotchet, &Bar);
			// multiply Wait time by the Crotchet then divide 60000 (miliseconds in 1 min)
			int BPM = 60000/(Wait*Crotchet);
			CurrentMeasure = 0;
			//int CurrentStep = 0;
			//int TotalStep = 0;
			printw("Wait Time/BPM	%d/%d\n", Wait, BPM);
			//printw("Measure		%d/%d\n", CurrentMeasure, TotalMeasure);
			printw("Measures	%d\n", TotalMeasure);
			printw("Time Signature	%d/%d\n", Crotchet, Bar);
			//printw("Steps		%d/%d\n", CurrentStep, TotalStep);
			printw("Track 1		%d	(%d)\n", Track[0], Freq[0]);
			printw("Track 2		%d	(%d)\n", Track[1], Freq[1]);
			printw("Track 3		%d	(%d)\n", Track[2], Freq[2]);
			printw("Track 4		%d	(%d)\n", Track[3], Freq[3]);
			printw("Track 5		%d	(%d)\n", Track[4], Freq[4]);
			printw("Track 6		%d	(%d)\n", Track[5], Freq[5]);
			printw("Track 7		%d	(%d)\n", Track[6], Freq[6]);
			printw("Track 8		%d	(%d)\n", Track[7], Freq[7]);

			//only CS compatable orgs supported right now
			/*
			printf("Drum 1		%s", Drum[Drum1]);
			printf("Drum 2		%s", Drum[Drum2]);
			printf("Drum 3		%s", Drum[Drum3]);
			printf("Drum 4		%s", Drum[Drum4]);
			printf("Drum 5		%s", Drum[Drum5]);
			printf("Drum 6		%s", Drum[Drum6]);
			printf("Drum 7		%s", Drum[Drum7]);
			printf("Drum 8		%s", Drum[Drum8]);
			*/
			//file size



			// Wait until user presses q
			printw("Press q to exit.\n");
			while (1) {
				int key;
				key = getch();
				if (key == 'q') {
					break;
				}
			}
			endwin();
		}

		else {
			printf("error! .org does not exist!\n");
		}

		// Deinit
		EndDirectSound();
	}
}
