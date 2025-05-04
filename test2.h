class Animation_base
{
private:
  int colors[10];
  int frametime = 100;
  int loop_point = 10000;
  int current_animation_time = 0;
  int led_amount = 0;
  int running = 0;

public:
  Animation_base();

  // void init();
  // void frame_limiter();
  // void update();
};
