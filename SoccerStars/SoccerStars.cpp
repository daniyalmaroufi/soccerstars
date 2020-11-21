#include "SoccerStars.hpp"

SoccerStars::SoccerStars() {
    blue_goals = 0;
    red_goals = 0;
    blue_rounds = 0;
    red_rounds = 0;
    quit = false;
    turn = BLUE_TURN;
    selected_player = NULL;
}

void SoccerStars::get_rounds_number() {
    cout << "Enter the Number of rounds:";
    cin >> rounds_number;
    rounds_number = (rounds_number + 1) / 2;
}
void SoccerStars::get_goals_number() {
    cout << "Enter the Number of goals:";
    cin >> goals_number;
}

void SoccerStars::read_initial_players_position() {
    ifstream fin;
    fin.open(PLAYERS_INITIAL_POSITION);
    int x, y;
    for (int i = 0; i < NUMBER_OF_TEAM_PLAYERS; i++) {
        fin >> x >> y;
        blue_players.push_back(new Player(Point(x, y), PLAYER1_PATH));
    }
    for (int i = 0; i < NUMBER_OF_TEAM_PLAYERS; i++) {
        fin >> x >> y;
        red_players.push_back(new Player(Point(x, y), PLAYER2_PATH));
    }

    fin.close();
}

void SoccerStars::run() {
    initialize_game();
    // draw();
    run_the_game();
}

void SoccerStars::initialize_game() {
    win = new Window(GAME_WIDTH, GAME_HEIGHT, GAME_NAME);
    ball = new Ball(Point(BALL_INITIAL_X, BALL_INITIAL_Y));
}

void SoccerStars::set_up_background() {
    win->draw_img(BACKGROUND_PATH, get_field_box());
    return;
}

Rectangle SoccerStars::get_field_box() {
    Point top_left(0, 0);
    Point bottom_right(GAME_WIDTH, FIELD_HEIGHT);
    return Rectangle(top_left, bottom_right);
}

void SoccerStars::show_scores() {
    win->show_text(
        "Goals: " + to_string(blue_goals) + "/" + to_string(goals_number),
        Point(BLUE_SCORES_POS, FIELD_HEIGHT + 5), WHITE, GAME_FONT, FONT_SIZE);
    win->show_text(
        "Goals: " + to_string(red_goals) + "/" + to_string(goals_number),
        Point(RED_SCORES_POS, FIELD_HEIGHT + 5), WHITE, GAME_FONT, FONT_SIZE);
}

void SoccerStars::release_all_alloc_memory() {
    delete win;
    delete ball;
    release_players(blue_players);
    release_players(red_players);
}

void SoccerStars::release_players(vector<Player*> players) {
    for (auto player : players) delete player;
}

void SoccerStars::draw() {
    win->clear();
    set_up_background();
    ball->draw(win);
    draw_players();
    show_scores();
    win->update_screen();
}

void SoccerStars::draw_players() {
    for (auto player : blue_players) player->draw(win);
    for (auto player : red_players) player->draw(win);
}

Player* SoccerStars::find_player_by_pos(vector<Player*> players, Point pos) {
    for (auto player : players)
        if (player->is_in_pos(pos)) {
            return player;
        }
    return NULL;
}

Player* SoccerStars::select_player(Point mouse_click_pos) {
    if (turn == BLUE_TURN) {
        return find_player_by_pos(blue_players, mouse_click_pos);
    }
    if (turn == RED_TURN) {
        return find_player_by_pos(red_players, mouse_click_pos);
    }
}

void SoccerStars::toggle_turn() {
    if (turn == BLUE_TURN)
        turn = RED_TURN;
    else
        turn = BLUE_TURN;
}

void SoccerStars::handle_events() {
    Event event = win->poll_for_event();
    switch (event.get_type()) {
        case Event::LCLICK:
            selected_player = select_player(event.get_mouse_position());
            break;
        case Event::LRELEASE:
            if (selected_player) {
                // selected_player->move_to_pos(event.get_mouse_position());
                throw_selected_player(event.get_mouse_position());
                toggle_turn();
            }
            selected_player = NULL;
            break;
        case Event::QUIT:
            quit = true;
            break;
    }

    if (quit) quit_game();
}

void SoccerStars::throw_selected_player(Point mouse_release_pos) {
    velocity v = calculate_initial_velocity(selected_player->get_position(),
                                            mouse_release_pos);
}

velocity SoccerStars::calculate_initial_velocity(Point from_pos, Point to_pos) {
    Point throw_vector;
    throw_vector.x = from_pos.x - to_pos.x;
    throw_vector.y = from_pos.y - to_pos.y;
    double distance = sqrt(pow(throw_vector.x, 2) + pow(throw_vector.y, 2));
    velocity v;
    if (distance < THROW_RADIUS) {
        v.x = -throw_vector.x * MAX_INITIAL_SPEED / THROW_RADIUS;
        v.y = -throw_vector.y * MAX_INITIAL_SPEED / THROW_RADIUS;
    } else {
        v.x = -throw_vector.x * MAX_INITIAL_SPEED / distance;
        v.y = -throw_vector.y * MAX_INITIAL_SPEED / distance;
    }
    return v;
}

void SoccerStars::run_the_game() {
    while (!any_team_won()) {
        while (!any_team_won_in_round()) {
            play_round();
            if (quit) return;
            delay(GAME_DELAY);
        }
    }
}

void SoccerStars::play_round() {
    draw();
    handle_events();
}

bool SoccerStars::any_team_won() {
    if (blue_rounds == rounds_number) return true;
    if (red_rounds == rounds_number) return true;
    return false;
}

bool SoccerStars::any_team_won_in_round() {
    return check_blue_rounds() || check_red_rounds();
}

bool SoccerStars::check_blue_rounds() {
    if (blue_goals == goals_number) {
        blue_rounds++;
        blue_goals = 0;
        return true;
    } else
        return false;
}

bool SoccerStars::check_red_rounds() {
    if (red_goals == goals_number) {
        red_rounds++;
        red_goals = 0;
        return true;
    } else
        return false;
}

void SoccerStars::quit_game() {
    release_all_alloc_memory();
    SDL_Quit();
}