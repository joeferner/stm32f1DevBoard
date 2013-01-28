
#include <wirish/wirish.h>

void setup() {
  Serial1.begin(9600);
  Serial1.println("begin");
  pinMode(PA0, OUTPUT);
}

void loop() {
  togglePin(PA0);
  Serial1.println("loop");
  delay(1000);
}

// Force init to be called *first*, i.e. before static object allocation.
// Otherwise, statically allocated objects that need libmaple may fail.

__attribute__((constructor)) void premain() {
  init();
}

int main(void) {
  setup();

  while (true) {
    loop();
  }

  return 0;
}
