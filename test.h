class Animation_base
{
private:
  int colors[3];
  int pixel_range_start = 0;
  int pixel_range_end = 0;
  int target_frametime = 100;
  int previous_millis = 0;
  int previous_frametime = 0;
  int loop_point = 10000;
  int current_step = 0;
  int strip_length = 0;
  /* -------------------------------- frametime ------------------------------- */
  void set_frametime_prev_frame(int frametime);
  int set_start_time_current_frame();
  int get_start_time_prev_frame();
  /* ----------------------------- animation data ----------------------------- */
  int set_strip_length(int number);
  int get_strip_length();
  int get_loop_point();
  int step();

public:
  Animation_base(int pixel_range_start, int pixel_range_end, int target_frametime, int loop_point, int strip_length);
  /* -------------------------------- frametime ------------------------------- */
  int set_target_frametime(int frametime);
  int get_target_frametime();
  int get_frametime_progress();
  int get_frametime_prev_frame();
  /* ------------------------------ pixel ranges ------------------------------ */
  void set_pixel_range(int start, int end);
  int set_pixel_range_start(int number);
  int get_pixel_range_start();
  int set_pixel_range_end(int number);
  int get_pixel_range_end();
  /* ----------------------------- animation data ----------------------------- */
  int get_step();
  int set_loop_point(int number);
  int reset_animation();
  int update_animation(bool render_now);
};
