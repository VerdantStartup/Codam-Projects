void draw_line(int x0, int y0, int x1, int y1) {
		const int dx = x1 - x0;
		const int dy = y1 - y0;
		int x_step;
		int y_step;
		int error = 0;
		int current_x = x0;
		int current_y = y0;

    if (dx >= 0) {
        x_step = 1;
    } else {
        x_step = -1;
    }

    if (dy >= 0) {
			
        y_step = 1;
    } else {
        y_step = -1;
    }


    while (current_x != x1 || current_y != y1) {
        if (abs(dx) > abs(dy)) {
            current_x += x_step;
            error += abs(dy);
        } else {
            current_y += y_step;
            error += abs(dx);
        }

        if (error >= abs(dx)) {
            current_y += y_step;
            error -= abs(dx);
        }

        draw_pixel(current_x, current_y);
    }
}



static void iso(int x, int y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = x;
    previous_y = y;
    x = (previous_x - previous_y) * cos(0.523599);
    y = -z + (previous_x + previous_y) * sin(0.523599);
}


void drawLine(int x0, int y0, int x1, int y1) {
  // calculate the slope of the line
  int dx = x1 - x0;
  int dy = y1 - y0;

  // initialize the error term to compensate for the fractional part of the pixel location
  int error = 0;

  // determine the direction of the line
  int xstep = 1;
  if (dx < 0) {
    xstep = -1;
    dx = -dx;
  }

  int ystep = 1;
  if (dy < 0) {
    ystep = -1;
    dy = -dy;
  }

  // calculate the constants for the Bresenham algorithm
  int numerator = 2 * dy;
  int denominator = 2 * dx;
  int constant = numerator - dx;

  // start at the first pixel
  int x = x0;
  int y = y0;

  // draw the line one pixel at a time
  while (x != x1 || y != y1) {
    // plot the pixel at (x, y)
    plot(x, y);

    // update the error term
    error += constant;

    // determine the next pixel to draw
    if (error >= 0) {
      error -= denominator;
      y += ystep;
    }
    x += xstep;
  }

  // plot the final pixel to ensure that the line is drawn completely
  plot(x, y);
}
