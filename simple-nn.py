import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
import random
import pandas as pd
tf.keras.utils.disable_interactive_logging()

class CategoricalNN:
    def __init__(self, input_size, output_size):
        self.input_size = input_size # number of inputs the agents take
        self.output_size = output_size # number of outputs the agents has to choose from
        self.model = self.build_model()
        
    def build_model(self):
        # builds a simple nn for regression with two hidden layers
        model = Sequential()
        model.add(Dense(16, input_dim=self.input_size, activation='relu'))
        model.add(Dense(8, activation='relu'))
        model.add(Dense(self.output_size, activation='linear'))
        model.compile(optimizer=tf.keras.optimizers.Adam(), loss=tf.keras.losses.MeanSquaredError())
        return model
    
    def fit(self, inputs, targets):
        
        inputs = np.array(inputs, dtype=np.float32)
        targets = np.array(targets, dtype=np.float32)
        
        # trains the model
        self.model.fit(inputs, targets, epochs=1)

def generate_dummy_data(num_samples=1000):
    # Generate random input features
    X = np.random.rand(num_samples, 3)  # You can modify the shape based on your input features

    # Generate corresponding output labels with some noise for regression
    noise = np.random.normal(0, 0.1, size=(num_samples, 1))
    y = np.sum(X * np.arange(1, 4), axis=1, keepdims=True) + noise

    return X, y

x, y = generate_dummy_data(10000)

nn = RegressionNN(3, 1)
nn.fit(x, y)

model.save('regression_nn.keras')