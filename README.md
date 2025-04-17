# TemplaTin V1.1.2

TemplaTin is a basic template creator tool under development. This utility will create a template file that can save your time and it's completely language agnostic (i.e) you can create basic template files that will speed up your development process!

## Features

- Language agnostic template file creation
- Uses Standard Library functions
- Easy to use

## What's new with V1.1.2?

- Code optimizations done for memory access
- Added support for multiple file creation
- Organized Sources
- Added Config File support for Templatin

## Installation

- Right as of now as it is in testing you can test it by cloning the repo and run.

```
git clone https://github.com/Matthatter693/TemplaTin.git
```

- The Templatin currently follows the following path structure for the config and template files

```
HOME
├── .tinconf
└── .tindir
         └──templates
                ├── .cpptmp
                └── .ctmp
```

- The following make command will create config file structures and compile the source in build directory

```
make conf
make 
```

- Go to the build directory where all the object files and executables will be saved after compilation

```
cd build
```

- You can test the utility for C and C++ extension files with the default provided templates.This will create the files in PWD..

```
./tin file.c \\For C
./tin file.cpp \\For C++
```
- To clean up everything in the build directory run

```
make clean
```


