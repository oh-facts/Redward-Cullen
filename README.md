# Yekate

Yekate is the successor of Ball;Square, my previous engine. So, you can call Yekate as BS2 if you want.

It uses sfml for now and uses an ECS paradigm, although its quite different from regular ECS. Main reason being that I need to make more games with it before I can decide what architecture suits it best. Its very simple to use and very modular.

While its perfectly cross platform, I haven't been able to get it to run on my WSL Ubuntu due to vcpkg related issues. I think its a WSL issue and it should ideally work. (Test and lmk)

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
