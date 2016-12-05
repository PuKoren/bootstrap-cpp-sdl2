# bootstrap-cpp-sdl2
cpp/sdl2 bootstrap project structure and files, to clone and start coding

# How to use
.1 Clone the repo
```
git clone git@github.com:PuKoren/bootstrap-cpp-sdl2.git
```

.2 Init script
```
make init NAME=project_name
```

.3 Change origin to your repo URL
```
git remote set-url origin git@github.com:{handle}/{repo-name}.git
```

.4 Push to your repo
```
git push -f
```

.5 Build & run
Open the project in your favorite IDE or use the provided Makefile
```
make build
make run
```

.6 Start coding
Go to `src/Application.cpp` and add your logic

# Commands
## Build
```
make build
make release
```

## Run
```
make run
```

## Lint, format code, test
```
make lint
make format
make tests
```

# Dependencies
## Core (until Dockerfile is done)
```
sudo pacman -S sdl2 sdl2_image sdl2_ttf
```

## Lint and tests (until Dockerfile is done)
Used for linting and unit tests
```
sudo pacman -S clang-tools-extra cppunit
```