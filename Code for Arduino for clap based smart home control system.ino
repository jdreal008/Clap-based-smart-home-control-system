const int soundPin = 2;
const int lightRelay = 8;
const int fanRelay = 9;

bool lightState = false;
bool fanState = false;

int clapCount = 0;
unsigned long firstClapTime = 0;
unsigned long lastClapTime = 0;
const unsigned long clapGap = 400;
const unsigned long windowTime = 1200;

bool waitingForClaps = false;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(lightRelay, OUTPUT);
  pinMode(fanRelay, OUTPUT);

  digitalWrite(lightRelay, HIGH);
  digitalWrite(fanRelay, HIGH);
  Serial.begin(9600);
}

void loop() {
  int sound = digitalRead(soundPin);

  if (sound == HIGH) {
    unsigned long now = millis();

    if (!waitingForClaps) {
      clapCount = 1;
      firstClapTime = now;
      waitingForClaps = true;
    } else if (now - lastClapTime > 50) {
      clapCount++;
    }
    lastClapTime = now;

    delay(50);
  }

  if (waitingForClaps && (millis() - firstClapTime > windowTime)) {
    Serial.print("Claps detected: ");
    Serial.println(clapCount);

    if (clapCount == 1) {
      lightState = !lightState;
      digitalWrite(lightRelay, lightState ? LOW : HIGH);
    } else if (clapCount == 2) {
      fanState = !fanState;
      digitalWrite(fanRelay, fanState ? LOW : HIGH);
    } else if (clapCount == 3) {
      lightState = !lightState;
      fanState = !fanState;
      digitalWrite(lightRelay, lightState ? LOW : HIGH);
      digitalWrite(fanRelay, fanState ? LOW : HIGH);
    }

    waitingForClaps = false;
    clapCount = 0;
  }
}
