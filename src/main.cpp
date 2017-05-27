#include <iostream>
#include <ncurses.h>
#include <sstream>
#include <zconf.h>
#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include "../include/AEntity.hpp"
#include "../include/Player.hpp"
#include "../include/game.h"
#include "../include/EnimyLite.hpp"
#include "../include/EnimyWide.hpp"

#define MAPX 64
#define MAPY 27
#define MAXOBJ 150
#define MAXSHIP 20
#define SPAWNCHANCE 15

std::string foo;
AEntity *g_obj[MAXOBJ];
AShip *g_ship[MAXSHIP];
Player *g_player = new Player;
int g_count = 0;
int g_shipCount = 0;

void draw() {
	wclear(g_win);
	box(g_win, 0, 0);
	box(g_scr, 0, 0);
	for (int x = 0; x < g_count; ++x) {
		int width = g_obj[x]->getWidth();
		if (width > 1){
			for (int i = 0; i < width; ++i) {
				mvwaddch(g_win, g_obj[x]->getYLoc() + 1, g_obj[x]->getXLoc() + 1 + i, g_obj[x]->getSymbol());
			}
		}
		else {
			mvwaddch(g_win, g_obj[x]->getYLoc() + 1, g_obj[x]->getXLoc() + 1, g_obj[x]->getSymbol());
		}
	}
	wrefresh(g_win);
}

bool checkWindow() {
	getmaxyx(stdscr, g_wy, g_wx);
	return (g_wy >= MAPY + 5 && g_wx >= MAPX + 2);
}

void getKey() {
	int c = getch();
	switch (c) {
		case 'q':
			g_loop = false;
			break;
		case KEY_LEFT:
			g_player->moveLeft();
			break;
		case KEY_RIGHT:
			g_player->moveRight(MAPX - 1);
			break;
		case KEY_UP:
			g_player->moveUp();
			break;
		case KEY_DOWN:
			g_player->moveDown(MAPY - 1);
			break;
		case ' ':
			if (g_count < MAXOBJ)
				g_obj[g_count++] = g_player->shoot();
			break;
		default:
			break;
	}
}

void removeObj(int index) {
	AEntity *temp = g_obj[index];
	for (int j = index; j < g_count - 1; ++j) {
		g_obj[j] = g_obj[j + 1];
	}
	int i = 0;
	while (i < g_shipCount) {
		if (g_ship[i] == temp)
			break;
		i++;
	}
	for (int k = i; k < g_shipCount - 1; ++k) {
		g_ship[k] = g_ship[k + 1];
	}
	delete (temp);
	g_obj[g_count] = NULL;
	if (i != g_shipCount) {
		g_ship[g_shipCount] = NULL;
		g_shipCount--;
	}
	g_count--;
}

void update() {
	for (int i = 0; i < g_shipCount; ++i) {
		int chance = g_ship[i]->getShootChance();
		if (g_count < MAXOBJ && chance > 0&& (rand() % chance) == 1)
			g_obj[g_count++] = g_ship[i]->shoot();
	}
	for (int i = 0; i < g_count; ++i) {
		if (!g_obj[i]->update(MAPX, MAPY)) {
			removeObj(i);
		}
	}
	for (int i = 0; i < g_count - 1; ++i) {
		for (int j = i + 1; j < g_count; ++j) {
			if (g_obj[i]->getYLoc() == g_obj[j]->getYLoc() && g_obj[i]->getXLoc() == g_obj[j]->getXLoc()) {
				if (g_obj[i]->takeDamage() <= 0) {
					removeObj(i);
					if (i == 0) {
						g_loop = false;
					}
					j = (j - 1) < 0 ? 0 : j - 1;
					i = (i - 1) < 0 ? 0 : i - 1;
				}
				if (g_obj[j]->takeDamage() <= 0) {
					removeObj(j);
					j = (j - 1) < 0 ? 0 : j - 1;
				}
			}
			if (g_obj[i]->getWidth() > 1){
				int width = g_obj[i]->getWidth() + 1;
				for (int k = 1; k < width; ++k) {
					for (int l = i + 1; l < g_count; ++l) {
						if (g_obj[i]->getYLoc() == g_obj[l]->getYLoc() && g_obj[i]->getXLoc() + k == g_obj[l]->getXLoc()) {
							if (g_obj[i]->takeDamage() <= 0) {
								removeObj(i);
								if (i == 0) {
									g_loop = false;
								}
								l = (l - 1) < 0 ? 0 : l - 1;
								i = (i - 1) < 0 ? 0 : i - 1;
							}
							if (g_obj[l]->takeDamage() <= 0) {
								removeObj(l);
								l = (l - 1) < 0 ? 0 : l - 1;
							}
						}
					}
				}
			}
		}
	}
	//srand((unsigned int) time(NULL));
	if (g_count < MAXOBJ && g_shipCount < MAXSHIP && g_loop && (rand() % SPAWNCHANCE + 1) == 1) {
		if(rand() % 4 == 1){
			g_obj[g_count++] = g_ship[g_shipCount++] = new EnimyWide((rand() % MAPX - 3), 0);
		}else
			g_obj[g_count++] = g_ship[g_shipCount++] = new EnimyLite((rand() % MAPX), 0);
	}
	g_actions = 0;
}

void gameLoop() {
	time_t start;
	time_t now;
	g_loop = true;
	time(&start);
	time(&now);
	clock_t intavel = (clock_t) (((float) 1 / 60) * 1000);
	clock_t cycleSt = clock();
	float cycletime = 0;
	while (g_loop) {
		cycletime += ((float) (clock() - cycleSt) / CLOCKS_PER_SEC) * 1000;
		while (cycletime - intavel > 0) {
			update();
			draw();
			cycletime -= intavel;
		}
		cycleSt = clock();
		getKey();
		if (g_loop) {
			time(&now);
			g_player->addToScore((fmod(difftime(now, start), 20) == 0) ? 1 : 0);
			mvwprintw(g_scr, 1, 1, "score: %d, lives: %d, sec : %f", g_player->getScore(), g_player->getLives(),
			          difftime(now, start));
		}
		wrefresh(g_win);
		wrefresh(g_scr);
	}
}

void initObj() {
	for (int i = 0; i < MAXOBJ; ++i) {
		g_obj[i] = NULL;
	}
	for (int i = 0; i < MAXSHIP; ++i) {
		g_ship[i] = NULL;
	}
	g_player->setLocation(MAPX / 2, MAPY - 1);
	g_obj[g_count++] = g_player;
	g_ship[g_shipCount++] = g_player;
}

void initWindow() {
	initscr();
	noecho();
	curs_set(FALSE);
	getmaxyx(stdscr, g_wy, g_wx);
	g_win = newwin(MAPY + 2, MAPX + 2, ((g_wy - (MAPY + 5)) / 2), ((g_wx - (MAPX + 2)) / 2));
	g_scr = newwin(3, MAPX + 2, ((g_wy / 2) + ((MAPY) / 2)), ((g_wx - (MAPX + 2)) / 2));
	nodelay(stdscr, TRUE);
	nodelay(g_win, TRUE);
	nodelay(g_scr, TRUE);
	keypad(stdscr, TRUE);
	keypad(g_win, TRUE);
	keypad(g_scr, TRUE);
}

int main() {

	initWindow();
	initObj();
	if (checkWindow())
		gameLoop();
	else {
		g_loop = true;
		while (g_loop) {
			getKey();
			mvwaddstr(stdscr, 0, 0, "window is to small");
		}
	}
	delwin(g_scr);
	delwin(g_win);
	endwin();
	std::cout << g_count << ":" << foo << std::endl;
}
