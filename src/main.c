#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void)
{
   Display* display;
   Window window;
   XEvent event;
   const char *message = "Hello, World!";
   int screen_identifier;
 
   display = XOpenDisplay(NULL);

   if(display == NULL) 
   {
      fprintf(stderr, "Cannot open display\n");
      exit(1);
   }
 
   screen_identifier = DefaultScreen(display);
   window = XCreateSimpleWindow(display, RootWindow(display, screen_identifier), 10, 10, 100, 100, 1, BlackPixel(display, screen_identifier), WhitePixel(display, screen_identifier));
   
   XSelectInput(display, window, ExposureMask | KeyPressMask); //Tells the x11 server to report the events in the third paremeter.
   XMapWindow(display, window);
 
   while(1)
   {
		XNextEvent(display, &event); //Checks if any actions have been rasied within the window.

		if(event.type == Expose)
		{
		//Will try to figure out how the cario library organizes thes draw functions. 
		//	XFillRectangle(display, window, DefaultGC(display, screen_identifier), 20, 20, 10, 10);
		//	XDrawString(display, window, DefaultGC(display, screen_identifier), 10, 50, message, strlen(message));
		}
		
		if(event.type == KeyPress)
		{
			break;
		}
   }
 
   XCloseDisplay(display);
   return 0;
}
