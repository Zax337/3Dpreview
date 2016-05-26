# 3Dpreview

This program is a simple 3D preview using Qt. The aim is to allow the user to load a pre-existing design to get an idea of its 3D representation. There is virtual bed toggle option to visualize the scale.

### Compilation
You first need to run qmake at the root of the project to generate a Makefile. Please note that Qt5.6 or higher is required.

```sh
$ qmake src/3DPreview.pro
$ make
```

### Run!
At the root of the project an executable named `3DPreview` is now available. Have fun with it!
