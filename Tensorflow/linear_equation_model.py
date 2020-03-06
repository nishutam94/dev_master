
from __future__ import absolute_import, division, print_function, unicode_literals
import os
import tensorflow as tf
from tensorflow import keras
import numpy as np
print(tf.version.VERSION)

def create_model():
	model = tf.keras.Sequential([keras.layers.Dense(units=1, input_shape=[1])])
	model.compile(optimizer='sgd', loss='mean_squared_error')
	return model
model = create_model()
model.summary()

checkpoint_path = "/root/nishant/test/cp.ckpt"
checkpoint_dir = os.path.dirname(checkpoint_path)

xs = np.array([-1.0, 0.0, 1.0, 2.0, 3.0, 4.0], dtype=float)
ys = np.array([-2.0, 1.0, 4.0, 7.0, 10.0, 13.0], dtype=float)

x = np.array([-1.0, 1.0, 1.0, 2.0, 4.0, 4.0])
y = np.array([-2.0, 1.0, 4.0, 7.0, 10.0, 13.0])
#cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_path,save_weights_only=True,verbose=1)
#model.fit(xs, ys, epochs=500,validation_data=(xs, ys),callbacks=[cp_callback])
model.fit(xs, ys, epochs=500)
model.save('saved_model/test_model')
model.summary()
#print(model.predict([10.0]))

new_model = tf.keras.models.load_model('saved_model/test_model')
new_model.summary()
acc = new_model.evaluate(x, y, verbose=2)
print('Restored model, accuracy: {:5.2f}%'.format(100*acc))
print(new_model.predict([10.0]))