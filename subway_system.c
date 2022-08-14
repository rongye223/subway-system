
#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdlib.h>
#include<SDL.h>
#include<SDL_main.h>

int num(int i, SDL_Rect* rect,SDL_Renderer* rend);


int main(int argc, char* argv[])
{
	int max=100;
	int i, j, k;
	int d[10][10];
	for (i = 1;i <= 9;i++) {
		for (j = 1;j <= 9;j++) {
			d[i][j] = max;
		}
	}
	d[1][2] = d[2][1] = 1;
	d[2][3] = d[3][2] = 1;
	d[2][6] = d[6][2] = 1;
	d[3][4] = d[4][3] = 1;
	d[4][5] = d[5][4] = 1;
	d[6][8] = d[8][6] = 1;
	d[7][8] = d[8][7] = 1;
	d[8][9] = d[9][8] = 1;
	for (k = 1;k <= 9;k++) {
		for (i = 1;i <= 9;i++) {
			for (j = 1;j <= 9;j++) {
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Subway System",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* numb = SDL_LoadBMP("num.bmp");
	SDL_Surface* entry = SDL_LoadBMP("entry.bmp");
	SDL_Texture* entry1 = SDL_CreateTextureFromSurface(rend, entry);
	SDL_Surface* guide = SDL_LoadBMP("guide.bmp");
	SDL_Texture* guide1 = SDL_CreateTextureFromSurface(rend, guide);
	SDL_Surface* introduction = SDL_LoadBMP("introduction.bmp");
	SDL_Texture* introduction1 = SDL_CreateTextureFromSurface(rend, introduction);
	SDL_Surface* lines = SDL_LoadBMP("lines.bmp");
	SDL_Texture* lines_a = SDL_CreateTextureFromSurface(rend, lines);
	SDL_Surface* lines1 = SDL_LoadBMP("lines1.bmp");
	SDL_Texture* lines_b = SDL_CreateTextureFromSurface(rend, lines1);
	SDL_Surface* lines2 = SDL_LoadBMP("lines2.bmp");
	SDL_Texture* lines_c = SDL_CreateTextureFromSurface(rend, lines2);
	SDL_Surface* person = SDL_LoadBMP("person.bmp");
	SDL_Texture* person1 = SDL_CreateTextureFromSurface(rend, person);
	SDL_Surface* jiesuan = SDL_LoadBMP("jiesuan.bmp");
	SDL_Texture* jiesuan1 = SDL_CreateTextureFromSurface(rend, jiesuan);
	SDL_Surface* end = SDL_LoadBMP("end.bmp");
	SDL_Texture* end1 = SDL_CreateTextureFromSurface(rend, end);
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, entry1, NULL, NULL);
	SDL_RenderPresent(rend);
	
	SDL_Rect rect;
	rect.x = 90;
	rect.y = 80;
	rect.w = 60;
	rect.h = 80;



	SDL_Event event;
	int quit = 0;
	int forward = 0;
	int start;
	int ed;
	int p;
	int cost;
	int cost1, cost2;
	while (quit == 0)
	{

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
			else if (event.key.keysym.sym == SDLK_RIGHT) {
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, guide1, NULL, NULL);
				SDL_RenderPresent(rend);
				
			}
			else if (event.key.keysym.sym == SDLK_UP) {
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, lines_a, NULL, NULL);
				SDL_RenderPresent(rend);
			}
			else if (event.key.keysym.sym == SDLK_DOWN) {
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, introduction1, NULL, NULL);
				SDL_RenderPresent(rend);
			}
			else if (event.key.keysym.sym == SDLK_SPACE)
			{
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, lines_b, NULL, NULL);
				SDL_RenderPresent(rend);
				rect.x = 90;
				rect.y = 80;
				start=num(10, &rect, rend);
				forward = 0;
				while (forward == 0)
				{
					while (SDL_PollEvent(&event))
					{
						if (event.key.keysym.sym == SDLK_F1) {
							forward = 1;
						}
					}

				}
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, lines_c, NULL, NULL);
				SDL_RenderPresent(rend);
				rect.x = 90;
				rect.y = 80;
				ed = num(10, &rect, rend);
				forward = 0;
				while (forward == 0)
				{
					while (SDL_PollEvent(&event))
					{
						if (event.key.keysym.sym == SDLK_F2) {
							forward = 1;
						}
					}

				}
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, person1, NULL, NULL);
				SDL_RenderPresent(rend);
				rect.x = 490;
				rect.y = 260;
				p = num(10, &rect, rend);
				forward = 0;
				while (forward == 0)
				{
					while (SDL_PollEvent(&event))
					{
						if (event.key.keysym.sym == SDLK_F3) {
							forward = 1;
						}
					}

				}
				SDL_RenderClear(rend);
				SDL_RenderCopy(rend, jiesuan1, NULL, NULL);
				SDL_RenderPresent(rend);
				rect.x = 390;
				rect.y = 210;
				cost = p * d[start][ed];
				forward = 0;
				if (cost < 10) {
					num(cost, &rect, rend);
					
				}
				else {
					cost2 = cost % 10;
					cost1 = (cost - cost2) / 10;
					rect.w = 40;
					num(cost1, &rect, rend);
					rect.x = 430;
					num(cost2, &rect, rend);
				}
				while (forward == 0)
				{
					
					while (SDL_PollEvent(&event))
					{
						if (event.key.keysym.sym == SDLK_RETURN) {
							forward = 1;
							quit = 1;
							SDL_RenderClear(rend);
							SDL_RenderCopy(rend, end1, NULL, NULL);
							SDL_RenderPresent(rend);
							SDL_Delay(1500);
						}
						else if (event.key.keysym.sym == SDLK_ESCAPE)
						{
							SDL_RenderClear(rend);
							SDL_RenderCopy(rend, guide1, NULL, NULL);
							SDL_RenderPresent(rend);
							forward = 1;
						}
					}

				}

			}

		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

int num(int i, SDL_Rect* rect,SDL_Renderer* rend)
{
	SDL_Surface* number = SDL_LoadBMP("num.bmp");
	SDL_Texture* number1 = SDL_CreateTextureFromSurface(rend, number);
	int numWidth = 80;
	int numHeight = 140;
	int j;
	int m = 0;
	int n = 0;
	SDL_Event event;

	SDL_Rect clips[10];
	for (j = 0;j < 10;j++)
	{
		clips[j].x = j * numWidth;
		clips[j].y = 0;
		clips[j].w = numWidth;
		clips[j].h = numHeight;
	}
	if (i == 10) {
		while (m==0)
		{
			while (SDL_PollEvent(&event))
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_0:
					SDL_RenderCopy(rend, number1, &clips[0], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 0;
					break;
				
				case SDLK_1:
					SDL_RenderCopy(rend, number1, &clips[1], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 1;
					break;
				case SDLK_2:
					SDL_RenderCopy(rend, number1, &clips[2], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 2;
					break;
				case SDLK_3:
					SDL_RenderCopy(rend, number1, &clips[3], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 3;
					break;
				case SDLK_4:
					SDL_RenderCopy(rend, number1, &clips[4], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 4;
					break;
				case SDLK_5:
					SDL_RenderCopy(rend, number1, &clips[5], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 5;
					break;
				case SDLK_6:
					SDL_RenderCopy(rend, number1, &clips[6], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 6;
					break;
				case SDLK_7:
					SDL_RenderCopy(rend, number1, &clips[7], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 7;
					break;
				case SDLK_8:
					SDL_RenderCopy(rend, number1, &clips[8], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 8;
					break;
				case SDLK_9:
					SDL_RenderCopy(rend, number1, &clips[9], rect);
					SDL_RenderPresent(rend);
					m = 1;
					n = 9;
					break;

				}
			}
		}
	}
	else {
		SDL_RenderCopy(rend, number1, &clips[i], rect);
		SDL_RenderPresent(rend);
	}
	
	return n;
}

