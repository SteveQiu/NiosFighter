#include <stdio.h>
//#define DEBUG_FLAG 1

#ifdef DEBUG_FLAG
#define DEBUGMSG(x); printf(x);
#define DEBUGVAL(x,y); printf(x,y);

#else

#define DEBUGMSG(x);
#define DEBUGVAL(x,y);
#endif //DEBUG_FLAG
