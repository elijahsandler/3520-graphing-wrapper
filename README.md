# GeoGrapher

## Overview
This project contains a UI for the Matplot++ graphing library, and is specifically focused on plotting geographical data (hence the name "GeoGrapher", which I thought was funny). It loads data from a csv using the commata library. 

## External Libraries
- [Matplot++](https://github.com/alandefreitas/matplotplusplus "Matplot++")
  - Matplot++ requires [gnuplot](http://www.gnuplot.info/ "gnuplot"), which looks like a virus, but isn't
- [Commata](https://github.com/furfurylic/commata "Commata"), a header only library for reading CSVs
  - Requires C++17

## `get_weather.py` and `worldcities_temp.csv`
`get_weather.py` (and `get_weather.ipynb`) scrape data from the [OpenWeather API](https://openweathermap.org/api "OpenWeather API") to get the median high and low temperatures for each city for the past year, as well as the total rainfall over the same period. These data points can be used in `main.cpp`. 

`get_weather.py` can be executed at the command line as "python get_weather.py _yourOpenWeatherAPIkey_". If you have Python installed, you might get a series of error messages telling you about libraries used in `get_weather.py`, but you should be able to install most of them with "pip install _library_". If it doesn't work, it's probably because the OpenWeather AI is touchy and annoying to deal with. If that happens, and your job is to assign a numerical value to my time and effort, please be kind. It works, I promise.
The command can also be run within the UI. 

## Using GeoGraphy
Run `main.cpp` and follow the prompts. After creating a plot, the program will prompt you to hit Enter. When you do, the plot you just made will disappear, and you'll be able to create another. The program currently supports histograms, scatterplots, and geobubble plots, where each city is graphed in its location, with the size of the bubble equal to a parameter you pass. 
