#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#define P 28
#define L 31

struct xy
{
   int x;
   int y;
};

struct PacMan
{
   struct xy posisi;
   int ax;
   int ay;
   int food;
};

struct PacMan PacManData =
{
   {
      .x = 1,
      .y = 1,
   },
      .ax = 0,
      .ay = 0,
      .food = 0
};

char map[L][P] =
{
   { "############################" },
   { "#......##..........##......#" },
   { "#.####.##.########.##.####.#" },
   { "#.####.##.########.##.####.#" },
   { "#...##.##.########.##.##...#" },
   { "###.##................##.###" },
   { "  #.##.##.########.##.##.#  " },
   { "###.##.##.########.##.##.###" },
   { "....##....##....##....##...." },
   { "###.########.##.########.###" },
   { "  #.########.##.########.#  " },
   { "  #....##..........##....#  " },
   { "  ####.##.###..###.##.####  " },
   { "     #.##.##....##.##.#     " },
   { "     #....##....##....#     " },
   { "     #.##.##....##.##.#     " },
   { "  ####.##.########.##.####  " },
   { "  #....##..........##....#  " },
   { "  #.#####.########.#####.#  " },
   { "  #.#####.########.#####.#  " },
   { "  #..........##..........#  " },
   { "  #.##.#####.##.#####.##.#  " },
   { "  #.##.#####.##.#####.##.#  " },
   { "  #.##.##..........##.##.#  " },
   { "  #.##.##.########.##.##.#  " },
   { "###.##.##.########.##.##.###" },
   { "#...##.......##.......##...#" },
   { "#.#######.##.##.##.#######.#" },
   { "#.#######.##.##.##.#######.#" },
   { "#.........##....##.........#" },
   { "############################" }
};

void user_input()
{
   if (_kbhit())
   {
         char c2 = _getch();

         PacManData.ax = 0;
         PacManData.ay = 0;

         switch (c2)
         {
            case 72: PacManData.ay = -1; break;
            case 80: PacManData.ay = +1; break;
            case 75: PacManData.ax = -1; break;
            case 77: PacManData.ax = +1; break;
         }
   }
}


void move_figures()
{
   map[PacManData.posisi.y][PacManData.posisi.x] = ' ';

   int nx = PacManData.ax + PacManData.posisi.x;
   int ny = PacManData.ay + PacManData.posisi.y;

   if (map[ny][nx] == '#')
   {
      PacManData.ax = 0;
      PacManData.ay = 0;
   }

   PacManData.posisi.x += PacManData.ax;
   PacManData.posisi.y += PacManData.ay;

   if (map[ny][nx] == '.')
   {
      PacManData.food++;
   }
   map[PacManData.posisi.y][PacManData.posisi.x] = '@';
}

void show_playfield()
{
   printf("LEVEL 1\n");
   for (int i = 0; i < L; i++)
   {
      for (int j = 0; j < P; j++)
      {
         printf("%c", map[i][j]);
      }
      printf("\n");
   }

   printf("Score: %d", PacManData.food);
   if(PacManData.food == 295)
      {
         printf("\tYOU WIN!\n");
      }
}

void set_cursor_posisi(int x, int y)
{
   COORD xy = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
   system("cls");

   while (1)
   {
      hidecursor();
      user_input();
      move_figures();
      set_cursor_posisi(0,0);
      show_playfield();

      Sleep(50);
      if(PacManData.food == 295)
      {
         break;
      }
      if (_kbhit())
    {
         char c3 = _getch();

         switch (c3)
         {
            case 81: break;
            return 0;
         }
   }
   }
}
