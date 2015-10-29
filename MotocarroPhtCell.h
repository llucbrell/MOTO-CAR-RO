#include <Arduino.h>



class MotocarroEye {

  private:
    byte eye;
    int eyeRef;

  public:

    void setEye(byte pinEye) {
      // set pins
      eye = pinEye;

      // wake up pins!!!
      pinMode(eye, INPUT);

      eyeRef = analogRead(eye);
    }

    void setRef() {
      eyeRef = analogRead(eye);
    }

    int getRef(){
      return eyeRef;
    }

    int readLight() {
      return analogRead(eye);
    }

};
