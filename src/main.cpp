#include "main.h"

using namespace std;
using namespace pros;

Controller controls(E_CONTROLLER_MASTER);

// Vision vision_sensor(14, E_VISION_ZERO_CENTER);

void initialize(){
	lcd::initialize();
	pros::lcd::set_text(1, "Program running");
}

int x=0,y=0;
string color = "no colour";
string auton = "no auton";
bool status_checker(int x1, int x2, int y1, int y2){
	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		return true;
	}
	return false;
}
void auton_selector(){
	screen::erase();
	screen::set_eraser(COLOR_BLACK);
	screen_touch_status_s_t status;

	while (true){
		if (status.x != c::screen_touch_status().x && status.y != c::screen_touch_status().y){
			screen::erase();
			status = c::screen_touch_status();
			x=status.x;
			y=status.y;

			screen::set_pen(COLOR_RED);
			screen::draw_rect(0, 0, 100, 50);
			pros::c::screen_print_at(TEXT_LARGE, 10, 10, "RED");
			screen::set_pen(COLOR_BLUE);
			pros::c::screen_print_at(TEXT_LARGE, 400, 10, "BLYEU");
			screen::draw_rect(380, 0, 480, 50);

			screen::set_pen(COLOR_SLATE_GRAY);
			pros::c::screen_print_at(TEXT_MEDIUM, 1, 150, "Roller");
			pros::c::screen_print_at(TEXT_MEDIUM, 1, 200, "easy");
			screen::draw_rect(1, 150, 120, 250);

			pros::c::screen_print_at(TEXT_MEDIUM, 120, 150, "solo");
			pros::c::screen_print_at(TEXT_MEDIUM, 120, 200, "easy");
			screen::draw_rect(120, 150, 240, 250);

			pros::c::screen_print_at(TEXT_MEDIUM, 240, 150, "Solo");
			pros::c::screen_print_at(TEXT_MEDIUM, 240, 200, "hard");
			screen::draw_rect(240, 150, 360, 250);

			pros::c::screen_print_at(TEXT_MEDIUM, 360, 150, "Roller");
			pros::c::screen_print_at(TEXT_MEDIUM, 360, 200, "hard");
			screen::draw_rect(360, 150, 480, 250);

			if (status_checker(0,100,0,50)){
				color = "red";
			}
			else if (status_checker(380,480,0,50)){
				color = "blue";
			}
			else if (status_checker(360,480,150,200)){
				auton = "roller hard";
			}
			else if (status_checker(240,360,150,200)){
				auton = "hard solo";
			}
			else if (status_checker(120,240,150,200)){
				auton = "easy solo";
			}
			else if (status_checker(0,120,150,200)){
				auton = "roller easy";
			}

			screen::set_pen(COLOR_WHITE);
			if (color == "red"){
				c::screen_print_at(TEXT_LARGE, 100, 10, "selected red");
			}
			else if (color == "blue"){
				c::screen_print_at(TEXT_LARGE, 100, 10, "selected blue");
			}
			else{
				c::screen_print_at(TEXT_LARGE, 100, 10, "select a color");
			}

			if (auton == "roller easy"){
				c::screen_print_at(TEXT_LARGE, 0, 69, "selected easy roller");
			}
			else if (auton == "roller hard"){
				c::screen_print_at(TEXT_LARGE, 0, 69, "selected hard roller");
			}
			else if (auton == "hard solo"){
				c::screen_print_at(TEXT_LARGE, 0, 69, "selected hard solo");
			}
			else if (auton == "easy solo"){
				c::screen_print_at(TEXT_LARGE, 0, 69, "selected easy solo");
			}
			else{
				c::screen_print_at(TEXT_LARGE, 0, 69, "select an auton");
			}
			controls.set_text(0, 0, color);
			controls.set_text(0, 6, auton);
		}
	}
}

void disabled() {}
void competition_initialize() {}
void autonomous() {}
void opcontrol(){
	auton_selector();
	// vision_object_s_t goal = vision_sensor.get_by_size(0);

	while (true){
		controls.set_text(0, 0, "How did we get here?");

		/*
		goal = c::vision_get_by_size(14, 0);
		lcd::set_text(2, to_string(goal.x_middle_coord));
		lcd::set_text(3, to_string(goal.y_middle_coord));
		*/
	}
}
