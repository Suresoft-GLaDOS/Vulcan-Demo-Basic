int function(int x, int y) {
  int a,b ;

  a = x > y;
  b = x ==y;

  if(x == 10) {
      if (y == 10) {
        return 1;
      }
  } else if ( x==20 && y == 20) {
    return 1;
  }

  return 0;
}