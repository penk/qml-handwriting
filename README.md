# QML Handwriting 

![qml-handwriting](https://github.com/penk/qml-handwriting/raw/master/asset/screenshot.png)

### Open source handwriting recognition keyboard based on Qt/QML

Built out of QML, ShortStrawJS and Zinnia.

## Features 

* Pure QML-based layout, can integrate with input method panel 
* Supports Chinese (Traditional/Simplified) and Japanese, models and engines from Zinnia
* Strokes detection and recognition based on ShortStraw algorithm 

## How to Install

1. Install [Zinnia](http://zinnia.sourceforge.net/) library 
2. Install QML [Canvas](http://qt.gitorious.org/qt-labs/qmlcanvas) plugin 
3. Check-out source code and compile: `git clone https://github.com/penk/qml-handwriting.git`
4. Download [handwriting models](http://www.tegaki.org/releases/0.3/models/), default path is `/usr/share/tegaki/models/zinnia/handwriting-zh_TW.model`

## License

The source codes are, unless otherwise specified, distributed under the terms of the GNU Lesser General Public License. 

## Credits 

Copyright (C) 2012 Ping-Hsun Chen <[penkia@gmail.com](mailto:penkia@gmail.com)>, [@penk](https://twitter.com/penk)

Includes: 

* [ShortStrawJS](http://www.lab4games.net/zz85/blog/2010/01/21/geeknotes-shortstrawjs-fast-and-simple-corner-detection/) by [Joshua Koo](mailto:zz85nus@gmail.com) 
* [qmlcanvas](http://qt.gitorious.org/qt-labs/qmlcanvas/) by Qt Labs
* Zinnia models from [Tegaki](http://tegaki.org) project 
