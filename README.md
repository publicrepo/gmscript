##GameMonkey Script
**What is GameMonkey Script?**  
GameMonkey is a embedded scripting language that is intended for use in game and tool applications. GameMonkey is however suitable for use in any project requiring simple scripting support. GameMonkey borrows concepts from Lua (www.lua.org), but uses syntax similar to C, making it more accessible to game programmers. GameMonkey also natively supports multithreading and the concept of states.

**Can I use GameMonkey freely in my hobby or work project?**  
Yes, GameMonkey is distributed under the MIT license and is free for any use including commercial products. Please read the full license included in the download package.

**What are the key features of GM?**  

* Small code base. Compiled code may use about 75kb of RAM. Less when tweaking or sharing with application.
* Compile source code at run time, or link to precompiled libs.
* Lightweight, native threading (coroutines).
* Soft real-time incremental garbage collection. Controllable memory footprint. No painful reference counting.
* Easy to bind C\C++ functions and call script from C\C++.
* Runtime debugging and reflexion support.
* C style syntax.
* Competitive performance when compared to other scripting languages for both CPU and Memory usage. Speed is a trade off for flexibility and simplicity.
* Easily modifiable as it is written in C++ and uses Flex and Bison.

**What does the script code look like?**  
Here is some script code that calls functions bound in C:

```
OnDoorTriggerEnter = function(door, objEntering)
{
  if(objEntering == player && !door.IsOpen())
  {
    door.Open();
    return true;
  }
  return false;
};
```

**How do I bind a new script function in C?**  
Here is an example of binding a script function in C:

```
// Use in script as: DebugText(int x, int y, string text)
int GM_CDECL DebugText(gmThread *a_thread)
{
  GM_CHECK_NUM_PARAMS(1);
  GM_CHECK_STRING_PARAM(text, 2);
  GM_INT_PARAM(x, 0, 10);
  GM_INT_PARAM(y, 1, 10);
  
  Font::Text(text, (float) x, (float) y);
  
  return GM_OK;
}
```

**How easy is it to call script from C?**  
Here is some C code calling a script function:

```
#include "gmMachine.h"
#include "gmCall.h"   // Header contains helper class

extern gmMachine machine;   // Virtual Machine instance

// Attempts to call a function int Add(int, int) in script
int AddTwoIntegers(int valueA, int valueB)
{
  int resultInt = 0;

  gmCall call;

  if(call.BeginGlobalFunction(&machine, "Add"))
  {
    call.AddParamInt(valueA);
    call.AddParamInt(valueB);
    call.End();
    call.GetReturnedInt(resultInt);
  }

  return resultInt;
}
```

**What platforms does GameMonkey run on?**  
Written entirely in C++, it should run on any platform with at most minor modification or configuration. It has been successfully compiled and run on: Windows PC, Apple Mac, Microsoft XBox, Sony PlayStation2, Sony PSP and Nintendo GameCube. 
