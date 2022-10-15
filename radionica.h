#pragma once
#include "helper.h"
void RobotLine::radionica() {
  // ZADATAK: uvedite varijablu brojača.
  // HINT: static int nazivVarijable = vrijednost;
  static int broj = 0;
  static bool prolazak = false;


  // VARIJABLA ZA PRETVORBU BROJA U TEKST
  char simbol[10 + sizeof(char)];

  // ZADATAK: skretanje s povećanjem brojača
  // HINT: prekopirajte iz prijašnjeg zadatka i dodajte brojač

  if (setup()) {
    armOpen();
  }

  if (broj < 5) {
    if (front() < 150) {
      if (broj == 0 || broj == 3 || broj == 4) {
        go(100, -100);
        delayMs(400);
      } else {
        go(-100, 100);
        delayMs(400);
      }
      broj += 1;
    }
    if (rightFront() < 100) {
      go(50, 60);
    }
    if (leftFront() < 100) {
      go(60, 50);
    }
    if (leftFront() > 150 && rightFront() > 150) {
      go(60, 60);
    }
  } else if (!prolazak) {
    go(50, 50);
    delayMs(1200);
    go(-50, - 50);
    delayMs(1200);
    go(100, -100);
    delayMs(400);
    prolazak = true;
  }else if (prolazak){
    go(100, 100);
    delayMs(1000);
  }else {
    stop();
    end();
  }

  // PRETVORBA VARIJABLE BROJAČA U TEKST
  sprintf(simbol, "%d", broj);
  // ZADATAK: prikažite simbol
  display(simbol);
}
