import pandas as pd
import requests
from tqdm import tqdm
import statistics
import sys



def kelvin_to_fahrenheit(kelvin_temp):
    return (kelvin_temp - 273.15) * 9/5 + 32

def get_weather_data(api_key, lat, lon): 
    url = f"https://api.openweathermap.org/data/3.0/onecall?lat={lat}&lon={lon}&appid={api_key}&units=imperial"

    response = requests.get(url)

    data = response.json()
    
    return data

    low = data['daily'][0]['temp']['min']
    high = data['daily'][0]['temp']['max']
    rain = data['daily'][0]['rain']

    return high, low, rain




df_cities = pd.read_csv('..\worldcities.csv')
df_cities = df_cities[df_cities.index < 500]


cap_dict = dict(zip(df_cities['capital'].unique(), range(int(4))))
df_cities['capital'].replace(cap_dict, inplace=True)

api_key = sys.argv[1]
try:
    for idx in tqdm(df_cities.index, desc='collecting weather data', colour='#7ba67e'):
        high, low, rain = get_weather_data(api_key, df_cities.loc[idx, 'lat'], df_cities.loc[idx, 'lng'])
        df_cities.loc[idx, ['low_temp', 'high_temp', 'rain']] = [high, low, rain]
    df_cities.to_csv('worldcities_temp.csv')
except Exception as e:
    print(f"Error accessing API: {e}\n")

