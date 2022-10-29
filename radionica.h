#pragma once
#include "helper.h"
void RobotLine::radionica() {
  static int broj = 0;
  static bool prolazak = false;

  char simbol[10 + sizeof(char)];

  if (setup()) {
    armOpen();
  }

  if (broj < 5) {
    if (front() < 150) {
      if (broj == 0 || broj == 3 || broj == 4) {
        go(90, -90);
        delayMs(500);
        go(50, 50);
        delayMs(100);
      } else {
        go(-90, 90);
        delayMs(500);
        go(50, 50);
        delayMs(100);
      }
      broj += 1;
    }
    if (rightFront() < leftFront()) {
      if (rightFront() < 80) {
        go(50, 60);
      }
    } else if (rightFront() > leftFront()) {
      if (leftFront() < 80) {
        go(60, 50);
      }
    } else {
      go(80, 80);
    }
  } else if (!prolazak) {
    go(30, 0);
    delayMs(300);
    go(40, 40);
    delayMs(1200);
    go(-60, - 60);
    delayMs(1200);
    go(90, -90);
    delayMs(200);
    prolazak = true;
  } else if (prolazak && broj != 7) {
    if (front() < 120) {
      go(90, -90);
      delayMs(400);
      broj = 6;
    } else if (front() > 330 && leftFront() > 300 && broj == 6) {
      go(30, 100);
      delayMs(1000);
    } else {
      if (rightFront() < leftFront()) {
        if (rightFront() < 80) {
          go(50, 60);
        }
      } else if (rightFront() > leftFront()) {
        if (leftFront() < 60) {
          go(60, 50);
        }
      }  else if (!line(0) && !line(3) && !line(5) && !line(7)) {
        go(80, 80);
      } else {
        broj += 1;
      }
    }
  } else {
    stop();
    end();
  }

  sprintf(simbol, "%d", broj);
  display(simbol);
}
