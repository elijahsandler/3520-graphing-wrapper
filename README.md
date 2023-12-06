# GeoGrapher

## Overview
This project contains a UI for the Matplot++ graphing library, and is specifically focused on plotting geographical data (hence the name "GeoGrapher", which I thought was funny). It loads data from a csv using the commata library. 

## External Libraries
- [Matplot++](https://github.com/alandefreitas/matplotplusplus "Matplot++")
  - Matplot++ requires [gnuplot](http://www.gnuplot.info/ "gnuplot"), which looks like a virus, but isn't
- [Commata](https://github.com/furfurylic/commata "Commata"), a header only library for reading CSVs
  - Requires C++17

## `get_weather.py` and `worldcities_temp.csv`
`get_weather.py` scrapes data from the [OpenWeather API](https://openweathermap.org/api "OpenWeather API") to get the high and low temperatures for each city for today, as well as the  rainfall over the same period, the change of precipitation, and the phase of the moon. These data points can be used in `main.cpp`. 

`get_weather.py` can be excuted in the UI by using the "update" option, which will prompt you to enter your OpenWeather API key. The script is slow, and takes about six minutes to run to completion because of the API's query limits. Progress can be tracked by the tqdm progress bar that appears, but the library isn't configured to run in the terminal so it'll be a little weird. 

## Using GeoGraphy
Run `main.cpp` and follow the prompts. After creating a plot, the program will prompt you to hit Enter. When you do, the plot you just made will disappear, and you'll be able to create another. The program currently supports histograms, scatterplots, and geobubble plots, where each city is graphed in its location, with the size of the bubble equal to a parameter you pass. 
