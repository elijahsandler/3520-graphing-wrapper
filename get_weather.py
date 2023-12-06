#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import requests
from tqdm import tqdm
import statistics
import sys


# In[4]:


def kelvin_to_fahrenheit(kelvin_temp):
def kelvin_to_fahrenheit(kelvin_temp):
    return (kelvin_temp - 273.15) * 9/5 + 32

def get_yearly_weather_data(api_key, lat, lon):
    base_url = "http://api.openweathermap.org/data/2.5/onecall/timemachine"
    params = {
        'lat': lat,
        'lon': lon,
        'appid': api_key,
        'start': 1640995200,
        'end': 1641067200,   
    }

    response = requests.get(base_url, params=params)

    if response.status_code == 200:
        data = response.json()

        high_temps_kelvin = [entry['temp']['max'] for entry in data['hourly']]
        low_temps_kelvin = [entry['temp']['min'] for entry in data['hourly']]
        total_rainfall = sum(entry['rain']['1h'] if 'rain' in entry else 0 for entry in data['hourly'])

        high_temps_fahrenheit = [kelvin_to_fahrenheit(temp) for temp in high_temps_kelvin]
        low_temps_fahrenheit = [kelvin_to_fahrenheit(temp) for temp in low_temps_kelvin]

        median_high_temp = statistics.median(high_temps_fahrenheit)
        median_low_temp = statistics.median(low_temps_fahrenheit)

        return median_high_temp, median_low_temp, total_rainfall
    else:
        return None, None, None


# In[ ]:


df_cities = pd.read_csv('worldcities.csv')
df_cities = df_cities[df_cities.index < 500]


# In[ ]:


cap_dict = dict(zip(df_cities['capital'].unique(), range(int(4))))
df_cities['capital'].replace(cap_dict, inplace=True)


# In[ ]:


try:
    api_key = sys.argv[1]
except(IndexError):
    api_key = "60d37b0c7315fd2976c8042ba444c932"
try:
    for idx in tqdm(df_cities.index, desc='collecting weather data', colour='#7ba67e'):
        high, low, rain = get_yearly_weather_data(api_key, df_cities.loc[idx, 'lat'], df_cities.loc[idx, 'lng'])
        df_cities.loc[idx, ['low_temp', 'high_temp', 'rain']] = [high, low, rain]
except:
    pass


# In[ ]:


df_cities.to_csv('worldcities_temp.csv')

