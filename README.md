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
- Added Config File support for TemplaTin
- Added argument parsing functions

## Installation

- Right as of now as it is in development you can test it by cloning the repo.

```
git clone https://github.com/Matthatter693/TemplaTin.git
```

- The Templatin currently follows the following path structure for the config and template files.The template file should be named as .[lang file extenstion]tmp.It works irrespective of the programming languages.

```
HOME
├── .tinconf
└── .tindir
         └──templates
                ├── .cpptmp
                └── .ctmp
```

- The following make command will create config file structures and compile the source in build directory.Or you can create a file structure like the above mentioned file tree

```
make conf \\For building config file structure
make 
sudo make install \\this install in the bin path of the system
```

- Alternatively if you are in a debian based linux distribution you can run dpkg command to install and uninstall it and use make conf for creating essential directories

```
make conf
cd dist
sudo dpkg -i tin_1.1.2-1_amd64.deb
```

- You can test the utility for C and C++ extension files with the default provided templates.This will create the files in pwd or in the mentioned file path.

```
tin file.c \\For C
tin file.cpp \\For C++
```

- To clean up everything in the build directory run

```
make clean
```


