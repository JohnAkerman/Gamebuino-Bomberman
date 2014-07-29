#define BOMB_MAX 3

typedef struct {
  boolean active;
  byte x;
  byte y;
  unsigned long startTime;
} Bomb;

Bomb bombs[BOMB_MAX];

void initBombs() {
   for (int i = 0; i < BOMB_MAX; i++ ) {
     bombs[i].active = false;    
   }
}
void setBomb(byte x, byte y) {
   for (int i= 0; i < BOMB_MAX; i++) {     
      if (bombs[i].active) continue; 
      
      Bomb b;
      b.active = true;
      b.x = (round(x/4) * 4);
      b.y = (round(y/4) * 4);
      b.startTime = millis();
      bombs[i] = b;
      break;
   }
}

void renderBombs() {
  for (int i = 0; i < BOMB_MAX; i++) {
      if (!bombs[i].active) continue;
      
      Bomb *b = &bombs[i];
      if (gb.frameCount % 25) {
        gb.display.fillRect(b->x+1,b->y, 2,1); // top  
        gb.display.fillRect(b->x,b->y+1,1,2); // left  
        gb.display.fillRect(b->x+1,b->y+3, 2,1); // bottom
        gb.display.fillRect(b->x+3,b->y+1, 1,2); // right
      }
  }
}

void updateBombs() {
  for (int i = 0; i < BOMB_MAX; i++) {
      if (!bombs[i].active) continue;
      Bomb *b = &bombs[i];
  
      if ((millis() - b->startTime) >= 5000) {
         b->active = false; 
         bombExplode(b->x, b->y);
      } 
  }
}

