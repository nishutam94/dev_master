from __future__ import absolute_import, division, print_function, unicode_literals
import numpy as np
import tensorflow as tf
import tensorflow_hub as hub
import tensorflow_datasets as tfds
import logging

logging.basicConfig(filename='test_classification.log',level=logging.DEBUG)
logging.debug('Debugger msg')

tf.compat.v1.enable_eager_execution(config=None, device_policy=None, execution_mode=None)
logging.warning('eger mode enable mannualy')

print(tf.version.VERSION)
print("Eager mode: ", tf.executing_eagerly())

train_data, validation_data, test_data = tfds.load(name="imdb_reviews", split=('train[:60%]', 'train[60%:]', 'test'),as_supervised=True)
train_examples_batch, train_labels_batch = next(iter(train_data.batch(10)))
print(train_examples_batch)
print(train_labels_batch)	

logging.info('DATA LOADING DONE')
'''
embed = hub.load("https://tfhub.dev/google/tf2-preview/gnews-swivel-20dim/1")
embeddings = embed(["cat is on the mat", "dog is in the fog","howcan i help you"])
print(embeddings)	
'''

embedding = "https://tfhub.dev/google/tf2-preview/gnews-swivel-20dim/1"
hub_layer = hub.KerasLayer(embedding, input_shape=[], dtype=tf.string, trainable=True)
print(hub_layer(train_examples_batch[:3]))
logging.info('CREATING EMBEDDINGS')

model = tf.keras.Sequential()
model.add(hub_layer)
model.add(tf.keras.layers.Dense(16, activation='relu'))
model.add(tf.keras.layers.Dense(1))
print(model.summary())

model.compile(optimizer='adam',loss=tf.keras.losses.BinaryCrossentropy(from_logits=True), metrics=['accuracy'])
history = model.fit(train_data.shuffle(10000).batch(512),epochs=1,validation_data=validation_data.batch(512),verbose=1)
model.save('saved_model/testcls_model')

#new_model = tf.keras.models.load_model('saved_model/testcls_model')
#new_model.summary()




results = model.evaluate(test_data.batch(512), verbose=2)

for name, value in zip(model.metrics_names, results):
  print("%s: %.3f" % (name, value))




