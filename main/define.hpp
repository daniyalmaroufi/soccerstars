#ifndef __DEFINE__
#define __DEFINE__

#define GAME_NAME "soccerStars"
#define GAME_WIDTH 800
#define GAME_HEIGHT 530
#define FIELD_HEIGHT 480
#define BACKGROUND_PATH "../Assets/field.jpg"
#define PLAYER_RADIUS 15
#define PLAYERS_INITIAL_POSITION "./players_initial_position.txt"
#define NUMBER_OF_TEAM_PLAYERS 5
#define PLAYER1_PATH "../Assets/Player1.png"
#define PLAYER2_PATH "../Assets/Player2.png"
#define GAME_DELAY 15
#define BALL_IMAGE "../Assets/ball.png"
#define BALL_RADIUS 10
#define BALL_INITIAL_X 400
#define BALL_INITIAL_Y 240
#define GAME_FONT "Assets/game_font.ttf"
#define FONT_SIZE 25
#define BLUE_SCORES_POS 160
#define RED_SCORES_POS 560
#define BLUE_TURN 0
#define RED_TURN 1
#define GAME_FPS 25
#define FRAME_DURATION 40
#define THROW_RADIUS 60
#define MAX_INITIAL_SPEED 300
#define FRICTION_ACC 20

struct position{
    double x;
    double y;
};

struct velocity{
    double x;
    double y;
};

#endif