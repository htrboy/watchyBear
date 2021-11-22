//#define GREY 0x7BEF
//#define DARK_GREY 0x7BEE
//#define LIGHT_GREY 0x7BED

void Watchy999::drawBearWatchFace() {

  display.fillScreen(GxEPD_WHITE);
  display.drawBitmap(0, 0, SoB_cf_inv, DISPLAY_WIDTH, DISPLAY_HEIGHT, GxEPD_BLACK);

  int randomX1 = 0;
  int randomY1 = 0;
  int randomX2 = 0;
  int randomY2 = 0;

  randomX1 = random(5, 40);
  randomX2 = random(130, 165);
  randomY1 = random(10, 50);
  randomY2 = random(60, 125);

  display.drawBitmap(randomX1, randomY1, bee1, 27, 24, GxEPD_BLACK);
  display.drawBitmap(randomX2, randomY1, bee2_inv, 23, 25, GxEPD_BLACK);
  display.drawBitmap(randomX2, randomY2, bee3_inv, 23, 24, GxEPD_BLACK);

  int currentMinute = latestTime.minStr.toInt();
  int currentHour = latestTime.hourStr.toInt(); // adjusted local time

  // drawHand(offset, width, length, angle)
  // Minute
  drawBearHand(60, 4, 50, currentMinute / 60.0 * -3.1415926 * 2);
  // Hour
  drawBearHand(60, 4, 30, (currentHour + currentMinute / 60.0) / 12.0 * -3.1415926 * 2);
}

// Tweaked the filled triangle function by HN3000 for the hands
// offset is distance from center, 0 = xc/yc centers defined in function
// width is final rect. width 0=narrowest
void Watchy999::drawBearHand(int16_t rOffset, int16_t width, int16_t len, float angle) {

  //xo = dist (radius) from center
  const int16_t xo = (rOffset * sin(angle));
  const int16_t yo = (rOffset * cos(angle));

  const int16_t xc = 100; // X center
  const int16_t yc = 100; // Y center

  int16_t xe = floor(-len * sin(angle));
  int16_t ye = floor(-len * cos(angle));

  int16_t xb = round(-ye / (len / width));
  int16_t yb = round(xe / (len / width));

  xe += (xc - xo);
  ye += (yc - yo);

  //display.drawLine(xc, yc, xe, ye, (_darkMode? GxEPD_BLACK : GxEPD_WHITE));
  display.fillTriangle(xc - xb - xo, yc - yb - yo, xc + xb - xo, yc + yb - yo, xe + xb, ye + yb, GxEPD_BLACK);
  display.fillTriangle(xc - xb - xo, yc - yb - yo, xe + xb, ye + yb, xe - xb, ye - yb, GxEPD_BLACK);
}
