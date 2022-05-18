#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include "board.h"
#include "i_piece.h"
#include "tetronimos.h"
#include "score.h"

namespace marathon {
    class tetris 
    {
    private:
        int level {};
        int lines_deleted {};
        int lines_deleted_count {};
        int score_count {};
        std::unique_ptr<board> game_board;
        std::unique_ptr<tetrominos> game_piece;
        std::unique_ptr<score> game_score;

    public:
        tetris()=default;
        ~tetris();
        void initialize_game();
    };
}

namespace speed {
    class tetris 
    {
    private:
        int level {};
        int lines_deleted {};
        int lines_deleted_count {};
        int score_count {};
        clock_t time;
        std::unique_ptr<board> game_board;
        std::unique_ptr<tetrominos> game_piece;
        std::unique_ptr<score> game_score;

    public:
        tetris()=default;
        ~tetris();
        void initialize_game();
    };
}


#endif