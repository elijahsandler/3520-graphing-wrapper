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
    return (kelvin_temp - 273.15) * 9/5 + 32

def get_yearly_weather_data(api_key, lat, lon):
    base_url = "http://example-api.com/historical-weather"  # Replace with the actual API endpoint
    params = {
        'lat': lat,
        'lon': lon,
        'appid': api_key,
        'start_date': '2022-01-01',  # Replace with the start date for the past year
        'end_date': '2022-12-31',    # Replace with the end date for the past year
    }

    response = requests.get(base_url, params=params)

    if response.status_code == 200:
        data = response.json()

        high_temps_kelvin = [entry['high_temperature'] for entry in data['list']]
        low_temps_kelvin = [entry['low_temperature'] for entry in data['list']]
        total_rainfall = sum(entry['rainfall'] for entry in data['list'])

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
    api_key = "852c39dbb0207981c036677327cf4947"
try:
    for idx in tqdm(df_cities.index, desc='collecting weather data', colour='#7ba67e'):
        high, low, rain = get_yearly_weather_data(api_key, df_cities.loc[idx, 'lat'], df_cities.loc[idx, 'lng'])
        df_cities.loc[idx, ['low_temp', 'high_temp', 'rain']] = temp
except:
    pass


# In[ ]:


df_cities.to_csv('worldcities_temp.csv')

