### !! IMPORTANT !!

Now that 3 months have passed, I have decided to declare this codebase the worst piece of software to glaze the internet. I am rebuilding this in a separate repository, which will be made public once the renderer is set up.

# Redward Cullen

SFML is used to render graphics, everything else is written by me

### Features (oversimplified)

1. Very easy to use and modular. Component architecture makes it very decoupled.

2. Cross platform

3. Rendering and logic on separate threads. A 2D engine so there wont ever be a case where graphics would ever be a bottleneck, but still, I did it because I could.

3. Sprites, ortho camera, input, Entity-Component, box collisions, scenes.



### To Do

1. Audio and gui. You can call sfml bindinigs to get them to work, but there is no engine support yet

2. Event System

3. Develop current features further

Check the wiki for detailed explanations and exact feature list.


While its perfectly cross platform, I haven't been able to get it to run on my WSL Ubuntu due to vcpkg related issues. I think its a WSL issue and it should definitely work. (Test and lmk)

# Build Instructions
### Windows
Go to the scripts folder and run ```gen.bat``` (first time set-up)

Then, ```drun.bat``` (debug build)

or ```run.bat``` (release build)

### Linux
Go to the scripts folder and run ```gen.sh``` (first time set-up)

Then, ```drun.sh``` (debug build)



You need vcpkg and you need to set the VCPKG_ROOT variable.

There is some code in sandbox to show you how to use the engine.
