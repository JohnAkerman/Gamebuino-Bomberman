byte playervxStart;
byte playervyStart;
byte playerscore;

Entity player;

void initPlayer() {
  player.x = 4;
  player.y = 4;
  player.w = 4;
  player.h = 4;
  player.vx = 2;
  playervxStart = player.vx;
  player.vy = 2;
  playervyStart = player.vy;
  playerscore = 0;
}

void renderPlayer() {
   gb.display.fillRect(player.x, player.y, player.w, player.h); 
   gb.display.setColor(WHITE);
   gb.display.drawPixel(player.x+1, player.y+1);
   gb.display.drawPixel(player.x+2, player.y+2);
   gb.display.setColor(BLACK);
}