//
//  main.cpp
//  clib
//
//  Created by Lucas Greer on 6/15/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <curses.h>
#include <ncurses.h>

void printatpos(int x, int y) {
    mvaddch(x+1, y+1, '$');
    refresh();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    initscr();
    curs_set(0);
    addstr("##################\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n#                #\n##################\n"); // this has tiny holes in it and I don't know why
    FILE* f = fopen("/dev/urandom", "r");
    unsigned char* buf = (unsigned char*)malloc(64);
    fread(buf, 1, 64, f);
    fclose(f);
    std::vector<int> xs;
    std::vector<int> ys;
    for (int i = 0; i < 64; i++) {
        int x = buf[i]/16;
        int y = buf[i]%16;
        xs.push_back(x);
        ys.push_back(y);
    }
    for (int i = 0; i < 64; i++) {
        printatpos(xs[i], ys[i]);
    }
    getchar();
    curs_set(1);
    free(buf);
    endwin();
    return 0;
}
