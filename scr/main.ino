#include <GyverOLED.h>
#include "bitmap.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

double lpfx, lpfy, lpfz;
double gx, gy;
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
Adafruit_MPU6050 mpu;


void setup() {
  Serial.begin(115200);
  Wire.setClock(800000L);
  mpu.begin();
  oled.init();
  oled.clear();
  oled.update();

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  lpfx = 0.94 * lpfx + 0.06 * a.acceleration.x;
  lpfy = 0.94 * lpfy + 0.06 * a.acceleration.y;
  gx = lpfx / 9.8;
  gy = lpfy / 9.8;

  if (gy >= 0.2) {
    oled.drawBitmap(0, 0, right1, 128, 64);
  }
  if (gy >= 0.4) {
    oled.drawBitmap(0, 0, right2, 128, 64);
  }
  if (gy >= 0.6) {
    oled.drawBitmap(0, 0, right3, 128, 64);
  }
  if (gy >= 0.8) {
    oled.drawBitmap(0, 0, right4, 128, 64);
  }

  if (gy <= -0.2) {
    oled.drawBitmap(0, 0, left1, 128, 64);
  }
  if (gy <= -0.4) {
    oled.drawBitmap(0, 0, left2, 128, 64);
  }
  if (gy <= -0.6) {
    oled.drawBitmap(0, 0, left3, 128, 64);
  }
  if (gy <= -0.8) {
    oled.drawBitmap(0, 0, left4, 128, 64);
  }

  if (gx >= 0.2) {
    oled.drawBitmap(0, 0, top1, 128, 64);
  }
  if (gx >= 0.4) {
    oled.drawBitmap(0, 0, top2, 128, 64);
  }
  if (gx >= 0.6) {
    oled.drawBitmap(0, 0, top3, 128, 64);
  }
  if (gx >= 0.8) {
    oled.drawBitmap(0, 0, top4, 128, 64);
  }


  if (gx <= -0.2) {
    oled.drawBitmap(0, 0, bottom1, 128, 64);
  }
  if (gx <= -0.4) {
    oled.drawBitmap(0, 0, bottom2, 128, 64);
  }
  if (gx <= -0.6) {
    oled.drawBitmap(0, 0, bottom3, 128, 64);
  }
  if (gx <= -0.8) {
    oled.drawBitmap(0, 0, bottom4, 128, 64);
  }




  oled.update();
  oled.clear();
}
