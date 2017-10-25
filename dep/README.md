# sfw-AIE-Framework

[![Build status](https://ci.appveyor.com/api/projects/status/aq5538yyb232kbwb/branch/master?svg=true)](https://ci.appveyor.com/project/terryn-aie/sfw/branch/master)


Simple wrapper for GLFW/GLM/STB and OpenGL Loader.

# Installation

Only Windows is supported at this point in time.

## Windows

Download a release in the GitHub releases tab. You'll need to link against the
static library appropriate for your platform.

# Example Project

This example sets up a simple window and rendering context. A game loop is provided
that will automatically stop if the window is told to close.

Refer to the included [sfwdraw.h][sfwheader] for more documentation on the SFW API.

[sfwheader]:nsfw2draw/sfwdraw.h

```C++
#include "sfwdraw.h"

int main()
{
        // Create the window and drawing context
        sfw::initContext(800, 600, "NSFW Draw");
        
        // Assign the default background/clear color
        sfw::setBackgroundColor(BLACK);

        // Establish the game loop
        while (sfw::stepContext())
        {
                // game code goes here
        }

        // Clean up any dynamically allocated objects
        sfw::termContext();
}
```

# Contact

Contact Esmeralda Salamone at esmes@aie.edu.au for any complaints/feature requests.

# License

Copyright (c) 2016-2017 Academy of Interactive Entertainment All rights reserved.
