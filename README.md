# zlog_example
This is a quick logging utility that wraps [zlog](https://github.com/HardySimpson/zlog).  

Why This Exists
---
Hopefully I can integrate this into future c/c++ projects so that I'm not stuck reimplementing a custom logging utility each time.  For c++, [log4cxx](https://logging.apache.org/log4cxx/latest_stable/) is not bad; zlog is a bit different in that it uses the syslog model (but fast.) To date I haven't found any good open-source logging libraries for c beyond zlog.

That said, zlog is not nearly as easy to setup and use as I would like it to be, which is why I made this template (so I don't have to run into all these stupid, little gotchas all over again! Can you tell I'm frustated?  I'm frustrated!)

How to Use
---
`make linux` will build and install into /opt/zlog_example/

`make debuglinux` will build and install into a local /bin directory

`make clean` will delete both release and debug stuff that we put there.

You can run the example program, athough all it does is write a line or two to a log file.  To use, build logger.c, logger.h, and zlog.conf with your app.  You'll need to tune the values in zlog.conf and perhaps logger.h to make sure the output filepath is the one you want, etc.

Additional Notes to Self
---
- You'll likely want to add some sort of async write functionality or log batching.
- Zlog is licensed under LGPL v2.1, which is why we have to link to the dynamic lib after building the zlog dependency.  In lieu of tossing those .so files into the standard places, the makefile drops it into the directory of the zlog_example assembly.  It then sets LD flags during the build to instruct the linker to look in $ORIGIN.
- The directory for the output file specified in zlog.conf actually has to exist otherwise zlog_init() breaks.
