//#include "graphics.h"
#include <stdio.h>
#include <math.h>

#define M_PI 3.141592654

float fract(float x)
{
	int i=x;
	return x-i;
}

float sndVal(float t)
{
	return fract(t);
}

class CMusic
{
public:
	int sample;
	void Init()
	{
		sample=0;
	}
	void GenerateSamples(int nSamples)
	{
		for(int i=0;i<nSamples;i++)
		{
			float ts=sample/44100.;
			float l=sin(sample/30.)*0.5;
			sample++;
			printf("%f ",l);
		}
	}	
};


int main()
{
	CMusic music;
	music.Init();
	music.GenerateSamples(10);
	return 0;
}