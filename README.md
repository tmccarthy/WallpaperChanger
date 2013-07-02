# WallpaperChanger

A simple, command-line utility for changing and rotating through wallpapers in 
LXDE and XFCE.

## Usage

To switch to a wallpaper:

<pre>
wallpaperChanger &lt;path-to-wallpaper&gt;
</pre>

To go through a list of wallpapers:

<pre>
wallpaperChanger -p &lt;period-in-seconds&gt; &lt;path-to-wallpapers&gt;
</pre>

To cycle through a list of wallpapers:

<pre>
wallpaperChanger -r -p &lt;period-in-seconds&gt; &lt;path-to-wallpapers&gt;
</pre>

To shuffle a list of wallpapers, then cycle through them:

<pre>
wallpaperChanger -s -r -p &lt;period-in-seconds&gt; &lt;path-to-wallpapers&gt;
</pre>

## To compile: 

This application requires the Boost 
[filesystem](http://www.boost.org/doc/libs/1_54_0/libs/filesystem/doc/index.htm)
 and [system](http://www.boost.org/doc/libs/1_54_0/libs/system/doc/index.html)
libraries.

<pre>
cmake .
make
</pre>

## Known bugs

1. Referring to a wallpaper with a path containing the home folder symlink ("~")
   doesn't work.