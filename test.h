class Animation_base
{
private:
  int colors[3];
  int pixel_range_start = 0;
  int pixel_range_end = 0;
  int target_frametime = 100;
  int previous_millis = 0;
  int loop_point = 10000;
  int current_step = 0;
  int strip_length = 0;
  int set_strip_length(int number);
  int get_strip_length();
  int get_loop_point();
  int step();
  int get_step();
  int get_time_prev_frame();

public:
  Animation_base(int pixel_range_start, int pixel_range_end, int target_frametime, int loop_point);
  int set_target_frametime(int frametime);
  int get_target_frametime();
  int get_real_frametime();
  void set_pixel_range(int start, int end);
  int set_pixel_range_start(int number);
  int get_pixel_range_start();
  int set_pixel_range_end(int number);
  int get_pixel_range_end();

  int set_loop_point(int number);
  int reset_animation();
  int update_animation();
};
