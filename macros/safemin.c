// X and Y only calculated once
#define min(X, Y)                     \
({ typeof (X) __x = (X); \
  typeof (Y)  __y = (Y);   \
   (__x < __y) ? __x : __y; })